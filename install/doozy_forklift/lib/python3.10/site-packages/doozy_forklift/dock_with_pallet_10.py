#!/usr/bin/env python3

import rclpy
import math
import time
import serial
import threading
from numpy import pi
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from example_interfaces.srv import SetBool
from geometry_msgs.msg import Twist, Transform, Vector3
from std_msgs.msg import Bool, String

class SharedData:
    def __init__(self):
        self.pallet_x = 0.0
        self.pallet_y = 0.0
        self.imu_yaw = 0.0
        self.sick_angle = 0.0

        self.lock = threading.Lock()

class Dockpallet(Node):

    def __init__(self, shared_data):
        super().__init__('pallet_dock')

        self.shared_data = shared_data

        self.cmd_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.docking_undocking_diagnostics = self.create_publisher(String, '/dock_undock_diag', 10)
        self.switch_pub = self.create_publisher(Bool, 'switch_topic', 10)

        self.create_subscription(Bool, 'navigation_status', self.navigation_callback, 10)

        self.previous_dist = 0.0
        self.dist_diff = 0.0
        self.total_dist = 0.0
        self.controlled_speed = 0.0

        self.previous_angle = 0.0
        self.angle_diff = 0.0
        self.controlled_angle = 0.0

        self.angle_diff_c = 0.0
        self.angle_z = 0.0

        self.port = '/dev/ttyUSB0'
        self.baudrate = 9600

        self.load_present = False
        self.no_load_present = False
        self.switch_prev_time = False

        self.switch_value = False

        self.navigate_flag = False

        self.dock_flag = False
        self.undock_flag = False

        self.dock_completed_flag = False
        self.undock_completed_flag = False

        self.move_tug = Twist()
        self.diagnostics = String()
        self.switch = Bool()

        self.dock_service = self.create_service(SetBool, 'Docking', self.dock_func)
        # self.create_timer(0.1, self.dock_with_pallet)
        # self.create_timer(0.1, self.read_arduino)

        # PID coefficients
        self.kp_distance = 0.5
        self.ki_distance = 0.1
        self.kd_distance = 0.1
        self.kp_angle = 1.0
        self.ki_angle = 0.1
        self.kd_angle = 0.1

        # PID state
        self.integral_distance = 0.0
        self.integral_angle = 0.0
        self.prev_error_distance = 0.0
        self.prev_error_angle = 0.0

        self.get_logger().info("Initialized Dockpallet node")

    def dock_func(self, request, response):
        if request.data:
            if self.navigate_flag:
                self.dock_flag = True
                self.get_logger().info("Docking flag set to True")

                # Start a timer to tick the tree periodically
                self.create_timer(0.1, self.dock_with_pallet)

            if self.dock_completed_flag:
                response.message = "Docking Complete"
                response.success = True
                self.get_logger().info("Docking Complete")
                return response

        response.message = "Docking Not Initiated"
        response.success = False
        return response

    def dock_with_pallet(self):

        with self.shared_data.lock:
            self.pallet_x = self.shared_data.pallet_x
            self.pallet_y = self.shared_data.pallet_y
            self.imu_yaw = self.shared_data.sick_angle

        self.distance_c = round(math.fabs(math.sqrt((self.pallet_x ** 2) + (self.pallet_y ** 2))), 2)
        self.angle_diff_c = 0.0

        # PID control for distance
        error_distance = self.distance_c
        self.integral_distance += error_distance
        derivative_distance = error_distance - self.prev_error_distance
        control_signal_distance = (self.kp_distance * error_distance +
                                   self.ki_distance * self.integral_distance +
                                   self.kd_distance * derivative_distance)
        self.prev_error_distance = error_distance

        # Cap the linear velocity
        control_signal_distance = max(min(control_signal_distance, 0.3), -0.3)

        # PID control for angle
        error_angle = self.angle_diff_c
        self.integral_angle += error_angle
        derivative_angle = error_angle - self.prev_error_angle
        control_signal_angle = (self.kp_angle * error_angle +
                                self.ki_angle * self.integral_angle +
                                self.kd_angle * derivative_angle)
        self.prev_error_angle = error_angle

        # Cap the angular velocity
        if abs(control_signal_angle) > 0.1:
            if control_signal_angle > 0:
                control_signal_angle = 0.1
            else:
                control_signal_angle = -0.1
        
        elif abs(control_signal_angle) < 0.05:
            if control_signal_angle > 0:
                control_signal_angle = 0.05
            else:
                control_signal_angle = -0.05

        # Move the robot
        self.move_tug.linear.x = -control_signal_distance
        self.move_tug.angular.z = control_signal_angle
        self.cmd_pub.publish(self.move_tug)

        self.get_logger().info(f"distance {self.distance_c} -- angle {self.angle_diff_c} -- linear velocity {control_signal_distance} -- angular velocity {control_signal_angle}")
        
    def navigation_callback(self, msg):
        self.navigate_flag = msg.data

class SICK(Node):
    def __init__(self, shared_data):
        super().__init__('pallet_center_cb')
        self.shared_data = shared_data

        self.create_subscription(Transform, 'pallet_center', self.pallet_center_callback, 10)
        self.create_subscription(String, 'pallet_presence', self.pallet_present_callback, 10)

    def pallet_center_callback(self, msg):
        with self.shared_data.lock:
            self.shared_data.pallet_x = round(msg.translation.x / 1000, 2)
            self.shared_data.pallet_y = round(msg.translation.y / 1000, 2)
            self.shared_data.sick_angle = round(msg.rotation.z, 2)

        if not self.shared_data.pallet_presence:
            with self.shared_data.lock:
                self.shared_data.pallet_x = 0.0
                self.shared_data.pallet_y = 0.0

    def pallet_present_callback(self, msg):
        with self.shared_data.lock:
            if msg.data == 'True':
                self.shared_data.pallet_presence = True
            else:
                self.shared_data.pallet_presence = False

class IMU(Node):
    def __init__(self, shared_data):
        super().__init__('imu_callback')
        self.shared_data = shared_data

        self.create_subscription(Vector3, 'forklift_imu', self.imu_callback, 10)

    def imu_callback(self, msg):
        with self.shared_data.lock:
            self.shared_data.imu_yaw = math.radians(msg.z)

def main():
    rclpy.init()

    shared_data = SharedData()

    dockpallet = Dockpallet(shared_data)
    imu = IMU(shared_data)
    sick = SICK(shared_data)

    executor = MultiThreadedExecutor()
    executor.add_node(dockpallet)
    executor.add_node(imu)
    executor.add_node(sick)

    try:
        executor.spin()
    finally:
        executor.shutdown()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

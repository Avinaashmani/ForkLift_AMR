#!/usr/bin/env python3

import rclpy
import math
import tf2_ros
import threading
import numpy as np
from numpy import pi
from math import sqrt, atan2
from rclpy.node import Node
from rclpy.time import Time
from rclpy.executors import MultiThreadedExecutor
from example_interfaces.srv import SetBool
from geometry_msgs.msg import Twist, Transform, Vector3
from std_msgs.msg import Bool, String

class SharedData:
    def __init__(self):
        self.pallet_x = 0.0
        self.pallet_y = 0.0
        self.pallet_angle  = 0.0

        self.tb3_x = 0.0
        self.tb3_y = 0.0
        self.tb3_angle = 0.0

        self.distance = 0.0
        self.yaw_diff = 0.0

        self.lock = threading.Lock()

class Dockpallet(Node):

    def __init__(self, shared_data):
        super().__init__('pallet_dock')

        self.shared_data = shared_data

        self.move_cmd = self.create_publisher(Twist, 'cmd_vel', 10)
        self.docking_undocking_diagnostics = self.create_publisher(String, '/dock_undock_diag', 10)
        self.switch_pub = self.create_publisher(Bool, 'switch_topic', 10)

        self.create_subscription(Bool, 'navigation_status', self.navigation_callback, 10)

        self.previous_dist = 0.0
        self.dist_diff = 0.0
        self.total_dist = 0.0
        self.controlled_speed = 0.0
        self.previous_distance = 0.0

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

        self.cmd_vel = Twist()
        self.diagnostics = String()
        self.switch = Bool()

        self.path_angle_err = 0.0
        self.desired_heading = 0.0

        self.dock_service = self.create_service(SetBool, 'Docking', self.dock_func)
        # self.create_timer(0.1, self.dock_with_pallet)
        # self.create_timer(0.1, self.read_arduino)

        # PID coefficients
        self.kp_distance = 0.1
        self.ki_distance = 0
        self.kd_distance = 0.1

        self.kp_angle = 0.5
        self.ki_angle = 0
        self.kd_angle = 30

        self.threshold_distance = 0.5
        self.threshold_angle = 0.02

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
            self.pallet_angle = self.shared_data.pallet_angle

            self.tb3_x = self.shared_data.tb3_x
            self.tb3_y = self.shared_data.tb3_y 
            self.tb3_angle = self.shared_data.tb3_angle

            self.dist_diff = self.shared_data.distance
            self.angle_diff = self.shared_data.yaw_diff
            self.path_angle_err = self.shared_data.path_angle_err

        distance = self.dist_diff
        path_angle = self.angle_diff

        self.integral_distance += distance
        self.integral_angle += path_angle

        diff_angle = path_angle - self.previous_angle
        diff_distance = distance - self.previous_distance


        def dynamic_gain(base_gain, error, threshold):
            
            if abs(error) < threshold:
                return base_gain * (1 + (threshold - abs(error)) / threshold)
            
            else:
                return base_gain * threshold/ abs(error)
        
        
        kp_distance_dynamic = dynamic_gain(self.kp_distance, distance, self.threshold_distance)
        # ki_distance_dynamic = dynamic_gain(self.ki_distance, distance, self.threshold_distance)
        kd_distance_dynamic = dynamic_gain(self.kd_distance, distance, self.threshold_distance)

        kp_angle_dynamic = dynamic_gain(self.kp_angle, path_angle, self.threshold_angle)
        # ki_angle_dynamic = dynamic_gain(self.ki_angle, path_angle, self.threshold_angle)
        kd_angle_dynamic = dynamic_gain(self.kd_angle, path_angle, self.threshold_angle)

        self.controlled_speed = (self.kp_distance * distance +
                            #  ki_distance_dynamic * self.integral_distance +
                             self.kd_distance * diff_distance)

        self.controlled_angle = (self.kp_angle * path_angle +
                            #  ki_angle_dynamic * self.integral_angle +
                             self.kd_angle* diff_angle)
        
        # Apply a dead zone for angle control to prevent oscillations around the target angle
        if abs(path_angle) < 0.02:
            self.controlled_angle = 0.0

        # Limit the maximum speed to prevent overshooting
        max_linear_speed = 0.25  # Adjust based on your robot's dynamics
        max_angular_speed = 0.10  # Adjust based on your robot's dynamics

        self.controlled_speed = max(-max_linear_speed, min(max_linear_speed, self.controlled_speed))
        self.controlled_angle = max(-max_angular_speed, min(max_angular_speed, self.controlled_angle))
        
        self.cmd_vel.angular.z = self.controlled_angle
        self.cmd_vel.linear.x  = -self.controlled_speed

        self.move_cmd.publish(self.cmd_vel)

        self.previous_distance = distance
        self.previous_angle = path_angle

        if distance < 0.5 and abs(path_angle) < 0.02:
            self.get_logger().info("Docking complete")
            self.dock_completed_flag = True
            self.dock_flag = False
            self.cmd_vel.linear.x = 0.0
            self.cmd_vel.angular.z = 0.0
            self.move_cmd.publish(self.cmd_vel)
            return

        self.get_logger().info("Current position and rotation: distance = %.2f, angle = %.2f" % (distance, path_angle))
        self.get_logger().info("Current Speed and Angular vel: vel_x = %.2f, vel_z = %.2f" % (self.controlled_speed, self.controlled_angle))

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

# class IMU(Node):
    def __init__(self, shared_data):
        super().__init__('imu_callback')
        self.shared_data = shared_data

        self.create_subscription(Vector3, 'forklift_imu', self.imu_callback, 10)

    def imu_callback(self, msg):
        with self.shared_data.lock:
            self.shared_data.imu_yaw = math.radians(msg.z)

class ReadTf(Node):
    
    def __init__(self, shared_data):
        super().__init__('read_tf_data')

        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        self.pallet_x = 0.0
        self.pallet_y = 0.0
        self.pallet_angle = 0.0

        self.tb3_x = 0.0
        self.tb3_y = 0.0
        self.tb3_angle = 0.0

        self.distance = 0.0
        self.yaw_diff = 0.0
        self.path_angle_err = 0.0
        self.path_dist_err = 0.0
        self.desired_heading = 0.0
        self.heading_err = 0.0

        self.shared_data = shared_data

        self.diagnostic_pub = self.create_publisher(String, '/forklift_amr/diagnostics', 10 )
        
        self.pallet_frame = 'pallet_center'
        self.source_frame = 'odom'
        self.tb3_frame = 'base_link'

        self.diagnostics = String()

        self.create_timer(0.1, self.tf_update)

    def tf_update(self):

        try:
            pallet_transform = self.tf_buffer.lookup_transform(self.source_frame, self.pallet_frame, Time())
            tb3_transform = self.tf_buffer.lookup_transform(self.source_frame, self.tb3_frame, Time())
            self.update_frame(pallet_transform, tb3_transform)

        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:

            self.get_logger().warn("LookupException: {0}".format(str(e)))
            self.diagnostics.data = "Docking Error. Please Check !"
            self.diagnostic_pub.publish(self.diagnostics)

        self.distance = math.fabs(sqrt(pow(self.pallet_x - self.tb3_x, 2) + pow(self.pallet_y - self.tb3_y, 2)))
        self.path_angle_err = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x) / 3.14

        self.yaw_diff = self.path_angle_err

        angle_err_pallet = atan2(self.pallet_y, self.pallet_x)
        angle_err_robot = atan2(self.tb3_y, self.tb3_x)

        with self.shared_data.lock:

            self.shared_data.pallet_x = self.pallet_x
            self.shared_data.pallet_y = self.pallet_y
            self.shared_data.pallet_angle = self.pallet_angle
            self.shared_data.distance = self.distance
            self.shared_data.yaw_diff = angle_err_pallet - angle_err_robot
            self.shared_data.path_angle_err = angle_err_pallet - angle_err_robot

    def update_frame(self, target_frame, robot_frame):

        self.pallet_x = target_frame.transform.translation.x
        self.pallet_y = target_frame.transform.translation.y

        pallet_angle_x = target_frame.transform.rotation.x
        pallet_angle_y = target_frame.transform.rotation.y
        pallet_angle_z = target_frame.transform.rotation.z
        pallet_angle_w = target_frame.transform.rotation.w

        self.pallet_angle = self.euler_from_quaternion(pallet_angle_x, pallet_angle_y, 
                                                pallet_angle_z, pallet_angle_w)
                
        self.tb3_x = robot_frame.transform.translation.x
        self.tb3_y = robot_frame.transform.translation.y

        tb3_angle_x = robot_frame.transform.rotation.x
        tb3_angle_y = robot_frame.transform.rotation.y
        tb3_angle_z = robot_frame.transform.rotation.z
        tb3_angle_w = robot_frame.transform.rotation.w

        self.tb3_angle = self.euler_from_quaternion(tb3_angle_x, tb3_angle_y,
                                                      tb3_angle_z, tb3_angle_w)
        
    def euler_from_quaternion(self, x, y, z, w):
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll_x = math.atan2(t0, t1)

        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = math.asin(t2)

        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw_z = math.atan2(t3, t4)

        return yaw_z        

def main():
    rclpy.init()

    shared_data = SharedData()

    dockpallet = Dockpallet(shared_data)
    # imu = IMU(shared_data)
    # sick = SICK(shared_data)
    tf = ReadTf(shared_data)

    executor = MultiThreadedExecutor()
    executor.add_node(dockpallet)
    # executor.add_node(imu)
    # executor.add_node(sick)
    executor.add_node(tf)

    try:
        executor.spin()
    finally:
        executor.shutdown()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

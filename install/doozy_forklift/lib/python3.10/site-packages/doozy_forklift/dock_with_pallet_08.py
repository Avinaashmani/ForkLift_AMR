#1/usr/bin/env python3

import serial.serialutil
import rclpy
import tf2_ros
import math
import time
import serial
from math import sqrt, atan2
from rclpy.node import Node
from rclpy.time import Time
from rclpy.executors import SingleThreadedExecutor
from example_interfaces.srv import SetBool
from geometry_msgs.msg import Twist, Transform
from std_msgs.msg import Bool, String


class DockWithPallet(Node):
    def __init__(self):

        super().__init__('pallet_dock')
        # self.get_logger().info('Pallet Docker Node [dock] [undock] [e_stop]')
        
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel/test', 10)
        self.diagnostic_messages_pub = self.create_publisher(String, 'diagnostics_topic', 10)
        self.switch_status_pub = self.create_publisher(String, 'switch_status', 10)

        self.velocity_msg = Twist()
        self.switch_msg = String()
        self.diagnostic_msg = String()

        self.create_subscription(Bool, 'navigation_status', self.operation_callback, 10)
        self.create_subscription(Transform, 'pallet_center', self.pallet_center_callback, 10)
        self.create_subscription(Transform, 'pallet_right', self.pallet_right_callback, 10)
        self.create_subscription(Transform, 'pallet_left', self.pallet_left_callback, 10)
        self.create_subscription(String, 'pallet_presence', self.pallet_presence_callback, 10)

        self.operation_flag = 0

        self.navigation_flag = False

        self.pallet_presence_flag = False

        self.left_x = 0.0
        self.left_y = 0.0
        self.left_angle_z = 0.0

        self.right_x = 0.0
        self.right_y = 0.0
        self.right_angle_z = 0.0

        self.center_x = 0.0
        self.center_y = 0.0
        self.center_angle_z = 0.0

        self.robot_x = 0.0
        self.robot_y = 0.0
        self.robot_angle_z = 0.0

        self.angle_diff_center = 0.0
        self.distance_diff_center = 0.0

        self.angle_diff_right = 0.0
        self.distance_diff_right = 0.0

        self.angle_diff_left = 0.0
        self.distance_diff_left = 0.0

        self.dock_flag = False
        self.undock_flag = False
        self.e_stop_flag = False

        self.docking_status_flag = False
        self.undocking_status_flag = False
        self.e_stop_status_flag = False

        self.switch_flag = False
        self.engaged_timer = False
        self.serial_port = '/dev/ttyUSB0'
        self.baud_rate = 9600
        self.switch_prev_time = False

        self.dock_srv = self.create_service(SetBool, 'Docking', self.dock_service_callback)
        self.undock_srv = self.create_service(SetBool, 'Undocking', self.undock_service_callback)
        self.e_stop_srv = self.create_service(SetBool, 'E_Stop', self.e_stop_service_callback)

        self.create_timer(0.05, self.arduino_communication)
        self.create_timer(0.05, self.docking_compute)

    def dock_service_callback(self, request, response):
        
        if self.navigation_flag and request.data is True:
            
            self.dock_flag = True
            
            if self.docking_status_flag is True:
                response.message = " >> Docking is Completed <<"
                response.success = True
                self.get_logger().info(">> Docking Completed <<")
                return response
        
        return response
    
    def undock_service_callback(self, request, response):
        
        if self.navigation_flag and request.data is True:

            self.undock_flag = True

            if self.undocking_status_flag is True:
                response.message = '>> Undocking Completed <<'
                response.success = True
                self.get_logger().info(">> Undocking Complete <<")
                return response
        
        return response    

    def e_stop_service_callback(self, request, response):
        
        if request.data is True:

            self.e_stop_flag = True

            if self.e_stop_status_flag is True:
                response.message = '>> E-Stop Engaged <<'
                response.success = True
                self.get_logger().warn(">> EMERGENCY STOP <<")
                return response
        
        return response    
    
    def operation_callback(self, msg):
        
        if msg.data == 'load':
            self.operation_flag = 1
        elif msg.data == 'unload':
            self.operation_flag = 2
        else:
            self.operation_flag = 0    

    def docking_compute(self):

        if self.navigation_flag and self.dock_flag:

            if self.angle_diff_center > 1.5:

                if self.switch_flag:
                    
                    self.velocity_msg.linear.x = 0.0
                    self.velocity_msg.angular.z = 0.0
                    self.cmd_vel_pub.publish(self.velocity_msg)
                    self.dock_flag = False
                    self.docking_status_flag = False
                    self.get_logger().error("Switch triggered before Operation Complete")
                    self.diagnostic_msg.data = "Switch triggered before Operation Complete"
                    self.diagnostic_messages_pub.publish(self.diagnostic_msg)
                
                else:

                    self.velocity_msg.angular.z = 0.07
                    self.cmd_vel_pub.publish(self.velocity_msg)

                    if self.distance_diff_center > 1.5:
                        self.velocity_msg.linear.x = -0.1
                        self.cmd_vel_pub.publish(self.velocity_msg)

                    else:
                        self.velocity_msg.linear.x = 0.0
                        self.cmd_vel_pub.publish(self.velocity_msg)

                    self.get_logger().info(f"Angle {self.angle_diff_center} == Distance {self.distance_diff_center}")
                    self.diagnostic_msg.data = f"Angle {self.angle_diff_center} == Distance {self.distance_diff_center}"
                    self.diagnostic_messages_pub.publish(self.diagnostic_msg)
            
            elif self.angle_diff_center > 0.1 and self.angle_diff_center < 1.5:

                if self.switch_flag:
                    
                    self.velocity_msg.linear.x = 0.0
                    self.velocity_msg.angular.z = 0.0
                    self.cmd_vel_pub.publish(self.velocity_msg)
                    self.dock_flag = False
                    self.docking_status_flag = False
                    self.get_logger().error("Switch triggered before Operation Complete")
                    self.diagnostic_msg.data = "Switch triggered before Operation Complete"
                    self.diagnostic_messages_pub.publish(self.diagnostic_msg)
                
                else:
                    self.velocity_msg.angular.z = -0.07
                    self.cmd_vel_pub.publish(self.velocity_msg)

                    if self.distance_diff_center > 1.5:
                        self.velocity_msg.linear.x = -0.1
                        self.cmd_vel_pub.publish(self.velocity_msg)

                    else:
                        self.velocity_msg.linear.x = 0.0
                        self.cmd_vel_pub.publish(self.velocity_msg)
                    
                    self.get_logger().info(f"Angle {self.angle_diff_center} == Distance {self.distance_diff_center}")
                    self.diagnostic_msg.data = f"Angle {self.angle_diff_center} == Distance {self.distance_diff_center}"
                    self.diagnostic_messages_pub.publish(self.diagnostic_msg)
            
            elif self.angle_diff_center <= 0.1:

                if self.switch_flag:
                    
                    self.velocity_msg.linear.x = 0.0
                    self.velocity_msg.angular.z = 0.0
                    self.cmd_vel_pub.publish(self.velocity_msg)
                    self.dock_flag = False
                    self.docking_status_flag = False
                    self.get_logger().error("Switch triggered before Operation Complete")
                    self.diagnostic_msg.data = "Switch triggered before Operation Complete"
                    self.diagnostic_messages_pub.publish(self.diagnostic_msg)
                
                else:
                    self.velocity_msg.angular.z = 0.0
                    self.cmd_vel_pub.publish(self.velocity_msg)

                    if self.distance_diff_center > 1.5:
                        self.velocity_msg.linear.x = -0.1
                        self.cmd_vel_pub.publish(self.velocity_msg)

                    else:
                        self.velocity_msg.linear.x = 0.0
                        self.cmd_vel_pub.publish(self.velocity_msg)
                    
                    self.get_logger().info(f"Angle {self.angle_diff_center} == Distance {self.distance_diff_center}")
                    self.diagnostic_msg.data = f"Angle {self.angle_diff_center} == Distance {self.distance_diff_center}"
                    self.diagnostic_messages_pub.publish(self.diagnostic_msg)

    def navigation_callback(self, msg):
        self.navigation_flag = msg.data

    def pallet_presence_callback(self, msg):
        
        if msg.data == 'True':
            self.pallet_presence_flag = True
        
        else:
            self.pallet_presence_flag = False

    def pallet_center_callback(self, msg):
        
        self.center_x = msg.translation.x / 1000
        self.center_y = msg.translation.y / 1000

        self.center_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)
        self.robot_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)

        self.distance_diff_center = math.fabs(sqrt(pow(self.center_x - self.robot_x, 2) + pow(self.center_y - self.robot_y, 2)))
        self.angle_diff_center = math.fabs(atan2(self.robot_y - self.center_y , self.robot_x - self.center_x ) - self.robot_angle_z)
    
    def pallet_right_callback(self, msg):
        
        self.right_x = msg.translation.x / 1000
        self.right_y = msg.translation.y / 1000

        self.right_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)
        self.robot_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)

        self.distance_diff_right = math.fabs(sqrt(pow(self.right_x - self.robot_x, 2) + pow(self.right_y - self.robot_y, 2)))
        self.angle_diff_right = atan2(self.robot_y - self.right_y , self.robot_x - self.right_x ) - self.robot_angle_z
    
    def pallet_left_callback(self, msg):

        self.left_x = msg.translation.x / 1000
        self.left_y = msg.translation.y / 1000

        self.left_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)
        self.robot_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)

        self.distance_diff_left = math.fabs(sqrt(pow(self.left_x - self.robot_x, 2) + pow(self.left_y - self.robot_y, 2)))
        self.angle_diff_left = atan2(self.robot_y - self.left_y , self.robot_x - self.left_x ) - self.robot_angle_z
    
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
    
    def arduino_communication(self):

        try:
            arduino_01 = serial.Serial(self.serial_port, self.baud_rate)
            switch_state = arduino_01.readline().decode().strip()

            if switch_state == '1':

                self.switch_flag = True
                self.switch_msg.data = "Switch is Engaged"
                self.switch_status_pub.publish(self.switch_msg)

            else:

                self.switch_flag = False
                self.switch_msg.data = "Switch is Dis-engaged"
                self.switch_status_pub.publish(self.switch_msg)

            print(f" Switch is:  {str(self.switch_flag)}")
            
        except serial.serialutil.SerialException as e:
            self.get_logger().warn(e)   


def main():
    rclpy.init()
    docker = DockWithPallet()
    rclpy.spin(docker)
    rclpy.shutdown()

if __name__=='__main__':
    main()

if __name__=='__main__':
    main()
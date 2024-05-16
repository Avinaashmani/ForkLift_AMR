#!/usr/bin/env python3

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
# from sick_visionary_t_mini.msg import SickTMini

class Dockpallet(Node):

    def __init__(self):
        super().__init__('pallet_dock')

        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        self.cmd_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.docking_undocking_diagnostics = self.create_publisher(String, '/dock_undock_diag', 10)
        self.switch_pub = self.create_publisher(Bool, 'switch_topic', 10)
        
        self.create_subscription(Bool, 'navigation_status', self.navigation_status_callback, 10)
        self.create_subscription(Transform, '/pallet_center', self.pallet_center_callback, 10)
        self.port = '/dev/ttyUSB0'
        self.baudrate = 9600
        
        self.load_present = False
        self.no_load_present = False
        self.switch_prev_time = False
        
        self.load_flag = False
        self.unload_flag = False
        
        self.loading_completed = False
        self.unloading_completed = False
        
        self.pallet_released = False
        self.pallet_placed = False

        self.pallet_presence = False
        self.pallet_frame = 'pallet_center'
        self.source_frame = 'map'
        self.tb3_frame = 'map'

        self.tb3_x = 0.0
        self.tb3_y = 0.0
        self.tb3_angle_z = 0.0

        self.pallet_x = 0.0
        self.pallet_y = 0.0
        self.pallet_angle_z = 0.0

        self.navigate_flag = False
        
        self.dock_flag = False
        self.undock_flag = False
        
        self.dock_completed_flag = False
        self.undock_completed_flag = False

        self.move_tug = Twist()
        self.diagnostics = String()
        self.switch = Bool()
        
        self.dock_service = self.create_service(SetBool, 'Docking', self.dock_func)
        self.undock_servicee = self.create_service(SetBool, 'UnDocking', self.undock_func)
        
        self.create_subscription(Bool, 'load_topic', self.load, 10)
        self.create_subscription(String, 'pallet_presence', self.pallet_present_callback, 10)
        
        self.create_timer(0.1, self.dock_load)
        self.create_timer(0.1, self.read_arduino)
        # self.create_timer(0.1, self.update_frame)
        
        self.alignment_1 = False
        self.alignment_2 = False

        self.distance_c = 0.0
        self.angle_diff_c = 0.0

        self.distance_r = 0.0
        self.angle_diff_r = 0.0

        self.distance_l = 0.0
        self.angle_diff_l = 0.0

        self.left_align = False
        self.right_align = False
        self.center_aling = False

    def dock_func(self, request, response):
        
        if self.navigate_flag and request.data is True:
            # print(self.dock_flag)
            # print(self.navigate_flag)
            
            self.dock_flag = True
            
            if self.dock_completed_flag is True:
                response.message = "Docking Complete"
                response.success = True
                self.get_logger().info("Docking Complete")
                return response
            
        return response
    
    def undock_func(self, request, response):
        
        if self.navigate_flag and request.data is True:
            
            self.undock_flag = True
            
            if self.undock_completed_flag is True:
                response.message = "Undocking complete"
                response.success = True
                self.get_logger().info("Docking Complete")
                return response
            
        return response
    
    def load(self, msg):
        
        self.load_flag = msg.data
    
    def unload(self, msg):
        
        self.unload_flag = msg.data
                
    def dock_load(self):
        print(self.angle_diff_c)
        if self.load_flag:
            self.move_tug.linear.x = 0.0
            self.move_tug.angular.z = 0.0
            self.cmd_pub.publish(self.move_tug)
            self.dock_flag = False
            self.dock_completed_flag = False
            self.get_logger().error("Switch Pressed")
            self.diagnostics.data = "Switch Pressed"
            self.docking_undocking_diagnostics.publish(self.diagnostics)

        else:

            if self.dock_flag and self.navigate_flag :

                print("-----Pallet Center------")
                print(self.angle_diff_c)
                print("-----------------")

                if abs(self.angle_diff_c) > 1.5 :

                    self.move_tug.angular.z = 0.05
                    self.cmd_pub.publish(self.move_tug)

                elif self.angle_diff_c > 0.1 and self.angle_diff_c < 1.5:
                        # self.update_frame()
                        self.move_tug.angular.z = -0.05
                        self.cmd_pub.publish(self.move_tug)

                elif abs(self.angle_diff_c) <= 0.1:

                    self.move_tug.angular.z = 0.0
                    self.cmd_pub.publish(self.move_tug) 

                    self.center_aling = True

                # print(self.left_align)
                # print(self.right_align)
                print(self.center_aling)

            else:
                self.move_tug.angular.z = 0.0
                self.cmd_pub.publish(self.move_tug) 
                self.left_align = False
                self.right_align = False
                self.center_aling = False
           
    def update_frame(self):
                    
        try:
            pallet_transform_right = self.tf_buffer.lookup_transform(self.source_frame, 'pallet_right_corner', Time())
            pallet_transform_left = self.tf_buffer.lookup_transform(self.source_frame, 'pallet_left_corner', Time())
            pallet_center = self.tf_buffer.lookup_transform(self.source_frame, 'pallet_center', Time())

            tb3_frame = self.tf_buffer.lookup_transform(self.source_frame, self.tb3_frame, Time())
            # self.update_frame(target_frame=pallet_transform, tb3_frame=tb3_transform)
                   
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:
                
            self.get_logger().warn("LookupException: {0}".format(str(e)))
            self.diagnostics.data = "Docking Error. Please Check !"
            self.docking_undocking_diagnostics.publish(self.diagnostics)
            self.dock_flag = False
            self.dock_completed_flag = False
                
        print(self.distance_l)
        print(self.distance_c)
        print(self.distance_r)

        right_corner_x = pallet_transform_right.transform.translation.x
        right_corner_y = pallet_transform_right.transform.translation.y
        
        right_angle_x = pallet_transform_right.transform.rotation.x
        right_angle_y = pallet_transform_right.transform.rotation.y
        right_angle_z = pallet_transform_right.transform.rotation.z
        right_angle_w = pallet_transform_right.transform.rotation.w

        left_corner_x = pallet_transform_left.transform.translation.x
        left_corner_y = pallet_transform_left.transform.translation.y

        left_angle_x = pallet_transform_left.transform.rotation.x
        left_angle_y = pallet_transform_left.transform.rotation.y

        left_angle_x = pallet_transform_left.transform.rotation.x
        left_angle_y = pallet_transform_left.transform.rotation.y
        left_angle_z = pallet_transform_left.transform.rotation.z
        left_angle_w = pallet_transform_left.transform.rotation.w

        pallet_center_x = pallet_center.transform.translation.x
        pallet_center_y = pallet_center.transform.translation.y

        pallet_center_angle_x = pallet_center.transform.rotation.x
        pallet_center_angle_y = pallet_center.transform.rotation.y
        pallet_center_angle_z = pallet_center.transform.rotation.z
        pallet_center_angle_w = pallet_center.transform.rotation.w

        right_yaw_angle = self.euler_from_quaternion(right_angle_x, right_angle_y, 
                                                        right_angle_z, right_angle_w)
        
        left_yaw_angle = self.euler_from_quaternion(left_angle_x, left_angle_y, 
                                                    left_angle_z, left_angle_w)
        
        center_yaw_angle = self.euler_from_quaternion(pallet_center_angle_x, pallet_center_angle_y, 
                                                      pallet_center_angle_z, pallet_center_angle_w)
        
        self.angle_diff_r = atan2(right_corner_y - self.tb3_y, right_corner_x - self.tb3_x) - self.tb3_angle_z 
        self.distance_r = math.fabs(sqrt(pow(right_corner_x - self.tb3_x, 2) + pow(right_corner_y - self.tb3_y, 2)))
        
        self.angle_diff_l = atan2(left_corner_y - self.tb3_y, left_corner_x - self.tb3_x) - self.tb3_angle_z
        self.distance_l = math.fabs(sqrt(pow(left_corner_x - self.tb3_x, 2) + pow(left_corner_y - self.tb3_y, 2)))

        self.angle_diff_c = atan2(pallet_center_y - self.tb3_y, pallet_center_x - self.tb3_x) - self.tb3_angle_z
        self.distance_c = math.fabs(sqrt(pow(pallet_center_x - self.tb3_x, 2) + pow(pallet_center_y - self.tb3_y, 2)))
        
        self.tb3_x = tb3_frame.transform.translation.x
        self.tb3_y = tb3_frame.transform.translation.y

        tb3_angle_x = tb3_frame.transform.rotation.x
        tb3_angle_y = tb3_frame.transform.rotation.y
        tb3_angle_z = tb3_frame.transform.rotation.z
        tb3_angle_w = tb3_frame.transform.rotation.w

        self.tb3_angle_z = self.euler_from_quaternion(tb3_angle_x, tb3_angle_y,
                                                      tb3_angle_z, tb3_angle_w)
        
        # distance = math.fabs(sqrt(pow(self.pallet_x - self.tb3_x, 2) + pow(self.pallet_y - self.tb3_y, 2)))
        # angle_difference = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x) - self.tb3_angle_z

        # return distance, angle_difference

    def navigation_status_callback(self, msg):
        self.navigate_flag = msg.data

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
    
    # def get_frames(self):
        
    #     # if self.pallet_presence:

    def pallet_center_callback(self, msg):
        self.pallet_x = msg.translation.x / 1000
        self.pallet_y = msg.translation.y / 1000
        
        pallet_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)
        robot_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)
        

        self.distance = math.fabs(sqrt(pow(self.pallet_x - 0, 2) + pow(self.pallet_y - 0, 2)))
        self.angle_difference = atan2(0.0 - self.pallet_y , 0.0-self.pallet_x ) - robot_angle_z

        self.angle_diff_c = math.fabs(self.angle_difference / 3.14)

        # print(self.distance)
        print(math.fabs(self.angle_diff_c))

    def read_arduino(self):
        
        try:
            self.arduino_01 = serial.Serial(self.port, self.baudrate, timeout=0.1)
            switch_state = self.arduino_01.readline().decode().strip()
            
            if switch_state == '1':
                self.switch_value = True
                self.switch.data = True
                
                if self.switch_prev_time is None:
                    self.switch_prev_time = time.time()

                if time.time() - self.switch_prev_time > 0.5:
                    self.load_present = True
                    self.no_load_present = False
                else:
                    self.load_present = False
                    self.no_load_present = False
            
            else:
                self.switch_value = False
                self.switch.data = False
                self.switch_prev_time = None
                self.no_load_present = True
                self.load_present = False
            
            self.switch_pub.publish(self.switch)
            print(self.load_present, "-----", self.no_load_present)
            
        except serial.serialutil.SerialException as e:
            self.get_logger().warn(e)

    def pallet_present_callback(self, msg):

        if msg.data == 'True':
            self.pallet_presence = True
        else:
            self.pallet_presence = False
def main():
    rclpy.init()
    try:
        dock_with_pallet = Dockpallet()
        executor = SingleThreadedExecutor()
        executor.add_node(dock_with_pallet)
        try:
            executor.spin()
        finally:
            executor.shutdown()
            dock_with_pallet.destroy_node()
    finally:
        rclpy.shutdown()

if __name__=='__main__':
    main()
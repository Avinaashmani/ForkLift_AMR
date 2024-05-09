#!/usr/bin/env python3

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
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool, String
from sick_visionary_t_mini.msg import SickTMini

class Dockpallet(Node):

    def __init__(self):
        super().__init__('pallet_dock')

        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        self.cmd_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.docking_undocking_diagnostics = self.create_publisher(String, '/dock_undock_diag', 10)
        self.create_subscription(Bool, '/navigation_status', self.navigation_status_callback, 10)
        self.create_subscription(SickTMini, '/pallet_detection', self.sick_callback, 10)

        self.port = '/dev/ttyUSB01'

        self.limit_switch_01 = serial.Serial()

        self.pallet_presence = False
        self.pallet_frame = 'pallet_center'
        self.source_frame = 'map'
        self.tb3_frame = 'base_link'

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
        
        self.dock_service = self.create_service(SetBool, 'Docking', self.dock_func)
        self.undock_servicee = self.create_service(SetBool, 'UnDocking', self.undock_func)
        
        self.create_timer(0.1, self.check_distance)
        self.create_timer(0.1, self.undock_forklift)
    
    def dock_func(self, request, response):
        
        if self.navigate_flag and request.data is True:
            self.dock_flag = True
            
            if self.dock_completed_flag is True:
                response.message = "Docking complete"
                response.success = True
                return response
        return response
    
    def undock_func(self, request, response):
        
        if self.navigate_flag and request.data is True:
            self.undock_flag = True
            
            if self.undock_completed_flag is True:
                response.message = "Undocking complete"
                response.success = True
                return response
            
        return response
    
    def check_distance(self):

        if self.dock_flag and self.navigate_flag:

            try:
                pallet_transform = self.tf_buffer.lookup_transform(self.source_frame, self.pallet_frame, Time())
                tb3_transform = self.tf_buffer.lookup_transform(self.source_frame, self.tb3_frame, Time())
                self.update_frame(target_frame=pallet_transform, tb3_frame=tb3_transform)

                distance = math.fabs(sqrt(pow(self.pallet_x - self.tb3_x, 2) + pow(self.pallet_y - self.tb3_y, 2)))
                angle_difference = self.pallet_angle_z - self.tb3_angle_z
                distance_error = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x)
                yaw_angle_error = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x) - self.tb3_angle_z

                if abs(distance) > 0.2:
                    self.update_frame(target_frame=pallet_transform, tb3_frame=tb3_transform)
                    print("---------------")
                    print(distance)
                    print(distance_error)
                    print(yaw_angle_error)
                    print("---------------")
                    self.dock_completed_flag = False

                    self.diagnostics.data = "Docking Under Process..."
                    self.docking_undocking_diagnostics.publish(self.diagnostics)

                    if abs(yaw_angle_error) > 0.10:
                        
                        if abs(angle_difference) > 0.1:
                            
                            if yaw_angle_error > 0.0:
                                self.move_tug.angular.z = 0.2
                                self.cmd_pub.publish(self.move_tug)
                            else:
                                self.move_tug.angular.z = -0.2
                                self.cmd_pub.publish(self.move_tug)
                    else:
                        self.move_tug.linear.x = 0.07
                        self.cmd_pub.publish(self.move_tug)
                    
                    # self.move_tug.linear.x = 0.0
                    # self.move_tug.angular.z = 0.0
                    # self.cmd_pub.publish(self.move_tug)
                
                else:
                    self.move_tug.linear.x = 0.0
                    self.move_tug.angular.z = 0.0
                    self.cmd_pub.publish(self.move_tug)
                    self.dock_completed_flag = True
                    self.get_logger().warn("Docking completed :)")
                    self.dock_flag = False

                    self.diagnostics.data = "Docking Completed."
                    self.docking_undocking_diagnostics.publish(self.diagnostics)
                    return True

            except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:
                self.get_logger().warn("LookupException: {0}".format(str(e)))
                self.diagnostics.data = "Docking Error. Please Check !"
                self.docking_undocking_diagnostics.publish(self.diagnostics)
                self.dock_flag = False
                self.dock_completed_flag = False

    def undock_forklift(self):

        if self.undock_flag and self.navigate_flag:
            
            try:
                pallet_transform = self.tf_buffer.lookup_transform(self.source_frame, self.pallet_frame, Time())
                tb3_transform = self.tf_buffer.lookup_transform(self.source_frame, self.tb3_frame, Time())
                self.update_frame(target_frame=pallet_transform, tb3_frame=tb3_transform)

                distance = math.fabs(sqrt(pow(self.pallet_x - self.tb3_x, 2) + pow(self.pallet_y - self.tb3_y, 2)))
                angle_difference = self.pallet_angle_z - self.tb3_angle_z
                distance_error = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x)
                yaw_angle_error = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x) - self.tb3_angle_z

                if abs(distance) < 0.7:
                    
                    self.update_frame(target_frame=pallet_transform, tb3_frame=tb3_transform)
                    
                    print("---------------")
                    print(distance)
                    print(distance_error)
                    print(yaw_angle_error)
                    print(angle_difference)
                    print("---------------")

                    self.move_tug.linear.x = -0.07
                    self.cmd_pub.publish(self.move_tug) 

                    self.diagnostics.data = "Undocking Under Process..."
                    self.docking_undocking_diagnostics.publish(self.diagnostics)

                # if abs(yaw_angle_error) < 0.10:
                        
                #     if abs(angle_difference) > 0.1:
                            

                #         self.move_tug.angular.z = 0.2
                #         self.cmd_pub.publish(self.move_tug)
                    
                #     else:
                #         self.move_tug.angular.z = -0.2
                #         self.cmd_pub.publish(self.move_tug)
                else:
                    self.move_tug.linear.x = 0.0
                    self.move_tug.angular.z = 0.0
                    self.cmd_pub.publish(self.move_tug)
                    self.undock_completed_flag = True
                    self.get_logger().warn("Undocking completed :)")
                    self.diagnostics.data = "Undocking Completed."
                    self.docking_undocking_diagnostics.publish(self.diagnostics)
                    self.undock_flag = False
                    return True

            except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:
                self.get_logger().warn("LookupException: {0}".format(str(e)))
                self.diagnostics.data = "Undocking Error, Please Check !"
                self.docking_undocking_diagnostics.publish(self.diagnostics)
                self.undock_flag = False
                self.undock_completed_flag = False

                
    def update_frame(self,target_frame, tb3_frame):
        self.pallet_x = target_frame.transform.translation.x
        self.pallet_y = target_frame.transform.translation.y

        pallet_angle_x = target_frame.transform.rotation.x
        pallet_angle_y = target_frame.transform.rotation.y
        pallet_angle_z = target_frame.transform.rotation.z
        pallet_angle_w = target_frame.transform.rotation.w

        self.pallet_angle_z = self.euler_from_quaternion(pallet_angle_x, pallet_angle_y, 
                                                        pallet_angle_z, pallet_angle_w)
        
        self.tb3_x = tb3_frame.transform.translation.x
        self.tb3_y = tb3_frame.transform.translation.y

        tb3_angle_x = tb3_frame.transform.rotation.x
        tb3_angle_y = tb3_frame.transform.rotation.y
        tb3_angle_z = tb3_frame.transform.rotation.z
        tb3_angle_w = tb3_frame.transform.rotation.w

        self.tb3_angle_z = self.euler_from_quaternion(tb3_angle_x, tb3_angle_y,
                                                      tb3_angle_z, tb3_angle_w)
        
    def navigation_status_callback(self, msg):
        self.navigate_flag = msg.data
    
    def sick_callback(self, msg):
        self.pallet_presence = msg.data

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
    
    def sick_callback(self, msg):
        self.pallet_presence = msg.pallet_found

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

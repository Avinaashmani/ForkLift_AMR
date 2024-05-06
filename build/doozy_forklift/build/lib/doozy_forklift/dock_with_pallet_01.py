#!/usr/bin/env python3

import rclpy
import math
import time
from math import sqrt, pow, atan2
from rclpy.node import Node
from rclpy.time import Time
from example_interfaces.srv import SetBool
import tf2_ros
from geometry_msgs.msg import Twist
from std_msgs.msg import String, Bool

class Dockpallet(Node):

    def __init__(self):
        super().__init__('pallet_dock')

        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        self.cmd_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.create_subscription(Bool, '/navigation_status', self.navigation_status_callback, 10)
        self.create_subscription(Bool, '/sick_camera', self.sick_callback, 10)

        self.pallet_presence = True
        self.pallet_frame = 'pallet_center'
        self.source_frame = 'map'
        self.tb3_x = 0.0
        self.tb3_y = 0.0
        self.tb3_angle_z = 0.0

        self.pallet_x = 0.0
        self.pallet_y = 0.0
        self.pallet_angle_z = 0.0

        self.navigate_flag = False
        self.dock_flag = False

        self.move_tug = Twist()
        
        self.dock_service = self.create_service(SetBool, 'Docking', self.dock_func)
        self.undock_servicee = self.create_service(SetBool, 'UnDocking', self.undock_func)

    def dock_func(self, request, response):
        if self.navigate_flag and request.data is True:
            flag = True
            while flag:
                try:
                    pallet_transform = self.tf_buffer.lookup_transform(self.source_frame, self.pallet_frame, Time())
                    self.update_frame(target_frame=pallet_transform)

                except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:
                    self.get_logger().warn("LookupException: {0}".format(str(e)))
                    response.message = str(e)
                    response.success = False
                    return response
            # angle_difference = self.pallet_angle_z - self.tb3_angle_z
            # distance_error = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x)
            # yaw_angle_error = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x) - self.tb3_angle_z
                distance = math.fabs(sqrt(pow(self.pallet_x - self.tb3_x, 2) + pow(self.pallet_y - self.tb3_y, 2)))
            
                if distance > 0.75:
                
                    print("---------------")
                    print(distance)
                    print("---------------")
                
                    response.success = False
                else:
                    response.success = True
                    flag = False
                    self.cmd_pub.publish(self.move_tug)
                    self.move_tug.linear.x = 0.0
                    self.move_tug.angular.z = 0.0
                    self.dock_flag = False
                    flag = False
                    return response
            else:
                self.get_logger().warn("Not Going to Dock !")
                response.success = False
                return response
    
    def undock_func(self, request, response):
        if request.data is True:
            self.move_tug.linear.x = 0.5
            self.move_tug.angular.z = 0.0
            self.cmd_pub.publish(self.move_tug)
            time.sleep(5)
            self.move_tug.linear.x = 0.0
            self.move_tug.angular.z = 0.0
            self.cmd_pub.publish(self.move_tug)
            self.get_logger().info('Undocking completed....')
            response.success = True
            response.message = "Undocking completed...."
            return response
        else:
            self.get_logger().info('Waiting to complete docking....')
            response.success = False
            response.message = "Waiting to complete docking...."
            return response
                
    def update_frame(self,target_frame):
        self.pallet_x = target_frame.transform.translation.x
        self.pallet_y = target_frame.transform.translation.y

        pallet_angle_x = target_frame.transform.rotation.x
        pallet_angle_y = target_frame.transform.rotation.y
        pallet_angle_z = target_frame.transform.rotation.z
        pallet_angle_w = target_frame.transform.rotation.w

        self.pallet_angle_z = self.euler_from_quaternion(pallet_angle_x, pallet_angle_y, 
                                                        pallet_angle_z, pallet_angle_w)
        
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

def main():
    rclpy.init()
    docker = Dockpallet()
    rclpy.spin(docker)
    rclpy.shutdown()

if __name__=='__main__':
    main()

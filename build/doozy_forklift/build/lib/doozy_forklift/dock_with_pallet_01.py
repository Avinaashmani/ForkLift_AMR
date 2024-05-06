#!/usr/bin/env python3

import rclpy
import math
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
        self.pallet_frame = ''
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

        self.idx_number = ''
        self.navigate_err = ''

        self.move_tug = Twist()

        self.dock_service = self.create_service(SetBool, 'Docking', self.dock_func)

    def dock_func(self, request, response):
        dock_call = request.data
        if self.navigate_flag and self.pallet_presence and request.data is True:
            try:
                tb3_transform = self.tf_buffer.lookup_transform(self.source_frame, self.tb3_frame, Time())
                pallet_transform = self.tf_buffer.lookup_transform(self.source_frame, self.pallet_frame, Time())
                self.update_frame(tb3_frame=tb3_transform, target_frame=pallet_transform)

            except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:
                self.get_logger().warn("LookupException: {0}".format(str(e)))
                response.message = str(e)
                # return response
                
            distance = math.fabs(sqrt(pow(self.pallet_x - self.tb3_x, 2) + pow(self.pallet_y - self.tb3_y, 2)))
            angle_difference = self.pallet_angle_z - self.tb3_angle_z
            distance_error = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x)
            yaw_angle_error = atan2(self.pallet_y - self.tb3_y, self.pallet_x - self.tb3_x) - self.tb3_angle_z

            if distance > 0.2:

                if abs(yaw_angle_error) > 0.15:
                    if abs(angle_difference) > 0.1:
                        if yaw_angle_error > 0.0:
                            self.move_tug.angular.z = 0.2
                        else:
                            self.move_tug.angular.z = -0.2
                else:
                    self.move_tug.linear.x = 0.07
                self.move_tug.linear.x = 0.0
                self.move_tug.angular.z = 0.0
                self.cmd_pub.publish(self.move_tug)

            else:
                self.cmd_pub.publish(self.move_tug)
                self.move_tug.linear.x = 0.0
                self.move_tug.angular.z = 0.0
                self.dock_flag = False
                
                response.success = True
                # return response
        else:
            self.get_logger().warn("Not Going to Dock !")
            response.success = False
            # return response
        # response.success = False
        return response    
    
    def update_frame(self, tb3_frame, target_frame):
        self.tb3_x = tb3_frame.transform.translation.x
        self.tb3_y = tb3_frame.transform.translation.y

        tb3_angle_x = tb3_frame.transform.rotation.x
        tb3_angle_y = tb3_frame.transform.rotation.y
        tb3_angle_z = tb3_frame.transform.rotation.z
        tb3_angle_w = tb3_frame.transform.rotation.w

        self.tb3_angle_z = self.euler_from_quaternion(tb3_angle_x, tb3_angle_y, 
                                                      tb3_angle_z, tb3_angle_w)
        
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

if __name__=='__main__':
    main()

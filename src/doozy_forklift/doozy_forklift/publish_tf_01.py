#!/usr/bin/env python3 

import rclpy

from rclpy.node import Node
from rclpy.time import Time
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
from sick_visionary_t_mini.msg import SickTMini
from geometry_msgs.msg import Transform

class PalletTF(Node):

    def __init__(self):
        
        super().__init__('pallet_tf_publisher')

        self.tf_broadcaster = TransformBroadcaster(self)

        self.rightCorner_x = 0.0
        self.rightCorner_y = 0.0
        self.rightCorner_z = 0.0

        self.leftCorner_x = 0.0
        self.leftCorner_y = 0.0
        self.leftCorner_z = 0.0

        self.x_point = 0.0
        self.y_point = 0.0
        self.z_point = 0.0

        self.dolly_found = False

        self.right_pocket = Transform()
        self.left_pocket = Transform()
        self.center_pocket = Transform()
        
        self.create_timer(0.1, self.sick_callback)
        self.base_frame = 'map'

        # print(self.y_point)

    def sick_callback(self ):

        pallet_center = TransformStamped()
        
        pallet_center.child_frame_id = 'pallet_center'
        pallet_center.header.frame_id = self.base_frame
        pallet_center.transform.translation.x = self.center_pocket.x
        pallet_center.transform.translation.y = self.center_pocket.y
        pallet_center.transform.rotation.z = 1.0
        pallet_center.transform.rotation.w = 0.0

        pallet_right_corner = TransformStamped()
        
        pallet_right_corner.child_frame_id = self.base_frame
        pallet_right_corner.header.frame_id = 'pallet_right_corner'
        pallet_right_corner.header.stamp = Time().to_msg()
        pallet_right_corner.transform.translation.x = self.right_pocket.x
        pallet_right_corner.transform.translation.y = self.right_pocket.y
        pallet_right_corner.transform.rotation.z = 1.0
        pallet_right_corner.transform.rotation.w = 0.0
        
        pallet_left_corner = TransformStamped()
        
        pallet_left_corner.header.frame_id = self.base_frame
        pallet_left_corner.child_frame_id = 'pallet_left_corner'
        pallet_left_corner.transform.translation.x = self.left_pocket.x
        pallet_left_corner.transform.translation.y = self.left_pocket.y
        pallet_left_corner.transform.rotation.z = 1.0
        pallet_left_corner.transform.rotation.w = 0.0
        
        if msg.pallet_found is True:
            self.tf_broadcaster.sendTransform(pallet_center)
            self.tf_broadcaster.sendTransform(pallet_right_corner)
            self.tf_broadcaster.sendTransform(pallet_left_corner)
        
        else:
            pass
        self.rightCorner_z = msg.right_corners.z

        self.leftCorner_x = msg.left_corners.x 
        self.leftCorner_y = msg.left_corners.y
        self.leftCorner_z = msg.left_corners.z

        print(f"Center Pocket = {msg.center_point.x / 1000}")
        print(f"Right Pocket = {msg.right_pocket.x / 1000}")
        print(f"Left Pocket = {msg.left_pocket.x / 1000}")
        
    def left_pallet(self, msg):
        
        self.left_pocket.translation.x = msg.transalation.x / 1000
        self.left_pocket.translation.y = msg.transalation.y / 1000
        self.left_pocket.translation.z = msg.transalation.z / 1000
        
    def right_pallet(self, msg):
        self.right_pocket.translation.x = msg.transalation.x / 1000
        self.right_pocket.translation.y = msg.transalation.y / 1000
        self.right_pocket.translation.z = msg.transalation.z / 1000
  
    def center_pallet(self, msg):
        self.center_pocket.translation.x = msg.transalation.x / 1000
        self.center_pocket.translation.y = msg.transalation.y / 1000
        self.center_pocket.translation.z = msg.transalation.z / 1000

def main():

    rclpy.init()
    tf_pub = PalletTF()
    rclpy.spin(tf_pub)

if __name__=='__main__':
    main()
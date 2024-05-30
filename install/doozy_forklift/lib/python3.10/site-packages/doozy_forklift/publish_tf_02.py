#!/usr/bin/env python3 

import rclpy

from rclpy.node import Node
from rclpy.time import Time
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped


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

        # self.create_subscription(SickTMini, '/pallet_detection', self.sick_callback, 10)
        self.create_timer(0.1, self.publish_tf)
        self.base_frame = 'odom'

    def publish_tf(self):

        tf1 = TransformStamped()
        tf1.header.frame_id = self.base_frame
        tf1.child_frame_id = 'pallet_center'
        tf1.header.stamp = Time().to_msg()
        tf1.transform.translation.x = 1.92
        tf1.transform.translation.y = 0.00761
        tf1.transform.translation.z = 0.0
        tf1.transform.rotation.z = -5.75
        tf1.transform.rotation.w = 1.0
        self.tf_broadcaster.sendTransform(tf1)
        
        # tf2 = TransformStamped()
        # tf2.header.frame_id = self.base_frame
        # tf2.child_frame_id = 'pallet_right_corner'
        # tf2.header.stamp = Time().to_msg()
        # tf2.transform.translation.x = 2.0
        # tf2.transform.translation.y = -0.5
        # tf2.transform.rotation.z = 1.0 
        # tf2.transform.rotation.w = 0.0
        # self.tf_broadcaster.sendTransform(tf2)

        # sick_tf = TransformStamped()
        # sick_tf.header.frame_id = self.base_frame
        # sick_tf.child_frame_id = 'pallet_left_corner'
        # sick_tf.header.stamp = Time().to_msg()
        # sick_tf.transform.translation.x = 2.0
        # sick_tf.transform.translation.y = 0.5
        # sick_tf.transform.rotation.z = 1.0
        # sick_tf.transform.rotation.w = 0.0
        # self.tf_broadcaster.sendTransform(sick_tf)

        # print(self.x_point)
        # print(self.y_point)

    def sick_callback(self, msg ):

        # tf1 = TransformStamped()
        # tf1.header.frame_id = self.base_frame
        # tf1.child_frame_id = 'dolly_01'
        # tf1.header.stamp = Time().to_msg()
        # tf1.transform.translation.x = 1.8147761821746826
        # tf1.transform.translation.y = 1.222383975982666
        # tf1.transform.rotation.z = 1.0 
        # tf1.transform.rotation.w = 0.0
        # self.tf_broadcaster.sendTransform(tf1)
        
        # tf2 = TransformStamped()
        # tf2.header.frame_id = self.base_frame
        # tf2.child_frame_id = 'dolly_02'
        # tf2.header.stamp = Time().to_msg()
        # tf2.transform.translation.x = -1.75910
        # tf2.transform.translation.y = -1.40089
        # tf2.transform.rotation.z = 1.0 
        # tf2.transform.rotation.w = 0.0
        # self.tf_broadcaster.sendTransform(tf2)

        pallet_center = TransformStamped()
        
        pallet_center.child_frame_id = 'pallet_center'
        pallet_center.header.frame_id = self.base_frame
        pallet_center.transform.translation.x = msg.center_point.x / 1000
        pallet_center.transform.translation.y = msg.center_point.y / 1000
        pallet_center.transform.rotation.z = 1.0
        pallet_center.transform.rotation.w = 0.0

        pallet_right_corner = TransformStamped()
        
        pallet_right_corner.child_frame_id = self.base_frame
        pallet_right_corner.header.frame_id = 'pallet_right_corner'
        pallet_right_corner.header.stamp = Time().to_msg()
        pallet_right_corner.transform.translation.x = msg.right_pocket.x / 1000
        pallet_right_corner.transform.translation.y = msg.right_pocket.y / 1000
        pallet_right_corner.transform.rotation.z = 1.0
        pallet_right_corner.transform.rotation.w = 0.0
        
        pallet_left_corner = TransformStamped()
        
        pallet_left_corner.header.frame_id = self.base_frame
        pallet_left_corner.child_frame_id = 'pallet_left_corner'
        pallet_left_corner.transform.translation.x = msg.left_pocket.x / 1000
        pallet_left_corner.transform.translation.y = msg.left_pocket.y / 1000
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

def main():

    rclpy.init()
    tf_pub = PalletTF()
    rclpy.spin(tf_pub)

if __name__=='__main__':
    main()
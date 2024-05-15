#!/usr/bin/env python3 

import rclpy

from rclpy.node import Node
from rclpy.time import Time
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
from std_msgs.msg import String
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

        self.pallet_detected = False

        self.create_subscription(Transform, '/pallet_left', self.left_pallet, 10)
        self.create_subscription(Transform, '/pallet_right', self.right_pallet, 10)
        self.create_subscription(Transform, '/pallet_center', self.center_pallet, 10)
        self.create_subscription(String, '/pallet_presence', self.detected_pallet, 10)
        
        self.create_timer(0.1, self.sick_callback)
        self.base_frame = 'map'

        # print(self.y_point)

    def sick_callback(self ):

        pallet_center = TransformStamped()
        
        pallet_center.child_frame_id = 'pallet_center'
        pallet_center.header.frame_id = self.base_frame
        pallet_center.transform.translation.x = self.center_pocket.translation.x
        pallet_center.transform.translation.y = self.center_pocket.translation.y
        pallet_center.transform.rotation.z = 1.0
        pallet_center.transform.rotation.w = 0.0

        pallet_right_corner = TransformStamped()
        
        pallet_right_corner.child_frame_id = self.base_frame
        pallet_right_corner.header.frame_id = 'pallet_right_corner'
        pallet_right_corner.header.stamp = Time().to_msg()
        pallet_right_corner.transform.translation.x = self.right_pocket.translation.x
        pallet_right_corner.transform.translation.y = self.right_pocket.translation.y
        pallet_right_corner.transform.rotation.z = 1.0
        pallet_right_corner.transform.rotation.w = 0.0
        
        pallet_left_corner = TransformStamped()
        
        pallet_left_corner.header.frame_id = self.base_frame
        pallet_left_corner.child_frame_id = 'pallet_left_corner'
        pallet_left_corner.transform.translation.x = self.left_pocket.translation.x
        pallet_left_corner.transform.translation.y = self.left_pocket.translation.y
        pallet_left_corner.transform.rotation.z = 1.0
        pallet_left_corner.transform.rotation.w = 0.0
        
        if self.detected_pallet is True:
            self.tf_broadcaster.sendTransform(pallet_center)
            self.tf_broadcaster.sendTransform(pallet_right_corner)
            self.tf_broadcaster.sendTransform(pallet_left_corner)
        
        else:
            self.get_logger().error ("Pallet not Detecting ..")

        print(f"Center Pocket = {self.center_pocket}")
        print(f"Right Pocket = {self.right_pocket}")
        print(f"Left Pocket = {self.left_pocket}")
        print (f"Pallet Presence = {self.pallet_detected}")
    
    def detected_pallet(self, msg):
        if msg.data == 'true':
            self.pallet_detected = True
        else:
            self.pallet_detected = False
        
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
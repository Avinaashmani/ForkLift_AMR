#!/usr/bin/env python3

import rclpy
import re
import serial
import math
from rclpy.node import Node
from rclpy.time import Time
from geometry_msgs.msg import Vector3, TransformStamped, Quaternion
from sensor_msgs.msg import Imu
from tf2_ros import TransformBroadcaster

class ImuReader(Node):
    def __init__(self):
        super().__init__('imu_publisher')

        # self.imu_pub = self.create_publisher(Vector3, '/forklift_imu', 10)
        self.imu_tf_bradcaster = TransformBroadcaster(self)

        self.yaw = 0.0
        self.pitch = 0.0
        self.roll = 0.0

        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.w = 0.0

        self.imu_port = '/dev/ttyACM1'
        self.baudrate = 57600
        self.base_frame = 'odom'
        self.create_subscription(Imu, '/imu', self.imu_callback, 1)
        self.create_timer(0.03, self.read_imu)
    
    def read_imu(self):
        x = round(self.x, 2)
        y = round(self.y, 2)
        z = round(self.z, 2)
        w = round(self.w, 2)
        
        self.yaw = round(self.euler_from_quaternion(x, y, z, w), 2)
        
        imu_tf = TransformStamped()

        imu_tf.header.frame_id = self.base_frame
        imu_tf.child_frame_id = 'forklift_imu'
        imu_tf.header.stamp = Time().to_msg()
        imu_tf.transform.translation.x = 0.0
        imu_tf.transform.translation.y = 0.0
        imu_tf.transform.translation.z = 0.0

        imu_tf.transform.rotation.x = self.x
        imu_tf.transform.rotation.y = self.y
        imu_tf.transform.rotation.z = self.z
        imu_tf.transform.rotation.w = self.w

        self.get_logger().info(f"{x} {y} {z} {w}")
        self.imu_tf_bradcaster.sendTransform(imu_tf)

        # self.imu_pub.publish(self.ypr)
    
    def quaternion_from_euler(self, roll, pitch, yaw):
        """
        Converts euler roll, pitch, yaw to quaternion
        """
        cy = math.cos(yaw * 0.5)
        sy = math.sin(yaw * 0.5)
        cp = math.cos(pitch * 0.5)
        sp = math.sin(pitch * 0.5)
        cr = math.cos(roll * 0.5)
        sr = math.sin(roll * 0.5)

        q = Quaternion()
        q.w = round((cy * cp * cr + sy * sp * sr), 1)
        q.x = round((cy * cp * sr - sy * sp * cr), 1)
        q.y = round((sy * cp * sr + cy * sp * cr), 1)
        q.z = round((sy * cp * cr - cy * sp * sr), 1)
        return q 
    
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
      
    def imu_callback(self, msg):

        self.x = msg.orientation.x
        self.y = msg.orientation.y
        self.z = msg.orientation.z
        self.w = msg.orientation.w

def main():
    rclpy.init()
    node = ImuReader()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

#!/usr/bin/env python3

import rclpy
import re
import serial
import math
from rclpy.node import Node
from rclpy.time import Time
from geometry_msgs.msg import Vector3, TransformStamped, Quaternion
from tf2_ros import TransformBroadcaster

class ImuReader(Node):
    def __init__(self):
        super().__init__('imu_publisher')

        self.imu_pub = self.create_publisher(Vector3, '/forklift_imu', 10)
        self.imu_tf_bradcaster = TransformBroadcaster(self)

        self.ypr = Vector3()

        self.imu_port = '/dev/ttyACM1'
        self.baudrate = 57600
        self.base_frame = 'odom'

        try:
            self.serial_com = serial.Serial(self.imu_port, self.baudrate, timeout=1)
        except serial.SerialException as e:
            self.get_logger().error(f"Error opening serial port: {e}")
            return

        self.create_timer(0.03, self.read_imu)
    
    def read_imu(self):
        try:
            
            line = self.serial_com.readline().decode("utf-8").strip()
            imu_tf = TransformStamped()

            if line:
                match = re.match(r"#YPR=(-?\d+\.\d+),(-?\d+\.\d+),(-?\d+\.\d+)", line)
                
                if match:
                    yaw, pitch, roll = map(float, match.groups())
                    
                    roll = round(roll, 2)
                    pitch = round(pitch, 2)
                    yaw = round(yaw, 2)
                    
                    self.ypr.x = roll
                    self.ypr.y = pitch
                    self.ypr.z = yaw

                    q = Quaternion()
                    q = self.quaternion_from_euler(roll, pitch, yaw)

                    imu_tf.header.frame_id = self.base_frame
                    imu_tf.child_frame_id = 'forklift_imu'
                    imu_tf.header.stamp = Time().to_msg()
                    imu_tf.transform.translation.x = 0.0
                    imu_tf.transform.translation.y = 0.0
                    imu_tf.transform.translation.z = 0.0

                    imu_tf.transform.rotation.x = q.x
                    imu_tf.transform.rotation.y = q.y
                    imu_tf.transform.rotation.z = q.z
                    imu_tf.transform.rotation.w = q.w
                    self.get_logger().info(f"{q}")
                    self.imu_tf_bradcaster.sendTransform(imu_tf)
                    self.imu_pub.publish(self.ypr)

                else:
                    self.get_logger().warn(f"Received invalid data: {line}")
        
        except serial.SerialException as e:
            self.get_logger().error(f"Serial communication error: {e}")
        
        except Exception as e:
            self.get_logger().error(f"Error reading IMU data: {e}")
    
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

        return roll_x, pitch_y, yaw_z 
    
def main():
    rclpy.init()
    node = ImuReader()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

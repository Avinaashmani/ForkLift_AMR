#!/usr/bin/env python3

import rclpy
import re
import serial
from rclpy.node import Node
from geometry_msgs.msg import Vector3

class ImuReader(Node):
    def __init__(self):
        super().__init__('imu_publisher')

        self.imu_pub = self.create_publisher(Vector3, '/forklift_imu', 10)

        self.ypr = Vector3()

        self.imu_port = '/dev/ttyACM1'
        self.baudrate = 57600

        try:
            self.serial_com = serial.Serial(self.imu_port, self.baudrate, timeout=1)
        except serial.SerialException as e:
            self.get_logger().error(f"Error opening serial port: {e}")
            return

        self.create_timer(0.03, self.read_imu)
    
    def read_imu(self):
        try:
            line = self.serial_com.readline().decode("utf-8").strip()
            if line:
                match = re.match(r"#YPR=(-?\d+\.\d+),(-?\d+\.\d+),(-?\d+\.\d+)", line)
                if match:
                    yaw, pitch, roll = map(float, match.groups())
                    self.get_logger().info(f"Yaw: {yaw}, Pitch: {pitch}, Roll: {roll}")
                    
                    self.ypr.x = roll
                    self.ypr.y = pitch
                    self.ypr.z = yaw
                    
                    self.imu_pub.publish(self.ypr)
                else:
                    self.get_logger().warn(f"Received invalid data: {line}")
        except serial.SerialException as e:
            self.get_logger().error(f"Serial communication error: {e}")
        except Exception as e:
            self.get_logger().error(f"Error reading IMU data: {e}")

def main():
    rclpy.init()
    node = ImuReader()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

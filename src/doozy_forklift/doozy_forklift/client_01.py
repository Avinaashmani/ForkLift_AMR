#!/usr/bin/env python3

import rclpy
import time
from rclpy.node import Node
from std_msgs.msg import Bool
from example_interfaces.srv import SetBool

class Client_01(Node):

    def __init__(self):
        super().__init__('navigate_to_dolly')
        self.get_logger().info('Forklift Client Script-01')
        self.create_subscription(Bool, '/navigation_status', self.navigation_callback, 10)

        self.client_docking = self.create_client(SetBool, 'Docking')
        self.client_undocking = self.create_client(SetBool, 'UnDocking')
        self.docking_request = SetBool.Request()
        # self.response = SetBool.Response().success

    def navigation_callback(self, msg):
        # self.get_logger().info(f"Navigation Status = {msg.data}")
        self.docking_request.data = msg.data
        
        while not self.client_docking.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Service not available, waiting again...")
        if msg.data is True:
            future = self.client_docking.call_async(self.docking_request)
            # self.get_logger().info(future.result())
            return future.result()
        else:
            future = self.client_docking.call_async(self.docking_request)
            # self.get_logger().info(future.result())
            return future.result()


def main():
    rclpy.init()
    client_01 = Client_01()

    rclpy.spin(client_01)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

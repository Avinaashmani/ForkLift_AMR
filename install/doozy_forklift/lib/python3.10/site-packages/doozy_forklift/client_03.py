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
        
        self.navigation_status = Bool()

        while not self.client_docking.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
                
        self.docking_result = None
        self.undocking_result = None

    def navigation_callback(self, msg):
        self.navigation_status.data = msg.data
        if msg.data:
            self.send_dock_request(True)
        else:
            self.send_dock_request(False)
            self.get_logger().info("Navigation in progress....")

    def send_dock_request(self, dock_req):
        request = SetBool.Request()
        request.data = dock_req
        future = self.client_docking.call_async(request)
        future.add_done_callback(self.docking_callback)

    def docking_callback(self, future):
        try:
            response = future.result()
            self.docking_result = response.success

            if response.success:
                time.sleep(10)
                self.send_undock_request(True)
                self.get_logger().info("Undocking in progress....")

        except Exception as e:
            self.get_logger().error(str(e))
            self.get_logger().info("Docking error")

    def send_undock_request(self, undock_req):
        request = SetBool.Request()
        request.data = undock_req
        future = self.client_undocking.call_async(request)
        future.add_done_callback(self.undocking_callback)

    def undocking_callback(self, future):
        try:
            response = future.result()
            self.undocking_result = response.success

            if response.success and self.docking_result:
                self.get_logger().info("Done. Proceed to next goal")

        except Exception as e:
            self.get_logger().error(str(e))
            self.get_logger().info("Undocking error")

def main():
    rclpy.init()
    client_01 = Client_01()
    rclpy.spin(client_01)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

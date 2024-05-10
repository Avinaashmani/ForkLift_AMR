#!/usr/bin/env python3

import rclpy
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
        
        self.navigation_status = False
        self.docking_result = False
        self.undocking_result = False

    def navigation_callback(self, msg):
        self.navigation_status = msg.data

    async def send_dock_request(self, dock_req):
        request = SetBool.Request()
        request.data = dock_req
        future = self.client_docking.call_async(request)
        await future
        if future.result().success:
            await self.send_undock_request(True)

    async def send_undock_request(self, undock_req):
        request = SetBool.Request()
        request.data = undock_req
        future = self.client_undocking.call_async(request)
        await future
        if future.result().success and self.docking_result:
            self.get_logger().info("Done. Proceed to next goal")

def main():
    rclpy.init()
    client_01 = Client_01()
    rclpy.spin(client_01)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

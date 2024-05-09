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
        
        self.navigation_status = Bool

        while not self.client_docking.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
                
        self.docking_result = SetBool.Response()
        self.docking_request = SetBool.Request()
        
        self.undocking_result = SetBool.Response()
        self.undocking_request= SetBool.Request()
        
        self.docking_done = False
        self.undocking_done = False
        self.create_timer(0.1, self.compute)
        
    def navigation_callback(self, msg):
        self.navigation_status.data = msg.data
    
    def send_dock_request(self, dock_req):
        
        self.docking_request.data = dock_req
        self.dock_future = self.client_docking.call_async(self.docking_request)
        self.docking_result.success = self.dock_future.result().success
        
        print(f"Printing Docking Request... {self.docking_request.data}")

    def send_undock_request(self, undock_req):
        self.undocking_request.data = undock_req
        self.undock_future = self.client_undocking.call_async(self.undocking_request)
        print(f"Printing Docking Request... {self.undocking_request.data}")

    def compute(self):
        
        if self.navigation_status.data is True:
            self.send_dock_request(True)
            docked_response = self.docking_result.success
            self.get_logger().info(str(docked_response))
        
            if docked_response.success is True:
                self.docking_done = True
            else:
                self.docking_done = False
                self.get_logger().info('Docking is still under process....')
        else:
            self.get_logger().info('Navigation is still under process....')
            self.docking_done = False
            self.send_dock_request(False)
            
        if self.docking_done:
            self.send_undock_request(True)
            undocked_response = self.undock_future.result()
            self.get_logger().info(str(undocked_response.success))
            
            if undocked_response.success is True:
                self.undocking_done = True
            else:
                self.undocking_done = False   
        else:
            self.get_logger().info('Docking Still underprocess....')
            self.undocking_done = False
            self.send_undock_request(False) 
            
        if self.docking_done and self.undocking_done:
            self.get_logger("Task Complete....")
def main():
    rclpy.init()
    client_01 = Client_01()
    rclpy.spin(client_01)             
if __name__ == '__main__':
    main()

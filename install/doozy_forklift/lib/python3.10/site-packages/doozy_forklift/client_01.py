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
       
    def navigation_callback(self, msg):
        self.navigation_status.data = msg.data
    
    def send_dock_request(self, dock_req):
        self.docking_request.data = dock_req
        self.dock_future = self.client_docking.call_async(self.docking_request)
        print(f"Printing Docking Request... {self.docking_request.data}")

    def send_undock_request(self, undock_req):
        self.undocking_request.data = undock_req
        self.undock_future = self.client_undocking.call_async(self.undocking_request)
        print(f"Printing Docking Request... {self.undocking_request.data}")

def main():
    
    rclpy.init()
    client_01 = Client_01()
    rclpy.spin_once(client_01)
    
    if client_01.navigation_status.data is True:
        client_01.send_dock_request(dock_req=True)
        
        while rclpy.ok():
            rclpy.spin_once(client_01)
            
            if client_01.dock_future.done():
                
                try:
                    response_dock = client_01.dock_future.result()
                    # response_undock = client_01.undock_future.result()
                    
                    if response_dock is True:
                        client_01.send_undock_request(True)
                        
                        try:
                            response_undock = client_01.undock_future.result()
                        
                        except Exception as e:
                            client_01.get_logger().error(str(e))      
                              
                except Exception as e:
                    client_01.get_logger().error(str(e))
                
                else:
                    client_01.get_logger().info(str(response_dock.success))
                    client_01.get_logger().info(str(response_undock.success))
    else:
        client_01.send_dock_request(dock_req=False)
        client_01.send_undock_request(undock_req=False)  
        client_01.get_logger().info('Navigation under process...')             
        
    client_01.destroy_node()
    rclpy.shutdown()
                
if __name__ == '__main__':
    main()

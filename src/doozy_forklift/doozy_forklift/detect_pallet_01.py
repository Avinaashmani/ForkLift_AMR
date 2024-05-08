#!/usr/bin/env python3

import rclpy
import requests
from rclpy.node import Node
from sick_visionary_t_mini.msg import SickTMini

class PalletDetection(Node):
    
    def __init__(self):
        
        super().__init__('Pallet_Detector')
        
        self.sick_msg = SickTMini()
        
        self.sick_pallet_pub = self.create_publisher(SickTMini, "/pallet_detection", 10)
        self.create_timer(0.1, self.read_camera)
    
    def read_camera(self):
        
        while True:
            
            response =requests.get("http://192.168.1.10/api/detectionResult")
            
            self.sick_msg.left_pocket.x = float(response.json()['data']['detectionResult']['leftPocket']['Z'])
            self.sick_msg.left_pocket.y = float(response.json()['data']['detectionResult']['leftPocket']['X'])
            self.sick_msg.left_pocket.z = float(response.json()['data']['detectionResult']['leftPocket']['Y'])
            
            self.sick_msg.right_pocket.x = float(response.json()['data']['detectionResult']['rightPocket']['Z'])
            self.sick_msg.right_pocket.y = float(response.json()['data']['detectionResult']['rightPocket']['X'])
            self.sick_msg.right_pocket.z = float(response.json()['data']['detectionResult']['rightPocket']['Y'])
            
            self.sick_msg.center_point.x = float(response.json()['data']['detectionResult']['centerPoint']['Z'])
            self.sick_msg.center_point.y = float(response.json()['data']['detectionResult']['centerPoint']['X'])
            self.sick_msg.center_point.z = float(response.json()['data']['detectionResult']['centerPoint']['Y'])
            
            self.sick_msg.pallet_found = response.json()['data']['detectionResult']['palletFound']
            self.sick_msg.pallet_angle = float(response.json()['data']['detectionResult']['Angle'])
            self.sick_msg.header_pallet_detection.stamp = self.get_clock().now().to_msg()
            self.sick_msg.header_pallet_detection.frame_id = 'map'
            self.sick_msg.message = response.json()['header']['message']
            print(f"Left Pocket: {self.sick_msg.left_pocket.x}-> Center Pocket {self.sick_msg.center_point.x}<-{self.sick_msg.right_pocket.x} Right Pocket === Pallet_Presence {self.sick_msg.pallet_found}" )
            

            self.sick_pallet_pub.publish(self.sick_msg)
def main():
    rclpy.init()
    pallet_detection = PalletDetection()
    rclpy.spin(pallet_detection)
    
if __name__=='__main__':
    main()
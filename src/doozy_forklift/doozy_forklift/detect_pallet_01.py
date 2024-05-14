#!/usr/bin/env python3
import rclpy
import requests
from rclpy.node import Node
from geometry_msgs.msg import Transform

class PalletDetection(Node):
    
    def __init__(self):
        
        super().__init__('Pallet_Detector')

        self.center = Transform()
        self.right = Transform()
        self.left = Transform()
        
        self.center_pub = self.create_publisher(Transform, "/pallet_center", 10)
        self.right_pub = self.create_publisher(Transform, "/pallet_right", 10)
        self.left_pub = self.create_publisher(Transform, "/pallet_left", 10)
        
        
        self.create_timer(0.1, self.read_camera)
    
    def read_camera(self):
        
        while True:
            
            response =requests.get("http://192.168.1.10/api/detectionResult")
            
            self.left.translation.x = float(response.json()['data']['detectionResult']['leftPocket']['Z'])
            self.left.translation.y = float(response.json()['data']['detectionResult']['leftPocket']['X'])
            self.left.translation.z = float(response.json()['data']['detectionResult']['leftPocket']['Y'])
            
            self.right.translation.x = float(response.json()['data']['detectionResult']['rightPocket']['Z'])
            self.right.translation.y = float(response.json()['data']['detectionResult']['rightPocket']['X'])
            self.right.translation.z = float(response.json()['data']['detectionResult']['rightPocket']['Y'])
            
            self.center.translation.x = float(response.json()['data']['detectionResult']['centerPoint']['Z'])
            self.center.translation.y = float(response.json()['data']['detectionResult']['centerPoint']['X'])
            self.center.translation.z = float(response.json()['data']['detectionResult']['centerPoint']['Y'])

            print(f"Left Pocket: {self.left.x}-> Center Pocket {self.center.x}<-{self.right.x} Right Pocket")
            

            self.center_pub.publish(self.center)
            self.right_pub.publish(self.right)
            self.left_pub.publish(self.left)
def main():
    rclpy.init()
    pallet_detection = PalletDetection()
    rclpy.spin(pallet_detection)
    
if __name__=='__main__':
    main()
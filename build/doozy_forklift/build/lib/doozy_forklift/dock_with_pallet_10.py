#!/usr/bin/env python3

import rclpy
import tf2_ros
import math
import numpy
import time
import serial
from math import sqrt, atan2
from rclpy.node import Node
from rclpy.time import Time
from rclpy.executors import SingleThreadedExecutor
from example_interfaces.srv import SetBool
from geometry_msgs.msg import Twist, Transform
from std_msgs.msg import Bool, String

from py_trees.behaviour import Behaviour
from py_trees.common import Status
from py_trees.composites import Selector
from py_trees.composites import Sequence
from py_trees import logging

global linear_speed
global angular_speed

linear_speed = 0.0
angular_speed = 0.0

class Dockpallet(Node):

    def __init__(self):
        super().__init__('pallet_dock')

        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        self.cmd_pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.docking_undocking_diagnostics = self.create_publisher(String, '/dock_undock_diag', 10)
        self.switch_pub = self.create_publisher(Bool, 'switch_topic', 10)
        self.speed_pub = self.create_publisher(Twist, '/cmd_vel', 10)  # Publisher for speeds
        
        self.create_subscription(Bool, 'navigation_status', self.navigation_status_callback, 10)
        self.create_subscription(Transform, '/pallet_center', self.pallet_center_callback, 10)
        self.create_subscription(String, 'pallet_presence', self.pallet_present_callback, 10)

        self.previous_dist = 0.0
        self.dist_diff = 0.0
        self.total_dist = 0.0
        self.controlled_speed = 0.0

        self.kp_d = 0.4
        self.ki_d = 0.01
        self.kd_d = 0.5
        
        self.port = '/dev/ttyUSB0'
        self.baudrate = 9600
        
        self.load_present = False
        self.no_load_present = False
        self.switch_prev_time = False

        self.switch_value = False

        self.reached_point_1 = False
        
        self.pallet_presence = False

        self.navigate_flag = False
        
        self.dock_flag = False
        self.undock_flag = False
        
        self.dock_completed_flag = False
        self.undock_completed_flag = False

        self.move_tug = Twist()
        self.diagnostics = String()
        self.switch = Bool()
        
        self.dock_service = self.create_service(SetBool, 'Docking', self.dock_func)
        # self.undock_service = self.create_service(SetBool, 'UnDocking', self.undock_func)

        self.create_timer(0.1, self.tb3_transform)

        self.distance_c = 0.0
        self.angle_diff_c = 0.0

        self.distance_r = 0.0
        self.angle_diff_r = 0.0

        self.distance_l = 0.0
        self.angle_diff_l = 0.0

        self.left_align = False
        self.right_align = False
        self.center_align = False

        self.tb3_frame = 'base_link'
        self.tb3_baseframe = 'odom'

        self.tb3_x = 0.0
        self.tb3_y = 0.0
        self.tb3_z = 0.0
        self.tb3_yaw = 0.0

        self.switch_value = False

        self.tree = self.dock_with_pallet()
        self.get_logger().info("Initialized Dockpallet node")

    def dock_func(self, request, response):
        if request.data:
            if self.navigate_flag:
                self.dock_flag = True
                self.get_logger().info("Docking flag set to True")
                
                # Start a timer to tick the tree periodically
                self.create_timer(0.1, self.tick_tree)
            
            if self.dock_completed_flag:
                response.message = "Docking Complete"
                response.success = True
                self.get_logger().info("Docking Complete")
                return response
            
        response.message = "Docking Not Initiated"
        response.success = False
        return response

    def navigation_status_callback(self, msg):
        self.navigate_flag = msg.data
        self.get_logger().info(f"Navigation status updated: {self.navigate_flag}")

    def tick_tree(self):
        if self.dock_flag:

            self.get_logger().debug("Ticking the tree")
            self.dock_with_pallet().tick_once()
            status = self.dock_with_pallet().tick_once()
            self.get_logger().debug(f"Tree status: {status}")

            if status == Status.SUCCESS:
                self.dock_completed_flag = True
                self.get_logger().info("Docking process completed successfully")
            elif status == Status.FAILURE:
                self.get_logger().warn("Docking process failed")

    def dock_with_pallet(self):
        self.root = Sequence('pallet_alignment', memory=True)
        
        self.check_pallet = Condition('Check_Camera', self.pallet_presence)
        self.align_center_1= Action('Pocket', distance=self.distance_c, angle_diff=self.angle_diff_c, switch_value=self.switch_value, node=self)
        self.forward_1 = Action('Forward', distance=self.distance_c, angle_diff=self.angle_diff_c, switch_value=self.switch_value, node=self)
        self.align_center_2 = Action('Pocket', distance=self.distance_c, angle_diff=self.angle_diff_c, switch_value=self.switch_value, node=self)
        self.reverse_1 = Action('Reverse', distance=self.distance_c, angle_diff=self.angle_diff_c, switch_value=self.switch_value, node=self)
        self.align_center_3 = Action('Pocket', distance=self.distance_l, angle_diff=self.angle_diff_l, switch_value=self.switch_value, node=self)
        self.forward_2 = Action('Forward', distance=self.distance_c, angle_diff=self.angle_diff_c, switch_value=self.switch_value, node=self)
        self.align_center_4 = Action('Pocket', distance=self.distance_c, angle_diff=self.angle_diff_c, switch_value=self.switch_value, node=self)
        self.auto_dock = Action('Auto_Dock', distance=self.distance_c, angle_diff=self.angle_diff_c, switch_value=self.switch_value, node=self)

        self.root.add_children([
            self.check_pallet,
            self.align_center_1, 
            self.forward_1,
            self.reverse_1, 
            self.align_center_3, 
            self.forward_2,
            self.align_center_4,
            self.auto_dock

        ])
        
        self.get_logger().debug("Behavior tree constructed")
        return self.root

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
    
    def pallet_center_callback(self, msg):
        self.pallet_x = round (msg.translation.x / 1000, 2)
        self.pallet_y = round (msg.translation.y / 1000, 2)

        angle_z = round(math.radians(msg.rotation.z), 2)
        
        delta_x = self.tb3_x - self.pallet_x
        delta_y = self.tb3_y - self.pallet_y
        desired_heading = round(math.atan2(delta_x, delta_y), 2)
        heading_error = desired_heading - self.tb3_yaw
        yaw_error = abs(angle_z) - abs(self.tb3_yaw)

        if self.pallet_presence:
            # self.angle_diff_c = round((self.angle_difference / 3.14), 2)
            self.distance_c = round(math.fabs(sqrt(pow(self.pallet_x - 0, 2) + pow(self.pallet_y - 0, 2))), 2)
            self.get_logger().info(f"{heading_error} {yaw_error}")
        
        else:
            self.angle_diff_c = 0.0
            self.distance_c = 0.0

    def pallet_right_callback(self, msg):
        self.pallet_x = msg.translation.x / 1000
        self.pallet_y = msg.translation.y / 1000
        
        pallet_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)
        robot_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)
        
        self.distance_r = math.fabs(sqrt(pow(self.pallet_x - 0, 2) + pow(self.pallet_y - 0, 2)))
        self.angle_difference = atan2(0.0 - self.pallet_y , 0.0-self.pallet_x ) - robot_angle_z

        if self.pallet_presence:
            self.angle_diff_r = math.fabs(self.angle_difference / 3.14)
            self.distance_r = math.fabs(sqrt(pow(self.pallet_x - 0, 2) + pow(self.pallet_y - 0, 2)))
        
        else:
            self.angle_diff_r = 0.0
            self.distance_r = 0.0
    
    def pallet_left_callback(self, msg):
        self.pallet_x = msg.translation.x / 1000
        self.pallet_y = msg.translation.y / 1000
        
        pallet_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)
        robot_angle_z = self.euler_from_quaternion(0.0, 0.0, 1.0, 0.0)
        
        self.distance_l = math.fabs(sqrt(pow(self.pallet_x - 0, 2) + pow(self.pallet_y - 0, 2)))
        self.angle_difference = atan2(0.0 - self.pallet_y , 0.0-self.pallet_x ) - robot_angle_z

        if self.pallet_presence:
            self.angle_diff_l = math.fabs(self.angle_difference / 3.14)
            self.distance_l = math.fabs(sqrt(pow(self.pallet_x - 0, 2) + pow(self.pallet_y - 0, 2))) 
        else:
            self.angle_diff_l = 0.0
            self.distance_l = 0.0

    def pallet_present_callback(self, msg):
        if msg.data == 'True':
            self.pallet_presence = True
        else:
            self.pallet_presence = False

    def tb3_transform(self):
        
        try:
        
            tb3_transform = self.tf_buffer.lookup_transform(self.tb3_baseframe, self.tb3_frame, Time())
        
            self.tb3_x = tb3_transform.transform.translation.x
            self.tb3_y = tb3_transform.transform.translation.y
            
            tb3_rot_x = tb3_transform.transform.rotation.x
            tb3_rot_y = tb3_transform.transform.rotation.y
            tb3_rot_z = tb3_transform.transform.rotation.z
            tb3_rot_w = tb3_transform.transform.rotation.w

            self.tb3_yaw = self.euler_from_quaternion(tb3_rot_x, tb3_rot_y, 
                                                      tb3_rot_z, tb3_rot_w)
            
            # self.get_logger().info(f"x: {round(self.tb3_x, 4)} y: {round(self.tb3_y, 4)} z: {round(self.tb3_yaw, 4)}")
        
        except(tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException) as e:
            self.get_logger().error("LookupException: {0}".format(str(e)))

    def read_arduino(self):
        
        try:
            self.arduino_01 = serial.Serial(self.port, self.baudrate, timeout=0.1)
            switch_state = self.arduino_01.readline().decode().strip()
            
            if switch_state == '1':
                self.switch_value = True
                self.switch.data = True
                
                if self.switch_prev_time is None:
                    self.switch_prev_time = time.time()

                if time.time() - self.switch_prev_time > 1.0:
                    self.load_present = True
                    self.get_logger().info("docking swithc triggered...")
                    self.dock_flag = False
                    self.no_load_present = False
                else:
                    self.load_present = False
                    self.no_load_present = False
            
            else:
                self.switch_value = False
                self.switch.data = False
                self.switch_prev_time = None
                self.no_load_present = True
                self.load_present = False
            
            self.switch_pub.publish(self.switch)
            print(self.load_present, "-----", self.no_load_present)
            
        except serial.serialutil.SerialException as e:
            self.get_logger().warn(e)

    def publish_velocities(self, linear_vel, angular_vel):
        twist = Twist()
        twist.linear.x = linear_vel
        twist.angular.z = angular_vel
        self.cmd_pub.publish(twist)

class Condition(Behaviour):
    
    def __init__(self, name, pallet_present):
        super(Condition, self).__init__(name)
        self.name = name
        self.pallet = pallet_present
    
    def setup(self) :
        self.logger.debug(f"Action :: Setup {self.name}")

    def initialise(self):
        self.logger.debug(f"Action :: Update {self.name}")
    
    def update(self):
        self.logger.debug(f"Condition :: Update {self.name}")
        time.sleep(1)
        return Status.SUCCESS
    def terminate(self, new_status):
        self.logger.debug(f"Action :: Terminate {self.name} to {new_status}")

class Action(Behaviour):

    def __init__(self, name, distance, angle_diff, switch_value, node):
        super(Action, self).__init__(name)
        self.name = name
        self.distance = distance
        self.angle_diff = angle_diff
        self.switch_value = switch_value
        self.node = node
        self.logger = logging.Logger(name)

        self.linear_vel = 0.0
        self.angular_vel = 0.0
    
    def setup(self):
        self.logger.debug(f"Action :: Setup {self.name}")
    
    def initialise(self):
        self.logger.debug(f"Condition :: Initialize {self.name}")

    
    def update(self):
        self.logger.debug(f"Action update called for {self.name}")

        if self.name == 'Forward':
            self.logger.debug(f"Moving Forward: distance={self.distance}")
            logging.level = logging.Level.DEBUG
            status = self.forward_align()
            # time.sleep(2)
        
        elif self.name == 'Pocket':
            self.logger.debug(f"Centering Pocket: distance={self.distance}, angle_diff={self.angle_diff}")
            logging.level = logging.Level.DEBUG
            status = self.center_pocket()

        elif self.name == 'Reverse':
            self.logger.debug(f"Reversing: distance={self.distance}")
            logging.level = logging.Level.DEBUG
            status = self.reverse_align()
            # time.sleep(1)
        
        elif self.name == 'Auto_Dock':
            self.logger.debug(f"Auto Docking: distance={self.distance}")
            logging.level = logging.Level.DEBUG
            status = self.auto_dock_align()
            # time.sleep(1)

        self.node.publish_velocities(self.linear_vel, self.angular_vel)
        return status

    def forward_align(self):

        # if abs(self.controlled_speed) > 0.2:
        #     self.controlled_speed = 0.2

        # elif abs(self.controlled_speed) < 0.05:
        #     self.controlled_speed = 0.05

        if self.switch_value:
            self.angular_vel = 0.0
            self.linear_vel = 0.0
            self.logger.error(f"Forward Alignment : Switch Triggered {self.distance} Angle {self.angle_diff}")
            logging.level = logging.Level.DEBUG
            return Status.FAILURE
        
        else:         
            if self.distance < 1.5 :
                self.linear_vel = 0.08
                self.angular_vel = 0.0
                self.logger.info(f"Moving Forward: distance {self.distance} Angle {self.angle_diff}")
                logging.level = logging.Level.DEBUG
                return Status.RUNNING
        
            else:
                self.linear_vel = 0.08
                self.angular_vel = 0.0
                self.logger.info(f"Moving Forward: Completed! {self.distance} Angle {self.angle_diff}")
                logging.level = logging.Level.DEBUG
                return Status.SUCCESS

    def center_pocket(self):

        if self.switch_value:
            self.angular_vel = 0.0
            self.linear_vel = 0.0
            self.logger.error(f"Center pallet Alignment : Switch Triggered {self.angle_diff}")
            logging.level = logging.Level.DEBUG
            return Status.FAILURE
        
        else:          

            if self.angle_diff <= 1.97:
                if self.angle_diff > 1.5:
                    self.angular_vel = 0.04
                    
                    if self.distance > 0.9:
                        self.linear_vel = -0.05

                    self.logger.debug(f"Center pallet Alignment : {self.angle_diff}")
                    logging.level = logging.Level.DEBUG
                    return Status.RUNNING
                
                elif 0.1 <= self.angle_diff <= 1.5:
                    self.angular_vel = 0.04
                    
                    if self.distance > 0.9:
                        self.linear_vel = 0.05
                    
                    self.logger.debug(f"Center pallet Alignment : {self.angle_diff}")
                    logging.level = logging.Level.DEBUG
                    return Status.RUNNING
                
                elif 0.065 < self.angle_diff < 0.1:
                    self.angular_vel = 0.04
                    self.linear_vel = 0.05
                    self.logger.debug(f"Center pallet Alignment : {self.angle_diff}")
                    logging.level = logging.Level.DEBUG
                    return Status.RUNNING
                else:
                    # self.angular_vel = 0.0
                    # self.linear_vel = 0.0
                    self.logger.debug(f"Center pallet Alignment Completed! : {self.angle_diff}")
                    logging.level = logging.Level.DEBUG
                    return Status.SUCCESS
            self.logger.debug(f"Center pallet Alignment Completed! : {self.angle_diff}")
            logging.level = logging.Level.DEBUG
            return Status.SUCCESS
                
            # self.logger.debug(f"Center pallet Alignment Completed! : {self.angle_diff}")
            # logging.level = logging.Level.DEBUG
            # return Status.SUCCESS
        
            # elif self.angle_diff < 0.2 and self.angle_diff > 0.08:
            #     self.angular_vel = -0.04
            #     self.linear_vel = 0.07
            #     self.logger.info(f"Center pallet Alignment : {self.angle_diff}")
            #     logging.level = logging.Level.DEBUG
            #     return Status.RUNNING
            # elif self.angle_diff == 0.0 :
            #     self.angular_vel = 0.0
            #     self.linear_vel = 0.0
            #     self.logger.debug(f"Center pallet Alignment Completed! : {self.angle_diff}")
            #     logging.level = logging.Level.DEBUG
            #     return Status.SUCCESS                
            # else:
            #     self.angular_vel = 0.0
            #     self.linear_vel = 0.0
            #     self.logger.debug(f"Center pallet Alignment Completed! : {self.angle_diff}")
            #     logging.level = logging.Level.DEBUG
            #     return Status.SUCCESS

    def reverse_align(self):
        if self.switch_value:
            self.linear_vel = 0.0
            self.angular_vel = 0.0
            self.logger.error(f"Reversing: Switch Triggered distance {self.distance}")
            logging.level = logging.Level.DEBUG
            return Status.FAILURE
            
        else: 
            if self.distance > 1.5 or self.distance == 0.0:
                self.linear_vel = 0.0
                self.angular_vel = 0.0
                self.logger.info(f"Reversing: distance {self.distance}")
                logging.level = logging.Level.DEBUG
                return Status.SUCCESS
        
            else:
                self.linear_vel = 0.15
                self.angular_vel = 0.0
                self.logger.info(f"Reversing: distance {self.distance}")
                logging.level = logging.Level.DEBUG
                # return Status.RUNNING
        return Status.SUCCESS
    
    def auto_dock_align(self):
        if self.switch_value:
            self.linear_vel = 0.0
            self.angular_vel = 0.0
            return Status.FAILURE
        
        else:
            if self.distance == 0:
                self.linear_vel = 0.0
                self.angular_vel = 0.0
                return Status.SUCCESS
            else:
                self.linear_vel = -0.05
                self.angular_vel = 0.0
                return Status.SUCCESS
        
    def terminate(self, new_status):
        self.logger.debug(f"Condition :: Termination {self.name} to {new_status}")

def main():
    rclpy.init()
    docker = Dockpallet()
    executor = SingleThreadedExecutor()
    executor.add_node(docker)

    try:
        executor.spin()

    finally:
        executor.shutdown()
        docker.destroy_node()
        rclpy.shutdown()

if __name__=='__main__':
    main()

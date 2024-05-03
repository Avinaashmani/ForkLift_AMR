#!/usr/bin/env python3

import rospy 
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Twist
from std_msgs.msg import Header

class SteeringController:

    def __init__(self):

        rospy.init_node('joint_state_publisher')
        rospy.loginfo_once ("joint state publisher has begun")

        self.angular_velocity  = 0.0
        self.linear_velocity = 0.0

        self.angle_limiter = 1.57
        self.fork_angular = 0.0
        self.fork_linear = 0.0

        self.joint_names = ['base_joint', 'l_wheel_joint', 'r_wheel_joint', 'l_roller_joint', 'r_roller_joint']
        self.joint_angles = (0.0, 0.0, 0.0, 0.0, 0.0)
        
        self.fork_angular_vel = Twist()
        self.fork_linear_vel = Twist()
        self.q_size = 11

        self.cmd_vel_pub = rospy.Publisher('/fork_lift/cmd_vel', Twist, queue_size=self.q_size)
        self.fork_joint_publisher = rospy.Publisher('/joint_states', JointState, queue_size=self.q_size)
        self.fork_linear_publisher = rospy.Publisher('/fork_linear/cmd_vel', Twist, queue_size=self.q_size)
        
        rospy.Subscriber('/cmd_vel', Twist, self.velocity_callback, queue_size=10)
    
    def compute(self):
        fork_jointstate = JointState()
        
        try:
            rate = rospy.Rate(11) 
            fork_jointstate.header.stamp = rospy.Time.now()
            fork_jointstate.name = self.joint_names
            fork_jointstate.position = (self.fork_angular, 0.0, 0.0, 0.0, 0.0)
            fork_jointstate.velocity = []
            fork_jointstate.effort = []
            self.fork_joint_publisher.publish(fork_jointstate)
            self.cmd_vel_pub.publish(self.fork_linear_vel)
            rate.sleep()

        except rospy.ROSException:
            pass

    def velocity_callback (self, msg):
        
        self.fork_angular = msg.angular.z
        self.fork_linear_vel.angular.z = msg.linear.x

        print(self.fork_linear_vel.linear.x)
        print(self.fork_angular)

    def spin(self):
        r = rospy.Rate(11.0)
        while not rospy.is_shutdown():
            self.compute()
            r.sleep()

if __name__ == '__main__':
    try:
        controller = SteeringController()
        controller.spin()
    except rospy.ROSInterruptException:
        rospy.on_shutdown('Closing..')



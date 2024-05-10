import os 
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import xacro

def generate_launch_description():

    pkg_name = 'doozy_forklift'
    file_subpath = '/home/avinaash/ForkLift_AMR/src/doozy_forklift/forkassembly_bot/urdf/forkassembly_bot.urdf'

    xacro_file = os.path.join(get_package_share_directory(pkg_name),file_subpath)
    robot_description_raw = xacro.process_file(xacro_file).toxml()

    node_robot_state_publisher = Node(package='doozy_forklift', 
                                      executable='doozy_forklift', 
                                      output='screen')
    
    return LaunchDescription(
        [node_robot_state_publisher]
    )


# launch/ukf.launch.py
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # Path to the UKF configuration file
    config = os.path.join(
        get_package_share_directory('my_localization'),
        'config',
        'ukf.yaml'
    )

    # robot_localization's UKF node, fed only by our IMU driver node
    ukf_node = Node(
        package='robot_localization',
        executable='ukf_node',
        name='ukf_filter_node',
        output='screen',
        parameters=[config],
    )

    return LaunchDescription([ukf_node])

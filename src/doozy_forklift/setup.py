from setuptools import setup
from glob import glob
from setuptools import setup
from setuptools import find_packages
import os
package_name = 'doozy_forklift'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
        (os.path.join('share', package_name), glob('urdf/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='avinaash',
    maintainer_email='avinaash.mani@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': 
        ['Client_01 = doozy_forklift.client_01:main',
         'Client_02 = doozy_forklift.client_02:main',
         'Client_03 = doozy_forklift.client_03:main',
         'Dock_with_Pallet_01 = doozy_forklift.dock_with_pallet_01:main',
         'Dock_with_Pallet_02 = doozy_forklift.dock_with_pallet_02:main',
         'Dock_with_Pallet_03 = doozy_forklift.dock_with_pallet_03:main',
         'Dock_with_Pallet_04 = doozy_forklift.dock_with_pallet_04:main',
         'Detect_Pallet_01 = doozy_forklift.detect_pallet_01:main',
         'Publish_TF = doozy_forklift.publish_tf_01:main',
         'Publish_TF_2 = doozy_forklift.publish_tf_02:main',
         'state_publisher = doozy_forklift.robot_state_publisher:main',
        ],
    },
)

from setuptools import setup

package_name = 'doozy_forklift'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
         'Dock_with_Pallet_05 = doozy_forklift.dock_with_pallet_05:main',
         'Dock_with_Pallet_06 = doozy_forklift.dock_with_pallet_06:main',
         'Dock_with_Pallet_07 = doozy_forklift.dock_with_pallet_07:main',
         'Dock_with_Pallet_08 = doozy_forklift.dock_with_pallet_08:main',
         'Dock_with_Pallet_09 = doozy_forklift.dock_with_pallet_09:main',
         'Dock_with_Pallet_10 = doozy_forklift.dock_with_pallet_10:main',
         'Dock_with_Pallet_11 = doozy_forklift.dock_with_pallet_11:main',
         'Dock_tree = doozy_forklift.dock_tree_01:main',
         'Detect_Pallet_01 = doozy_forklift.detect_pallet_01:main',
         'Publish_TF = doozy_forklift.publish_tf_01:main',
         'Publish_TF_2 = doozy_forklift.publish_tf_02:main',
         'Imu_pub = doozy_forklift.imu_publisher_01:main',
         'Imu_pub_2 = doozy_forklift.imu_publisher_02:main',
        ],
    },
)

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
         'Dock_with_Pallet_01 = doozy_forklift.dock_with_pallet_01:main',
         'Detect_Pallet_01 = doozy_forklift.detect_pallet_01:main',
         'Publish_TF = doozy_forklift.publish_tf_01:main'
        ],
    },
)

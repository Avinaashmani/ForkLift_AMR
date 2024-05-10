from setuptools import find_packages
from setuptools import setup

setup(
    name='forklift_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('forklift_interfaces', 'forklift_interfaces.*')),
)

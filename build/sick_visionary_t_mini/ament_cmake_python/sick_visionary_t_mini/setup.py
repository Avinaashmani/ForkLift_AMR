from setuptools import find_packages
from setuptools import setup

setup(
    name='sick_visionary_t_mini',
    version='0.0.0',
    packages=find_packages(
        include=('sick_visionary_t_mini', 'sick_visionary_t_mini.*')),
)

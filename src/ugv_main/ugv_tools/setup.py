from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'ugv_tools'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share',package_name,'launch'),glob(os.path.join('launch','*launch.py'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dudu',
    maintainer_email='dudu@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'keyboard_ctrl = ugv_tools.keyboard_ctrl:main',
            'joy_ctrl = ugv_tools.joy_ctrl:main',
            'behavior_ctrl = ugv_tools.behavior_ctrl:main'
        ],
    },
)

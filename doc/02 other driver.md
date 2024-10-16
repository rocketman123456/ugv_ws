# Chassis driver and Joystick, keyboard control

- Chassis driver (executed within docker)
    
    If you switch to another radar, modify
    
    ```jsx
    export LDLIDAR_MODEL=
    ```
    - Use radar as imu sensor data (more stable)
        
        ```jsx
        ros2 launch ugv_bringup bringup_lidar.launch.py use_rviz:=true
        ```
        
    
    Rotate the car in place to check the posture
    
    [![](https://res.cloudinary.com/marcomontalbano/image/upload/v1727491431/video_to_markdown/images/youtube--5neLr1Q2ddM-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/5neLr1Q2ddM "")
    
- Joystick, keyboard control
    
    Start the car
    
    ```jsx
    ros2 launch ugv_bringup bringup_lidar.launch.py use_rviz:=true
    ```
    
    - Joystick control (the joystick USB interface needs to be connected to the car or virtual machine)
        
        ```jsx
        ros2 launch ugv_tools teleop_twist_joy.launch.py
        ```
        
    - keyboard control
        
        ```jsx
        ros2 run ugv_tools keyboard_ctrl
        ```
        
        ![image.png](images/Keyboard%20controls.png)
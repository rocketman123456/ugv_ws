# Visual interaction

- Visual interaction
    
    Start the car
    
    ```jsx
    ros2 launch ugv_bringup bringup_lidar.launch.py use_rviz:=true
    ```
    
    - Start related interfaces
        
        control car
        
        ```jsx
        ros2 run ugv_tools behavior_ctrl
        ```
        
        Turn on the camera, easy
        
        ```jsx
        ros2 run usb_cam usb_cam_node_exe
        ```
        
        Turn on the camera and remove distortion
        
        ```jsx
        ros2 launch ugv_vision camera.launch.py
        ```
        
    - Monocular
            
        - Apriltag control
            
            apriltag only sets tag36h11, which can be modified by yourself
            
            - Apriltag control
                
                1 2 3 4 Right, left, front and rear, other stops
                
                ```jsx
                ros2 run ugv_vision apriltag_ctrl
                ```
                
            - Apriltag Simple tracking
                
                Select the left and right according to the x coordinate of the center point of the ar tag. After centering, select the front and rear according to the y coordinate. If the y is upward, the front is forward, and if the y is downward, the rear is
                
                ```jsx
                ros2 run ugv_vision apriltag_track_0
                ```
                
            - Apriltag Target tracking (AR code needs to specify size 0.08)
                
                pose recognition
                
                Here, the previous command to turn on the camera is turned off and replaced with the following
                
                ```jsx
                ros2 launch ugv_vision apriltag_track.launch.py
                ```
                
                ![image.png](images/APIELTAG%20object%20tracking.jpg)
                
                - Simply drive to the target point (rotate, go straight)
                    
                    Turn on tracking
                    
                    ```jsx
                    ros2 run ugv_vision apriltag_track_1
                    ```
                    
                    command line
                    
                    ```jsx
                    ros2 topic pub /apriltag/track std_msgs/msg/Int8 -1
                    ```
                    
                - Combine nav2 to drive to the target point (you need to close the previous startup file and change to open nav)
                    
                    Turn on navigation
                    
                    ```jsx
                    ros2 launch ugv_nav nav.launch.py use_rviz:=true
                    ```
                    
                    Turn on tracking
                    
                    ```jsx
                    ros2 run ugv_vision apriltag_track_2
                    ```

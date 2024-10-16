# Gazebo comprehensive simulation

- Gazebo comprehensive simulation (executed on virtual machine)
    
    ```jsx
    cd ~/.gazebo/
    git clone https://github.com/osrf/gazebo_models.git models
    cp -r /home/ws/ugv_ws/src/ugv_main/ugv_gazebo/models/world models
    cp /home/ws/ugv_ws/ugv_description.zip models 
    cd ~/.gazebo/models/
    unzip ugv_description.zip
    rm -rf ugv_description.zip
    ```
    
    - View model
        - rasp_rover
            
            ```jsx
            export UGV_MODEL=rasp_rover
            ```
            
            start up
            
            ```jsx
             ros2 launch ugv_gazebo display.launch.py 
            ```
            
        - ugv_rover
            
            ```jsx
            export UGV_MODEL=ugv_rover
            ```
            
            start up
            
            ```jsx
             ros2 launch ugv_gazebo display.launch.py 
            ```
            
        - ugv_beast
            
            ```jsx
            export UGV_MODEL=ugv_beast
            ```
            
            start up
            
            ```jsx
             ros2 launch ugv_gazebo display.launch.py 
            ```
            
    - Load model
        - Empty
            
            ```elm
            ros2 launch ugv_gazebo bringup_test.launch.py
            ```
            
            ![image.png](images/Gazebo%20empty%20world.png)
            
        - House
            
            ```jsx
            ros2 launch ugv_gazebo bringup.launch.py
            ```
            
            ![image.png](images/Gazebo%20house%20world.png)
            
    
    The following takes ugv_rover as an example
    
    Specify model
    
    ```jsx
    export UGV_MODEL=ugv_rover
    ```
    
    start up
    
    ```jsx
    ros2 launch ugv_gazebo bringup.launch.py
    ```
    
    - Joystick, keyboard control
        - Joystick control (the joystick USB interface needs to be connected to the virtual machine)
            
            ```jsx
            ros2 launch ugv_tools teleop_twist_joy.launch.py
            ```
            
        - Keyboard control
            
            ```jsx
            ros2 run ugv_tools keyboard_ctrl
            ```
            
            ![image.png](images/Keyboard%20controls.png)
            
    - Mapping
        - 2D (LiDAR)
            
            ![image.png](images/Gazebo%202D%20mapping.png)
            
            - Gmapping
                
                ```elm
                ros2 launch ugv_gazebo gmapping.launch.py
                ```
                
                control car
                
                ```jsx
                ros2 run ugv_tools keyboard_ctrl
                ```
                
                save map
                
                ```jsx
                ./save_2d_gmapping_map_gazebo.sh
                ```
                
                save_2d_gmapping_map_gazebo.sh content
                
                ```jsx
                cd /home/ws/ugv_ws/src/ugv_main/ugv_gazebo/maps
                ros2 run nav2_map_server map_saver_cli -f ./map
                ```
                
            - Cartographer
                
                ```elm
                ros2 launch ugv_gazebo cartographer.launch.py
                ```
                
                control car
                
                ```jsx
                ros2 run ugv_tools keyboard_ctrl
                ```
                
                save map
                
                ```jsx
                ./save_2d_cartographer_map_gazebo.sh
                ```
                
                save_2d_cartographer_map_gazebo.sh content
                
                ```jsx
                cd /home/ws/ugv_ws/src/ugv_main/ugv_gazebo/maps
                ros2 run nav2_map_server map_saver_cli -f ./map && ros2 service call /write_state cartographer_ros_msgs/srv/WriteState "{filename: '/home/ws/ugv_ws/src/ugv_main/ugv_gazebo/maps/map.pbstream'}"
                ```
                
        - 3D (lidar + depth camera)
            - Rtabmap
                - Rtabmap_viz Visualization
                    
                    ```jsx
                    ros2 launch ugv_gazebo rtabmap_rgbd.launch.py
                    ```
                    
                    ![image.png](images/Gazebo%20rtabmap_viz%20visualization.png)
                    
                    control car
                    
                    ```jsx
                    ros2 run ugv_tools keyboard_ctrl
                    ```
                    
                - Rviz Visualization
                    
                    ```jsx
                    ros2 launch ugv_gazebo rtabmap_rgbd.launch.py use_rviz:=true
                    ```
                    
                    control car
                    
                    ```jsx
                    ros2 run ugv_tools keyboard_ctrl
                    ```
                    
                
                After the mapping is completed, directly press ctrl+c to exit the mapping node, and the system will automatically save the map. Map default save path ~/.ros/rtabmap.db 
                
    - Navigation
        - 2D
            - Local positioning
                
                use_localization amcl（default），emcl，cartographer
                
                - amcl
                    
                    Start first, you need to manually specify the approximate initial position
                    
                    ```jsx
                    ros2 launch ugv_gazebo nav.launch.py use_localization:=amcl 
                    ```
                    
                    Then by controlling the car, simply move and rotate to assist in initial positioning.
                    
                    ```jsx
                    ros2 run ugv_tools keyboard_ctrl
                    ```
                    
                - emcl
                    
                    After startup, you need to manually specify the approximate initial position
                    
                    ```jsx
                    ros2 launch ugv_gazebo nav.launch.py use_localization:=emcl 
                    ```
                    
                - cartographer
                    
                    Note that you need to use Cartographer to build the map before you can proceed.
                    
                    ```jsx
                    ros2 launch ugv_gazebo nav.launch.py use_localization:=cartographer 
                    ```
                    
                    After startup, if the accurate position has not been located, you can control the car and simply move it to assist in the initial positioning.
                    
                    ```jsx
                    ros2 run ugv_tools keyboard_ctrl
                    ```
                    
            - Local navigation
                
                use_localplan dwa，teb（默认）
                
                - dwa
                    
                    ```jsx
                     ros2 launch ugv_gazebo nav.launch.py use_localplan:=dwa 
                    ```
                    
                - teb
                    
                    ```jsx
                     ros2 launch ugv_gazebo nav.launch.py use_localplan:=teb 
                    ```
                    
        - 3D
            - Rtabmap
                - Local navigation
                    
                    Turn on positioning
                    
                    ```jsx
                    ros2 launch ugv_gazebo rtabmap_localization_launch.py
                    ```
                    
                    Turn on nav (you can wait slowly until the 3D data is loaded before navigating, it will take a while)
                    
                    ![image.png](images/Gazebo%20rtabmap%203D%20navigation.png)
                    
                    use_localplan dwa，teb（默认）
                    
                    - dwa
                        
                        ```jsx
                         ros2 launch ugv_gazebo nav_rtabmap.launch.py use_localplan:=dwa 
                        ```
                        
                    - teb
                        
                        ```jsx
                         ros2 launch ugv_ngazebo nav_rtabmap.launch.py use_localplan:=teb
                        ```
                        
    - Mapping and navigation are enabled at the same time (two-dimensional)
        
        ```jsx
        ros2 launch ugv_gazebo slam_nav.launch.py
        ```
        
        - Automatic exploration (to be in a closed rule area)
            
            ```jsx
             ros2 launch explore_lite explore.launch.py 
            ```
            
    - Web ai interaction
        - Start related interfaces
            
            ```jsx
            ros2 run ugv_tools behavior_ctrl
            ```
            
        - web ai Interaction (requires relevant ai interface, currently ollama local deployment)
            
            ```jsx
            ros2 run ugv_chat_ai app
            ```
            
    - Web control
        - ugv web
            
            ```jsx
            ros2 launch ugv_web_app bringup.launch.py host:=ip
            ```
            
    - Command interaction
        
        ```jsx
        ros2 run ugv_tools behavior_ctrl
        ```
        
        - Basic control (you need to put the car down and run, and judge whether the goal has been completed based on the odometer)
            
            Forward data unit meters
            
            ```jsx
            ros2 action send_goal /behavior ugv_interface/action/Behavior "{command: '[{\"T\": 1, \"type\": \"drive_on_heading\", \"data\": 0.5}]'}”
            ```
            
            Back data unit meters
            
            ```jsx
            ros2 action send_goal /behavior ugv_interface/action/Behavior "{command: '[{\"T\": 1, \"type\": \"back_up\", \"data\": 0.5}]'}”
            ```
            
            Rotation data unit degree positive number rotate right, negative number rotate left
            
            ```jsx
            ros2 action send_goal /behavior ugv_interface/action/Behavior "{command: '[{\"T\": 1, \"type\": \"spin\", \"data\": -1}]'}”
            ```
            
            Stop
            
            ```jsx
            ros2 action send_goal /behavior ugv_interface/action/Behavior "{command: '[{\"T\": 1, \"type\": \"spin\", \"data\": 0}]'}”
            ```
            
        
        Navigation needs to be enabled below
        
        ```jsx
        ros2 launch ugv_gazebo nav.launch.py use_rviz:=true
        ```
        
        - Get current point position
            
            ```elm
            ros2 topic echo /robot_pose --once
            ```
            
        - Save as navigation point
            
            data navigation point name, optional a-g
            
            ```jsx
            ros2 action send_goal /behavior ugv_interface/action/Behavior "{command: '[{\"T\": 1, \"type\": \"save_map_point\", \"data\": \"a\"}]'}"
            ```
            
        - Move to navigation point
            
            data navigation point name, optional a-g
            
            ```jsx
            ros2 action send_goal /behavior ugv_interface/action/Behavior "{command: '[{\"T\": 1, \"type\": \"pub_nav_point\", \"data\": \"a\"}]'}"
            ```
            
        
        The saved points will also be stored in the file.
        
        ![image.png](images/The%20saved%20points%20will%20also%20be%20stored%20in%20the%20file.png)
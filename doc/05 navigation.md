# Navigation

- Navigation
    - 2D
        - Local localization
            
            use_localization amcl（default），emcl，cartographer
            
            - amcl
                
                Start first, you need to manually specify the approximate initial position
                
                ```jsx
                ros2 launch ugv_nav nav.launch.py use_localization:=amcl use_rviz:=true
                ```
                
                Then by controlling the car, simply move and rotate to assist in initial positioning.
                
                ```jsx
                ros2 run ugv_tools keyboard_ctrl
                ```
                
            - emcl
                
                After startup, you need to manually specify the approximate initial position
                
                ```jsx
                ros2 launch ugv_nav nav.launch.py use_localization:=emcl use_rviz:=true
                ```
                
            - cartographer
                
                Note that you need to use Cartographer to build the map before you can proceed.
                
                ```jsx
                ros2 launch ugv_nav nav.launch.py use_localization:=cartographer use_rviz:=true
                ```
                
                ![image.png](images/Cartographer%20pure_localization.png)
                
                After startup, if the accurate position has not been located, you can control the car and simply move it to assist in the initial positioning.
                
                ```jsx
                ros2 run ugv_tools keyboard_ctrl
                ```
                
        - Local navigation
            
            use_localplan dwa，teb（default）
            
            - dwa
                
                ```jsx
                 ros2 launch ugv_nav nav.launch.py use_localplan:=dwa use_rviz:=true
                ```
                
            - teb
                
                ```jsx
                 ros2 launch ugv_nav nav.launch.py use_localplan:=teb use_rviz:=true
                ```
                
    - 3D
        - Rtabmap
            - Local navigation
                
                Turn on positioning
                
                ```jsx
                ros2 launch ugv_nav rtabmap_localization_launch.py
                ```
                
                Turn on nav (you can wait slowly until the 3D data is loaded before navigating, it will take a while)
                
                use_localplan dwa，teb（default）
                
                - dwa
                    
                    ```jsx
                     ros2 launch ugv_nav nav_rtabmap.launch.py use_localplan:=dwa use_rviz:=true
                    ```
                    
                - teb
                    
                    ```jsx
                     ros2 launch ugv_nav nav_rtabmap.launch.py use_localplan:=teb use_rviz:=true
                    ```

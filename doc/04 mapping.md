# Mapping

- Mapping
    - 2D (LiDAR)
        - Gmapping
            
            ```jsx
             ros2 launch ugv_slam gmapping.launch.py use_rviz:=true
            ```
            
            [![](https://res.cloudinary.com/marcomontalbano/image/upload/v1727493329/video_to_markdown/images/youtube--cBiuYmxGWks-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/cBiuYmxGWks "")
            
            control car
            
            ```jsx
            ros2 run ugv_tools keyboard_ctrl
            ```
            
            save map
            
            ```jsx
            ./save_2d_gmapping_map.sh
            ```
            
            ![image.png](images/Save_2d_gmapping_map.sh.png)
            
            save_2d_gmapping_map.sh内容
            
            ```jsx
            cd /home/ws/ugv_ws/src/ugv_main/ugv_nav/maps
            ros2 run nav2_map_server map_saver_cli -f ./map
            ```
            
        - Cartographer
            
            ```jsx
            ros2 launch ugv_slam cartographer.launch.py use_rviz:=true
            ```
            
            [![](https://res.cloudinary.com/marcomontalbano/image/upload/v1727491911/video_to_markdown/images/youtube--dHyNeuJ0k3U-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/dHyNeuJ0k3U "")
            
            control car
            
            ```jsx
            ros2 run ugv_tools keyboard_ctrl
            ```
            
            save map
            
            ```jsx
            ./save_2d_cartographer_map.sh
            ```
            
            ![image.png](images/Save_2d_cartographer_map.sh.png)
            
            save_2d_cartographer_map.sh内容
            
            ```jsx
            cd /home/ws/ugv_ws/src/ugv_main/ugv_nav/maps
            ros2 run nav2_map_server map_saver_cli -f ./map && ros2 service call /write_state cartographer_ros_msgs/srv/WriteState "{filename: '/home/ws/ugv_ws/src/ugv_main/ugv_nav/maps/map.pbstream'}"
            ```
            
    - 3D (lidar + depth camera)
        - Rtabmap
            - Rtabmap_viz Visualization
                
                ```jsx
                ros2 launch ugv_slam rtabmap_rgbd.launch.py use_rviz:=false
                ```
                
                [![](https://res.cloudinary.com/marcomontalbano/image/upload/v1727492108/video_to_markdown/images/youtube--J3_QCGVF7Jc-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/J3_QCGVF7Jc "")
                
                control car
                
                ```jsx
                ros2 run ugv_tools keyboard_ctrl
                ```
                
            - Rviz Visualization
                
                ```jsx
                ros2 launch ugv_slam rtabmap_rgbd.launch.py use_rviz:=true
                ```
                
                [![](https://res.cloudinary.com/marcomontalbano/image/upload/v1727492190/video_to_markdown/images/youtube--dxey_90tdFI-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/dxey_90tdFI "")
                
                control car
                
                ```jsx
                ros2 run ugv_tools keyboard_ctrl
                ```
                
            
            After the mapping is completed, directly press ctrl+c to exit the mapping node, and the system will automatically save the map. Map default save path ~/.ros/rtabmap.db 
 
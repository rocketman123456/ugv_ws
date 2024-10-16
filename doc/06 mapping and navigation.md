# Mapping and navigation

- Mapping and navigation are enabled at the same time (two-dimensional)
    
    ```jsx
    ros2 launch ugv_nav slam_nav.launch.py use_rviz:=true
    ```
    
    - Rviz manually publishes navigation points for exploration (you can also use the keyboard, handle, and web side for remote exploration)
        
        ![image.png](images/Rviz%20manually%20publishes%20navigation%20points%20for%20exploration.png)
        
    - Automatic exploration (to be in a closed rule area)
        
        ```jsx
         ros2 launch explore_lite explore.launch.py 
        ```

    - Save map
            
        ```jsx
        ./save_2d_gmapping_map.sh
        ```

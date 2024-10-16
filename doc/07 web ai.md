# Web ai interaction

- Web ai interaction
    - Start the car
        
        ```jsx
        ros2 launch ugv_bringup bringup_lidar.launch.py use_rviz:=true
        ```
        
    - Start related interfaces
        
        ```jsx
        ros2 run ugv_tools behavior_ctrl
        ```
        
    - Web ai Interaction (requires relevant ai interface, currently ollama local deployment)
        
        ```jsx
        ros2 run ugv_chat_ai app
        ```

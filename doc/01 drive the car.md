# start car driver

Enter docker and start ssh to remotely access docker and the visual interface

- Car settings docker
    - Set up docker remote login
        
        Execute on the host and enter the directory
        
        ```jsx
        cd /home/ws/ugv_ws
        sudo chmod +x ros2_humble.sh remotessh.sh
        ./ros2_humble.sh
        ```
        
        1进入docker
        
        ![image.png](images/Enter%20docker.png)
        
    - Exit docker
        
        Execute within docker
        
        ```jsx
        exit
        ```
        
- Remote to docker
    
    ![image.png](images/Connect%20to%20docker%20remotely.png)
    
    ![image.png](images/Docker%20username.png)
    
    ```jsx
    #username
    root
    #Password needs to be set in advance
    ws
    ```
    
    Enter workspace
    
    ```jsx
    cd /home/ws/ugv_ws
    ```
    
- View model joints
    - rasp_rover
        
        ```jsx
        export UGV_MODEL=rasp_rover
        ```
        
        start up
        
        ```jsx
        ros2 launch ugv_description display.launch.py use_rviz:=true
        ```
        
        ![image.png](images/rasp_rover.png)
        
    - ugv_rover
        
        ```jsx
        export UGV_MODEL=ugv_rover
        ```
        
        start up
        
        ```jsx
        ros2 launch ugv_description display.launch.py use_rviz:=true
        ```
        
        ![image.png](images/ugv_rover.png)
        
    - ugv_beast
        
        ```jsx
        export UGV_MODEL=ugv_beast
        ```
        
        start up
        
        ```jsx
        ros2 launch ugv_description display.launch.py use_rviz:=true
        ```
        
        ![image.png](images/ugv_beast.png)

  - Drive the car (can control the pan/tilt and LED lights)
      
      ```jsx
      ros2 run ugv_bringup ugv_driver
      ```
      
      Drag the slider related to the joint angle publisher to control the gimbal
      
      [![](https://res.cloudinary.com/marcomontalbano/image/upload/v1727491041/video_to_markdown/images/youtube--jA9LJTBRQqY-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/jA9LJTBRQqY "")
      
      Control the light data 0-255 data[0] control the light IO4 near the oak camera data[1] control the light IO5 near the usb camera
      
      ```jsx
      ros2 topic pub /ugv/led_ctrl std_msgs/msg/Float32MultiArray "{data: [0, 0]}" -1
      ```

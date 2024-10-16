#cd /home/ws/ugv_ws
colcon build --executor sequential --packages-select cv_bridge apriltag apriltag_msgs apriltag_ros cartographer costmap_converter_msgs costmap_converter emcl2 explore_lite openslam_gmapping slam_gmapping ldlidar rf2o_laser_odometry robot_pose_publisher --symlink-install
colcon build --executor sequential --packages-select teb_msgs teb_local_planner vizanti vizanti_cpp vizanti_demos vizanti_msgs vizanti_server ugv_base_node ugv_interface --symlink-install
colcon build --executor sequential --packages-select ugv_bringup ugv_chat_ai ugv_description ugv_gazebo ugv_nav ugv_slam ugv_tools ugv_vision ugv_web_app --symlink-install
source install/setup.bash

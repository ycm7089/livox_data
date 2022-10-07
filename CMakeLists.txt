cmake_minimum_required(VERSION 3.0.2)
project(cm_data_sub)

find_package(catkin REQUIRED COMPONENTS
  livox_ros_driver
  pcl_ros
  roscpp
  rospy
  std_msgs
  message_generation
)

catkin_package(
#  INCLUDE_DIRS include
 LIBRARIES cm_data_sub
 CATKIN_DEPENDS  pcl_ros roscpp rospy std_msgs message_runtime
 DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(lidar_data_sub src/data_sub.cpp)

target_link_libraries(lidar_data_sub
  ${catkin_LIBRARIES}
)

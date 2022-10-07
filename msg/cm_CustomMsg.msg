# Livox publish pointcloud msg format.

Header header             # ROS standard message header
uint64 timebase           # The time of first point
uint32 point_num          # Total number of pointclouds
uint8  lidar_id           # Lidar device id number
uint8[3]  rsvd            # Reserved use
uint32 offset_time        # offset time relative to the base time
float32 x                 # X axis, unit:m
float32 y                 # Y axis, unit:m
float32 z                 # Z axis, unit:m
uint8 reflectivity        # reflectivity, 0~255
uint8 tag                 # livox tag
uint8 line                # laser number in lidar

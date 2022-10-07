#include <livox_ros_driver/CustomMsg.h>
// #include <livox_ros_driver/CustomPoint.h>
#include <ros/ros.h>

//라이다 데이터 1초동안 PCL 정보 저장하고 (1 Image, many angle(pcd))

typedef struct
{
    int LiDARInfo_timebase;
    int LiDARInfo_point_num ;
    int LiDARInfo_id;
    int LiDARInfo_rsvd[3];
    // below is CustomPoint
    int LiDARInfo_offset_time;
    double LiDARInfo_x;
    double LiDARInfo_y;
    double LiDARInfo_z;
    int LiDARInfo_reflectivity;
    int LiDARInfo_tag;
    int LiDARInfo_line;
} Livox_data_Info;

void lidar_cb(const livox_ros_driver::CustomMsg::ConstPtr & msg)
{
    Livox_data_Info livox_info;
    // ROS_INFO("%.3f", msg -> points.x);
    livox_info.LiDARInfo_timebase = msg -> timebase;
    livox_info.LiDARInfo_point_num = msg -> point_num;
    for(int i = 0; i < 3; i++)
    {
        livox_info.LiDARInfo_rsvd[i] = msg -> rsvd[i];
        // ROS_INFO("%d", livox_info.LiDARInfo_rsvd[i]);
    }
    // 왜 0이지?
    // ROS_INFO("points size is %.3f", sizeof(msg->points)) ; 

    for(int i = 0; i < 7; i++)
    {
        livox_info.LiDARInfo_offset_time = msg -> points[i].offset_time;
        livox_info.LiDARInfo_x = msg -> points[i].x;
        livox_info.LiDARInfo_y = msg -> points[i].y;
        livox_info.LiDARInfo_z = msg -> points[i].z;
        livox_info.LiDARInfo_reflectivity = msg -> points[i].reflectivity;
        livox_info.LiDARInfo_tag = msg -> points[i].tag;
        livox_info.LiDARInfo_line = msg -> points[i].line;

        ROS_INFO("x %.3f", livox_info.LiDARInfo_x);
        ROS_INFO("y %.3f", livox_info.LiDARInfo_y);
        ROS_INFO("z %.3f", livox_info.LiDARInfo_z);
    }    
    // ROS_INFO("%d", livox_info.LiDARInfo_timebase);
    // ROS_INFO("%d", livox_info.LiDARInfo_point_num); //2400개

}


int main(int argc, char** argv){
    ros::init(argc, argv, "lidar_data_sub");
    ros::NodeHandle nh;
    
    ros::Subscriber data_sub = nh.subscribe("livox/lidar",1, lidar_cb);
    
    ros::spin();
    return 0;
};
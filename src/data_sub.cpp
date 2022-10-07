#include <livox_ros_driver/CustomMsg.h>
#include <ros/ros.h>

//라이다 데이터 1초동안 PCL 정보 저장하고 (1 Image, many angle(pcd))
void lidar_cb(const livox_ros_driver::CustomMsg::ConstPtr & msg)
{
    ROS_INFO("%.3f", msg -> points);
}


int main(int argc, char** argv){
    ros::init(argc, argv, "lidar_data_sub");
    ros::NodeHandle nh;

    ros::Subscriber data_sub = nh.subscribe("livox/lidar",1, lidar_cb);
    
    ros::spin();
    return 0;
};
#include "ros/ros.h"
#include "std_msgs/String.h"

void msgCallback(const std_msgs::String::ConstPtr& msg) {
	ROS_INFO("%s", msg->data.c_str());
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "HelloWorld_sub_str");
	ros::NodeHandle nh;

	ros::Subscriber HelloWorld_sub = nh.subscribe<std_msgs::String>("chatter", 100, msgCallback);

	ros::spin();

	return 0;
}

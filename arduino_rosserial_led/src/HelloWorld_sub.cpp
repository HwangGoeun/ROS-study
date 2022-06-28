#include "ros/ros.h"
#include "std_msgs/String.h"

void msgCallback(const std_msgs::String::ConstPtr& msg) {
	ROS_INFO("%s", msg->data);
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "HelloWorld_sub");
	ros::NodeHandle nh;

	ros::Subscriber HelloWorld_sub = nh.subscribe<std_msgs::String>("chatter", 100, msgCallback);

	ros::spin();

	return 0;
}

#include "ros/ros.h"
#include "std_msgs/Char.h"

void msgCallback(const std_msgs::Char::ConstPtr& msg) {
	ROS_INFO("%c", msg->data);
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "HelloWorld_sub");
	ros::NodeHandle nh;

	ros::Subscriber HelloWorld_sub = nh.subscribe<std_msgs::Char>("chatter", 100, msgCallback);

	ros::spin();

	return 0;
}

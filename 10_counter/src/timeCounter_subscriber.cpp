#include "ros/ros.h"
#include "10_counter/MsgData.h"

void msgCallback(const 10_counter::MsgData::ConstPtr& msg) {
	ROS_INFO("recieve msg = %d", msg->stamp.sec);
	ROS_INFO("recieve msg = %d", msg->stamp.nsec);
	ROS_INFO("recieve msg = %d", msg->data);
}

int main(int argc, char **argv) {

	// node setting
	ros::init(argc, argv, "timeCounter_subscriber");
	ros::NodeHandle nh;

	// subscriber setting
	ros::Subscriber msg_sub = nh.subscribe("MsgData", 100, msgCallback);

	ros::spin();

	return 0;
}

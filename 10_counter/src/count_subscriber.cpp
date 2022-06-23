#include "ros/ros.h"
#include "10_counter/MsgData.h"

void msgCallback(const 10_counter::MsgData::ConstPtr& msg) {

	if (msg->data % 10 == 0) {
		ROS_INFO("recieve count = %d", msg->data);
	}

}

int main(int argc, char **argv) {

	// node setting
	ros::init(argc, argv, "count_subscriber");
	ros::NodeHandle nh;

	// subscriber setting
	ros::Subscriber msg_sub = nh.subscribe("MsgData", 100, msgCallback);

	ros::spin();

	return 0;
}

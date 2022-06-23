#include "ros/ros.h"
#include "10_counter/MsgData.h"

int main(int argc, char **argv) {
	
	// Node setting
	ros::init(argc, argv, "timeCounter_publisher");
	ros::NodeHandle nh;

	// Publisher setting
	ros::Publisher msg_pub = nh.advertise<10_counter::MsgData>("MsgData", 100);
	
	ros::Rate loop_rate(10);

	// topic message setting	
	10_counter::MsgData msg;
	int count = 0;	

	while(ros::ok()) {
		msg.stamp = ros::Time::now();
		msg.data = count;

		ROS_INFO("send msg = %d", msg.stamp.sec);
		ROS_INFO("send msg = %d", msg.stamp.nsec);
		ROS_INFO("send msg = %d", msg.data);

		msg_pub.publish(msg);

		loop_rate.sleep();

		++count;
	}

	return 0;
}

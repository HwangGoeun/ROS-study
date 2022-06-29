/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/Char.h>

ros::NodeHandle  nh;

std_msgs::Char str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello = 'h';

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}

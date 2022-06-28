#!/usr/bin/env python

import rospy
from sensor_msgs.msg import LaserScan
def callback(data):
	laser_ranges = data.ranges
	print(laser_ranges)

	for element in laser_ranges:
		if element < 1:
			print("The ranges value is Under 1")
			
		elif element < 3:
			print("The ranges value is Under 3")

		elif element < 5:
			print("The ranges value is Under 5")

def main():	
	rospy.init_node("range_sub")
	sub = rospy.Subscriber("/scan", LaserScan, callback)
	rospy.spin()

if __name__ == '__main__':
	try:
		main()
	except rospy.ROSInterruptException:
		GPIO.cleanup()

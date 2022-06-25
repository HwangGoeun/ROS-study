#!/usr/bin/env python

import rospy
import Jetson.GPIO as GPIO
import time

def main():
	GPIO.setwarnings(False)

	rospy.init_node("LED_GPIO")

	# GPIO setting
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(11, GPIO.OUT)
	GPIO.setup(13, GPIO.OUT)
	GPIO.setup(15, GPIO.OUT)

	while not rospy.is_shutdown():
		GPIO.output(15, GPIO.HIGH)
		GPIO.output(13, GPIO.LOW)
		GPIO.output(11, GPIO.LOW)
		print("Green Light")
		
		time.sleep(1)

		GPIO.output(15, GPIO.LOW)
		GPIO.output(13, GPIO.HIGH)
		GPIO.output(11, GPIO.LOW)
		print("Yellow Light")
		
		time.sleep(1)

		GPIO.output(15, GPIO.LOW)
		GPIO.output(13, GPIO.LOW)
		GPIO.output(11, GPIO.HIGH)
		print("Red Light")
		
		time.sleep(1)

if __name__ == '__main__':
	try:
		main()
	except rospy.ROSInterruptException:
		GPIO.cleanup()

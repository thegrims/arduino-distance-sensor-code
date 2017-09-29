# Hweekend arduino powered distance sensor

During the Fall Hweekend of 2016, I collaborated with some folks in the school of EECS and MIME to make this arduino powered distance sensor. The intended use case would be for blind or sight impaired people, but we really just developed it for fun! 

The device works by taking in distance levels from the four ultrasonic distance sensors pictured below, smoothing those levels with a basic moving average, and then converting that data into a pwm output. 

The pwm output is sent to an H-bridge motor driver, which drives four different pager motors located in the palm of the device. 

The closer the ultrasonic sensors get to a solid object, the more they vibrate, creating a non visual feedback mechanism for depth.

![alt text](https://raw.githubusercontent.com/thegrims/arduino-distance-sensor-code/master/hweekend_sensor.jpg)

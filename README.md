# Programming_the_Arduino_Rollbot
Authors: Bilal Alawwir, Ibrahim Hussein, Majed Wakim, YiHui Wang
## Description
The purpose of the project is to construct an algorithm which can navigate the rollbot through a course by following the black line.<br/>
In this project we are going to use the sensors to detect the black line on the track. The rollbot is going to start on a black line perpendicular to the main line which the rollbot is going to follow through. The rollbot should follow the line and make any kind of turns for a number of laps clockwise and counter clockwise.
> ”Arduino is an open-source electronics platform based on easy-to-use hardware and software. Arduino boards can read inputs - light on a sensor, a finger on a button, or a Twitter message - and turn it into an output - activating a motor, turning on an LED, publishing something online. You can program your board what to do by sending a set of instructions to the microcontroller on the board. To do so you use the Arduino program (based on C Language), and the Arduino Software (IDE).” 
## Flowchart
This a flowchart of the code. At the beginning five were initialized sensors, laps number(unknown), opposite direction laps(unknown), total laps (laps number plus opposite direction laps) and the counter to 0. There is a loop that reads the inputs from the five sensors. If all sensors are black, add one to the counter, and then if the counter equals laps number " follow junction” which is when the rollbot have done the number of laps required clockwise. if it does not equal to laps number we have another if statement here if counter does not equal to total laps number continue straight and if it does equal then stop. Then if sensor1 and sensor5 are white and sensor2 or sensor3 or sensor4 is black go straight but if it is false add another if statement if sensor1 and sensor2 are black and sensor5 is white turn left, if it is false add another if statement if sensor5 and sensor4 are black and sensor1 is white turn right.
![](https://github.com/jameswyh/Programming_the_Arduino_Rollbot/blob/master/Rollbot_chart/chart1.png)
![](https://github.com/jameswyh/Programming_the_Arduino_Rollbot/blob/master/Rollbot_chart/chart2.png)

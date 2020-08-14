#include "Rollbot.h"

RollbotReadSensor Sensor;
RollbotMotors Motor;

int Speed_Dir = 0;
int BASE_SPEED = 100;
int blackthreshold = 160;
int clockwise = 1;
int c_clockwise = 1;
int count = 0;
int turnflag = 0;


void setup() {

}

void loop() {
  // put your main code here, to run repeatedly:
Sensor.Read_Data();

// go straight
if ((Sensor.data[0] > blackthreshold) && (Sensor.data[1] > blackthreshold) && (Sensor.data[2] < blackthreshold) && (Sensor.data[3] > blackthreshold) && (Sensor.data[4] > blackthreshold))
{
  Motor.Motordrive(Speed_Dir, BASE_SPEED, BASE_SPEED);
}

//start line
else if((Sensor.data[0] < blackthreshold) && (Sensor.data[1] < blackthreshold) && (Sensor.data[2] < blackthreshold) && (Sensor.data[3] < blackthreshold) && (Sensor.data[4] < blackthreshold))
{
  delay(90);
  count++;
  if ((count == (clockwise+1)) && (turnflag == 0))
 {
    Motor.Motordrive(Speed_Dir, BASE_SPEED ,  -50);
    turnflag = 1;
    delay(500);
  }
  else if(turnflag == 1)
  {
    Motor.Motordrive(Speed_Dir, 0 , BASE_SPEED);
    turnflag = 0;
    count--;
    delay(500);
  }
  else if(count == (clockwise+c_clockwise+1))
 {
    Motor.Motordrive(Speed_Dir, 0 , 0);
    BASE_SPEED = 0;
 }
 else
 {
  Motor.Motordrive(Speed_Dir, BASE_SPEED, BASE_SPEED);
 }
}

else if ((turnflag == 1)&&((Sensor.data[0] < blackthreshold) && (Sensor.data[1] < blackthreshold) && (Sensor.data[2] < blackthreshold)))
{
  Motor.Motordrive(Speed_Dir,-50 , BASE_SPEED);
  turnflag = 0;
  delay(500);
}

else if ((turnflag == 1)&&((Sensor.data[2] < blackthreshold) && (Sensor.data[3] < blackthreshold) && (Sensor.data[4] < blackthreshold)))
{
  Motor.Motordrive(Speed_Dir, -50 , BASE_SPEED-20);
  turnflag = 0;
  delay(100);
}

// turn left
else if (((Sensor.data[0] < blackthreshold)||(Sensor.data[1] < blackthreshold)) && (Sensor.data[2] > blackthreshold))
{
  Motor.Motordrive(Speed_Dir, 40 , BASE_SPEED);
}

// turn right
else if (((Sensor.data[3] < blackthreshold)||(Sensor.data[4] < blackthreshold)) && (Sensor.data[2] > blackthreshold))
{
 /* if (((Sensor.data[0] > blackthreshold) && (Sensor.data[1] < blackthreshold)) && (Sensor.data[2] < blackthreshold) && (Sensor.data[3] < blackthreshold) && (Sensor.data[4] < blackthreshold))
  {
    Motor.Motordrive(Speed_Dir, BASE_SPEED , BASE_SPEED);
  }*/
  Motor.Motordrive(Speed_Dir, BASE_SPEED ,  40);
}

}
 

#include "robot.h"

Robot robot;

void setup(){
  Serial.begin(9600);
  robot.setupRobot(8, 6); 
}

void loop(){
   robot.receive();
}

#include "robot.h"

Robot robot;
String receivedString;

void setup(){
  Serial.begin(9600);
  robot.setupRobot(7, 6); 
}

void loop(){
  if(Serial.available()){
    receivedString = Serial.readStringUntil('\n');
    robot.receive(receivedString);
  }
}

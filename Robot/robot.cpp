#include <Servo.h>
#include "robot.h"

void Robot::setupRobot(int pinClaw, int pinArm1){
  
  this->pinClaw = pinClaw;
  this->pinArm1 = pinArm1;
  
  this->claw.attach(this->pinClaw);
  this->arm1.attach(this->pinArm1);
}

void Robot::receive(int data){
    switch(data){
      case 0:
        activateClaw();

      case 1:
        activateArm1(1);

      case 2:
        activateArm1(2);
    }
}

void Robot::activateClaw(){

    if(this->clawState == false){
        this->claw.write(this->closedClawPosition);
        this->clawState = true;
        return;
    }

    else{
        this->claw.write(this->openedClawPosition);
        this->clawState = false;
        return;
    }
}

void activateArm1(int data){

  if
  
}

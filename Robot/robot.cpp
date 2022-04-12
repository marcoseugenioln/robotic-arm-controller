#include <Servo.h>

#include "robot.h"

void Robot::setupRobot(int pinClaw, int pinArm1){
  
  this->pinClaw = pinClaw;
  this->pinArm1 = pinArm1;
  
  this->claw.attach(this->pinClaw);
  this->arm1.attach(this->pinArm1);
  
}

void Robot::receive(){
  if(Serial.available()){
    int data = Serial.parseInt();
    switch(data){
      case 9:
        activateClaw();
    
      case 1:
        moveUp();
        
      case 2:
        moveDown();
    }
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

void Robot::moveVerticalArm(){
  while(this->up){
    this->arm1.write(this->positionArm1 + this->velocity);
  }

  while(this->down){
    this->arm1.write(this->positionArm1 - this->velocity);
  }
}

void Robot::moveUp(){
  if(this->down){
    this->down = false;
  }
  
  if(this->up){
    this->down = false;
  }

  else{
    this->up = true;
  }

  while(this->up){
    this->arm1.write(this->positionArm1 + this->velocity);
    receive();
  }
}

void Robot::moveDown(){
  if(this->up){
    this->up = false;
  }
 
  if(this->down){
    this->down = false;
  }
  
  else{
    this->down = true;
  }

  while(this->down){
    this->arm1.write(this->positionArm1 - this->velocity);
    receive();
  }
}

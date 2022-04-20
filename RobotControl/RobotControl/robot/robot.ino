#define PIN_CLAW 8
#define PIN_ARM1 6
#define HOME 0
#define CLOSED 120
#define MAX_TIME 6000

#include <Servo.h>
#include <Thread.h>
#include <ThreadController.h>

ThreadController controller;
Thread* receiver;
Thread* moveUp;
Thread* moveDown;

Servo claw;
Servo arm1;

int positionArm1 = 0;
bool movingUp = false;
bool movingDown = false;
bool closed = false;

void activateClaw(){
  if(!closed){
    claw.write(CLOSED);
    closed = true;
    return;
  }

  else{
    claw.write(HOME);
    closed = false;
    return;
  }
}

void up(){
  while(1){
    positionArm1 = positionArm1 + 3;
    arm1.write(positionArm1);
  }
}

void down(){
  while(1){
    positionArm1 = positionArm1 - 3;
    arm1.write(positionArm1);
  }
}

void setup(){
  Serial.begin(9600);
  
  claw.attach(PIN_CLAW);
  arm1.attach(PIN_ARM1);
  
  arm1.write(HOME);

  receiver = new Thread();
  moveUp = new Thread();
  moveDown = new Thread();
  
  receiver.onRun(&receive);
  moveUp.onRun(&up);
  moveDown.onRun(&down);

  moveUp.setInterval(MAX_TIME);
  moveDown.setInterval(MAX_TIME);
  
  receiver.enabled = true;  
  moveUp.enabled = false;
  moveDown.enabled = false; 

  controller = ThreadController();
  controller.add(moveUp);
  controller.add(moveDown);
  controller.add(receiver);
}

void receive(){
  if(Serial.available()){
  switch(Serial.parseInt()){
    case 9:
      activateClaw();
    case 1:
      if(!moveUp.enabled){
        moveUp.enabled = true;
      }
      else{
        moveUp.enabled = false;
      }
    case 2:
      if(!moveDown.enabled){
        moveDown.enabled = true;
      }
      else{
        moveDown.enabled = false;
      }
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    }
  }
}

void loop(){
  receive();
}

#define PIN_CLAW 8
#define PIN_VERTICAL_ARM 9
#define PIN_HORIZONTAL_ARM 10
#define PIN_BASE 11
#define HOME 0
#define FRONT 90
#define CLOSED 100
#define MAX_TIME 6000

#define CLAW 9
#define UP 1
#define DOWN 2
#define FORWARDS 3
#define BACKWARDS 4
#define RIGHT 5
#define LEFT 6

#include <Servo.h>
Servo claw;
Servo verticalArm;
Servo horizontalArm;
Servo base;

bool closed = true;
int velocity = 10;

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

void setup(){
  Serial.begin(9600);
  
  claw.attach(PIN_CLAW);
  verticalArm.attach(PIN_VERTICAL_ARM);
  horizontalArm.attach(PIN_HORIZONTAL_ARM);
  base.attach(PIN_BASE);

  verticalArm.write(HOME);
  horizontalArm.write(HOME);
  base.write(FRONT);
  claw.write(CLOSED);
}

void loop(){
  if(Serial.available()){
    switch(Serial.parseInt()){
      case CLAW:
        activateClaw();
        break;
      case UP:
        //verticalArm.write(verticalArm.read() + velocity);
        break;
      case DOWN:
        //verticalArm.write(verticalArm.read() - velocity);
        break;
      case FORWARDS:
        horizontalArm.write(horizontalArm.read() + velocity);
        delay(50);
        break;
      case BACKWARDS:
        horizontalArm.write(horizontalArm.read() - velocity);
        delay(50);
        break;
      case RIGHT:
        //base.write(base.read() + velocity);
        break;
      case LEFT:
        //base.write(base.read() - velocity);
        break;
    }
  }
}

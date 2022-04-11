#ifndef Robot_h
#define Robot_h

#include <Arduino.h>
#include <Servo.h>

class Robot{

    private:

    /*Claw atributes*/
    Servo claw;
    int pinClaw;
    bool clawState = false;
    int closedClawPosition = 120;
    int openedClawPosition = 0;

    /*First arm atributes*/
    Servo arm1;
    int pinArm1;
    int positionArm1 = 0;
    bool moveUp = false;
    bool moveDown = false;
    
    public:
    void receive(String data);
    void setupRobot(int pinClaw, int pinArm1);
    
    void activateClaw();
    void activateArm1(int data);
    
};

#endif

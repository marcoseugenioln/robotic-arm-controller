#ifndef Robot_h
#define Robot_h

#include <Arduino.h>
#include <Servo.h>
#include <Thread.h>

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
    int velocity = 1;
    bool up = false;
    bool down = false;
    
    public:

    /*
    * executa as configurações iniciais do robô
    */
    void setupRobot(int pinClaw, int pinArm1);  

    /*
    * Ativa a garra
    */
    void activateClaw();

    /*
    * movimenta o braço 1
    */
    void moveVerticalArm();
    void moveUp();
    void moveDown();

    void receive();
};

#endif

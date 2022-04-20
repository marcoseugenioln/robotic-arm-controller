#define SEND
#define MAX_DATA_LENGTH 255
#define PORT_NAME "COM5"
#define CLAW "9"
#define UP "1"
#define DOWN "2"
#define FORWARDS "3"
#define BACKWARDS "4"
#define RIGHT "5"
#define LEFT "6"

#include "robot_control.h"
#include "serial_port.hpp"
#include <QDebug>
#include <QTimer>

RobotControl::RobotControl(QWidget *parent)
    : QMainWindow(parent)
{
	this->arduino = new SerialPort(PORT_NAME);

    ui.setupUi(this);

	connect(ui.claw, SIGNAL(clicked()), this, SLOT(activateClaw()));
	connect(ui.up, SIGNAL(clicked()), this, SLOT(moveUp()));
	connect(ui.down, SIGNAL(clicked()), this, SLOT(moveDown()));
	connect(ui.forwards, SIGNAL(clicked()), this, SLOT(moveForwards()));
	connect(ui.backwards, SIGNAL(clicked()), this, SLOT(moveBackwards()));
	connect(ui.right, SIGNAL(clicked()), this, SLOT(moveRight()));
	connect(ui.left, SIGNAL(clicked()), this, SLOT(moveLeft()));
}

void RobotControl::autoConnect()
{
	//better than recusion
	//avoid stack overflows
	while (1) {
		// ui - searching
		std::cout << "Searching in progress";
		// wait connection
		while (!arduino->isConnected()) {
			Sleep(100);
			std::cout << ".";
			arduino = new SerialPort(PORT_NAME);
		}

		//Checking if arduino is connected or not
		if (arduino->isConnected()) {
			std::cout << std::endl << "Connection established at port " << PORT_NAME << std::endl;
		}
	}
}

void RobotControl::activateClaw() {
	arduino->writeSerialPort(CLAW, MAX_DATA_LENGTH);
}

void RobotControl::moveUp() {
	arduino->writeSerialPort(UP, MAX_DATA_LENGTH);
}

void RobotControl::moveDown() {
	arduino->writeSerialPort(DOWN, MAX_DATA_LENGTH);
}

void RobotControl::moveForwards() {
	arduino->writeSerialPort(FORWARDS, MAX_DATA_LENGTH);
}

void RobotControl::moveBackwards() {
	arduino->writeSerialPort(BACKWARDS, MAX_DATA_LENGTH);
}

void RobotControl::moveRight() {
	arduino->writeSerialPort(RIGHT, MAX_DATA_LENGTH);
}

void RobotControl::moveLeft() {
	arduino->writeSerialPort(LEFT, MAX_DATA_LENGTH);
}
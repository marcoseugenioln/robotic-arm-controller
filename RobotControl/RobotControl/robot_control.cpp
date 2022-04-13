#define SEND
#define MAX_DATA_LENGTH 255
#define PORT_NAME "COM5"

#include "robot_control.h"
#include "serial_port.hpp"
#include <QDebug>

RobotControl::RobotControl(QWidget *parent)
    : QMainWindow(parent)
{
	this->arduino = new SerialPort(PORT_NAME);
    ui.setupUi(this);
	connect(ui.claw, SIGNAL(clicked()), this, SLOT(activateClaw()));

	connect(ui.up, SIGNAL(pressed()), this, SLOT(moveUp()));
	connect(ui.down, SIGNAL(pressed()), this, SLOT(moveDown()));
	connect(ui.up, SIGNAL(released()), this, SLOT(moveUp()));
	connect(ui.down, SIGNAL(released()), this, SLOT(moveDown()));

	connect(ui.forwards, SIGNAL(pressed()), this, SLOT(moveForwards()));
	connect(ui.backwards, SIGNAL(pressed()), this, SLOT(moveBackwards()));
	connect(ui.forwards, SIGNAL(released()), this, SLOT(moveForwards()));
	connect(ui.backwards, SIGNAL(released()), this, SLOT(moveBackwards()));

	connect(ui.right, SIGNAL(pressed()), this, SLOT(moveRight()));
	connect(ui.left, SIGNAL(pressed()), this, SLOT(moveLeft()));
	connect(ui.right, SIGNAL(released()), this, SLOT(moveRight()));
	connect(ui.left, SIGNAL(released()), this, SLOT(moveLeft()));
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
	char data[] = "9";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}

void RobotControl::moveUp() {
	char data[] = "1";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}

void RobotControl::moveDown() {
	char data[] = "2";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}

void RobotControl::moveForwards() {
	char data[] = "3";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}

void RobotControl::moveBackwards() {
	char data[] = "4";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}

void RobotControl::moveRight() {
	char data[] = "5";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}

void RobotControl::moveLeft() {
	char data[] = "6";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}
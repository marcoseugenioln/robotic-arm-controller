#define SEND
#define MAX_DATA_LENGTH 255
#define PORT_NAME "COM5"

#include "robot_control.h"
#include "serial_port.hpp"

RobotControl::RobotControl(QWidget *parent)
    : QMainWindow(parent)
{
	this->arduino = new SerialPort(PORT_NAME);
    ui.setupUi(this);
	connect(ui.claw, SIGNAL(clicked()), this, SLOT(activateClaw()));
	connect(ui.verticalArmUp, SIGNAL(pressed()), this, SLOT(moveUp()));
	connect(ui.verticalArmDown, SIGNAL(pressed()), this, SLOT(moveDown()));
	connect(ui.verticalArmUp, SIGNAL(released()), this, SLOT(moveUp()));
	connect(ui.verticalArmDown, SIGNAL(released()), this, SLOT(moveDown()));
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
	char data[] = "CLAW\n";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}

void RobotControl::moveUp() {
	char data[] = "UP\n";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}

void RobotControl::moveDown() {
	char data[] = "DOWN\n";
	arduino->writeSerialPort(data, MAX_DATA_LENGTH);
}


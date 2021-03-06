#pragma once

#include <QtWidgets/QMainWindow>
#include <QThread>
#include "ui_robot_control.h"
#include "serial_port.hpp"

class RobotControl : public QMainWindow
{
    Q_OBJECT

public:
	SerialPort *arduino;
    RobotControl(QWidget *parent = Q_NULLPTR);
	QThread signal;

public slots:
	void activateClaw();
	void moveUp();
	void moveDown();
	void moveForwards();
	void moveBackwards();
	void moveRight();
	void moveLeft();

private:
    Ui::RobotControlClass ui;
	void autoConnect();
};

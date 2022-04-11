#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_robot_control.h"
#include "serial_port.hpp"

class RobotControl : public QMainWindow
{
    Q_OBJECT

public:
	SerialPort *arduino;
    RobotControl(QWidget *parent = Q_NULLPTR);

public slots:
	void activateClaw();
	void moveUp();
	void moveDown();

private:
    Ui::RobotControlClass ui;
	void autoConnect();
};

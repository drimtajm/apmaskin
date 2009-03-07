/*
 * IRSensor.cpp
 *
 *  Created on: 2009-mar-03
 *      Author: bege
 */

#include <iostream>
#include <list>
#include "IRSensor.h"
#include "CommandInterpreterModule.h"

using namespace std;

IRSensor::IRSensor() {
	// TODO Auto-generated constructor stub

}

IRSensor::~IRSensor() {
	// TODO Auto-generated destructor stub
}

void IRSensor::executeCommand(int cmdID, std::list<int> arguments) {
	switch (cmdID) {
	case CMD_IRPING:
		irping(arguments);
	}
}

void IRSensor::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("irping", CMD_IRPING, this);
}

int IRSensor::irping(std::list<int> arguments) {
//	if (arguments)
	std::cout << arguments.size() << std::endl;

	return 0;
}

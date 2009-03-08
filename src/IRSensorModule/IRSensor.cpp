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

void IRSensor::executeCommand(int cmdID, std::vector<int> arguments) {
	switch (cmdID) {
	case CMD_GETIRDATA:
		irping(arguments);
	}
}

void IRSensor::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("getirdata", CMD_GETIRDATA, this);
}

int IRSensor::irping(std::vector<int> arguments) {
	std::cout << "arguments: " << arguments.size() << std::endl;
	switch (arguments.size()) {
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
	return 0;
}

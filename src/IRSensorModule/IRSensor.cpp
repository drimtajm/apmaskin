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
		getirping(arguments);
	}
}

void IRSensor::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("getirping", CMD_GETIRDATA, this);
}

int IRSensor::getirping(const std::vector<int>& arguments) {
	switch (arguments.size()) {
	case 0:
		//Ping left and right
		break;
	case 1:
		//ping left or right
		break;
	case 2:
		break;
	default:
		break;
	}
	return 0;
}

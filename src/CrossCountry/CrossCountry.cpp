/*
 * CrossCountry.cpp
 *
 *  Created on: 2009-apr-08
 *      Author: bege
 */

#include "CrossCountry.h"

#include <iostream>
#include "CommandInterpreterModule.h"

CrossCountry::CrossCountry(EventGenerator& irSensor) {
	// TODO Auto-generated constructor stub

}

CrossCountry::~CrossCountry() {
	// TODO Auto-generated destructor stub
}

void CrossCountry::executeCommand(int cmdID, std::vector<int> arguments) {
	switch (cmdID) {
	case CMD_CROSSCOUNTRY:
		std::cout << "Cross country competition started" << std::endl;
	}
}

void CrossCountry::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("crosscountry", CMD_CROSSCOUNTRY, this);
}

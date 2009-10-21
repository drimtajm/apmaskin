/*
 * SteeringModule.cpp
 *
 *  Created on: 2009-okt-21
 *      Author: bege
 */

#include "SteeringModule.h"

SteeringModule::SteeringModule(CommandInterpreter& commandInterpreter, SerialPort& saberTooth) :
	commandInterpreter(commandInterpreter), saberTooth(saberTooth) {
}

void SteeringModule::executeCommand(int cmdID, std::vector<int> arguments) {
	switch(cmdID) {
	case CMD_SETSPEED:
		saberTooth.write(NULL, 1);
	}
}

void SteeringModule::registerCommands() {
	commandInterpreter.registerCommand("setspeed", CMD_SETSPEED, this);
}






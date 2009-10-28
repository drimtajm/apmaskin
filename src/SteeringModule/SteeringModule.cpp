/*
 * SteeringModule.cpp
 *
 *  Created on: 2009-okt-21
 *      Author: bege
 */

#include <cassert>
#include "SteeringModule.h"

SteeringModule::SteeringModule(CommandInterpreter& commandInterpreter, MotorController& motorController) :
	commandInterpreter(commandInterpreter), motorController(motorController) {
}

void SteeringModule::executeCommand(int cmdID, std::vector<int> arguments) {
	switch(cmdID) {
	case CMD_SETSPEED:
		motorController.setSpeed(arguments[0]);
		break;
	case CMD_SETTURNRATE:
		motorController.setTurnRate(arguments[0]);
		break;
	default:
		assert(false && "Invalid command given to SteeringModule");
	}
}

void SteeringModule::registerCommands() {
	commandInterpreter.registerCommand("setspeed", CMD_SETSPEED, this);
	commandInterpreter.registerCommand("setturnrate", CMD_SETTURNRATE, this);
}






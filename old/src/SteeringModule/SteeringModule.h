/*
 * SteeringModule.h
 *
 *  Created on: 2009-okt-21
 *      Author: bege
 */

#ifndef STEERINGMODULE_H_
#define STEERINGMODULE_H_
#include "CommandServer.h"
#include "CommandInterpreter.h"
#include "MotorController.h"

class SteeringModule : public CommandServer {
public:
	SteeringModule(CommandInterpreter& commandInterpreter, MotorController& motorController);
	void executeCommand(int cmdID, std::vector<int> arguments);
	void registerCommands();
private:
	CommandInterpreter& commandInterpreter;
	MotorController& motorController;

	typedef enum {
		CMD_SETSPEED,
		CMD_SETTURNRATE
	} SteeringCommand;

};

#endif /* STEERINGMODULE_H_ */

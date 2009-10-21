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
#include "../hardware/SerialPort.h"

class SteeringModule : public CommandServer {
public:
	SteeringModule(CommandInterpreter& commandInterpreter, SerialPort& saberTooth);
	void executeCommand(int cmdID, std::vector<int> arguments);
	void registerCommands();
private:
	CommandInterpreter &commandInterpreter;
	SerialPort& saberTooth;

	typedef enum {
		CMD_SETSPEED
	} SteeringCommand;

};

#endif /* STEERINGMODULE_H_ */

/*
 * IRSensor.h
 *
 *  Created on: 2009-mar-03
 *      Author: bege
 */

#ifndef IRSENSOR_H_
#define IRSENSOR_H_

#include "EventGenerator.h"
#include "CommandServer.h"
#include <list>

class IRSensor: /*public EventGenerator,*/ public CommandServer {
public:
	IRSensor();
	virtual void executeCommand(int cmdID, std::vector<int> arguments);
	virtual void registerCommands();

	virtual ~IRSensor();

private:
	typedef enum {
		CMD_GETIRDATA
	} IRSensorCommand;

	int getirping(const std::vector<int>& arguments);
};

#endif /* IRSENSOR_H_ */

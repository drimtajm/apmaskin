/*
 * CommandInterpreter.h
 *
 *  Created on: 2009-okt-21
 *      Author: bege
 */

#ifndef COMMANDINTERPRETER_H_
#define COMMANDINTERPRETER_H_

#include <string>

class CommandServer;

class CommandInterpreter {
public:
	virtual ~CommandInterpreter() {};
	virtual void registerCommand(std::string commandString, int cmdID, CommandServer * const cmdServer) = 0;

};

#endif /* COMMANDINTERPRETER_H_ */

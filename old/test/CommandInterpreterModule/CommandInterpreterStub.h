/*
 * CommandInterpreterStub.h
 *
 *  Created on: 2009-okt-28
 *      Author: bege
 */

#ifndef COMMANDINTERPRETERSTUB_H_
#define COMMANDINTERPRETERSTUB_H_

#include "CommandInterpreter.h"
#include <string>
#include <list>

class CommandInterpreterStub : public CommandInterpreter {
public:
	CommandInterpreterStub() { }
	struct Command {
		std::string name;
		int id;
	};
	std::list<Command> commands;

	void registerCommand(std::string commandString, int cmdID, CommandServer * const cmdServer) {
		Command cmd;
		cmd.name = commandString;
		cmd.id = cmdID;
		commands.push_back(cmd);
	}

	int idForRegisteredCommand(const std::string& cmd) {
		for(std::list<Command>::iterator iter = commands.begin();
				iter != commands.end(); ++iter) {
			if (iter->name == cmd)
				return iter->id;
		}
		return -1;
	}
};

#endif /* COMMANDINTERPRETERSTUB_H_ */

#include "CommandInterpreterModule.h"
#include "ICommandServer.h"

#include <iostream>
#include <pthread.h>
#include <string>
#include <sstream>
using namespace std;

/*****************
 * class members *
 *****************/

CommandInterpreterModule* CommandInterpreterModule::ciInstance = NULL;

/*********************
 * Private functions *
 *********************/

CommandInterpreterModule::CommandInterpreterModule() :
	running(true) {
}

/********************
 * Public functions *
 ********************/

CommandInterpreterModule::~CommandInterpreterModule() {
	for(CommandMap::iterator it = registeredCommands.begin(); it != registeredCommands.end(); ++it) {
		delete it->second;
	}
}

CommandInterpreterModule* CommandInterpreterModule::getInstance() {
	if (ciInstance == NULL)
		ciInstance = new CommandInterpreterModule();
	return ciInstance;
}

void CommandInterpreterModule::registerCommand(string commandString, int cmdID, ICommandServer * const cmdServer) {
	CommandData *cmdData = new CommandData(cmdID, cmdServer);
	registeredCommands.insert(pair<string, CommandData*> (commandString, cmdData));
}

void CommandInterpreterModule::executeCommand(int cmdID, std::list<int> arguments) {
	switch (cmdID) {
	case CMD_HELP:
		cout << "Command list: " << endl;
		for (CommandMap::iterator it = registeredCommands.begin(); it != registeredCommands.end(); ++it) {
			cout << "\t" << it->first << endl;
		}
		break;
	case CMD_EXIT:
		running = false;
		cout << "Goodbye!" << endl;
		break;
	}
}

void CommandInterpreterModule::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("help", CMD_HELP, this);
	ci->registerCommand("exit", CMD_EXIT, this);
}

void CommandInterpreterModule::start() {
	string inputLine;
	CommandMap::iterator cmdIterator;
	CommandData *cmdData;
	ICommandServer *cmdServer;
	int cmdID;
	list<int> args;
	string command;

	while (running) {
		cout << "> ";
		getline(cin, inputLine);
		extractCommandAndParameters(inputLine, command, args);
		cmdIterator = registeredCommands.find(command);
		if (cmdIterator != registeredCommands.end()) {
			cmdData = cmdIterator->second;
			cmdServer = cmdData->getCmdServer();
			cmdID = cmdData->getCmdID();
			cmdServer->executeCommand(cmdID, list<int> ());
		} else {
			cout << "ERROR: Command does not exist." << endl;
		}
	}
}

void CommandInterpreterModule::destroy() {
	delete ciInstance;
	ciInstance = NULL;
}

/**
 * Assume [ ]cmd[ ][arg1[ ][,[ ]arg2]]
 * [ ] is none or several whitespace
 */
int CommandInterpreterModule::extractCommandAndParameters(string inputLine, string &command, list<int> &args) {
	int argInt;
	istringstream ss;
	unsigned int cutAt;
	const string whitespaces(" ");
	const string delimiter(",");

	string::size_type beginCmd = inputLine.find_first_not_of(whitespaces);
	string::size_type endCmd = inputLine.find_first_of(whitespaces, beginCmd);
	if(endCmd > beginCmd)
		command = inputLine.substr(beginCmd, endCmd - beginCmd);
	else
		command = string();

	args.clear();
	if(endCmd != inputLine.npos) {
		inputLine = inputLine.substr(endCmd);
		while((cutAt = inputLine.find_first_of(delimiter)) != inputLine.npos) {
			if(cutAt > 0) {
				ss.clear();
				ss.str(inputLine.substr(0, cutAt));
				ss >> argInt;
				if(!ss.fail())
					args.push_back(argInt);
			}
			inputLine = inputLine.substr(cutAt+1);
		}
		if(inputLine.length() > 0) {
			ss.clear();
			ss.str(inputLine);
			ss >> argInt;
			args.push_back(argInt);
		}
	}
	return args.size();
}

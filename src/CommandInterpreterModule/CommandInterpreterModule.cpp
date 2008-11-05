#include "CommandInterpreterModule.h"
#include "ICommandServer.h"

#include <iostream>
#include <pthread.h>
#include <string>

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
	string inputString;
	CommandMap::iterator cmdIterator;
	CommandData *cmdData;
	ICommandServer *cmdServer;
	int cmdID;

	while (running) {
		cout << "> ";
		getline(cin, inputString);
		cmdIterator = registeredCommands.find(inputString);
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

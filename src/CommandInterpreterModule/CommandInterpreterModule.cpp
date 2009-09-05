#include "CommandInterpreterModule.h"
#include "CommandServer.h"

#include <iostream>
#include <string>
#include <sstream>
#include <boost/spirit/core.hpp>
#include "CommandParser.h"

using namespace std;
using namespace boost::spirit;


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

void CommandInterpreterModule::registerCommand(string commandString, int cmdID, CommandServer * const cmdServer) {
	CommandData *cmdData = new CommandData(cmdID, cmdServer);
	registeredCommands.insert(pair<string, CommandData*> (commandString, cmdData));
}

void CommandInterpreterModule::executeCommand(int cmdID, std::vector<int> arguments) {
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
	CommandServer *cmdServer;
	int cmdID;
	vector<int> args;
	string command;

	while (running) {
		cout << "> ";
		cin.clear();
		getline(cin, inputLine);
		extractCommandAndParameters(inputLine, command, args);
		cmdIterator = registeredCommands.find(command);
		if (cmdIterator != registeredCommands.end()) {
			cmdData = cmdIterator->second;
			cmdServer = cmdData->getCmdServer();
			cmdID = cmdData->getCmdID();
			cmdServer->executeCommand(cmdID, args);
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
void CommandInterpreterModule::extractCommandAndParameters(string inputLine, string &command, vector<int> &args) {
	args.clear();
	CommandParser parser(command, args);
	parse_info<> info = parse(inputLine.c_str(), parser, space_p);
}

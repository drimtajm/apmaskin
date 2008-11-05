#ifndef COMMANDINTERPRETERMODULE_H_
#define COMMANDINTERPRETERMODULE_H_

#include "ICommandServer.h"
#include <string>
#include <map>

class CommandInterpreterModule: public ICommandServer {
private:
	class CommandData;
	typedef std::map<std::string, CommandData *> CommandMap;
	typedef enum {
		CMD_HELP, CMD_EXIT
	} CommandInterpreterCommand;

	static CommandInterpreterModule *ciInstance;
	bool running;
	CommandMap registeredCommands;
protected:
	CommandInterpreterModule();
	CommandInterpreterModule(const CommandInterpreterModule&);
	CommandInterpreterModule& operator=(const CommandInterpreterModule&);
public:
	static CommandInterpreterModule* getInstance();
	static void destroy();
	void executeCommand(int cmdID, std::list<int> arguments); //ICommandServer
	void registerCommands(); //ICommandServer
	virtual ~CommandInterpreterModule();
	void registerCommand(std::string commandString, int cmdID, ICommandServer * const cmdServer);
	void start();
};

class CommandInterpreterModule::CommandData {
private:
	ICommandServer* const m_cmdServer;
	int m_cmdID;
public:
	CommandData(int cmdID, ICommandServer * const cmdServer) : m_cmdServer(cmdServer), m_cmdID(cmdID) {};
	int getCmdID() {
		return m_cmdID;
	}
	ICommandServer* const getCmdServer() {
		return m_cmdServer;
	}
};

#endif /*COMMANDINTERPRETERMODULE_H_*/

#ifndef ICOMMANDSERVER_H_
#define ICOMMANDSERVER_H_

#include <list>

class ICommandServer {
public:
	virtual void executeCommand(int cmdID, std::list<int> arguments) = 0;
	virtual void registerCommands() = 0;
};

#endif /* ICOMMANDSERVER_H_ */

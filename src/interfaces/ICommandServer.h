#ifndef ICOMMANDSERVER_H_
#define ICOMMANDSERVER_H_

#include <vector>

class ICommandServer {
public:
	virtual void executeCommand(int cmdID, std::vector<int> arguments) = 0;
	virtual void registerCommands() = 0;
	virtual ~ICommandServer() {};
};

#endif /* ICOMMANDSERVER_H_ */

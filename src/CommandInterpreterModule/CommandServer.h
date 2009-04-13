#ifndef CommandServer_H_
#define CommandServer_H_

#include <vector>

class CommandServer {
public:
	/**
	 * This method is called from the command interpreter.
	 */
	virtual void executeCommand(int cmdID, std::vector<int> arguments) = 0;

	/**
	 * This method should register all commands in the command interpreter.
	 */
	virtual void registerCommands() = 0;
	virtual ~CommandServer() {};
};

#endif /* CommandServer_H_ */

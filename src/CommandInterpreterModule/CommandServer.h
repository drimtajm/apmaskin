#ifndef CommandServer_H_
#define CommandServer_H_

#include <vector>

class CommandServer {
public:
	virtual void executeCommand(int cmdID, std::vector<int> arguments) = 0;
	virtual void registerCommands() = 0;
	virtual ~CommandServer() {};
};

#endif /* CommandServer_H_ */

#ifndef CAMERAMODULE_H_
#define CAMERAMODULE_H_

#include "Event.h"
#include "EventListener.h"
#include "EventGenerator.h"
#include "CommandServer.h"

#include "BoundedBuffer.h"
#include "CommandInterpreterModule.h"
#include <list>

class CameraModule : public EventGenerator, CommandServer {
private:
	CommandInterpreter& commandInterpreter;
	std::list<EventListener*> positionErrorListeners;
	std::list<EventListener*> intersectionFoundListeners;
	std::list<EventListener*> numberFoundListeners;
	BoundedBuffer<Event>* sendQueue;
public:
	typedef enum {
		CMD_SNAPSHOT,
		CMD_CALIBRATE
	} CameraCommand;

	CameraModule(CommandInterpreter& commandInterpreter);
	void startSendEvents(BoundedBuffer<Event>& eventQueue);							//EventGenerator
	void stopSendEvents() {};												//EventGenerator
	void executeCommand(int cmdID, std::vector<int> arguments); 			//CommandServer
	void registerCommands();											//CommandServer
};

#endif /* CAMERAMODULE_H_ */

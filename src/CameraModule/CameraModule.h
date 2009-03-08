#ifndef CAMERAMODULE_H_
#define CAMERAMODULE_H_

#include "IEvent.h"
#include "IEventListener.h"
#include "IEventGenerator.h"
#include "ICommandServer.h"

#include <list>

using namespace std;

class CameraModule : public IEventGenerator, ICommandServer {
private:
	list<IEventListener*> positionErrorListeners;
	list<IEventListener*> intersectionFoundListeners;
	list<IEventListener*> numberFoundListeners;
public:
	typedef enum {
		CMD_SNAPSHOT,
		CMD_CALIBRATE
	} CameraCommand;

	CameraModule();
	void addEventListener(IEvent::EventType type, IEventListener* listener);	//IEventGenerator
	void removeEventListener(IEvent::EventType type, IEventListener* listener); //IEventGenerator
	void executeCommand(int cmdID, std::vector<int> arguments); 			//ICommandServer
	void registerCommands();											//ICommandServer
};

#endif /* CAMERAMODULE_H_ */

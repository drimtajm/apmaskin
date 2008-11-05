#include "CameraModule.h"
#include "CommandInterpreterModule.h"
#include <iostream>

using namespace std;

void CameraModule::addEventListener(enum IEvent::EventType type, IEventListener* listener) {
}


void CameraModule::removeEventListener(enum IEvent::EventType type, IEventListener* listener) {
}

void CameraModule::executeCommand(int cmdID, std::list<int> arguments) {

}


void CameraModule::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("savesnapshot", CMD_SNAPSHOT, this);
}

CameraModule::CameraModule() {
}

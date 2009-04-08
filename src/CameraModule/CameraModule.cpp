#include <iostream>
#include "CameraModule.h"
#include "CommandInterpreterModule.h"

using namespace std;

void CameraModule::setMessageQueue(EventQueue* eventQueue) {
	this->eventQueue = eventQueue;
}

void CameraModule::executeCommand(int cmdID, std::vector<int> arguments) {

}


void CameraModule::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("savesnapshot", CMD_SNAPSHOT, this);
}

CameraModule::CameraModule() : eventQueue(NULL) {
}


#include <iostream>
#include "CameraModule.h"
#include "CommandInterpreterModule.h"

void CameraModule::startSendEvents(BoundedBuffer<Event>& eventQueue) {
	sendQueue = &eventQueue;
}


void CameraModule::executeCommand(int cmdID, std::vector<int> arguments) {
}

void CameraModule::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("savesnapshot", CMD_SNAPSHOT, this);
}

CameraModule::CameraModule() : sendQueue(NULL) {
}


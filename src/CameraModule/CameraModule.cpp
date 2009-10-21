#include <iostream>
#include "CameraModule.h"
#include "CommandInterpreterModule.h"

CameraModule::CameraModule(CommandInterpreterModule& ci) :
	commandInterpreter(ci), sendQueue(NULL) {
}

void CameraModule::startSendEvents(BoundedBuffer<Event>& eventQueue) {
	sendQueue = &eventQueue;
}


void CameraModule::executeCommand(int cmdID, std::vector<int> arguments) {
}

void CameraModule::registerCommands() {
	commandInterpreter.registerCommand("savesnapshot", CMD_SNAPSHOT, this);
}



#include "CameraModule.h"
#include "CommandInterpreterModule.h"
#include <iostream>

using namespace std;

void CameraModule::addEventListener(enum Event::EventType type, EventListener* listener) {
}


void CameraModule::removeEventListener(enum Event::EventType type, EventListener* listener) {
}

void CameraModule::executeCommand(int cmdID, std::vector<int> arguments) {

}


void CameraModule::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("savesnapshot", CMD_SNAPSHOT, this);
}

CameraModule::CameraModule() {
}


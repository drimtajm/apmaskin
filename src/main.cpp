#include <iostream>
#include "CameraModule.h"
#include "CommandInterpreterModule.h"

using namespace std;

int main(int argc, char *argv[]) {
	CameraModule camera;
	CommandInterpreterModule *commandInterpreter = CommandInterpreterModule::getInstance();
	commandInterpreter->registerCommands();
	camera.registerCommands();
	commandInterpreter->start();
	CommandInterpreterModule::destroy();

	return 0;
}

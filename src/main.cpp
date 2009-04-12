#include <iostream>
#include "CameraModule.h"
#include "CommandInterpreterModule.h"
#include "IRSensor.h"
#include "CrossCountry/CrossCountry.h"

using namespace std;

int main(int argc, char *argv[]) {
	CameraModule camera;
	IRSensor irSensor;
	CommandInterpreterModule& commandInterpreter = *CommandInterpreterModule::getInstance();

	CrossCountry crossCountry(irSensor);
	crossCountry.registerCommands();
	commandInterpreter.registerCommands();
	camera.registerCommands();
	irSensor.registerCommands();
	commandInterpreter.start();
	CommandInterpreterModule::destroy();

	return 0;
}

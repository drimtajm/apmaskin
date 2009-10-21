#include <iostream>
#include "CameraModule.h"
#include "CommandInterpreterModule.h"
#include "IRSensor.h"
#include "CrossCountry/CrossCountry.h"
#include "SteeringModule/SteeringModule.h"

using namespace std;

int main(int argc, char *argv[]) {
	CommandInterpreterModule commandInterpreter;
	CameraModule camera(commandInterpreter);
	IRSensor irSensor(commandInterpreter);

	CrossCountry crossCountry(commandInterpreter, irSensor);
	SteeringModule steering;
	crossCountry.registerCommands();
	commandInterpreter.registerCommands();
	camera.registerCommands();
	irSensor.registerCommands();
	steering.registerCommands();
	commandInterpreter.start();
	CommandInterpreterModule::destroy();

	return 0;
}

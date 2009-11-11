#include <iostream>
#include "CameraModule.h"
#include "CommandInterpreterModule.h"
#include "IRSensor.h"
#include "CrossCountry/CrossCountry.h"
#include "SteeringModule/SteeringModule.h"
#include "MotorControllerImpl.h"

using namespace std;

int main(int argc, char *argv[]) {
	CommandInterpreterImpl commandInterpreter;
	CameraModule camera(commandInterpreter);
	IRSensor irSensor(commandInterpreter);
	MotorControllerImpl motorController;
	SteeringModule steering(commandInterpreter, motorController);
	CrossCountry crossCountry(commandInterpreter, irSensor);

	crossCountry.registerCommands();
	commandInterpreter.registerCommands();
	camera.registerCommands();
	irSensor.registerCommands();
	steering.registerCommands();
	commandInterpreter.start();

	return 0;
}

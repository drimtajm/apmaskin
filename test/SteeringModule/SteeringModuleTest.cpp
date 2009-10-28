/*
 * SteeringModuleTest.cpp
 *
 *  Created on: 2009-okt-21
 *      Author: bege
 */

#include "gtest.h"
#include "SteeringModule.h"
#include "CommandInterpreterModule.h"
#include "MotorController.h"
#include "MotorControllerStub.h"
#include "../CommandInterpreterModule/CommandInterpreterStub.h"

using namespace std;


class SteeringModuleTest : public testing::Test  {
protected:
	SteeringModuleTest()  {}
	CommandInterpreterStub ci;
	MotorControllerStub motorController;
};

TEST_F (SteeringModuleTest, registerSetspeedCommandInCommandInterpreter) {
	SteeringModule steeringModule(ci, motorController);
	steeringModule.registerCommands();
	const int SETSPEED_ID = ci.idForRegisteredCommand("setspeed");
	ASSERT_NE(-1, SETSPEED_ID);
}

TEST_F (SteeringModuleTest, registerSetTurnRateCommandInCommandInterpreter) {
	SteeringModule steeringModule(ci, motorController);
	steeringModule.registerCommands();
	const int SETTURNRATE_ID = ci.idForRegisteredCommand("setturnrate");
	ASSERT_NE(-1, SETTURNRATE_ID);

}

TEST_F(SteeringModuleTest, setSpeedShouldDelegateToMotorController) {
	SteeringModule steeringModule(ci, motorController);
	steeringModule.registerCommands();
	const int SETSPEED_ID = ci.idForRegisteredCommand("setspeed");
	vector<int> arguments;
	arguments.push_back(5);
	steeringModule.executeCommand(SETSPEED_ID, arguments);
	ASSERT_TRUE(motorController.setSpeedIsCalled);
	ASSERT_EQ(5, motorController.speed);
}

TEST_F(SteeringModuleTest, setTurnRateShouldDelegateToMotorController) {
	SteeringModule steeringModule(ci, motorController);
	steeringModule.registerCommands();
	const int SETTURNRATE_ID = ci.idForRegisteredCommand("setturnrate");
	vector<int> arguments;
	arguments.push_back(10);
	steeringModule.executeCommand(SETTURNRATE_ID, arguments);
	ASSERT_TRUE(motorController.setTurnRateIsCalled);
	ASSERT_EQ(10, motorController.turnRate);
}


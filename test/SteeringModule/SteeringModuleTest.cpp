/*
 * SteeringModuleTest.cpp
 *
 *  Created on: 2009-okt-21
 *      Author: bege
 */

#include "gtest.h"
#include "../../src/SteeringModule/SteeringModule.h"
#include "CommandInterpreterModule.h"
#include <string>
#include "../../src/hardware/SerialPort.h"
using namespace std;

class CommandInterpreterStub : public CommandInterpreter {
public:
	CommandInterpreterStub() : registeredCommandId(-1) { }

	string registeredCommand;
	int registeredCommandId;

	void registerCommand(std::string commandString, int cmdID, CommandServer * const cmdServer) {
		registeredCommand = commandString;
		registeredCommandId = cmdID;
	}
};

class SerialPortStub : public SerialPort {
public:
	SerialPortStub() : writtenBytes(0) {}
	void write(char data, unsigned int numberOfBytes) {
		writtenBytes += numberOfBytes;
	}
	int writtenBytes;
};

class SteeringModuleTest : public testing::Test  {
protected:
	SteeringModuleTest()  {}
	CommandInterpreterStub ci;
	SerialPortStub serialPort;
};

TEST_F (SteeringModuleTest, registerSetspeedCommandInCommandInterpreter) {
	SteeringModule steeringModule(ci, serialPort);
	steeringModule.registerCommands();
	ASSERT_EQ("setspeed", ci.registeredCommand);
}

TEST_F(SteeringModuleTest, setspeedShouldWriteAByteToSabertooth) {
	SteeringModule steeringModule(ci, serialPort);
	steeringModule.registerCommands();
	ASSERT_EQ("setspeed", ci.registeredCommand);
	const int SETSTEERING_ID = ci.registeredCommandId;
	vector<int> arguments;
	arguments.push_back(0);
	steeringModule.executeCommand(SETSTEERING_ID, arguments);
	ASSERT_GT(serialPort.writtenBytes, 0);
}



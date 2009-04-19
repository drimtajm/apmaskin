/*
 * IRSensor.cpp
 *
 *  Created on: 2009-mar-03
 *      Author: bege
 */

#include <iostream>
#include <list>
#include "IRSensor.h"
#include "CommandInterpreterModule.h"
#include "IRSensorReader.h"
#include "Thread.h"

using namespace std;

IRSensor::IRSensor() :
	readerThread(NULL), reader(NULL) {
}

IRSensor::~IRSensor() {
	stopSendEvents();
}

void IRSensor::executeCommand(int cmdID, std::vector<int> arguments) {
	switch (cmdID) {
	case CMD_GETIRDATA:
		cmdGetIRPing(arguments);
	}
}

void IRSensor::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("getirping", CMD_GETIRDATA, this);
}

int IRSensor::cmdGetIRPing(const std::vector<int>& arguments) {
	switch (arguments.size()) {
	case 0:
		//Ping left and right
		break;
	case 1:
		//ping left or right
		break;
	case 2:
		break;
	default:
		break;
	}
	return 0;
}

void IRSensor::startSendEvents(BoundedBuffer<Event>& eventQueue) {
	delete reader;
	reader = new IRSensorReader(eventQueue);
	readerThread = new Thread(reader);
	readerThread->start();
}

void IRSensor::stopSendEvents() {
	if(reader != NULL) {
		reader->stop();
		readerThread->join();
		delete readerThread;
		delete reader;
		reader = NULL;
		readerThread = NULL;
	}
}

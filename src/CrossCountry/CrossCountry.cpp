/*
 * CrossCountry.cpp
 *
 *  Created on: 2009-apr-08
 *      Author: bege
 */

#include "CrossCountry.h"

#include <iostream>
#include "CommandInterpreterModule.h"
#include "EventQueue.h"
#include "IREvent.h"

using std::cout;
using std::endl;

void CrossCountry::cmdCrossCountry(const std::vector<int>& arguments) {
	if (arguments.size() == 0) {
		startCrossCountry();
	} else if (arguments.size() == 1 && arguments[0] == 0) {
		stopCrossCountry();
	}
}
void CrossCountry::startCrossCountry() {
	Event const * event;
	EventQueue eventQueue(5);
	irSensor.startSendEvents(eventQueue);
	std::cout << "Cross country competition started" << std::endl;
	for (int i = 0; i < 15; ++i) {
		event = eventQueue.receive();
		if (event->getEventType() == Event::INFRARED_DISTANCE_EVENT) {
			IREvent const * e = (IREvent*) event;
			cout << e->getValue() << endl;
		}
		delete event;
	}
	std::cout << "Cross country competition ended" << std::endl;
}

void CrossCountry::stopCrossCountry() {
	irSensor.stopSendEvents();
	cout << "stopping" << endl;
}

void CrossCountry::executeCommand(int cmdID, std::vector<int> arguments) {
	switch (cmdID) {
	case CMD_CROSSCOUNTRY:
		cmdCrossCountry(arguments);
	}
}

void CrossCountry::registerCommands() {
	CommandInterpreterModule *ci = CommandInterpreterModule::getInstance();
	ci->registerCommand("crosscountry", CMD_CROSSCOUNTRY, this);
}

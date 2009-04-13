/*
 * CrossCountry.cpp
 *
 *  Created on: 2009-apr-08
 *      Author: bege
 */

#include "CrossCountry.h"

#include <iostream>
#include "CommandInterpreterModule.h"
#include "BoundedBuffer.h"
#include "IREvent.h"
#include "Thread.h"

using std::cout;
using std::endl;

CrossCountry::CrossCountry(EventGenerator& irSensor) : irSensor(irSensor), thread(NULL), running(false) {
	pthread_mutex_init(&mutex, NULL);
};

CrossCountry::~CrossCountry() {
	if(thread != NULL) {
		delete thread;
	}
	pthread_mutex_destroy(&mutex);
}

void CrossCountry::cmdCrossCountry(const std::vector<int>& arguments) {
	if (arguments.size() == 0) {
		startCrossCountry();
	} else if (arguments.size() == 1 && arguments[0] == 0) {
		stopCrossCountry();
	}
}

void CrossCountry::startCrossCountry() {
	if(thread != NULL) {
		delete thread;
	}
	setRunning(true);
	thread = new Thread(this);
	thread->start();
}

void CrossCountry::stopCrossCountry() {
	setRunning(false);
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

void CrossCountry::run() {
	Event const * event;
	BoundedBuffer<Event> eventQueue(5);
	irSensor.startSendEvents(eventQueue);
	std::cout << "Cross country competition started" << std::endl;
	while(getRunning()) {
		event = eventQueue.receive();
		if (event->getEventType() == Event::INFRARED_DISTANCE_EVENT) {
			IREvent const * e = (IREvent*) event;
			cout << e->getValue() << endl;
		}
		delete event;
	}
	irSensor.stopSendEvents();
	std::cout << "Cross country competition ended" << std::endl;
}

inline void CrossCountry::setRunning(bool value) {
	pthread_mutex_lock(&mutex);
	running = value;
	pthread_mutex_unlock(&mutex);

}

inline bool const CrossCountry::getRunning() {
	pthread_mutex_lock(&mutex);
	bool const value = running;
	pthread_mutex_unlock(&mutex);
	return value;
}

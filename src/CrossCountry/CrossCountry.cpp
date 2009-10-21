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
#include "EventGenerator.h"
#include "IREvent.h"
#include "Thread.h"

using std::cout;
using std::endl;

CrossCountry::CrossCountry(CommandInterpreter& ci, EventGenerator& irSensor) :
	commandInterpreter(ci), irSensor(irSensor), running(false) {
	pthread_mutex_init(&mutex, NULL);
}
;

CrossCountry::~CrossCountry() {
	pthread_mutex_destroy(&mutex);
}

/**
 * Do stuff depending on arguments.
 */
void CrossCountry::cmdCrossCountry(const std::vector<int>& arguments) {
	if (arguments.size() == 0) {
		startCrossCountry();
	} else if (arguments.size() == 1 && arguments[0] == 0) {
		stopCrossCountry();
	}
}

/**
 * Start up the thread that listens to data from the IRSensor if and only if
 * the thread isn't already started.
 */
void CrossCountry::startCrossCountry() {
	if (!isRunning()) {
		setRunning(true);
		Thread(this).start();
	} else {
		cout << "Already in crosscountry mode" << endl;
	}
}

/**
 * Abort the receiving loop in run()
 */
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
	commandInterpreter.registerCommand("crosscountry", CMD_CROSSCOUNTRY, this);
}

void CrossCountry::run() {
	Event const * event;
	BoundedBuffer<Event> eventQueue(5);
	irSensor.startSendEvents(eventQueue);
	cout << "Cross country competition started" << endl;
	while (isRunning()) {
		event = eventQueue.receive();
		if (event->getEventType() == Event::INFRARED_DISTANCE_EVENT) {
			const IREvent& e = *static_cast<const IREvent*>( event);
			cout << e.getValue() << endl;
		}
		delete event;
	}
	irSensor.stopSendEvents();
	cout << "Cross country competition ended" << endl;
}

inline void CrossCountry::setRunning(bool value) {
	pthread_mutex_lock(&mutex);
	running = value;
	pthread_mutex_unlock(&mutex);

}

inline bool const CrossCountry::isRunning() {
	pthread_mutex_lock(&mutex);
	bool const value = running;
	pthread_mutex_unlock(&mutex);
	return value;
}

/*
 * IRSensorReader.cpp
 *
 *  Created on: 2009-apr-09
 *      Author: bege
 */

#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include "IRSensorReader.h"
#include "IREvent.h"

using std::cout;
using std::endl;

void IRSensorReader::run() {
	running = true;
	for (int i = 0; i < 15 && running; ++i) {
		IREvent * newEvent = new IREvent(i);
		usleep(TIME_TO_SLEEP);
		sendQueue.send(newEvent);
	}
}

void IRSensorReader::stop() {
	running = false;
}

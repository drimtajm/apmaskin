/*
 * IRSensorReader.h
 *
 *  Created on: 2009-apr-09
 *      Author: bege
 */

#ifndef IRSENSORREADER_H_
#define IRSENSORREADER_H_

#include "EventQueue.h"
#include "Runnable.h"
#include "Event.h"

class IRSensorReader : public Runnable {
public:
	explicit IRSensorReader(EventQueue<Event>& eventQueue) : sendQueue(eventQueue), running(false) {};
	virtual ~IRSensorReader() {};
	void run();
	void stop();
protected:
	static const int TIME_TO_SLEEP = 1000000;
	EventQueue<Event>& sendQueue;
	bool running; //TODO: Should have mutex
};

#endif /* IRSENSORREADER_H_ */

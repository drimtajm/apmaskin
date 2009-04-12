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

class IRSensorReader : public Runnable {
public:
	explicit IRSensorReader(EventQueue& eventQueue) : sendQueue(eventQueue), running(false) {};
	virtual ~IRSensorReader() {};
	void run();
	void stop();
protected:
	static const int TIME_TO_SLEEP = 1000000;
	EventQueue& sendQueue;
	bool running;
};

#endif /* IRSENSORREADER_H_ */

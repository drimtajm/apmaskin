/*
 * IRSensorReader.h
 *
 *  Created on: 2009-apr-09
 *      Author: bege
 */

#ifndef IRSENSORREADER_H_
#define IRSENSORREADER_H_

#include "BoundedBuffer.h"
#include "Runnable.h"
#include "Event.h"

class IRSensorReader : public Runnable {
public:
	explicit IRSensorReader(BoundedBuffer<Event>& eventQueue) : sendQueue(eventQueue), running(false) {};
	virtual ~IRSensorReader() {};
	void run();
	void stop();
protected:
	static const int TIME_TO_SLEEP = 1000000;
	BoundedBuffer<Event>& sendQueue;
	bool running; //TODO: Should have mutex
};

#endif /* IRSENSORREADER_H_ */

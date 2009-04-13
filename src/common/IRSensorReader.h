/*
 * IRSensorReader.h
 *
 *  Created on: 2009-apr-09
 *      Author: bege
 */

#ifndef IRSENSORREADER_H_
#define IRSENSORREADER_H_

#include "Runnable.h"
class Event;

template<class T>
class BoundedBuffer;

class IRSensorReader : public Runnable {
public:
	/**
	 * Read sensor data will be available on eventQueue.
	 */
	explicit IRSensorReader(BoundedBuffer<Event>& eventQueue) : sendQueue(eventQueue), running(false) {};
	virtual ~IRSensorReader() {};
	void run();		//Runnable

	/**
	 * Terminate the thread.
	 */
	void stop();
protected:
	static const int TIME_TO_SLEEP = 1000000;
	BoundedBuffer<Event>& sendQueue;
	bool running; //TODO: Should have mutex
};

#endif /* IRSENSORREADER_H_ */

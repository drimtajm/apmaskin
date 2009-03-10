/*
 * EventBuffer.h
 *
 *  Created on: 2009-mar-08
 *      Author: bege
 */

#ifndef EVENTBUFFER_H_
#define EVENTBUFFER_H_

#include <pthread.h>

class IEvent;

class EventBuffer {
private:

public:
	EventBuffer(int const bufferSize);
	virtual ~EventBuffer();
	void send(IEvent const * const event);
	IEvent* receive();
private:
	pthread_mutex_t mutex;
};

#endif /* EVENTBUFFER_H_ */

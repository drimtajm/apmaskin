/*
 * EventBuffer.h
 *
 *  Created on: 2009-mar-08
 *      Author: bege
 */

#ifndef EVENTBUFFER_H_
#define EVENTBUFFER_H_

#include <pthread.h>
#include <semaphore.h>
#include <vector>

class Event;

class EventBuffer {
private:
	Event const * ev;
public:
	EventBuffer(int const bufferSize);
	virtual ~EventBuffer();
	void send(Event const * const event);
	Event const * receive();
private:
	pthread_mutex_t mutex;
	sem_t empty;
	sem_t full;
	std::vector<Event *> buffer;
	unsigned int writeIndex;
	unsigned int readIndex;
};

#endif /* EVENTBUFFER_H_ */

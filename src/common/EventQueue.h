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

class EventQueue {
public:
	explicit EventQueue(int const bufferSize);
	virtual ~EventQueue();
	void send(Event const * const event);
	Event const * receive();
private:
	pthread_mutex_t mutex;
	sem_t empty;
	sem_t full;
	std::vector<Event *> buffer;
	Event const ** eventBuffer;
	unsigned int writeIndex;
	unsigned int readIndex;
	unsigned int size;
};

#endif /* EVENTBUFFER_H_ */

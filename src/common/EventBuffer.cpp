/*
 * EventBuffer.cpp
 *
 *  Created on: 2009-mar-08
 *      Author: bege
 */

#include "EventBuffer.h"
#include "Event.h"
#include "IREvent.h"
#include <pthread.h>
#include <vector>

EventBuffer::EventBuffer(int const bufferSize) {
	buffer.reserve(bufferSize);
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, bufferSize);
	sem_init(&full, 0, 0);
	//Initiate writeIndex = readIndex = 0;
	writeIndex = readIndex = 0;
}

void EventBuffer::send(Event const * const event) {
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	//Add event in buffer at writeIndex
	ev = event;
//	buffer.insert(writeIndex, event);
	//++writeIndex mod bufferSize
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

Event const * EventBuffer::receive() {
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	//remove from buffer
	//++readIndex mod bufferSize
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	return ev; //TODO: return event
}

EventBuffer::~EventBuffer() {
	// release mutex
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	// deallocate buffer and content
}

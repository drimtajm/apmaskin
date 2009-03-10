/*
 * IEventBuffer.cpp
 *
 *  Created on: 2009-mar-08
 *      Author: bege
 */

#include "EventBuffer.h"
#include "IEvent.h"
#include "IREvent.h"
#include <pthread.h>


EventBuffer::EventBuffer(int const bufferSize) {
	//Allocate buffer
	//Initiate mutex lock
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_init(&mutex, false);
	//Initiate empty semaphore = buffersize
	//Initiate full semaphore = 0
	//Initiate writeIndex = readIndex = 0;
}

void EventBuffer::send(IEvent const * const event) {
	//sem_wait(empty);
	pthread_mutex_lock(&mutex);
	//Add event in buffer at writeIndex
	//++writeIndex mod bufferSize
	pthread_mutex_unlock(&mutex);
	//sem_post(full);
}

IEvent* EventBuffer::receive() {
	//sem_wait(full);
	pthread_mutex_lock(&mutex);
	//remove from buffer
	//++readIndex mod bufferSize
	pthread_mutex_unlock(&mutex);
	//sem_post(empty);
	return new IREvent(); //TODO: return event
}

EventBuffer::~EventBuffer() {
	// release mutex
	pthread_mutex_destroy(&mutex);
	// release empty
	// release full
	// deallocate buffer and content
}

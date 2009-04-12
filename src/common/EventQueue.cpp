/*
 * EventBuffer.cpp
 *
 *  Created on: 2009-mar-08
 *      Author: bege
 */

#include "EventQueue.h"
#include "Event.h"
#include "IREvent.h"
#include <pthread.h>
#include <vector>

EventQueue::EventQueue(int const bufferSize) : size(bufferSize) {
	eventBuffer = new Event const *[bufferSize];
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, bufferSize);
	sem_init(&full, 0, 0);
	writeIndex = readIndex = 0;
}

void EventQueue::send(Event const * const event) {
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	eventBuffer[writeIndex] = event;
	writeIndex = (writeIndex + 1) % size;
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

Event const * EventQueue::receive() {
	Event const * e;
	sem_wait(&full);

	pthread_mutex_lock(&mutex);
	e = eventBuffer[readIndex];
	readIndex = (readIndex + 1) % size;
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	return e; //TODO: return event
}

EventQueue::~EventQueue() {
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	delete [] eventBuffer;
}

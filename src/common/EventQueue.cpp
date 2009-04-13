/*
 * EventBuffer.cpp
 *
 *  Created on: 2009-mar-08
 *      Author: bege
 */

#include "EventQueue.h"
#include <vector>

template<class T>
EventQueue<T>::EventQueue(int const bufferSize) : size(bufferSize) {
	eventBuffer = new T const *[bufferSize];
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, bufferSize);
	sem_init(&full, 0, 0);
	writeIndex = readIndex = 0;
}

template<class T>
EventQueue<T>::~EventQueue() {
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	while(!isEmpty())
		delete receive();
	delete [] eventBuffer;
}

template<class T>
void EventQueue<T>::send(T const * const event) {
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	eventBuffer[writeIndex] = event;
	writeIndex = (writeIndex + 1) % size;
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

template<class T>
T const * EventQueue<T>::receive() {
	T const * e;
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	e = eventBuffer[readIndex];
	readIndex = (readIndex + 1) % size;
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	return e; //TODO: return event
}


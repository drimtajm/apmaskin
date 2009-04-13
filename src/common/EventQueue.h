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

template<class T>
class EventQueue {
public:
	explicit EventQueue(int const bufferSize) : size(bufferSize) {
		eventBuffer = new T const *[bufferSize];
		pthread_mutex_init(&mutex, NULL);
		sem_init(&empty, 0, bufferSize);
		sem_init(&full, 0, 0);
		writeIndex = readIndex = 0;
	};

	virtual ~EventQueue() {
		pthread_mutex_destroy(&mutex);
		sem_destroy(&empty);
		sem_destroy(&full);
		while(!isEmpty())
			delete receive();
		delete [] eventBuffer;
	};

	void send(T const * const event) {
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		eventBuffer[writeIndex] = event;
		writeIndex = (writeIndex + 1) % size;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	};

	T const * receive() {
		T const * e;
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		e = eventBuffer[readIndex];
		readIndex = (readIndex + 1) % size;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		return e; //TODO: return event
	};
private:
	bool isEmpty() const {return readIndex == writeIndex; };
	pthread_mutex_t mutex;
	sem_t empty;
	sem_t full;
	std::vector<T *> buffer;
	T const ** eventBuffer;
	unsigned int writeIndex;
	unsigned int readIndex;
	unsigned int size;

	//Hidden copy constructor and assigment operator
	EventQueue(const EventQueue<T>&);
	EventQueue& operator=(const EventQueue<T>&);
};

#endif /* EVENTBUFFER_H_ */

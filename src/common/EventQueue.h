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
template<class T>
class EventQueue {
public:
	explicit EventQueue(int const bufferSize);
	virtual ~EventQueue();
	void send(T const * const event);
	T const * receive();
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

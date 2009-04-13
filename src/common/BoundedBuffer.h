/*
 * BoundedBuffer.h
 *
 *  Created on: 2009-mar-08
 *      Author: bege
 */

#ifndef BOUNDEDBUFFER_H_
#define BOUNDEDBUFFER_H_

#include <pthread.h>
#include <semaphore.h>
#include <vector>

template<class T>
class BoundedBuffer {
public:
	explicit BoundedBuffer(int const bufferSize) : size(bufferSize) {
		buffer = new T const *[bufferSize];
		pthread_mutex_init(&mutex, NULL);
		sem_init(&empty, 0, bufferSize);
		sem_init(&full, 0, 0);
		writeIndex = readIndex = 0;
	};

	virtual ~BoundedBuffer() {
		pthread_mutex_destroy(&mutex);
		sem_destroy(&empty);
		sem_destroy(&full);
		while(!isEmpty())
			delete receive();
		delete [] buffer;
	};

	/**
	 * Adds an item to the bounded buffer. The receiver is responsible for releasing resources.
	 */
	void send(T const * const item) {
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[writeIndex] = item;
		writeIndex = (writeIndex + 1) % size;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	};

	/**
	 * Gets the next item in the buffer. The receiver is responsible for releasing resources.
	 */
	T const * receive() {
		T const * item;
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		item = buffer[readIndex];
		readIndex = (readIndex + 1) % size;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		return item; //TODO: return item
	};
private:
	bool isEmpty() const {return readIndex == writeIndex; };
	pthread_mutex_t mutex;
	sem_t empty;
	sem_t full;
	T const ** buffer;
	unsigned int writeIndex;
	unsigned int readIndex;
	unsigned int size;

	//Hidden copy constructor and assigment operator
	BoundedBuffer(const BoundedBuffer<T>&);
	BoundedBuffer& operator=(const BoundedBuffer<T>&);
};

#endif /* BOUNDEDBUFFER_H_ */

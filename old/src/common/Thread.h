/*
 * Thread.h
 *
 *  Created on: 2009-apr-10
 *      Author: bege
 */

#ifndef THREAD_H_
#define THREAD_H_

#include "Runnable.h"
#include <pthread.h>

class Thread {
public:
	explicit Thread(Runnable* r) : runnable(r), running(false) {};
	virtual ~Thread() { };
	/**
	 * Start to execute the thread. This methos can only be executed once on each object.
	 */
	void start();

	/**
	 * Do a thread join on the thread.
	 */
	void join();
private:
	static void go(Runnable* r) { r->run(); }
	Runnable* runnable;
	pthread_t thread;
	bool running;
	//Hidden copy constructor and assignment operator
	Thread(const Thread&);
	Thread& operator=(const Thread&);
};

#endif /* THREAD_H_ */

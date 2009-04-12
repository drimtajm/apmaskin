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
	virtual ~Thread() {join(); };
	void start();
	void join();
private:
	static void go(Runnable* r) { r->run(); };
	Runnable* runnable;
	pthread_t thread;
	bool running;
};

#endif /* THREAD_H_ */

/*
 * Thread.cpp
 *
 *  Created on: 2009-apr-10
 *      Author: bege
 */

#include "Thread.h"

void Thread::start() {
	if (!running) {
		running = true;
		pthread_create(&thread, NULL, (void* (*)(void*)) &go, runnable);
	}
}

void Thread::join() {
	if (running)
		pthread_join(thread, NULL);
}

/*
 * Thread.cpp
 *
 *  Created on: 2009-apr-10
 *      Author: bege
 */

#include "Thread.h"
#include <cassert>

void Thread::start() {
	assert(!running && "Can't start an Thread more than once.");
	running = true;
	pthread_create(&thread, NULL, (void* (*)(void*)) &go, runnable);
}

void Thread::join() {
	assert(running && "Can't join a non started thread");
	pthread_join(thread, NULL);
}

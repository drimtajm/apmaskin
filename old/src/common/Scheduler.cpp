/*
 * Scheduler.cpp
 *
 *  Created on: 2009-apr-20
 *      Author: bege
 */

#include "Scheduler.h"
#include "Periodic.h"
#include "Thread.h"
#include <iostream>

/**
 * Add a periodics to be scheduled.
 */
void Scheduler::add(Periodic& periodic) {
	periodics.push_back(&periodic);
}

/**
 * Starts the scheduled periodics.
 */
void Scheduler::start() {
	for(PeriodicVector::iterator it = periodics.begin(); it != periodics.end(); ++it) {
		Thread* t = new Thread(*it);
		t->start();
		threads.push_back(t);
	}
}

/**
 * Stops all periodics.
 */
void Scheduler::stop() {
	for(PeriodicVector::iterator it = periodics.begin(); it != periodics.end(); ++it) {
		(*it)->stop();
	}
}

/**
 * Stops all periodics and blocks until all threads have exited.
 */
void Scheduler::stopAndJoin() {
	stop();
	for(ThreadVector::iterator it = threads.begin(); it != threads.end(); ++it) {
		(*it)->join();
		delete (*it);
	}
	threads.clear();
}






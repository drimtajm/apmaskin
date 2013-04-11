/*
 * Periodic.cpp
 *
 *  Created on: 2009-apr-20
 *      Author: bege
 */

#include "Periodic.h"
#include <iostream>
#include <time.h>
#include "TimeSpec.h"

using std::ostream;
using std::cout;
using std::endl;


ostream& operator<<(ostream& out, const Periodic& p) {
	return out << p.name;
}

/**
 * Starts the execution of the runnable with the given period.
 */
void Periodic::run() {
	TimeSpec before;
	TimeSpec after;
	TimeSpec wcet;
	TimeSpec maxDelay;
	TimeSpec lastStart;

	running = true;
	timer.start();
	sem_wait(&start);
	while (running) {
		before.getTime();
		runnable.run();
		after.getTime();
		if(wcet < after - before) {
			wcet = after - before;
		}
		if(before - lastStart > maxDelay && lastStart > TimeSpec(0,0))
			maxDelay = before - lastStart;
		lastStart = before;
		sem_wait(&start);
	}
	timer.stop();
	cout << name << " Worst case execution time: " << wcet << " seconds" << endl;
	cout << name << " maxDelay: " << maxDelay << endl;
}

/**
 * Stops the periodic task. The function does not interrupt
 * the current execution.
 */
void Periodic::stop()
{
	running = false;
}



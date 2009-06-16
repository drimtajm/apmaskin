/*
 * Scheduler.h
 *
 *  Created on: 2009-apr-20
 *      Author: bege
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include <vector>
class Thread;
class Periodic;

/**
 *	Scheduler is a container for a set of periodic tasks with
 *	convenience methods for starting and stopping.
 *
 *  Example:
 *
 *	Scheduler scheduler;
 *	Task t1;
 *	Task t2;
 *	Periodic p1(t1, TimeSpec(0, 100000000), "t1");
 *	scheduler.add(p1);
 *	Periodic p2(t2, TimeSpec(0, 500000000), "t2");
 *	scheduler.add(p2);
 *	scheduler.start();
 *	sleep(1000);
 *	scheduler.stopAndJoin();
 */


class Scheduler {
public:
	void add(Periodic& periodic);
	void start();
	void stop();
	void stopAndJoin();
private:
	typedef std::vector<Periodic*> PeriodicVector;
	typedef std::vector<Thread*> ThreadVector;
	PeriodicVector periodics;
	ThreadVector threads;
};

#endif /* SCHEDULER_H_ */

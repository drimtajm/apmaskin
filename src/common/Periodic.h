/*
 * Periodic.h
 *
 *  Created on: 2009-apr-20
 *      Author: bege
 */

#ifndef PERIODIC_H_
#define PERIODIC_H_
#include <ostream>
#include <string>
#include <semaphore.h>
#include "Runnable.h"
#include "Timer.h"

using std::ostream;
using std::string;

/**
 * Periodic is special case of a Thread. It executes the run() method in the
 * given Runnable with the given period.
 */
class Periodic: public Runnable {
	friend ostream& operator<<(ostream& out, const Periodic& p);
public:
	explicit Periodic(Runnable& runnable, const TimeSpec& period,
			const string& name = "") :
			runnable(runnable), name(name),
			timer(Timer(handler, this, period)),
			running(false){
		sem_init(&start, 0, 0);
	}

	virtual ~Periodic() { sem_destroy(&start); }

	void run();

	void stop();
private:
	void signal() { sem_post(&start); }
	static void handler(int sig, siginfo_t *si, void *uc) {
		Periodic *p = static_cast<Periodic*>(si->si_value.sival_ptr);
		p->signal();
	}
	Runnable& runnable;
	string name;
	sem_t start;
	Timer timer;
	struct sigevent sev;
	bool running;

	//Hidden copy constructor and assignment operator
	Periodic(const Periodic&);
	Periodic& operator=(const Periodic&);
};

#endif /* PERIODIC_H_ */

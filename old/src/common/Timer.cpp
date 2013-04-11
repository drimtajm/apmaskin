/*
 * Timer.cpp
 *
 *  Created on: 2009-apr-22
 *      Author: bege
 */

#include "Timer.h"
#include <signal.h>
#include <stdexcept>
#include <iostream>
#include "TimeSpec.h"

using std::runtime_error;
using std::cerr;
using std::endl;

Timer::Timer(handlerFunction handler, void * sigValue, const TimeSpec& period) throw() :
	_period(period), sigValue(sigValue) {
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGRTMIN, &sa, NULL) == -1)
		throw runtime_error("sigaction() did not succeed");

}

void Timer::start() {
	struct sigevent sev;
	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = SIGRTMIN;
	sev.sigev_value.sival_ptr = sigValue;
	if (timer_create(CLOCK_REALTIME, &sev, &timer) == -1) {
		throw runtime_error("Could not create timer");
	}

	struct itimerspec spec;
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGRTMIN);
	if (pthread_sigmask(SIG_BLOCK, &set, NULL) == -1)
		cerr << "sigprocmask failed" << endl;
	spec.it_value = _period;
	spec.it_value = _period;
	spec.it_interval.tv_sec = spec.it_value.tv_sec;
	spec.it_interval.tv_nsec = spec.it_value.tv_nsec;

	timer_settime(timer, 0, &spec, NULL);
}

void Timer::stop() {
	timer_delete(timer);
}




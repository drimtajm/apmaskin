/*
 * Timer.h
 *
 *  Created on: 2009-apr-22
 *      Author: bege
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <time.h>
#include <signal.h>
#include "TimeSpec.h"

typedef void (*handlerFunction)(int sig, siginfo_t *si, void *uc);

class Timer {
public:
	Timer(handlerFunction handler, void* sigValue, const TimeSpec& period) throw();

	TimeSpec period() const {
		return _period;
	}

	void start();

	void stop();

	Timer(const Timer& rhs) :
		timer(rhs.timer), _period(rhs._period) {
	}

	Timer& operator=(const Timer& rhs) {
		timer = rhs.timer;
		_period = rhs._period;
		return *this;
	}
private:
	timer_t timer;
	TimeSpec _period;
	__suseconds_t periodNSec;
	void * sigValue;
};
#endif /* TIMER_H_ */

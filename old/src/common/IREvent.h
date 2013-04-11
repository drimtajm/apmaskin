/*
 * IREvent.h
 *
 *  Created on: 2009-mar-10
 *      Author: bege
 */

#ifndef IREVENT_H_
#define IREVENT_H_

#include "Event.h"

class IREvent: public Event {
public:
	IREvent(int val) : Event(INFRARED_DISTANCE_EVENT), value(val) {};
	virtual ~IREvent() {};
	int getValue() const { return value; };
protected:
	int value;
};

#endif /* IREVENT_H_ */

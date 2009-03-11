#ifndef EventGENERATOR_H_
#define EventGENERATOR_H_

#include "EventListener.h"
#include "Event.h"



class EventGenerator {
private:

public:
	virtual void addEventListener(Event::EventType type, EventListener* listener) = 0;
	virtual void removeEventListener(Event::EventType type, EventListener* listener) = 0;
	virtual ~EventGenerator() {};
};

#endif /* EventGENERATOR_H_ */

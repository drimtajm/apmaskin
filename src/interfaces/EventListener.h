#ifndef EventLISTENER_H_
#define EventLISTENER_H_

#include "Event.h"
class EventListener {
public:
	virtual void eventHandler(Event e)=0;
	virtual ~EventListener() {};
};

#endif /* EventLISTENER_H_ */

#ifndef EventGENERATOR_H_
#define EventGENERATOR_H_

#include "EventListener.h"
#include "Event.h"
#include "EventQueue.h"



class EventGenerator {
private:

public:
	virtual void setMessageQueue(EventQueue* eventQueue) = 0;
	virtual ~EventGenerator() {};
};

#endif /* EventGENERATOR_H_ */

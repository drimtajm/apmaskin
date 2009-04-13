#ifndef EventGENERATOR_H_
#define EventGENERATOR_H_

#include "EventListener.h"
#include "Event.h"
#include "BoundedBuffer.h"



class EventGenerator {
private:

public:
	virtual void startSendEvents(BoundedBuffer<Event>& eventQueue) = 0;
	virtual void stopSendEvents() = 0;
	virtual ~EventGenerator() {};
};

#endif /* EventGENERATOR_H_ */

#ifndef IEVENTGENERATOR_H_
#define IEVENTGENERATOR_H_

#include "IEventListener.h"
#include "IEvent.h"



class IEventGenerator {
private:

public:
	virtual void addEventListener(IEvent::EventType type, IEventListener* listener) = 0;
	virtual void removeEventListener(IEvent::EventType type, IEventListener* listener) = 0;
};

#endif /* IEVENTGENERATOR_H_ */

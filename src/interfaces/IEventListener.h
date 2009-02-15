#ifndef IEVENTLISTENER_H_
#define IEVENTLISTENER_H_

#include "IEvent.h"
class IEventListener {
public:
	virtual void eventHandler(IEvent e)=0;
	virtual ~IEventListener() {};
};

#endif /* IEVENTLISTENER_H_ */

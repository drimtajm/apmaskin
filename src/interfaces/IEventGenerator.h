#include "IEventListener.h"
#include "IEvent.h"

class IEventGenerator {
private:
public:
	virtual void addEventListener(EventType type, IEventListener listener) = 0;
	virtual void removeEventListener(EventType type, IEventListener listener) = 0;
};
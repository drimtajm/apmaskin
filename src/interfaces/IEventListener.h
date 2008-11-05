#include "IEvent.h"
class IEventListerner {
public:
	virtual void eventHandler(IEvent e) = 0;
};

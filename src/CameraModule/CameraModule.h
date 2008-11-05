#include "IEvent.h"
#include "IEventListener.h"
#include "IEventGenerator.h"

#include <list>
using namespace std;

class CameraModule : public IEventGenerator {
private:
	list<IEventListener> positionErrorListeners; 
	list<IEventListener> intersectionFoundListeners;
	list<IEventListener> numberFoundListeners;
public:
	void addEventListener(EventType type, IEventListener listener);
	void removeEventListener(EventType type, IEventListener listener);
};
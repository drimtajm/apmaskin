#include "IEvent.h"

class PositionErrorEvent : public IEvent {
private:
	int distanceError;
public:
	int getDistanceError();
};

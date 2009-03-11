#ifndef POSITIONERROREVENT_H_
#define POSITIONERROREVENT_H_

#include "Event.h"

class PositionErrorEvent : public Event {
private:
	int distanceError;
public:
	int getDistanceError();
};

#endif /* POSITIONERROREVENT_H_ */

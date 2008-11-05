#ifndef POSITIONERROREVENT_H_
#define POSITIONERROREVENT_H_

#include "IEvent.h"

class PositionErrorEvent : public IEvent {
private:
	int distanceError;
public:
	int getDistanceError();
};

#endif /* POSITIONERROREVENT_H_ */

#ifndef IEVENT_H_
#define IEVENT_H_

class IEvent {
public:
	enum EventType {POSITION_ERROR_EVENT = 1,
					INTERSECTION_FOUND_EVENT = 2,
					NUMBER_FOUND_EVENT = 4,
					ULTRASONICS_DISTANCE_EVENT = 8,
					INFRARED_DISTANCE_EVENT = 16};
	virtual ~IEvent() {};
	EventType getEventType();
protected:
	EventType eventType;
	IEvent() {};
};

#endif /* IEVENT_H_ */

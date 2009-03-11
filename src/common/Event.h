#ifndef Event_H_
#define Event_H_

class Event {
public:
	enum EventType {POSITION_ERROR_EVENT = 1,
					INTERSECTION_FOUND_EVENT = 2,
					NUMBER_FOUND_EVENT = 4,
					ULTRASONICS_DISTANCE_EVENT = 8,
					INFRARED_DISTANCE_EVENT = 16};
	virtual ~Event() {};
	EventType getEventType();
protected:
	EventType eventType;
	Event() {};
};

#endif /* Event_H_ */

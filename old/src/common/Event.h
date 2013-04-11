#ifndef Event_H_
#define Event_H_

class Event {
public:
	/**
	 * Different types of events
	 */
	enum EventType {POSITION_ERROR_EVENT = 0,
					INTERSECTION_FOUND_EVENT,
					NUMBER_FOUND_EVENT,
					ULTRASONICS_DISTANCE_EVENT,
					INFRARED_DISTANCE_EVENT};
	virtual ~Event() {};
	EventType getEventType() const {return eventType;}
protected:
	Event(EventType evType) : eventType(evType) {}
private:
	EventType eventType;
};

#endif /* Event_H_ */

enum EventType {POSITION_ERROR_EVENT = 1, INTERSECTION_FOUND_EVENT = 2, NUMBER_FOUND_EVENT = 4, ULTRASONICS_DISTANCE_EVENT = 8};

class IEvent {
private:
	EventType eventType;
public:
	EventType getEventType();
};

/*
 * IRSensor.h
 *
 *  Created on: 2009-mar-03
 *      Author: bege
 */

#ifndef IRSENSOR_H_
#define IRSENSOR_H_

#include <list>
#include "EventGenerator.h"
#include "CommandServer.h"
#include "Thread.h"
#include "IRSensorReader.h"

class IRSensor: public EventGenerator, CommandServer {
public:
	IRSensor();
	void startSendEvents(BoundedBuffer<Event>& eventQueue);
	void stopSendEvents();
	virtual void executeCommand(int cmdID, std::vector<int> arguments);
	virtual void registerCommands();

	virtual ~IRSensor();

private:
	typedef enum {
		CMD_GETIRDATA
	} IRSensorCommand;
	int cmdGetIRPing(const std::vector<int>& arguments);
	Thread * readerThread;
	IRSensorReader * reader;

	//Hidden copy constructor and assignment operator
	IRSensor(const IRSensor&);
	IRSensor& operator=(const IRSensor&);
};

#endif /* IRSENSOR_H_ */

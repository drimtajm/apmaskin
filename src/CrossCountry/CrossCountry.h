/*
 * CrossCountry.h
 *
 *  Created on: 2009-apr-08
 *      Author: bege
 */

#ifndef CROSSCOUNTRY_H_
#define CROSSCOUNTRY_H_

#include <pthread.h>
#include "CommandServer.h"
#include "EventGenerator.h"
#include "Runnable.h"
#include "Thread.h"

class CrossCountry : public CommandServer, Runnable{
public:
	CrossCountry(EventGenerator& irSensor);
	virtual ~CrossCountry();
	virtual void executeCommand(int cmdID, std::vector<int> arguments);
	virtual void registerCommands();
	void run();
private:
	void cmdCrossCountry(const std::vector<int>& arguments);
	void startCrossCountry();
	void stopCrossCountry();
	void setRunning(bool value);
	bool const getRunning();
    typedef enum {
		CMD_CROSSCOUNTRY
	} CrossCountryCommand;

	EventGenerator& irSensor;
	Thread* thread;
	bool running;
	pthread_mutex_t mutex; //lock for CrossCountry::running

	//hidden Copy constructor and assignment operator
	CrossCountry(const CrossCountry&);
	CrossCountry& operator=(const CrossCountry&);
};

#endif /* CROSSCOUNTRY_H_ */

/*
 * CrossCountry.h
 *
 *  Created on: 2009-apr-08
 *      Author: bege
 */

#ifndef CROSSCOUNTRY_H_
#define CROSSCOUNTRY_H_

#include "CommandServer.h"
#include "EventGenerator.h"

class CrossCountry : public CommandServer{
public:
	CrossCountry(EventGenerator& irSensor) : irSensor(irSensor) {};
	virtual ~CrossCountry() {};
	virtual void executeCommand(int cmdID, std::vector<int> arguments);
	virtual void registerCommands();
private:
	void cmdCrossCountry(const std::vector<int>& arguments);
	void startCrossCountry();
	void stopCrossCountry();

    typedef enum {
		CMD_CROSSCOUNTRY
	} CrossCountryCommand;

	EventGenerator& irSensor;

};

#endif /* CROSSCOUNTRY_H_ */

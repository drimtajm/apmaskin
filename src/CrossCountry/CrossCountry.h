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
	virtual void executeCommand(int cmdID, std::vector<int> arguments);
	virtual void registerCommands();
	CrossCountry(EventGenerator& irSensor);
	virtual ~CrossCountry();
private:
	typedef enum {
		CMD_CROSSCOUNTRY
	} CrossCountryCommand;

	int getirping(const std::vector<int>& arguments);

};

#endif /* CROSSCOUNTRY_H_ */

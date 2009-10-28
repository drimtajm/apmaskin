/*
 * MotorControllerStub.h
 *
 *  Created on: 2009-okt-28
 *      Author: bege
 */

#ifndef MOTORCONTROLLERSTUB_H_
#define MOTORCONTROLLERSTUB_H_

#include "MotorController.h"

class MotorControllerStub : public MotorController {
public:
	MotorControllerStub() : setSpeedIsCalled(false), setTurnRateIsCalled(false) {}
	void setSpeed(int speed) {
		setSpeedIsCalled = true;
		this->speed = speed;
		}
	void setTurnRate(int turnRate) {
		setTurnRateIsCalled = true;
		this->turnRate = turnRate;
	}
	bool setSpeedIsCalled;
	bool setTurnRateIsCalled;
	int speed;
	int turnRate;
};


#endif /* MOTORCONTROLLERSTUB_H_ */

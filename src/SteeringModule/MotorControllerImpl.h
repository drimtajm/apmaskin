/*
 * MotorControllerImpl.h
 *
 *  Created on: 11 nov 2009
 *      Author: bege
 */

#ifndef MOTORCONTROLLERIMPL_H_
#define MOTORCONTROLLERIMPL_H_

#include "MotorController.h"

class MotorControllerImpl : public MotorController {
public:
	MotorControllerImpl() {}
	~MotorControllerImpl() {}
	void setSpeed(int speed);
	void setTurnRate(int turnRate);
};

#endif /* MOTORCONTROLLERIMPL_H_ */

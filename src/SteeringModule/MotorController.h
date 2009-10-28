/*
 * MotorController.h
 *
 *  Created on: 2009-okt-28
 *      Author: bege
 */

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

class MotorController {
public:
	virtual ~MotorController() {};
	virtual void setSpeed(int speed) = 0;
	virtual void setTurnRate(int turnRate) = 0;

};

#endif /* MOTORCONTROLLER_H_ */

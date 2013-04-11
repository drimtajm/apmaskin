/*
 * Runnable.h
 *
 *  Created on: 2009-apr-10
 *      Author: bege
 */

#ifndef RUNNABLE_H_
#define RUNNABLE_H_

class Runnable {
public:
	virtual ~Runnable() {};
/**
 * The function that runs the thread.
 */
	virtual void run() = 0;
};

#endif /* RUNNABLE_H_ */

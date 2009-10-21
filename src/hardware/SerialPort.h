/*
 * SerialPort.h
 *
 *  Created on: 2009-okt-21
 *      Author: bege
 */

#ifndef SERIALPORT_H_
#define SERIALPORT_H_

class SerialPort {
public:
	virtual ~SerialPort() {};
	virtual void write(char data, unsigned int numberOfBytes) = 0;
};

#endif /* SERIALPORT_H_ */

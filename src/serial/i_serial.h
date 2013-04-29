#ifndef SERIAL_IF_H_
#define SERIAL_IF_H_

#include "type.h"

typedef enum {
  SERIAL_SUCCESS,
  SERIAL_FAILURE
} SerialResult;

typedef void (*SerialRxCallback)(uint8_t rxData[], size_t sizeOfRxData);

class ISerial
{
  virtual ISerial();
  virtual ~ISerial();

  /**
   * Request transmission of data
   *
   * @param    dataToSend        Array of data to send
   * @param    sizeOfDataToSend    Size of data to send
   *
   * @return    'SERIAL_SUCCESS' if successful. 'SERIAL_FAILURE' otherwise
   */
  virtual SerialResult send(uint8_t dataToSend[], size_t sizeOfDataToSend);

  /**
   * Synchronous read from serial port
   *
   * @param    rxData                Array where to store received data
   * @param    sizeOfReceivedData    Pointer to where to store size of received data
   *
   * @return    'SERIAL_SUCCESS' if successful. 'SERIAL_FAILURE' if port is unavailable.
   *            'SERIAL_SUCCESS' does not mean that 'sizeOfReceivedData' is non-zero, it only means
   *            that the port is still available.
   */
  virtual SerialResult receive(uint8_t rxData[], size_t* sizeOfReceivedData);

  /**
   * Add call-back for asynchronous reception of data
   * There shall be no limit to the number of subscribers
   */
  virtual void addRxCallback(SerialRxCallback rxCallback);
};


#endif /* SERIAL_IF_H_ */

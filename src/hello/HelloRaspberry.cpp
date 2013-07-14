#include <stdio.h>
#include "variant.h"
//#include "led.h"
//#include "motor.h"

int main()
{
  printf("Hello Raspberry!\n");
  DEBUG_PRINTF("This is a debug build\n");
  DEBUG_PRINTF("These are numbers: %d, %f, 0x%X\n", 4, 0.75, 0xFE);
  DEBUG_PRINTF("Line number: %d\n", __LINE__);
  DEBUG_PRINTF("Built at: %s, %s\n", __TIME__, __DATE__);
//  Led::turnOnLed();
//  Led::turnOffLed();
//
//  Motor* motor = new Motor();
//  motor->start();
//  motor->stop();
//  delete motor;
  return 0;
}

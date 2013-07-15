#include <stdio.h>
#include "motor.h"
#include "led.h"

void start(void)
{
  turnOnLed();
}

void stop(void)
{
  printf("'Motor::stop()' not implemented yet!\n");
}

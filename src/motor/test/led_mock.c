#include "led.h"
#include "led_spy.h"

static int ledIsOn_ = 0;

void ledMockReset(void) {
  ledIsOn_ = 0;
}

int ledIsOn(void) {
  return ledIsOn_;
}

void turnOnLed(void) {
  ledIsOn_ = 1;
}

void turnOffLed(void) {
  ledIsOn_ = 0;
}

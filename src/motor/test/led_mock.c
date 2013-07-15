#include "led.h"
#include "led_spy.h"

static LedState ledState = LED_STATE_UNKNOWN;

void ledMockReset(void) {
  ledState = LED_STATE_UNKNOWN;
}

LedState getLedState(void) {
  return ledState;
}

void turnOnLed(void) {
  ledState = LED_STATE_ON;
}

void turnOffLed(void) {
  ledState = LED_STATE_OFF;
}

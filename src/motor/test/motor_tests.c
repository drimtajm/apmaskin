#include "unity.h"
#include "motor.h"
#include "led.h"
#include "led_spy.h"

void setUp(void) {
  ledMockReset();
}
void tearDown(void) {}

void test_MotorLightsLedWhenStarted(void) {
  start();
  TEST_ASSERT(getLedState() == LED_STATE_ON);
}

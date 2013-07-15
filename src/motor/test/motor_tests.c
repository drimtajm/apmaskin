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
  TEST_ASSERT_EQUAL(LED_STATE_ON, getLedState());
}

void test_MotorSwitchesOffLedWhenStopped(void) {
  stop();
  TEST_ASSERT_EQUAL(LED_STATE_OFF, getLedState());
}

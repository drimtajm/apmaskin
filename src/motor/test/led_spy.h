#ifndef LED_SPY_H_
#define LED_SPY_H_

typedef enum LedState {
  LED_STATE_UNKNOWN,
  LED_STATE_ON,
  LED_STATE_OFF
} LedState;

void ledMockReset(void);
LedState getLedState(void);

#endif /* LED_SPY_H_ */

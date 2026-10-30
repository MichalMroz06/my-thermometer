#ifndef STATUS_LED_H
#define STATUS_LED_H

// Variables:
typedef enum { // Enum for different types of LED status
    LED_STATE_IDLE,
    LED_STATE_CONNECTED,
    LED_STATE_ERROR,
    LED_STATE_OFF
} led_state_t;

// Functions:
void status_led_init(void); // Initial function
void status_led_set_state(led_state_t state); // Async change of LED status

#endif

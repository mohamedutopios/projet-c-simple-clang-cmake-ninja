#include "gpio.h"
#include "led_control.h"

#define LED_PIN 13  // Example GPIO pin number

typedef enum {
    LED_OFF,
    LED_ON,
    LED_BLINK
} LEDMode;

static LEDMode current_mode = LED_OFF;
static int led_state = LOW;
static int blink_counter = 0;

void led_set_mode(int mode) {
    switch (mode) {
        case LED_OFF:
            current_mode = LED_OFF;
            led_update(LOW);
            break;
        case LED_ON:
            current_mode = LED_ON;
            led_update(HIGH);
            break;
        case LED_BLINK:
            current_mode = LED_BLINK;
            blink_counter = 0; // Reset the blink counter when entering blink mode
            break;
        default:
            break;
    }
}

void led_init() {
    gpio_pin_mode(LED_PIN, GPIO_OUTPUT);
    led_update(LOW);
}

void led_update() {
    switch (current_mode) {
        case LED_OFF:
            gpio_digital_write(LED_PIN, LOW);
            break;
        case LED_ON:
            gpio_digital_write(LED_PIN, HIGH);
            break;
        case LED_BLINK:
            if (blink_counter >= 5) { // Adjust the counter limit as needed
                led_state = !led_state;
                gpio_digital_write(LED_PIN, led_state);
                blink_counter = 0;
            }
            blink_counter++;
            break;
        default:
            break;
    }
}

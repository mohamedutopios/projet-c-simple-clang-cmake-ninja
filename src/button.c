#include <stdio.h>
#include "button.h"
#include "gpio.h"
#include "led_control.h"

#define BUTTON_PIN_1 1
#define BUTTON_PIN_2 2
#define LED_MODE_NEXT 1

static int button_state_1 = BUTTON_UNPRESSED;
static int button_state_2 = BUTTON_UNPRESSED;

void button_init() {
    gpio_pin_mode(BUTTON_PIN_1, GPIO_INPUT);
    gpio_pin_mode(BUTTON_PIN_2, GPIO_INPUT);
    button_state_1 = BUTTON_UNPRESSED; // Ensure initial state is unpressed
    button_state_2 = BUTTON_UNPRESSED; // Ensure initial state is unpressed
    printf("button_init: button_state_1=%d, button_state_2=%d\n", button_state_1, button_state_2);
}

void button_check() {
    button_state_1 = gpio_digital_read(BUTTON_PIN_1);
    button_state_2 = gpio_digital_read(BUTTON_PIN_2);
    printf("button_check: button_state_1=%d, button_state_2=%d\n", button_state_1, button_state_2);

    if (button_state_1 == BUTTON_PRESSED) {
        led_set_mode(LED_MODE_NEXT);
    }
}

int get_button_state() {
    printf("get_button_state: %d\n", button_state_1);
    return button_state_1;
}

void simulate_button_press() {
    gpio_set_simulated_value(BUTTON_PIN_1, BUTTON_PRESSED);
    printf("simulate_button_press: button_state_1=%d\n", BUTTON_PRESSED);
}

void simulate_button_release() {
    gpio_set_simulated_value(BUTTON_PIN_1, BUTTON_UNPRESSED);
    printf("simulate_button_release: button_state_1=%d\n", BUTTON_UNPRESSED);
}

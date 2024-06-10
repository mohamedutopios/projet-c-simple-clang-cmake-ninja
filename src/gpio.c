#include "gpio.h"
#include <stdio.h>

static int simulated_value_1 = LOW;
static int simulated_value_2 = LOW;

void gpio_pin_mode(int pin, int mode) {
    // Mock implementation
    printf("Setting pin %d to mode %d\n", pin, mode);
}

void gpio_digital_write(int pin, int value) {
    // Mock implementation
    printf("Writing value %d to pin %d\n", value, pin);
}

int gpio_digital_read(int pin) {
    // Mock implementation, return the simulated value
    if (pin == BUTTON_PIN_1) {
        return simulated_value_1;
    } else if (pin == BUTTON_PIN_2) {
        return simulated_value_2;
    }
    return LOW;
}

void gpio_set_simulated_value(int pin, int value) {
    if (pin == BUTTON_PIN_1) {
        simulated_value_1 = value;
    } else if (pin == BUTTON_PIN_2) {
        simulated_value_2 = value;
    }
    printf("Simulated value set for pin %d to %d\n", pin, value);
}

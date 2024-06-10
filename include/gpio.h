#ifndef GPIO_H
#define GPIO_H

#define GPIO_INPUT 0
#define GPIO_OUTPUT 1
#define HIGH 1
#define LOW 0

#define BUTTON_PIN_1 1
#define BUTTON_PIN_2 2

void gpio_pin_mode(int pin, int mode);
void gpio_digital_write(int pin, int value);
int gpio_digital_read(int pin);

void gpio_set_simulated_value(int pin, int value);  // Nouvelle fonction pour définir une valeur simulée

#endif // GPIO_H

#include "main.h"
#include "led_control.h"
#include "button.h"

int main(void) {
    led_init();
    button_init();

    while (1) {
        button_check();
        led_update();
    }
}

#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON_UNPRESSED 0
#define BUTTON_PRESSED 1

void button_init();
void button_check();
int get_button_state();
void simulate_button_press();
void simulate_button_release();

#endif // BUTTON_H

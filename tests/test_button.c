#include <assert.h>
#include <stdio.h>
#include "button.h"

// Fonction pour tester l'initialisation des boutons
void test_button_init() {
    printf("Running test_button_init\n");
    button_init();
    assert(get_button_state() == BUTTON_UNPRESSED);
    printf("Test Init: PASS\n");
}

// Fonction pour tester la fonctionnalité des boutons
void test_button_functionality() {
    printf("Running test_button_functionality\n");
    button_init();
    simulate_button_press();
    button_check();
    assert(get_button_state() == BUTTON_PRESSED);
    printf("Test Button Press: PASS\n");

    simulate_button_release();
    button_check();
    assert(get_button_state() == BUTTON_UNPRESSED);
    printf("Test Button Reset: PASS\n");
}

// Fonction pour tester la détection de la répétition de bouton
void test_button_debounce() {
    printf("Running test_button_debounce\n");
    button_init();
    simulate_button_press();
    simulate_button_release();
    simulate_button_press();
    button_check();
    assert(get_button_state() == BUTTON_PRESSED);
    printf("Test Debounce: PASS\n");
}

// Point d'entrée pour les tests de bouton
int main() {
    printf("Starting tests\n");
    test_button_init();
    test_button_functionality();
    test_button_debounce();
    printf("All tests passed\n");
    return 0;
}

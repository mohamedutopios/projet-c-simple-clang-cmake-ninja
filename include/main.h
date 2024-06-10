#ifndef MAIN_H
#define MAIN_H

// Inclure les fichiers d'en-tête nécessaires pour la visibilité des fonctions
#include "led_control.h"
#include "button.h"

// Définir des constantes globales, si nécessaire
#define SYSTEM_CLOCK_FREQUENCY 16000000 // Fréquence du système en Hertz, exemple

// Déclarations de fonctions qui pourraient être utilisées à travers plusieurs fichiers
// Par exemple, des fonctions pour initialiser le système ou gérer les interruptions

void System_Init(void); // Fonction pour initialiser les composants du système
void Delay_ms(unsigned int ms); // Fonction pour introduire un délai en millisecondes

#endif // MAIN_H

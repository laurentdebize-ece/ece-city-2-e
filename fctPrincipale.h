//
// Created by crouz on 27/11/2022.
//

#ifndef ECE_CITY_2_E_FCTPRINCIPALE_H
#define ECE_CITY_2_E_FCTPRINCIPALE_H

#include "affichage1.h"
#include "timer1.h"

Plateau initialiserPlateau();
void fonctionPrincipale();
void jeu(ALLEGRO_DISPLAY *fenetre, ALLEGRO_EVENT_QUEUE *queue, Plateau *plateau, int mode);

#endif //ECE_CITY_2_E_FCTPRINCIPALE_H

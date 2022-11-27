//
// Created by crouz on 03/11/2022.
//

#ifndef PROJETING2_SIMCITYGROUPE2E_FONCTIONPRINCIPALE_H
#define PROJETING2_SIMCITYGROUPE2E_FONCTIONPRINCIPALE_H
#include "affichage.h"
#include "timer.h"
Plateau initialiserPlateau();
void fonctionPrincipale();
void jeu(ALLEGRO_DISPLAY *fenetre, ALLEGRO_EVENT_QUEUE *queue, Plateau *plateau, int mode);
#endif PROJETING2_SIMCITYGROUPE2E_FONCTIONPRINCIPALE_H

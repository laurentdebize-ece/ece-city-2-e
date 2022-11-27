//
// Created by crouz on 27/11/2022.
//

#ifndef ECE_CITY_2_E_MENUPRINCIPAL1_H
#define ECE_CITY_2_E_MENUPRINCIPAL1_H

#include "../../ece-city-2-e/ftcsReutilisables1.h"
#include "../../ece-city-2-e/sauvegarde1.h"
#include "../../ece-city-2-e/Partie/clcPartie1.h"

void choixPartie(ALLEGRO_DISPLAY *fenetre, ALLEGRO_EVENT_QUEUE *queue, Plateau *plateau);
void initilisationTaillesBoutonsMenuPrincipal(Rect *rCOMMUNISTE, Rect *rCAPITALISTE);
void clicsMenuChoixPartie(int *choix, int mouseX, int mouseY);
void clicsMenuPrincipal(int *choix, int mouseX, int mouseY);


#endif //ECE_CITY_2_E_MENUPRINCIPAL1_H

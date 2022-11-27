//
// Created by crouz on 27/11/2022.
//

#ifndef ECE_CITY_2_E_CLCPARTIE1_H
#define ECE_CITY_2_E_CLCPARTIE1_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/bitmap.h>
#include "poserObj1.h"
#include "../../ece-city-2-e//ftcsReutilisables1.h"

int clicsPartie(ALLEGRO_BITMAP *interf, int mouseX, int mouseY, ALLEGRO_TIMER* timer1s, int minutes, int niveau, int *etatBouton);
void initilisationTaillesBoutonsPartie(Rect *rPLATEAU, Rect *rpause, Rect *rsortie, Rect *rFinPause,
                                       Rect *rPoserMaison, Rect *rPoserRoute, Rect *rPoserElec, Rect *rPoserEau,
                                       Rect *rstatue, Rect *recole, Rect *rtransport, Rect *rparc);
int mettrePause (ALLEGRO_TIMER* timer1s);
int finPause (ALLEGRO_TIMER* timer1s);

#endif //ECE_CITY_2_E_CLCPARTIE1_H

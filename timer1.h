//
// Created by crouz on 27/11/2022.
//

#ifndef ECE_CITY_2_E_TIMER1_H
#define ECE_CITY_2_E_TIMER1_H

#include "affichage1.h"
#include "ftcsReutilisables1.h"

void evolutionMaisonsCapitaliste(Plateau **plateau);
void evolutionMaisonsCommuniste(Plateau **plateau);
int fImpots(Plateau *plateau, int impots);


int dessinerTout(int mode, Plateau *plateau, ALLEGRO_BITMAP *interf, ALLEGRO_DISPLAY *fenetre, ALLEGRO_TIMER *timer1s,
                 int minutes,
                 int niveau, int *bouton, ALLEGRO_BITMAP *pause, ALLEGRO_BITMAP *route,
                 ALLEGRO_BITMAP *maison1, ALLEGRO_BITMAP *maison2, ALLEGRO_BITMAP *maison3,
                 ALLEGRO_BITMAP *maison4,
                 ALLEGRO_BITMAP *maison5,
                 ALLEGRO_BITMAP *eauPNG, ALLEGRO_BITMAP *elecPNG,
                 int sourisX, int sourisY, ALLEGRO_FONT *police20, ALLEGRO_FONT *police30,
                 ALLEGRO_BITMAP *statuePNG, ALLEGRO_BITMAP *ecolePNG, ALLEGRO_BITMAP *transportPNG,
                 ALLEGRO_BITMAP *parcPNG, int *info, int clicX, int clicY);


#endif //ECE_CITY_2_E_TIMER1_H

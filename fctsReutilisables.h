//
// Created by Matis Mur on 11/11/2022.
//

#ifndef PROJETING2_SIMCITYGROUPE2E_FCTSREUTILISABLES_H
#define PROJETING2_SIMCITYGROUPE2E_FCTSREUTILISABLES_H

#include <allegro5/allegro.h>
#include "fonctionPrincipale.h"
//#include "structure.h"
#include <stdbool.h>
#define PAUSE 1
#define SORTIE 2
#define ROUTE 3
#define MAISON 4
#define ELEC 5
#define EAU 6

typedef struct{
    int x,y, larg, haut;
    ALLEGRO_COLOR color;
}Rect;

void convertirLCenXY (int ligne, int colone, int* x, int* y);
void initilisationBoutonEcran2(Rect *rNouvellePartie, Rect *rAnciennePartie);
void selectionRectangle (Rect r, int mouseX, int mouseY, bool *in);
bool verifierCaseOccupe(Plateau *plateau, Case caseDepo, int info);

#endif //PROJETING2_SIMCITYGROUPE2E_FCTSREUTILISABLES_H

//
// Created by crouz on 27/11/2022.
//

#include "ftcsReutilisables1.h"
#include "affichage1.h"

void convertirLCenXY(int ligne, int colone, int *x, int *y) {
    *x = (colone * TAILLE_CASE) + X_DEPART_TRACE;
    *y = (ligne * TAILLE_CASE) + Y_DEPART_TRACE;
}

void selectionRectangle(Rect r, int mouseX, int mouseY, bool *in) {
    if (r.x < mouseX && r.x + r.larg > mouseX &&
        r.y < mouseY && r.y + r.haut > mouseY) { *in = true; }
    else { *in = false; }
}


void initilisationBoutonEcran2(Rect *rNouvellePartie, Rect *rAnciennePartie) {
    rNouvellePartie->x = 225;
    rNouvellePartie->y = 285;
    rNouvellePartie->larg = 935;
    rNouvellePartie->haut = 200;

    rAnciennePartie->x = 225;
    rAnciennePartie->y = 570;
    rAnciennePartie->larg = 935;
    rAnciennePartie->haut = 200;
}


bool verifierCaseOccupe(Plateau *plateau, Case caseDepo, int info) {
    bool occupe = -1;
    int x = caseDepo.x;
    int y = caseDepo.y;
    int ligne = caseDepo.ligne;
    int colonne = caseDepo.colonne;
    switch (info) {
        case ROUTE: {
            if (plateau->tabCases[ligne][colonne].etat == 1) { occupe = true; }
            else { occupe = false; }
            break;
        }
        case MAISON:{
            if ((plateau->tabCases[ligne][colonne].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne].etat == 1) || (plateau->tabCases[ligne + 2][colonne].etat == 1)
                || (plateau->tabCases[ligne][colonne + 1].etat == 1) || (plateau->tabCases[ligne][colonne + 2].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne + 1].etat == 1) ||
                (plateau->tabCases[ligne + 1][colonne + 2].etat == 1)
                || (plateau->tabCases[ligne + 2][colonne + 1].etat == 1) ||
                (plateau->tabCases[ligne + 2][colonne + 2].etat == 1)) {
                occupe = true;
            } else { occupe = false; }
            break;
        }
        case ELEC:{
            if ((plateau->tabCases[ligne][colonne].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne].etat == 1) || (plateau->tabCases[ligne + 2][colonne].etat == 1)
                || (plateau->tabCases[ligne][colonne + 1].etat == 1) || (plateau->tabCases[ligne][colonne + 2].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne + 1].etat == 1) ||(plateau->tabCases[ligne + 1][colonne + 2].etat == 1)
                || (plateau->tabCases[ligne + 2][colonne + 1].etat == 1) ||(plateau->tabCases[ligne + 2][colonne + 2].etat == 1)
                || (plateau->tabCases[ligne + 3][colonne].etat == 1) || (plateau->tabCases[ligne + 3][colonne+1].etat == 1)
                || (plateau->tabCases[ligne + 3][colonne+2].etat == 1) || (plateau->tabCases[ligne + 3][colonne+3].etat == 1)
                || (plateau->tabCases[ligne + 3][colonne+4].etat == 1) || (plateau->tabCases[ligne + 3][colonne+5].etat == 1)
                || (plateau->tabCases[ligne][colonne+3].etat == 1) || (plateau->tabCases[ligne][colonne+4].etat == 1)
                || (plateau->tabCases[ligne][colonne+5].etat == 1) || (plateau->tabCases[ligne + 1][colonne+3].etat == 1)
                || (plateau->tabCases[ligne+1][colonne+4].etat == 1) || (plateau->tabCases[ligne + 1][colonne+5].etat == 1)
                || (plateau->tabCases[ligne + 2][colonne+3].etat == 1)|| (plateau->tabCases[ligne+2][colonne+4].etat == 1)
                || (plateau->tabCases[ligne + 2][colonne+5].etat == 1)){
                occupe = true;}
            else { occupe = false; }
            break;
        }
        case EAU:{
            if ((plateau->tabCases[ligne][colonne].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne].etat == 1) || (plateau->tabCases[ligne + 2][colonne].etat == 1)
                || (plateau->tabCases[ligne][colonne + 1].etat == 1) || (plateau->tabCases[ligne][colonne + 2].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne + 1].etat == 1) ||(plateau->tabCases[ligne + 1][colonne + 2].etat == 1)
                || (plateau->tabCases[ligne + 2][colonne + 1].etat == 1) ||(plateau->tabCases[ligne + 2][colonne + 2].etat == 1)
                || (plateau->tabCases[ligne + 3][colonne].etat == 1) || (plateau->tabCases[ligne + 3][colonne+1].etat == 1)
                || (plateau->tabCases[ligne + 3][colonne+2].etat == 1) || (plateau->tabCases[ligne + 3][colonne+3].etat == 1)
                || (plateau->tabCases[ligne + 3][colonne+4].etat == 1) || (plateau->tabCases[ligne + 3][colonne+5].etat == 1)
                || (plateau->tabCases[ligne][colonne+3].etat == 1) || (plateau->tabCases[ligne][colonne+4].etat == 1)
                || (plateau->tabCases[ligne][colonne+5].etat == 1) || (plateau->tabCases[ligne + 1][colonne+3].etat == 1)
                || (plateau->tabCases[ligne+1][colonne+4].etat == 1) || (plateau->tabCases[ligne + 1][colonne+5].etat == 1)
                || (plateau->tabCases[ligne + 2][colonne+3].etat == 1)|| (plateau->tabCases[ligne+2][colonne+4].etat == 1)
                || (plateau->tabCases[ligne + 2][colonne+5].etat == 1)){
                occupe = true;}
            else { occupe = false; }
            break;
        }
        case 7:{
            if ((plateau->tabCases[ligne][colonne].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne].etat == 1) || (plateau->tabCases[ligne][colonne + 1].etat == 1)
                || (plateau->tabCases[ligne][colonne + 2].etat == 1) || (plateau->tabCases[ligne + 1][colonne + 1].etat == 1)
                ||(plateau->tabCases[ligne + 1][colonne + 2].etat == 1)){
                occupe = true;}
            else { occupe = false; }
            break;
        }
        case 8:{
            if ((plateau->tabCases[ligne][colonne].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne].etat == 1) || (plateau->tabCases[ligne][colonne + 1].etat == 1)
                || (plateau->tabCases[ligne][colonne + 2].etat == 1) || (plateau->tabCases[ligne + 1][colonne + 1].etat == 1)
                ||(plateau->tabCases[ligne + 1][colonne + 2].etat == 1)){
                occupe = true;}
            else { occupe = false; }
            break;
        }
        case 9:{
            if ((plateau->tabCases[ligne][colonne].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne].etat == 1) || (plateau->tabCases[ligne][colonne + 1].etat == 1)
                || (plateau->tabCases[ligne + 1][colonne + 1].etat == 1)){
                occupe = true;}
            else { occupe = false; }
            break;
        }
        case 10:{
            if ((plateau->tabCases[ligne][colonne].etat == 1)||(plateau->tabCases[ligne][colonne + 1].etat == 1)){
                occupe = true;}
            else { occupe = false; }
            break;
        }
    }
    return occupe;
}
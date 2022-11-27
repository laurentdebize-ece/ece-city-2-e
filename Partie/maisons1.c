//
// Created by crouz on 27/11/2022.
//

#include "maisons1.h"
#include "../../ece-city-2-e//ftcsReutilisables1.h"

Batiment creerMaison(Plateau* plateau, Batiment *tabMaison[], int *nbMaison, int *nbBat, int xMaison, int yMaison, int ligneMaison, int colonneMaison) {

    (*nbMaison) ++;
    (*nbBat) ++;

    Batiment nvlMaison = nvllMaison(plateau,xMaison, yMaison, ligneMaison, colonneMaison);
    return nvlMaison;
}
Batiment creerRoute(Plateau* plateau, Batiment *tabMaison[], int *nbBat, int x, int y, int ligne, int colonne) {

    (*nbBat) ++;

    Batiment nvlRoute = nvllroute(plateau,x, y, ligne, colonne);
    return nvlRoute;
}
void rendreOccupe(Plateau **plateau, Case caseDepot, int info) {
    int x = caseDepot.x;
    int y = caseDepot.y;
    int ligne = caseDepot.ligne;
    int colonne = caseDepot.colonne;
    switch (info) {
        case ROUTE: {
            (*plateau)->tabCases[ligne][colonne].etat = 1;
            break;
        }
        case MAISON:{
            (*plateau)->tabCases[ligne][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne + 2].etat = 1;
            break;
        }
        case ELEC:{
            (*plateau)->tabCases[ligne][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+1].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+2].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+3].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+4].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+5].etat = 1;
            (*plateau)->tabCases[ligne][colonne+3].etat = 1;
            (*plateau)->tabCases[ligne][colonne+4].etat = 1;
            (*plateau)->tabCases[ligne][colonne+5].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne+3].etat = 1;
            (*plateau)->tabCases[ligne+1][colonne+4].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne+5].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne+3].etat = 1;
            (*plateau)->tabCases[ligne+2][colonne+4].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne+5].etat = 1;
            break;
        }
        case EAU:{
            (*plateau)->tabCases[ligne][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+1].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+2].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+3].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+4].etat = 1;
            (*plateau)->tabCases[ligne + 3][colonne+5].etat = 1;
            (*plateau)->tabCases[ligne][colonne+3].etat = 1;
            (*plateau)->tabCases[ligne][colonne+4].etat = 1;
            (*plateau)->tabCases[ligne][colonne+5].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne+3].etat = 1;
            (*plateau)->tabCases[ligne+1][colonne+4].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne+5].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne+3].etat = 1;
            (*plateau)->tabCases[ligne+2][colonne+4].etat = 1;
            (*plateau)->tabCases[ligne + 2][colonne+5].etat = 1;
            break;
        }
        case 7:{
            (*plateau)->tabCases[ligne][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 2].etat = 1;
            break;
        }
        case 8:{
            (*plateau)->tabCases[ligne][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 2].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 2].etat = 1;
            break;
        }
        case 9:{
            (*plateau)->tabCases[ligne][colonne].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 1].etat = 1;
            (*plateau)->tabCases[ligne + 1][colonne + 1].etat = 1;
            break;
        }
        case 10:{
            (*plateau)->tabCases[ligne][colonne].etat = 1;
            (*plateau)->tabCases[ligne][colonne + 1].etat = 1;
            break;
        }
    }
}
Batiment nvllMaison(Plateau *plateau, int x, int y, int ligne, int colonne) {
    plateau->banque.flouz -= PRIX_MAISON;
    Batiment nvlMaison;
    nvlMaison.x = x;
    nvlMaison.y = y;
    nvlMaison.ligne = ligne;
    nvlMaison.colonne = colonne;
    nvlMaison.evolution = 0;
    nvlMaison.nbHabitants = 0;
    nvlMaison.alimenteeEau = 0;
    nvlMaison.alimenteeElec =0;
}

Batiment nvllCentrale(Plateau *plateau, int x, int y, int ligne, int colonne) {
    plateau->banque.flouz -= 100000;
    Batiment nvllCentrale;
    nvllCentrale.x = x;
    nvllCentrale.y = y;
    nvllCentrale.ligne = ligne;
    nvllCentrale.colonne = colonne;
    nvllCentrale.evolution = 6;
}

Batiment nvChateauEau(Plateau *plateau, int x, int y, int ligne, int colonne){
    plateau->banque.flouz -= 100000;
    Batiment nvChateauEau;
    nvChateauEau.x = x;
    nvChateauEau.y = y;
    nvChateauEau.ligne = ligne;
    nvChateauEau.colonne = colonne;
    nvChateauEau.evolution = 5;
}

Batiment nvllroute(Plateau *plateau, int x, int y, int ligne, int colonne) {
    plateau->banque.flouz -= 10;
    Batiment nvllRoute;
    nvllRoute.x = x;
    nvllRoute.y = y;
    nvllRoute.ligne = ligne;
    nvllRoute.colonne = colonne;
    nvllRoute.evolution = 7;
}
Batiment nvllStatue(Plateau *plateau, int x, int y, int ligne, int colonne) {
    plateau->banque.flouz -= 5000;
    Batiment nvllStatue;
    nvllStatue.x = x;
    nvllStatue.y = y;
    nvllStatue.ligne = ligne;
    nvllStatue.colonne = colonne;
    nvllStatue.evolution = 8;
}
Batiment nvllEcole(Plateau *plateau, int x, int y, int ligne, int colonne) {
    plateau->banque.flouz -= 7000;
    Batiment nvllEcole;
    nvllEcole.x = x;
    nvllEcole.y = y;
    nvllEcole.ligne = ligne;
    nvllEcole.colonne = colonne;
    nvllEcole.evolution = 9;
}
Batiment nvTransport(Plateau *plateau, int x, int y, int ligne, int colonne) {
    plateau->banque.flouz -= 2000;
    Batiment nvTransport;
    nvTransport.x = x;
    nvTransport.y = y;
    nvTransport.ligne = ligne;
    nvTransport.colonne = colonne;
    nvTransport.evolution = 10;
}
Batiment nvParc(Plateau *plateau, int x, int y, int ligne, int colonne) {
    plateau->banque.flouz -= 1000;
    Batiment nvParc;
    nvParc.x = x;
    nvParc.y = y;
    nvParc.ligne = ligne;
    nvParc.colonne = colonne;
    nvParc.evolution = 11;
}
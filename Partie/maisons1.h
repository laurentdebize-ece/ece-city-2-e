//
// Created by crouz on 27/11/2022.
//

#ifndef ECE_CITY_2_E_MAISONS1_H
#define ECE_CITY_2_E_MAISONS1_H

#include "../../ece-city-2-e//affichage1.h"

Batiment nvllMaison(Plateau *plateau, int x, int y, int ligne, int colonne);
Batiment creerMaison(Plateau *plateau, Batiment *tabMaison[], int *nbMaison, int *nbBat, int xMaison, int yMaison, int ligneMaison, int colonneMaison) ;
Batiment creerRoute(Plateau* plateau, Batiment *tabMaison[], int *nbBat, int x, int y, int ligne, int colonne);
Batiment nvllCentrale(Plateau *plateau, int x, int y, int ligne, int colonne);
void rendreOccupe(Plateau **plateau, Case caseDepot, int info) ;
Batiment nvChateauEau(Plateau *plateau, int x, int y, int ligne, int colonne);
Batiment nvllroute(Plateau *plateau, int x, int y, int ligne, int colonne);
Batiment nvllStatue(Plateau *plateau, int x, int y, int ligne, int colonne);
Batiment nvllEcole(Plateau *plateau, int x, int y, int ligne, int colonne);
Batiment nvTransport(Plateau *plateau, int x, int y, int ligne, int colonne);
Batiment nvParc(Plateau *plateau, int x, int y, int ligne, int colonne);

#endif //ECE_CITY_2_E_MAISONS1_H

//
// Created by crouz on 27/11/2022.
//

#ifndef ECE_CITY_2_E_SAUVEGARDE1_H
#define ECE_CITY_2_E_SAUVEGARDE1_H

#include "affichage1.h"

void sauvegarderElec(Plateau *plateau);
void sauvegarderEeau(Plateau *plateau);
void sauvegarderBatiment(Plateau *plateau);
void sauvegarder(Plateau *plateau);
Plateau chargerSauvegarde();
void initTabCase(Plateau *plateau);

#endif //ECE_CITY_2_E_SAUVEGARDE1_H

//
// Created by crouz on 16/11/2022.
//

#ifndef PROJETING2_SIMCITYGROUPE2E_SAUVEGARDE_H
#define PROJETING2_SIMCITYGROUPE2E_SAUVEGARDE_H

#include "affichage.h"

void sauvegarderElec(Plateau *plateau);
void sauvegarderEeau(Plateau *plateau);
void sauvegarderBatiment(Plateau *plateau);
void sauvegarder(Plateau *plateau);
Plateau chargerSauvegarde();
void initTabCase(Plateau *plateau);
#endif //PROJETING2_SIMCITYGROUPE2E_SAUVEGARDE_H

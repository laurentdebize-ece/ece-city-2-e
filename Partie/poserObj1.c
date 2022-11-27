//
// Created by crouz on 27/11/2022.
//

#include "poserObj1.h"
#include "maisons1.h"

void poserObjet(int sourisX, int sourisY, Plateau **plateau, int info) {
    bool occupe = -1;

    Case caseDepo = caseDepoObjets(sourisX, sourisY, plateau);
    occupe = verifierCaseOccupe(*plateau, caseDepo, info);

    switch (info) {
        case ROUTE: {
            if (occupe != true && ((*plateau)->banque.flouz - PRIX_ROUTE) >= 0) {
                (*plateau)->nbBat ++;
                Batiment nvlRoute = nvllroute(*plateau, caseDepo.x, caseDepo.y, caseDepo.x, caseDepo.y);
                (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment = nvlRoute;

                (*plateau)->tabBatiment[((*plateau)->nbBat)-1] = (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment;
                (*plateau)->tabBatiment[((*plateau)->nbBat)-1].x = caseDepo.x;
                (*plateau)->tabBatiment[((*plateau)->nbBat)-1].y = caseDepo.y;
                (*plateau)->tabBatiment[((*plateau)->nbBat)-1].evolution = 7;
                rendreOccupe(plateau, caseDepo, info);
            }
            break;
        }
        case MAISON: {
            if ((sourisX >= X_DEPART_TRACE) && (sourisX <= X_FIN_TRACE - (2 * TAILLE_CASE)) &&
                (sourisY >= Y_DEPART_TRACE) && (sourisY <= Y_FIN_TRACE - (2 * TAILLE_CASE))) {

                if (occupe != true && ((*plateau)->banque.flouz - PRIX_MAISON) >= 0) {
                    (*plateau)->nbMaisons++;
                    (*plateau)->nbBat ++;
                    Batiment nvlMaison = nvllMaison(*plateau,caseDepo.x, caseDepo.y, caseDepo.x, caseDepo.y);
                    (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment = nvlMaison;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1] = (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].x = caseDepo.x;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].y = caseDepo.y;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].evolution = 0;
                    rendreOccupe(plateau, caseDepo, info);
                }
            }
            break;
        }
        case ELEC: {
            if ((sourisX >= X_DEPART_TRACE) && (sourisX <= X_FIN_TRACE - (5 * TAILLE_CASE)) &&
                (sourisY >= Y_DEPART_TRACE) && (sourisY <= Y_FIN_TRACE - (3 * TAILLE_CASE))) {

                if (occupe != true && ((*plateau)->banque.flouz - PRIX_CENTRALE) >= 0) {
                    (*plateau)->nbBat ++;
                    Batiment nvlCentrale = nvllCentrale(*plateau,caseDepo.x, caseDepo.y, caseDepo.x, caseDepo.y);
                    (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment = nvlCentrale;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1] = (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].x = caseDepo.x;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].y = caseDepo.y-32;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].evolution = 6;
                    (*plateau)->banque.capaElec += 5000;
                    rendreOccupe(plateau, caseDepo, info);
                }
            }
            break;
        }
        case EAU: {
            if ((sourisX >= X_DEPART_TRACE) && (sourisX <= X_FIN_TRACE - (5 * TAILLE_CASE)) &&
                (sourisY >= Y_DEPART_TRACE) && (sourisY <= Y_FIN_TRACE - (3 * TAILLE_CASE))) {

                if (occupe != true && ((*plateau)->banque.flouz - PRIX_CENTRALE) >= 0) {
                    (*plateau)->nbBat ++;
                    Batiment nvChateaudEau = nvChateauEau(*plateau,caseDepo.x, caseDepo.y, caseDepo.x, caseDepo.y);
                    (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment = nvChateaudEau;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1] = (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].x = caseDepo.x;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].y = caseDepo.y-28;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].evolution = 5;
                    (*plateau)->banque.capaEau += 5000;
                    rendreOccupe(plateau, caseDepo, info);
                }
            }
            break;
        }
        case 7: {
            if ((sourisX >= X_DEPART_TRACE) && (sourisX <= X_FIN_TRACE - (2 * TAILLE_CASE)) &&
                (sourisY >= Y_DEPART_TRACE) && (sourisY <= Y_FIN_TRACE - (1 * TAILLE_CASE))) {

                if (occupe != true && ((*plateau)->banque.flouz - 5000) >= 0) {
                    (*plateau)->nbBat ++;
                    (*plateau)->nbBonus ++;
                    Batiment nvStatue = nvllStatue(*plateau,caseDepo.x, caseDepo.y, caseDepo.x, caseDepo.y);
                    (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment = nvStatue;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1] = (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].x = caseDepo.x;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].y = caseDepo.y-41;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].evolution = 8;
                    rendreOccupe(plateau, caseDepo, info);
                }
            }
            break;
        }
        case 8: {
            if ((sourisX >= X_DEPART_TRACE) && (sourisX <= X_FIN_TRACE - (2 * TAILLE_CASE)) &&
                (sourisY >= Y_DEPART_TRACE) && (sourisY <= Y_FIN_TRACE - (1 * TAILLE_CASE))) {

                if (occupe != true && ((*plateau)->banque.flouz - 7000) >= 0) {
                    (*plateau)->nbBat ++;
                    (*plateau)->nbBonus ++;
                    Batiment newEcole = nvllEcole(*plateau,caseDepo.x, caseDepo.y, caseDepo.x, caseDepo.y);
                    (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment = newEcole;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1] = (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].x = caseDepo.x;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].y = caseDepo.y;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].evolution = 9;
                    rendreOccupe(plateau, caseDepo, info);
                }
            }
            break;
        }
        case 9: {
            if ((sourisX >= X_DEPART_TRACE) && (sourisX <= X_FIN_TRACE - (1 * TAILLE_CASE)) &&
                (sourisY >= Y_DEPART_TRACE) && (sourisY <= Y_FIN_TRACE - (1 * TAILLE_CASE))) {

                if (occupe != true && ((*plateau)->banque.flouz - 2000) >= 0) {
                    (*plateau)->nbBat ++;
                    (*plateau)->nbBonus ++;
                    Batiment newTransport = nvTransport(*plateau,caseDepo.x, caseDepo.y, caseDepo.x, caseDepo.y);
                    (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment = newTransport;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1] = (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].x = caseDepo.x;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].y = caseDepo.y;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].evolution = 10;
                    rendreOccupe(plateau, caseDepo, info);
                }
            }
            break;
        }
        case 10: {
            if ((sourisX >= X_DEPART_TRACE) && (sourisX <= X_FIN_TRACE - (1 * TAILLE_CASE)) &&
                (sourisY >= Y_DEPART_TRACE) && (sourisY <= Y_FIN_TRACE - (0 * TAILLE_CASE))) {

                if (occupe != true && ((*plateau)->banque.flouz - 1000) >= 0) {
                    (*plateau)->nbBat ++;
                    (*plateau)->nbBonus ++;
                    Batiment newParc = nvParc(*plateau,caseDepo.x, caseDepo.y, caseDepo.x, caseDepo.y);
                    (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment = newParc;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1] = (*plateau)->tabCases[caseDepo.colonne][caseDepo.ligne].batiment;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].x = caseDepo.x;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].y = caseDepo.y;
                    (*plateau)->tabBatiment[((*plateau)->nbBat)-1].evolution = 11;
                    rendreOccupe(plateau, caseDepo, info);
                }
            }
            break;
        }
    }
}


Case caseDepoObjets(int sourisX, int sourisY, Plateau **plateau) {
    Case caseDepo;

    caseDepo.colonne = (int) (sourisX - X_DEPART_TRACE) / TAILLE_CASE;
    caseDepo.ligne = (int) (sourisY - Y_DEPART_TRACE) / TAILLE_CASE;
    //printf("CASE DEPOT OBJET : \ncolone:%d\nligne:%d\n", caseDepo.colonne, caseDepo.ligne);

    convertirLCenXY(caseDepo.ligne, caseDepo.colonne, &caseDepo.x, &caseDepo.y);
    //printf("CASE DEPOT OBJET : \nx:%d\ny:%d\n", caseDepo.x, caseDepo.y);
    return caseDepo;
}
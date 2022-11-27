//
// Created by crouz on 27/11/2022.
//

#include "clcPartie1.h"
#include "../menuPrincipal/menuPrincipal1.h"

///fonctions qui gèrent la pause
int mettrePause(ALLEGRO_TIMER *timer1s) {
    printf("fct de Pause\n");
    al_stop_timer(timer1s);
    return 1;
}

int finPause(ALLEGRO_TIMER *timer1s) {
    printf("fct de fin de Pause\n");
    al_start_timer(timer1s);
    return 0;
}


int clicsPartie(ALLEGRO_BITMAP *interf, int mouseX, int mouseY, ALLEGRO_TIMER *timer1s, int minutes, int niveau,
                int *etatBouton) {///fonction qui check quand et quels boutons sont selectionner lors de la partie

    Rect rPLATEAU;

    Rect rpause;
    Rect rsortie;
    Rect rFinPause;
    Rect rPoserMaison;
    Rect rPoserRoute;
    Rect rPoserElec;
    Rect rPoserEau;

    Rect rstatue;
    Rect recole;
    Rect rtransport;
    Rect rparc;

    initilisationTaillesBoutonsPartie(&rPLATEAU, &rpause, &rsortie, &rFinPause,
                                      &rPoserMaison, &rPoserRoute, &rPoserElec, &rPoserEau,
                                      &rstatue, &recole, &rtransport, &rparc);
    bool in = false;
    //   refaire ce meme schema pour chaque nouveau bouton (en mettant var+1 a chaques fois)
    selectionRectangle(rpause, mouseX, mouseY, &in);
    if (in == true) {
        in = false;
        *etatBouton = mettrePause(timer1s); // 1
    }

    selectionRectangle(rFinPause, mouseX, mouseY, &in);
    if (((*etatBouton) == PAUSE) && (in == true)) {
        *etatBouton = finPause(timer1s);
    }

    selectionRectangle(rsortie, mouseX, mouseY, &in);
    if (in == true) {
        printf("SORTIE\n");
        in = false;
        *etatBouton = 2;
        //return 100;
    }

    selectionRectangle(rPoserRoute, mouseX, mouseY, &in);
    if (in == true) {
        if (*etatBouton == 3) {
            printf("désélection poser ROUTE\n");
            in = false;
            *etatBouton = 0;
        } else {
            printf("Poser ROUTE\n");
            in = false;
            *etatBouton = 3;
        }
    }
    selectionRectangle(rPoserMaison, mouseX, mouseY, &in);
    if (in == true) {
        if (*etatBouton == 4) {
            printf("désélection poser MAISON\n");
            in = false;
            *etatBouton = 0;
        } else {
            printf("Poser MAISON\n");
            in = false;
            *etatBouton = 4;
        }
    }
    selectionRectangle(rPoserElec, mouseX, mouseY, &in);
    if (in == true) {
        if (*etatBouton == 5) {
            printf("désélection poser ELEC\n");
            in = false;
            *etatBouton = 0;
        } else {
            printf("Poser ELEC\n");
            in = false;
            *etatBouton = 5;
        }
    }
    selectionRectangle(rPoserEau, mouseX, mouseY, &in);
    if (in == true) {
        if (*etatBouton == 6) {
            printf("désélection poser EAU\n");
            in = false;
            *etatBouton = 0;
        } else {
            printf("Poser EAU\n");
            in = false;
            *etatBouton = 6;
        }
    }
    selectionRectangle(rstatue, mouseX, mouseY, &in);
    if (in == true) {
        if (*etatBouton == 7) {
            printf("désélection poser STATUE\n");
            in = false;
            *etatBouton = 0;
        } else {
            printf("Poser STATUE\n");
            in = false;
            *etatBouton = 7;
        }
    }
    selectionRectangle(recole, mouseX, mouseY, &in);
    if (in == true) {
        if (*etatBouton == 8) {
            printf("désélection poser ECOLE\n");
            in = false;
            *etatBouton = 0;
        } else {
            printf("Poser ECOLE\n");
            in = false;
            *etatBouton = 8;
        }
    }
    selectionRectangle(rtransport, mouseX, mouseY, &in);
    if (in == true) {
        if (*etatBouton == 9) {
            printf("désélection poser TRANSPORT\n");
            in = false;
            *etatBouton = 0;
        } else {
            printf("Poser TRANSPORT\n");
            in = false;
            *etatBouton = 9;
        }
    }
    selectionRectangle(rparc, mouseX, mouseY, &in);
    if (in == true) {
        if (*etatBouton == 10) {
            printf("désélection poser PARC\n");
            in = false;
            *etatBouton = 0;
        } else {
            printf("Poser PARC\n");
            in = false;
            *etatBouton = 10;

        }
    }
    return *etatBouton;
}

void initilisationTaillesBoutonsPartie(Rect *rPLATEAU, Rect *rpause, Rect *rsortie, Rect *rFinPause,
                                       Rect *rPoserMaison, Rect *rPoserRoute, Rect *rPoserElec, Rect *rPoserEau,
                                       Rect *rstatue, Rect *recole, Rect *rtransport, Rect *rparc) {///fonction qui donne l'emplacement de tous les boutons de l'interface de jeu
    rPLATEAU->x = X_DEPART_TRACE;
    rPLATEAU->y = Y_DEPART_TRACE;
    rPLATEAU->larg = X_FIN_TRACE-X_DEPART_TRACE;
    rPLATEAU->y = Y_FIN_TRACE-X_DEPART_TRACE;

    rpause->x = 1246;
    rpause->y = 82;
    rpause->larg = rpause->haut = 70;

    rsortie->x = 1246;
    rsortie->y = 170;
    rsortie->larg = rsortie->haut = 70;

    rFinPause->x = 510;
    rFinPause->y = 280;
    rFinPause->larg = 410;
    rFinPause->haut = 320;

    rPoserRoute->x = 1232;
    rPoserRoute->y = 354;
    rPoserRoute->larg = rPoserRoute->haut = 94;

    rPoserMaison->x = 1232;
    rPoserMaison->y = 450;
    rPoserMaison->larg = rPoserMaison->haut = 94;

    rPoserElec->x = 1232;
    rPoserElec->y = 548;
    rPoserElec->larg = rPoserElec->haut = 94;

    rPoserEau->x = 1232;
    rPoserEau->y = 646;
    rPoserEau->larg = rPoserEau->haut = 94;

    rstatue->x = rtransport->x = 32;
    rstatue->y = recole->y = 340;
    recole->x = rparc->x = 125;
    rtransport->y = rparc->y = 430;

    rstatue->larg = rstatue->haut = rtransport->larg = rtransport->haut = recole->larg = recole->haut = rparc->larg = rparc->haut = 50;
}
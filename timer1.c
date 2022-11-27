//
// Created by crouz on 27/11/2022.
//

#include "timer1.h"
#include <allegro5/allegro.h>
#include "affichage1.h"
#include "Partie/poserObj1.h"


void evolutionMaisonsCapitaliste(Plateau **plateau) {

    for (int i = 0; i < (*plateau)->nbMaisons; i++) {
        ///evolution des batiments
        if ((*plateau)->tabBatiment[i].evolution < 4 && (*plateau)->tabBatiment[i].timerEvo >= 600) {
            (*plateau)->tabBatiment[i].evolution++;
            (*plateau)->tabBatiment[i].timerEvo = 0;
            switch ((*plateau)->tabBatiment[i].evolution) {
                case 1 : {
                    (*plateau)->nbHabitants += NBHAB_CABANE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_CABANE;
                    break;
                }
                case 2 : {
                    (*plateau)->nbHabitants += NBHAB_MAISON - NBHAB_CABANE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_MAISON;
                    break;
                }
                case 3 : {
                    (*plateau)->nbHabitants += NBHAB_IMMEUBLE - NBHAB_MAISON;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_IMMEUBLE;
                    break;
                }
                case 4 : {
                    (*plateau)->nbHabitants += NBHAB_CHATEAU - NBHAB_IMMEUBLE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_CHATEAU;
                    break;
                }
            }
        }
        ///regression des batiments
        int nbHabitantsApresRegression = 0;
        switch ((*plateau)->tabBatiment[i].evolution-1) {
            case 0 : {
                nbHabitantsApresRegression = (*plateau)->nbHabitants - NBHAB_CABANE;
                break;
            }
            case 1 : {
                nbHabitantsApresRegression = (*plateau)->nbHabitants - (NBHAB_MAISON - NBHAB_CABANE);
                break;
            }
            case 2 : {
                nbHabitantsApresRegression = (*plateau)->nbHabitants - (NBHAB_IMMEUBLE - NBHAB_MAISON);
                break;
            }
            case 3 : {
                nbHabitantsApresRegression = (*plateau)->nbHabitants - (NBHAB_CHATEAU - NBHAB_IMMEUBLE);
                break;
            }
        }
        if ((*plateau)->tabBatiment[i].evolution >= 1 &&
            (*plateau)->tabBatiment[i].evolution <= 4 &&
            (*plateau)->tabBatiment[i].timerEvo >= 600 &&
            nbHabitantsApresRegression <= (*plateau)->banque.capaEau &&
            nbHabitantsApresRegression <= (*plateau)->banque.capaElec){

            (*plateau)->tabBatiment[i].evolution--;
            (*plateau)->tabBatiment[i].timerEvo = 0;
            switch ((*plateau)->tabBatiment[i].evolution) {
                case 0 : {
                    (*plateau)->nbHabitants -= NBHAB_CABANE;
                    (*plateau)->tabBatiment[i].nbHabitants = 0;
                    break;
                }
                case 1 : {
                    (*plateau)->nbHabitants -= NBHAB_MAISON - NBHAB_CABANE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_CABANE;
                    break;
                }
                case 2 : {
                    (*plateau)->nbHabitants -= NBHAB_IMMEUBLE - NBHAB_MAISON;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_MAISON;
                    break;
                }
                case 3 : {
                    (*plateau)->nbHabitants -= NBHAB_CHATEAU - NBHAB_IMMEUBLE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_IMMEUBLE;
                    break;
                }
            }
        }
    }
}

void evolutionMaisonsCommuniste(Plateau **plateau) {
    for (int i = 0; i < (*plateau)->nbMaisons; i++) {
        int nbHabitantPlateauNivSuiv = 0;
        switch ((*plateau)->tabBatiment[i].evolution + 1) {
            case 1 : {
                nbHabitantPlateauNivSuiv = (*plateau)->nbHabitants + NBHAB_CABANE;
                break;
            }
            case 2 : {
                nbHabitantPlateauNivSuiv = (*plateau)->nbHabitants + NBHAB_MAISON - NBHAB_CABANE;
                break;
            }
            case 3 : {
                nbHabitantPlateauNivSuiv = (*plateau)->nbHabitants + NBHAB_IMMEUBLE - NBHAB_MAISON;
                break;
            }
            case 4 : {
                nbHabitantPlateauNivSuiv = (*plateau)->nbHabitants + NBHAB_CHATEAU - NBHAB_IMMEUBLE;
                break;
            }
        }
        ///evolution des batiments
        if ((*plateau)->tabBatiment[i].evolution < 4 &&
            (*plateau)->tabBatiment[i].alimenteeEau == 1 &&
            (*plateau)->tabBatiment[i].alimenteeElec == 1 &&
            nbHabitantPlateauNivSuiv <= (*plateau)->banque.capaEau &&
            nbHabitantPlateauNivSuiv <= (*plateau)->banque.capaElec &&
            (*plateau)->tabBatiment[i].timerEvo >= 600) {
            (*plateau)->tabBatiment[i].evolution++;
            (*plateau)->tabBatiment[i].timerEvo = 0;
            switch ((*plateau)->tabBatiment[i].evolution) {
                case 1 : {
                    (*plateau)->nbHabitants += NBHAB_CABANE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_CABANE;
                    break;
                }
                case 2 : {
                    (*plateau)->nbHabitants += NBHAB_MAISON - NBHAB_CABANE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_MAISON;
                    break;
                }
                case 3 : {
                    (*plateau)->nbHabitants += NBHAB_IMMEUBLE - NBHAB_MAISON;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_IMMEUBLE;
                    break;
                }
                case 4 : {
                    (*plateau)->nbHabitants += NBHAB_CHATEAU - NBHAB_IMMEUBLE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_CHATEAU;
                    break;
                }
            }
        }
        ///regression des batiments
        if ((*plateau)->tabBatiment[i].evolution >= 1 && (*plateau)->tabBatiment[i].evolution <= 4 &&
            (*plateau)->tabBatiment[i].alimenteeEau == 0 &&
            (*plateau)->tabBatiment[i].alimenteeElec == 0 && (*plateau)->tabBatiment[i].timerEvo >= 600) {
            (*plateau)->tabBatiment[i].evolution--;
            (*plateau)->tabBatiment[i].timerEvo = 0;
            switch ((*plateau)->tabBatiment[i].evolution) {
                case 0 : {
                    (*plateau)->nbHabitants -= NBHAB_CABANE;
                    (*plateau)->tabBatiment[i].nbHabitants = 0;
                    break;
                }
                case 1 : {
                    (*plateau)->nbHabitants -= NBHAB_MAISON - NBHAB_CABANE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_CABANE;
                    break;
                }
                case 2 : {
                    (*plateau)->nbHabitants -= NBHAB_IMMEUBLE - NBHAB_MAISON;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_MAISON;
                    break;
                }
                case 3 : {
                    (*plateau)->nbHabitants -= NBHAB_CHATEAU - NBHAB_IMMEUBLE;
                    (*plateau)->tabBatiment[i].nbHabitants = NBHAB_IMMEUBLE;
                    break;
                }
            }
        }
    }
}

int dessinerTout(int mode, Plateau *plateau, ALLEGRO_BITMAP *interf, ALLEGRO_DISPLAY *fenetre, ALLEGRO_TIMER *timer1s,
                 int minutes, int niveau, int *bouton, ALLEGRO_BITMAP *pause, ALLEGRO_BITMAP *route,
                 ALLEGRO_BITMAP *maison1, ALLEGRO_BITMAP *maison2, ALLEGRO_BITMAP *maison3,
                 ALLEGRO_BITMAP *maison4, ALLEGRO_BITMAP *maison5, ALLEGRO_BITMAP *eauPNG, ALLEGRO_BITMAP *elecPNG,
                 int sourisX, int sourisY, ALLEGRO_FONT *police20, ALLEGRO_FONT *police30,
                 ALLEGRO_BITMAP *statuePNG, ALLEGRO_BITMAP *ecolePNG, ALLEGRO_BITMAP *transportPNG,
                 ALLEGRO_BITMAP *parcPNG, int *info, int clicX, int clicY) {
    al_init_font_addon();
    assert(al_init_primitives_addon());

    if (niveau == 0) {

        dessinerNiv0(plateau);
        dessinerMap();
        for (int i = 0; i < plateau->nbBat; i++) {
            switch (plateau->tabBatiment[i].evolution) {
                case 0 : {
                    al_draw_bitmap(maison1, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 1 : {
                    al_draw_bitmap(maison2, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 2 : {
                    al_draw_bitmap(maison3, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 4 : {
                    al_draw_bitmap(maison5, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 7 : {
                    al_draw_bitmap(route, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 9 : {
                    al_draw_bitmap(ecolePNG, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 10 : {
                    al_draw_bitmap(transportPNG, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 11 : {
                    al_draw_bitmap(parcPNG, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;

                }
                case 3 : {
                    al_draw_bitmap(maison4, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 5 : {
                    al_draw_bitmap(eauPNG, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 6 : {
                    al_draw_bitmap(elecPNG, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }
                case 8 : {
                    al_draw_bitmap(statuePNG, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
                    break;
                }

            }
        }


    } else if (niveau == 1) {
        dessinerNiv1(plateau, eauPNG);
        dessinerMap();
    } else if (niveau == 2) {
        dessinerNiv2(plateau, elecPNG);
        dessinerMap();
    }

    al_draw_bitmap(interf, 0, 0, 0);

    ///dessin du compteur temps
    if (al_get_timer_count(timer1s) == 60) {
        al_stop_timer(timer1s);
        al_set_timer_count(timer1s, 0);
        al_start_timer(timer1s);
        minutes = minutes + 1;
    }
    if (mode == CAPITALISTE) {
        evolutionMaisonsCapitaliste(&plateau);
    }
    if (mode == COMMUNISTE) {
        evolutionMaisonsCommuniste(&plateau);
    }
    if (minutes < 10 && al_get_timer_count(timer1s) < 10) {
        al_draw_textf(police30, al_map_rgb(0, 0, 0), 700, 35, 0, "0%d : 0%d", minutes,
                      al_get_timer_count(timer1s));
    } else if (minutes < 10 && al_get_timer_count(timer1s) >= 10) {
        al_draw_textf(police30, al_map_rgb(0, 0, 0), 700, 35, 0, "0%d : %d", minutes,
                      al_get_timer_count(timer1s));
    } else if (minutes >= 10 && al_get_timer_count(timer1s) < 10) {
        al_draw_textf(police30, al_map_rgb(0, 0, 0), 700, 35, 0, "%d : 0%d", minutes,
                      al_get_timer_count(timer1s));
    } else {
        al_draw_textf(police30, al_map_rgb(0, 0, 0), 700, 35, 0, "%d : %d", minutes,
                      al_get_timer_count(timer1s));
    }
    if (((al_get_timer_count(timer1s) % 15) == 0) && (al_get_timer_count(timer1s) != 0)) {
        al_draw_textf(police20, al_map_rgb(255, 0, 0), 605, 80, 0, "Evolution des Batiments");
    }
    switch (*bouton) {

        ///dessin des boutons de l'interface jeu
        case PAUSE : {
            al_draw_bitmap(pause, 0, 0, 0);
            break;
        }
        case SORTIE : {
            ecranChargementSauvegarde(fenetre);
            return 100;
        }
        case ROUTE: {
            al_draw_bitmap(route, sourisX, sourisY, 0);
            al_draw_textf(police30, al_map_rgb(0, 0, 0), 1230, 300, 0, "ROUTE");
            *info = ROUTE;
            break;
        }
        case MAISON: {
            al_draw_bitmap(maison1, sourisX, sourisY, 0);
            al_draw_textf(police30, al_map_rgb(0, 0, 0), 1221, 300, 0, "MAISON");
            *info = MAISON;
            break;
        }
        case ELEC: {
            al_draw_bitmap(elecPNG, sourisX, sourisY, 0);
            al_draw_textf(police30, al_map_rgb(0, 0, 0), 1212, 300, 0, "CENTRALE");
            *info = ELEC;
            break;
        }
        case EAU: {
            al_draw_bitmap(eauPNG, sourisX, sourisY, 0);
            al_draw_textf(police30, al_map_rgb(0, 0, 0), 1177, 300, 0, "CHATEAU D'EAU");
            *info = EAU;
            break;
        }
        case 7: {
            al_draw_bitmap(statuePNG, sourisX, sourisY, 0);
            al_draw_textf(police30, al_map_rgb(0, 0, 0), 55, 485, 0, "STATUE");
            *info = 7;
            break;
        }
        case 8: {
            al_draw_bitmap(ecolePNG, sourisX, sourisY, 0);
            al_draw_textf(police30, al_map_rgb(0, 0, 0), 63, 485, 0, "ECOLE");
            *info = 8;
            break;
        }
        case 9: {
            al_draw_bitmap(transportPNG, sourisX, sourisY, 0);
            al_draw_textf(police30, al_map_rgb(0, 0, 0), 27, 485, 0, "TRANSPORT");
            *info = 9;
            break;
        }
        case 10: {
            al_draw_bitmap(parcPNG, sourisX, sourisY, 0);
            al_draw_textf(police30, al_map_rgb(0, 0, 0), 69, 485, 0, "PARC");
            *info = 10;
            break;
        }
    }

    ///dessin compteur flouz
    al_draw_textf(police30, al_map_rgb(255, 255, 255), 1060, 35, 0, "%d", plateau->banque.flouz);

    ///dessin compteur habitants
    al_draw_textf(police30, al_map_rgb(255, 255, 255), 290, 40, 0, "%d", plateau->nbHabitants);

    ///dessin niveau (0, -1, -2)
    al_draw_textf(police20, al_map_rgb(0, 0, 0), 65, 580, 0, "Niveau : %d", niveau);

    ///dessin ressources
    if (plateau->nbHabitants < 1000) {
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 120, 188, 0, "%d", plateau->nbHabitants);
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 120, 260, 0, "%d", plateau->nbHabitants);
    }
    if (plateau->nbHabitants >= 1000 && plateau->nbHabitants < 10000) {
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 100, 188, 0, "%d", plateau->nbHabitants);
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 100, 260, 0, "%d", plateau->nbHabitants);
    }
    if (plateau->nbHabitants >= 10000) {
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 95, 188, 0, "%d", plateau->nbHabitants);
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 95, 260, 0, "%d", plateau->nbHabitants);
    }
    if (plateau->banque.capaEau == 0) {
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 120, 210, 0, "%d", plateau->banque.capaEau);
    }
    if (plateau->banque.capaEau < 10000 && plateau->banque.capaEau != 0) {
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 100, 210, 0, "%d", plateau->banque.capaEau);
    }
    if (plateau->banque.capaEau >= 10000 && plateau->banque.capaEau < 100000) {
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 93, 210, 0, "%d", plateau->banque.capaEau);
    }
    if (plateau->banque.capaElec == 0) {
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 120, 283, 0, "%d", plateau->banque.capaElec);
    }
    if (plateau->banque.capaElec < 10000 && plateau->banque.capaElec != 0) {
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 100, 283, 0, "%d", plateau->banque.capaElec);
    }
    if (plateau->banque.capaElec >= 10000 && plateau->banque.capaElec < 100000) {
        al_draw_textf(police20, al_map_rgb(0, 0, 0), 93, 283, 0, "%d", plateau->banque.capaElec);
    }
    al_draw_line(87, 212, 160, 212, al_map_rgb(0, 0, 0), 0);
    al_draw_line(87, 285, 160, 285, al_map_rgb(0, 0, 0), 0);
    if ((plateau->nbMaisons + 4 * plateau->nbBonus) * 20 / (plateau->nbMaisons + 1) <= 100) {
        al_draw_textf(police20, al_map_rgb(255, 255, 255), 100, 538, 0, "%d%%",
                      ((plateau->nbMaisons + 4 * plateau->nbBonus) * 20 / (plateau->nbMaisons + 1)));
    } else if ((plateau->nbMaisons + 4 * plateau->nbBonus) * 20 / (plateau->nbMaisons + 1) >= 100) {
        al_draw_textf(police20, al_map_rgb(255, 255, 255), 100, 538, 0, "100%%");
    }

    al_flip_display();
    return minutes;
}

int fImpots(Plateau *plateau, int impots) {
    impots++;
    if (impots == 600) {
        impots = 0;
        plateau->banque.flouz += TAXE_HABITANT * plateau->nbHabitants;
        printf("%d", plateau->banque.flouz);
    }
    return impots;
}
//
// Created by crouz on 03/11/2022.
//

#include "affichage.h"

void dessinerMap() {
    //dessin de la grille
    for (int i = 0; i < (NB_CASES_LARGEUR + 1); ++i) {
        al_draw_line(X_DEPART_TRACE + (i * TAILLE_CASE),
                     Y_DEPART_TRACE,
                     X_DEPART_TRACE + (i * TAILLE_CASE),
                     Y_DEPART_TRACE + (NB_CASES_HAUTEUR * TAILLE_CASE),
                     COULEUR_LIGNE,
                     THICKNESS_LIGNE);
    }
    for (int i = 0; i < (NB_CASES_HAUTEUR + 1); ++i) {
        al_draw_line(X_DEPART_TRACE,
                     Y_DEPART_TRACE + (i * TAILLE_CASE),
                     X_DEPART_TRACE + (NB_CASES_LARGEUR * TAILLE_CASE),
                     Y_DEPART_TRACE + (i * TAILLE_CASE),
                     COULEUR_LIGNE,
                     THICKNESS_LIGNE);
    }
}

void dessinerRoute(Plateau *plateau) {
    for (int i = 0; i < plateau->nbBat; i++) {
        if (plateau->tabBatiment[i].evolution==7){
            al_draw_filled_rectangle(plateau->tabBatiment[i].x,
                                     plateau->tabBatiment[i].y,
                                     plateau->tabBatiment[i].x + TAILLE_CASE,
                                     plateau->tabBatiment[i].y + TAILLE_CASE,
                                     COULEUR_ROUTE);

        }
    }
}

void dessinerReseauEau(Plateau *plateau, ALLEGRO_BITMAP *eau) {
    for (int i = 0; i < plateau->nbBat; i++) {
        if (plateau->tabBatiment[i].evolution==7){
            al_draw_filled_rectangle(plateau->tabBatiment[i].x,
                                     plateau->tabBatiment[i].y,
                                     plateau->tabBatiment[i].x + TAILLE_CASE,
                                     plateau->tabBatiment[i].y + TAILLE_CASE,
                                     COULEUR_EAU);

        }
        if (plateau->tabBatiment[i].evolution==5){
            al_draw_bitmap(eau, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);
        }
    }
}

void dessinerReseauElec(Plateau *plateau, ALLEGRO_BITMAP *elec) {
    for (int i = 0; i < plateau->nbBat; i++) {
        if (plateau->tabBatiment[i].evolution==7){
            al_draw_filled_rectangle(plateau->tabBatiment[i].x,
                                     plateau->tabBatiment[i].y,
                                     plateau->tabBatiment[i].x + TAILLE_CASE,
                                     plateau->tabBatiment[i].y + TAILLE_CASE,
                                     COULEUR_ELEC);

        }
        if (plateau->tabBatiment[i].evolution==6){
            al_draw_bitmap(elec, plateau->tabBatiment[i].x, plateau->tabBatiment[i].y, 0);

        }
    }
}

void dessinerNiv0(Plateau *plateau) {
    //dessin Bitmap Niv 0
    al_clear_to_color(al_map_rgb(208, 232, 217));
    //dessinerMap();
    dessinerRoute(plateau);
    //al_flip_display();
}

void dessinerNiv1(Plateau *plateau, ALLEGRO_BITMAP *eau) {
    //dessin Bitmap Niv -1
    al_clear_to_color(al_map_rgb(122, 122, 255));
    dessinerMap();
    dessinerReseauEau(plateau, eau);
    //al_flip_display();
}

void dessinerNiv2(Plateau *plateau, ALLEGRO_BITMAP *elec) {
    //dessiner Bitmap Niv -2
    al_clear_to_color(al_map_rgb(241, 205, 152));
    dessinerMap();
    dessinerReseauElec(plateau, elec);
    //al_flip_display();
}

void ecranChargementAccueil(ALLEGRO_DISPLAY *display) {
    ALLEGRO_BITMAP *bulles = al_load_bitmap("../Images/bullesChargement.png");
    ALLEGRO_BITMAP *ecranChargement = al_load_bitmap("../Images/ecranChargement.png");
    for (int x = 0; x < 2; ++x) {
        for (int i = 0; i < 4 * 182; i += 182) {
            for (int j = 0; j < 5 * 182; j += 182) {
                al_draw_bitmap(ecranChargement, 0, 0, 0);
                al_draw_scaled_bitmap(bulles, j, i, 181.2, 186.25, (largeur - 182) / 2 + 15, 500, 182, 182, 0);
                al_flip_display();
                al_rest(0.05);
            }
        }
    }
    al_destroy_bitmap(ecranChargement);
    al_destroy_bitmap(bulles);
}

void ecranChargementSauvegarde(ALLEGRO_DISPLAY *display) {
    ALLEGRO_BITMAP *bulles = al_load_bitmap("../Images/bullesChargement.png");
    ALLEGRO_BITMAP *ecranSauvegarde = al_load_bitmap("../Images/ecranSauvegarde.png");
    for (int x = 0; x < 2; ++x) {
        for (int i = 0; i < 4 * 182; i += 182) {
            for (int j = 0; j < 5 * 182; j += 182) {
                al_draw_bitmap(ecranSauvegarde, 0, 0, 0);
                al_draw_scaled_bitmap(bulles, j, i, 181.2, 186.25, (largeur - 182) / 2 + 15, 500, 182, 182, 0);
                al_flip_display();
                al_rest(0.1);
            }
        }
    }
    al_destroy_bitmap(ecranSauvegarde);
    al_destroy_bitmap(bulles);
}
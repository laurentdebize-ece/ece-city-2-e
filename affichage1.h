//
// Created by crouz on 27/11/2022.
//

#ifndef ECE_CITY_2_E_AFFICHAGE1_H
#define ECE_CITY_2_E_AFFICHAGE1_H

#include <time.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/bitmap.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define NB_CASES_LARGEUR 45
#define NB_CASES_HAUTEUR 35
#define hauteur 860
#define largeur 1400
#define COULEUR_FOND al_map_rgb(122,255, 255)
#define COULEUR_ROUTE al_map_rgb(0,0,0)
#define COULEUR_EAU al_map_rgb(0,0,255)
#define COULEUR_ELEC al_map_rgb(100,100,0)
#define COULEUR_BAT al_map_rgb(255,255,255)
#define X_DEPART_TRACE 225
#define X_FIN_TRACE 1170
#define Y_DEPART_TRACE 100
#define Y_FIN_TRACE 835
#define TAILLE_CASE 21
#define COULEUR_LIGNE al_map_rgb(0, 0, 0)
#define THICKNESS_LIGNE 0
#define COMMUNISTE 1
#define CAPITALISTE 2

#define NBHAB_CABANE 10
#define NBHAB_MAISON 50
#define NBHAB_IMMEUBLE 100
#define NBHAB_CHATEAU 1000

#define TAXE_HABITANT 10
#define PRIX_MAISON 1000
#define PRIX_ROUTE 10
#define PRIX_CENTRALE 100000

typedef struct Batiment {
    int evolution;
    int numRoute;
    // 0 = ruine / 1 = cabane / 2 = maison / 3 = immeuble / 4 = gratte-ciel / 5= chateau eau / 6= central electrique /8=route
    int x, y; // coin superieur gauche du bitmap
    //int recherhce; // permet de vérifier si toutes les cases autour on été explorer
    int ligne, colonne; // ligne -> y , colonne -> x
    int alimenteeEau;
    int alimenteeElec;
    int prix;
    int nbHabitants;
    int timerEvo;
}Batiment;


typedef struct Case {
    int etat; // 0 libre / 1 occupe
    Batiment batiment;   // type de batiment
    int x, y;
    int ligne, colonne; // en numéro de case (ligne = y, colonne = x)
    int alimenteElec, alimenteEau;
}Case;

typedef struct Banque{
    int flouz;
    int capaEau, capaElec;
}Banque;

typedef struct Plateau { // structure principale, on met tout dedans pour pas se passer 1000 trucs en parametre à chaque fct
    int ligne;
    int colonne;
    //int tailleGraphe;
    Batiment tabBatiment[100];
    //Graphe* graphe;
    int timer;
    Banque banque;
    int nbMaisons;
    int nbBat;
    int nbBonus;
    int nbHabitants;
    Case tabCases [NB_CASES_LARGEUR][NB_CASES_HAUTEUR]; // en ligne et colonne, pas x et y
}Plateau;


void initialisationCases (Plateau *plateau);
void dessinerMap();
void dessinerRoute(Plateau *plateau);
void dessinerReseauEau(Plateau *plateau, ALLEGRO_BITMAP *eau);
void dessinerReseauElec(Plateau *plateau, ALLEGRO_BITMAP *elec);
void dessinerNiv0(Plateau *plateau);
void dessinerNiv1(Plateau *plateau, ALLEGRO_BITMAP *eau);
void dessinerNiv2(Plateau *plateau, ALLEGRO_BITMAP *elec) ;
void ecranChargementAccueil(ALLEGRO_DISPLAY* display);
void ecranChargementSauvegarde(ALLEGRO_DISPLAY* display);

#endif //ECE_CITY_2_E_AFFICHAGE1_H

//
// Created by crouz on 27/11/2022.
//

#ifndef ECE_CITY_2_E_GRAPHE1_H
#define ECE_CITY_2_E_GRAPHE1_H

#include "affichage1.h"


struct Arc
{
    int sommet; // numero de sommet d'un arc adjacent au sommet initial
    int poidsArc;
    int valeur;
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

/* Structure d'un sommet*/
struct Sommet
{
    struct Arc* arc; //arc = lien entre deux routes
    int x,y;
    int valeur;
    int numeroSommet;
    int predecesseur, suivant;

};

/* Alias de pointeur sur un Sommet */
typedef struct Sommet* pSommet;
typedef struct Graphe
{
    int taille;
    int orientation;
    int ordre;
    pSommet* pSommet;
} Graphe;

struct Adjacence{
    int sommet1,sommet2;
};
typedef struct Adjacence Adjacence;

#endif //ECE_CITY_2_E_GRAPHE1_H

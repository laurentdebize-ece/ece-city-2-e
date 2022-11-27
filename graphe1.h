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
    char couleur;
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



pSommet *CreerArete(pSommet *sommet, int s1, int s2);
int ordreGraphe(Plateau * p);
Plateau numerotationRoute(Plateau p);
Graphe *CreerGraphe(int ordre);
void creerFichierGraphe(Plateau * plateau, char*nomFichier);

Graphe *lire_graphe(char *nomFichier, Plateau * plateau);


typedef int typage;

struct _cellule {
    typage element;
    struct _cellule *suivant;
};

typedef struct _cellule* Cellule;
struct _file {
    int longueur;
    Cellule tete;
    Cellule queue;
};

typedef struct _file* File;



//Fonction qui renvoie si une file est vide ou non
#define fileEstVide(F) ((F)->longueur == 0)

//Fonction qui initialise une file vide
File fileVide();

//Fonction qui renvoie la longueur de la file en 0(1) (longueur stockee dans une variable)
int longueur(File F);

//Fonction qui enfile un element dans la File F
void enfiler(File F, typage element);

//Fonction qui renvoie la tete de la file (sans l'enlever)
typage tete(File F);

//Fonction qui enleve la tete de la file sans la renvoyer
void decapiter(File F);

//Fonction qui enleve la tete de la file ET qui renvoie la tete
typage defiler(File F);

//Fonction qui affiche le contenu d'une file
void afficherFile(File F);
#endif //ECE_CITY_2_E_GRAPHE1_H

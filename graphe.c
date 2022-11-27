//
// Created by Amadou Kassim on 25/11/2022.
//

#include "graphe.h"

pSommet *CreerArete(pSommet *sommet, int s1, int s2) {
    if (sommet[s1]->arc == NULL) {
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommet = s2;
        Newarc->arc_suivant = NULL;
        sommet[s1]->arc = Newarc;
        return sommet;
    } else {
        pArc temp = sommet[s1]->arc;
        while (!(temp->arc_suivant == NULL)) {
            temp = temp->arc_suivant;
        }
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommet = s2;
        Newarc->arc_suivant = NULL;
        if (temp->sommet > s2) {
            Newarc->arc_suivant = temp->arc_suivant;
            Newarc->sommet = temp->sommet;
            temp->sommet = s2;
            temp->arc_suivant = Newarc;
            return sommet;
        }
        temp->arc_suivant = Newarc;
        return sommet;
    }
}

///fonction qui renvoie l'odre du graphe que l'on va par la suite cree
/// ordre du graphe correspond au nombre de route présentent sur le plateau
///permet aussi numéroter les routes
int ordreGraphe(Plateau p){
    int ordre=0;
    for (int i = 0; i < NB_CASES_LARGEUR; ++i) {
        for (int j = 0; j < NB_CASES_HAUTEUR; ++j) {
            if (p.tabCases[i][j].batiment.evolution==5){
                p.tabCases[i][j].batiment.numRoute=ordre;
                ordre+=1;
            }
        }
    }
    return ordre;
}

// creer le graphe


Graphe *CreerGraphe(int ordre) {
    Graphe *Newgraphe = (Graphe *) malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet *) malloc(ordre * sizeof(pSommet));


    for (int i = 0; i < ordre; i++) {
        Newgraphe->pSommet[i] = (pSommet) malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->valeur = i;
        Newgraphe->pSommet[i]->arc = NULL;
    }
    Newgraphe->ordre=ordre;
    return Newgraphe;
}


void creerFichierGraphe(Plateau plateau) {
    FILE * fichier= fopen("../Fichiers/graphe.txt", "w");
    int ordre = ordreGraphe(plateau);
    Adjacence tableau[ordre + 1];
    for (int i = 0; i < ordre + 1; ++i) {
        tableau[i].sommet1 = -1;
        tableau[i].sommet2 = -1;
    }
    Adjacence *adjacence;
    adjacence = malloc(1 * sizeof(Adjacence));
    int itterateur = 0;
    for (int i = 0; i < NB_CASES_LARGEUR; ++i) {
        for (int j = 0; j < NB_CASES_HAUTEUR; ++j) {
            if (plateau.tabCases[i][j].batiment.evolution == 5 && plateau.tabCases[i - 1][j].batiment.evolution == 5) {
                tableau[itterateur].sommet1 = plateau.tabCases[i][j].batiment.numRoute;
                tableau[itterateur].sommet2 = plateau.tabCases[i - 1][j].batiment.numRoute;
                itterateur += 1;
            }
            else if (plateau.tabCases[i][j].batiment.evolution == 5 &&
                     plateau.tabCases[i + 1][j].batiment.evolution == 5) {
                tableau[itterateur].sommet1 = plateau.tabCases[i][j].batiment.numRoute;
                tableau[itterateur].sommet2 = plateau.tabCases[i + 1][j].batiment.numRoute;
                itterateur += 1;
            }
            else if (plateau.tabCases[i][j].batiment.evolution == 5 &&
                     plateau.tabCases[i][j + 1].batiment.evolution == 5) {
                tableau[itterateur].sommet1 = plateau.tabCases[i][j].batiment.numRoute;
                tableau[itterateur].sommet2 = plateau.tabCases[i][j + 1].batiment.numRoute;
                itterateur += 1;
            } else if (plateau.tabCases[i][j].batiment.evolution == 5 &&
                       plateau.tabCases[i][j - 1].batiment.evolution == 5) {
                tableau[itterateur].sommet1 = plateau.tabCases[i][j].batiment.numRoute;
                tableau[itterateur].sommet2 = plateau.tabCases[i][j - 1].batiment.numRoute;
                itterateur += 1;
            }
        }
    }
    for (int i = 0; i < ordre + 1; ++i) {
        if (adjacence[i].sommet1 == -1 && adjacence[i].sommet2 == -1) {
        }else {fprintf(fichier,"%d %d",adjacence[i].sommet1,adjacence[i].sommet2);
            fprintf(fichier, "\n");
        }
    }
}



































/* La construction du reseau peut se faire a partir d'un fichier dont le nom est passe en parametre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */
void ajouterRouteGraphe(char *nomFichier, int ordre,int xRoute, int yRoute) {
    FILE *ifs = fopen(nomFichier, "w");
    fprintf(ifs, "%d %d", xRoute,yRoute);
    fputs("\n",ifs);
}

void reparerRoute(Plateau plateau, Graphe*graphe){
    int xCentral,yCentral;
    for (int i = 0; i < NB_CASES_LARGEUR; i++) {
        for (int j = 0; j < NB_CASES_HAUTEUR; j++) {
            if(plateau.tabCases[i][j].batiment.evolution==5){
                xCentral=plateau.tabCases[i][j].batiment.x;
                yCentral=plateau.tabCases[i][j].batiment.y;
                for (int k = 0; k < 6; k++) {
                    for (int l = 0; l < 4; l++) {
                        //ajouter route au graphe
                    }
                }
            }

        }
    }
}
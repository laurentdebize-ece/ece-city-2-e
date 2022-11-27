//
// Created by Amadou Kassim on 25/11/2022.
//

/*#include "graphe1.h"

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
int ordreGraphe(Plateau * p){
    int ordre=0;
    for (int i = 0; i < NB_CASES_LARGEUR; ++i) {
        for (int j = 0; j < NB_CASES_HAUTEUR; ++j) {
            if (p->tabCases[i][j].batiment.evolution==5){
                p->tabCases[i][j].batiment.numRoute=ordre;
                ordre+=1;
            }
        }
    }
    return ordre;
}


/// creer le graphe


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


void creerFichierGraphe(Plateau *plateau, char*nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    int ordre = ordreGraphe(plateau);
    fprintf(fichier, "%d",ordre);
    fprintf(fichier, "\n");
    int taille=0;
    for (int i = 0; i < NB_CASES_LARGEUR; ++i) {
        for (int j = 0; j < NB_CASES_HAUTEUR; ++j) {

            if (plateau->tabCases[i][j].batiment.evolution == 8 && plateau->tabCases[i + 1][j].batiment.evolution == 8 && plateau->tabCases[i+1][j].batiment.recherhce==0) {
                fprintf(fichier, "%d %d",plateau->tabCases[i][j].batiment.numRoute, plateau->tabCases[i+1][j].batiment.numRoute);
                fprintf(fichier, "\n");
                taille+=1;
            }

            if (plateau->tabCases[i][j].batiment.evolution == 8 && plateau->tabCases[i - 1][j].batiment.evolution == 8 && plateau->tabCases[i-1][j].batiment.recherhce==0) {
                fprintf(fichier, "%d %d",plateau->tabCases[i][j].batiment.numRoute, plateau->tabCases[i-1][j].batiment.numRoute);
                fprintf(fichier, "\n");
                taille+=1;
            }

            if (plateau->tabCases[i][j].batiment.evolution == 8 && plateau->tabCases[i][j + 1].batiment.evolution == 8  && plateau->tabCases[i][j+1].batiment.recherhce==0) {
                fprintf(fichier, "%d %d",plateau->tabCases[i][j].batiment.numRoute, plateau->tabCases[i][j+1].batiment.numRoute);
                fprintf(fichier, "\n");
                taille+=1;
            }

            if (plateau->tabCases[i][j].batiment.evolution == 8 && plateau->tabCases[i][j - 1].batiment.evolution == 8  && plateau->tabCases[i][j-1].batiment.recherhce==0) {
                fprintf(fichier, "%d %d",plateau->tabCases[i][j].batiment.numRoute, plateau->tabCases[i][j-1].batiment.numRoute);
                fprintf(fichier, "\n");
                taille+=1;
            }


            plateau->tabCases[i][j].batiment.recherhce=-1;
        }
    }
    plateau->tailleGraphe=taille;
}

Graphe *lire_graphe(char *nomFichier, Plateau * plateau) {
    creerFichierGraphe(plateau,nomFichier);
    Graphe *graphe;
    FILE *ifs = fopen(nomFichier, "r");
    int ordre, s1, s2;
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    fscanf(ifs, "%d", &ordre);

    graphe = CreerGraphe(ordre); /// creer le graphe d'ordre sommets
    int taille=plateau->tailleGraphe;

    graphe->ordre = ordre;

    /// creer les aretes du graphe
    for (int i = 0; i < taille; ++i) {
        fscanf(ifs, "%d%d", &s1, &s2);
        graphe->pSommet = CreerArete(graphe->pSommet, s1, s2);
    }

    return graphe;
}


File fileVide() {
    File F;
    F = (File)malloc(sizeof(struct _file));
    if (F == NULL) printf("erreur allocation fileVide");
    F->longueur = 0;
    F->tete = F->queue = NULL;
    return(F);
}

int longueur(File F) {
    if (F == NULL)printf("file existe pas - longueur");
    return(F->longueur);
}

void enfiler(File F, typage element) {
    Cellule cellule;
    if (F == NULL) printf ("file existe pas - enfiler");

    cellule = (Cellule)malloc(sizeof(struct _cellule));
    if (cellule == NULL) printf("erreur allocation memoire - enfiler");
    cellule->element = element;
    cellule->suivant = NULL;
    if (longueur(F) == 0){
        F->tete = F->queue = cellule;
    }
    else {
        F->queue->suivant = cellule;
        F->queue = cellule;
    }
    ++(F->longueur);
}

typage defiler(File F) {
    Cellule cellule;
    typage element;
    if (F == NULL || longueur(F) == 0) printf("File existe pas - defilement");
    cellule = F->tete;
    element = cellule->element;
    if (longueur(F) == 1){
        F->tete = F->queue = NULL;
    }
    else{
        F->tete = F->tete->suivant;
    }
    free(cellule);
    --(F->longueur);
    return(element);
}


void parcoursBFS(Graphe* graphe, int s0){
    int taille = graphe->taille;
    int preds[taille];
    for(int i=0;i<graphe->ordre;i++){
        graphe->pSommet[i]->couleur=0;
    }
    for (int i = 0;i <graphe->ordre ;++i) {
        preds[i] = -1;
    }
    File file = fileVide();
    enfiler(file,s0);
    graphe->pSommet[s0]->couleur=1;

    while(file->tete!=NULL){
        int num=defiler(file);
        struct Arc* pArc=graphe->pSommet[num]->arc;
        while(pArc!=NULL){
            int num2=pArc->sommet;
            if(graphe->pSommet[num2]->couleur==0){
                enfiler(file,num2);
                graphe->pSommet[num2]->couleur=1;
                preds[num2]=num;
            }
            pArc=pArc->arc_suivant;
        }
    }
}
*/
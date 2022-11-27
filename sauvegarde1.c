//
// Created by crouz on 27/11/2022.
//

#include "sauvegarde1.h"

void initTabCase(Plateau *plateau){
    for (int i = 0; i < NB_CASES_LARGEUR; ++i) {
        for (int j = 0; j < NB_CASES_HAUTEUR; ++j) {
            plateau->tabCases[i][j].ligne=i;
            plateau->tabCases[i][j].colonne=j;
            plateau->tabCases[i][j].x=X_DEPART_TRACE+ 21*i;
            plateau->tabCases[i][j].y=Y_DEPART_TRACE+ 21*i;
        }
    }
}

//sauvegarder les donne pour eau, l'électricité et les batiment et eceFlouz
void sauvegarderElec(Plateau *plateau){
    FILE * fichier= fopen("../Fichiers/fichierAlimenteElec.txt", "w");
    for (int i = 0; i < NB_CASES_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASES_LARGEUR; ++j) {
            fprintf(fichier,"%d",plateau->tabCases[j][i].alimenteElec);
            fputs(" ",fichier);
        }
        fputs("\n",fichier);
    }
}
void sauvegarderEeau(Plateau *plateau){
    FILE * fichier= fopen("../Fichiers/fichierAlimenteEau.txt", "w");
    for (int i = 0; i < NB_CASES_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASES_LARGEUR; ++j) {
            fprintf(fichier,"%d",plateau->tabCases[j][i].alimenteEau);
            fputs(" ",fichier);
        }
        fputs("\n",fichier);
    }
}
void sauvegarderBatiment(Plateau *plateau){
    FILE * fichier= fopen("../Fichiers/fichierBatiment.txt", "w");
    FILE * fArgent= fopen("../Fichiers/fArgent.txt", "w");
    for (int i = 0; i < NB_CASES_HAUTEUR; ++i) {
        for (int j = 0; j < NB_CASES_LARGEUR; ++j) {
            fprintf(fichier,"%d",plateau->tabCases[j][i].batiment.evolution);
            fputs(" ",fichier);
        }
        fputs("\n",fichier);
    }
    fprintf(fArgent, "%d",plateau->banque.flouz);
} //eceFlouz ici

void sauvegarder(Plateau *plateau){
    sauvegarderElec(plateau);
    sauvegarderEeau(plateau);
    sauvegarderBatiment(plateau);
}

Plateau chargerSauvegarde(){
    FILE * fichierElec= fopen("../Fichiers/fichierAlimenteElec.txt","r");
    FILE * fichierEau= fopen("../Fichiers/fichierAlimenteEau.txt","r");
    FILE * fichierBatiment= fopen("../Fichiers/fichierBatiment.txt","r");
    FILE * fargent= fopen("../Fichiers/fArgent.txt","r");
    Plateau plateau;
    initTabCase(&plateau);
    int eau,electricite,batiment,eceFlouz;
    fscanf(fargent, "%d",&eceFlouz);
    plateau.banque.flouz=eceFlouz;
    for (int i = 0; i < NB_CASES_LARGEUR; ++i) {
        for (int j = 0; j < NB_CASES_HAUTEUR; ++j) {
            fscanf(fichierElec,"%d",&electricite);
            plateau.tabCases[i][j].alimenteElec=electricite;
            fscanf(fichierEau,"%d",&eau);
            plateau.tabCases[i][j].alimenteEau=eau;
            fscanf(fichierBatiment,"%d",&batiment);
            plateau.tabCases[i][j].batiment.evolution=batiment;
        }
    }
    return plateau;
}

void sauvegardeCoordonneBatimentPosee(Plateau plateau,int x,int y,int typeBatiment){
    if(typeBatiment==3){
        plateau.tabCases[x][y].batiment.evolution=8;
        plateau.tabCases[x][y].batiment.x=x;
        plateau.tabCases[x][y].batiment.y=y;
    }
    if(typeBatiment==4){
        plateau.tabCases[x][y].batiment.evolution=0;
        plateau.tabCases[x][y].batiment.x=x;
        plateau.tabCases[x][y].batiment.y=y;
    }
    if(typeBatiment==5){
        plateau.tabCases[x][y].batiment.evolution=5;
        plateau.tabCases[x][y].batiment.x=x;
        plateau.tabCases[x][y].batiment.y=y;
    }
    if(typeBatiment==6){
        plateau.tabCases[x][y].batiment.evolution=6;
        plateau.tabCases[x][y].batiment.x=x;
        plateau.tabCases[x][y].batiment.y=y;
    }
}
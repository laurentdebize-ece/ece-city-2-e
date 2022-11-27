//
// Created by crouz on 27/11/2022.
//

#include "menuPrincipal1.h"

void choixPartie(ALLEGRO_DISPLAY *fenetre, ALLEGRO_EVENT_QUEUE *queue, Plateau *plateau) {

    bool close = false;
    bool in = false;
    int choix = 0;
    ALLEGRO_BITMAP *accueil = NULL;
    ALLEGRO_MOUSE_STATE mouse;
    ALLEGRO_EVENT event;

    al_register_event_source(queue, al_get_display_event_source(fenetre));  //fermer la fenetre
    al_register_event_source(queue, al_get_mouse_event_source());           //Capter les donnés souris

    accueil = al_load_bitmap("../Images/choixMode.png");

    al_draw_bitmap(accueil, 0, 0, 0);
    al_flip_display();
    while (!close) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE: {
                close = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                al_get_mouse_state(&mouse);
                clicsMenuPrincipal(&choix, event.mouse.x, event.mouse.y);
                if (choix != 0) {
                    switch (choix) {
                        case 1 : {
                            printf("MODE COMMUNISTE\n");
                            jeu(fenetre, queue, plateau, COMMUNISTE);

                            close = true;
                            break;
                        }
                        case 2 : {
                            printf("MODE CAPITALISTE\n");
                            jeu(fenetre, queue, plateau, CAPITALISTE);
                            /// sauvegarder(tabCase, "FichierSauvergarde.txt", banque);
                            close = true;
                            break;
                        }
                    }
                }
            }
                break;
        }
    }
}

void initilisationTaillesBoutonsMenuPrincipal(Rect *rCOMMUNISTE, Rect *rCAPITALISTE) {
    rCOMMUNISTE->x = 95;
    rCOMMUNISTE->y = 285;
    rCOMMUNISTE->larg = 330;
    rCOMMUNISTE->haut = 330;

    rCAPITALISTE->x = 945;
    rCAPITALISTE->y = 285;
    rCAPITALISTE->larg = 330;
    rCAPITALISTE->haut = 330;
}

void clicsMenuChoixPartie(int *choix, int mouseX, int mouseY) {
    Rect rNouvellePartie;
    Rect rAnciennePartie;
    initilisationBoutonEcran2(&rNouvellePartie, &rAnciennePartie);
    bool in = false;
    //  refaire ce meme schema pour chaque nouveau bouton (en mettant var+1 a chaques fois)
    selectionRectangle(rNouvellePartie, mouseX, mouseY, &in);
    if (in == true) {
        *choix = 1;
        in = false;
    }

    selectionRectangle(rAnciennePartie, mouseX, mouseY, &in);
    if (in == true) {
        *choix = 2;
        in = false;
    }
}

void clicsMenuPrincipal(int *choix, int mouseX, int mouseY) {
    Rect rCOMMUNISTE;
    Rect rCAPITALISTE;
    initilisationTaillesBoutonsMenuPrincipal(&rCOMMUNISTE, &rCAPITALISTE);
    bool in = false;
    //  refaire ce meme schema pour chaque nouveau bouton (en mettant var+1 a chaques fois)
    selectionRectangle(rCOMMUNISTE, mouseX, mouseY, &in);
    if (in == true) {
        *choix = 1;
        in = false;
    }

    selectionRectangle(rCAPITALISTE, mouseX, mouseY, &in);
    if (in == true) {
        *choix = 2;
        in = false;
    }

}
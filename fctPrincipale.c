//
// Created by crouz on 27/11/2022.
//

#include "fctPrincipale.h"
#include "affichage1.h"
#include "sauvegarde1.h"
#include "ftcsReutilisables1.h"
#include "Partie/clcPartie1.h"
#include "menuPrincipal/menuPrincipal1.h"

Plateau initialiserPlateau(){ //nous permet d'initialiser toutes les données du plateau
    Plateau plateau;
    plateau.banque.flouz = 500000;
    plateau.nbHabitants = 0;
    plateau.nbMaisons=0;
    plateau.nbBonus = 0;
    for (int i = 0; i < NB_CASES_LARGEUR; ++i) {
        for (int j = 0; j < NB_CASES_HAUTEUR; ++j) {
            plateau.tabCases[i][j].ligne = i;
            plateau.tabCases[i][j].colonne = j;
            plateau.tabCases[i][j].x = X_DEPART_TRACE + 21 * i;
            plateau.tabCases[i][j].y = Y_DEPART_TRACE + 21 * i;
            plateau.tabCases[i][j].batiment.evolution = 0;
            plateau.tabCases[i][j].batiment.numRoute=-1;
            plateau.tabCases[i][j].batiment.recherhce=0;
            plateau.tabCases[i][j].etat = 0;
        }
    }
    return plateau;
}

void fonctionPrincipale() {
    bool end = false;
    Plateau plateau = initialiserPlateau();


    ALLEGRO_BITMAP *choixPrt = NULL;

    ALLEGRO_DISPLAY *fenetre = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_MOUSE_STATE mouse;
    ALLEGRO_EVENT event;
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *songinstance;
    int choix =0;       //CHOIX 1 : MODE COMMUNISTE    // CHOIX 2 : MODE CAPITALISTE

    srand(time(NULL));
    al_init_font_addon();
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_mouse());
    assert(al_install_keyboard());
    assert(al_init_image_addon());
    assert(al_init_ttf_addon());
    assert(al_install_audio());
    assert(al_init_acodec_addon());
    assert(al_reserve_samples(1));

    fenetre = al_create_display(largeur, hauteur);
    queue = al_create_event_queue();
    if (queue == NULL) {
        al_destroy_display(fenetre);
        exit(EXIT_FAILURE);
    }
    al_register_event_source(queue, al_get_display_event_source(fenetre));  //fermer la fenetre
    al_register_event_source(queue, al_get_keyboard_event_source());        //Capter les donnés claviers
    al_register_event_source(queue, al_get_mouse_event_source());           //Capter les donnés souris

    al_set_window_position(fenetre, 0, 0);
    al_set_window_title(fenetre, "ECE City");
    ///////////////////////////////////
    choixPrt = al_load_bitmap("../Images/choixPartie.png");


    sample = al_load_sample("../Images/song.wav");
    songinstance = al_create_sample_instance(sample);

    al_attach_sample_instance_to_mixer(songinstance, al_get_default_mixer());
    al_play_sample_instance(songinstance);

    al_clear_to_color(COULEUR_FOND);
    al_draw_bitmap(choixPrt, 0, 0, 0);
    al_flip_display();

    while (!end) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE: {
                end = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                al_get_mouse_state(&mouse);
                clicsMenuChoixPartie(&choix, event.mouse.x, event.mouse.y);
                if (choix != 0) {
                    switch (choix) {
                        case 1 : {
                            printf("NouvellePartie\n");
                            choixPartie(fenetre, queue, &plateau);
                            end = true;
                            break;
                        }
                        case 2 : {
                            printf("AnciennePartie\n");
                            ecranChargementAccueil(fenetre);
                            initTabCase(&plateau);
                            plateau = chargerSauvegarde();
                            jeu(fenetre, queue, &plateau, CAPITALISTE);
                            end = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    al_destroy_display(fenetre);
    al_destroy_event_queue(queue);
    al_destroy_sample_instance(songinstance);
}

void jeu(ALLEGRO_DISPLAY *fenetre, ALLEGRO_EVENT_QUEUE *queue, Plateau *plateau, int mode) {
    bool close = false;
    ALLEGRO_BITMAP *interf = NULL;
    ALLEGRO_BITMAP *pause = NULL;
    ALLEGRO_BITMAP *maison1 = NULL;
    ALLEGRO_BITMAP *maison2 = NULL;
    ALLEGRO_BITMAP *maison3 = NULL;
    ALLEGRO_BITMAP *maison4 = NULL;
    ALLEGRO_BITMAP *maison5 = NULL;
    ALLEGRO_BITMAP *eauPNG = NULL;
    ALLEGRO_BITMAP *elecPNG = NULL;
    ALLEGRO_BITMAP *road = NULL;
    ALLEGRO_BITMAP *statue = NULL;
    ALLEGRO_BITMAP *ecole = NULL;
    ALLEGRO_BITMAP *transport = NULL;
    ALLEGRO_BITMAP *parc = NULL;
    ALLEGRO_MOUSE_STATE mouse;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_TIMER *timer1s = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_FONT *police20 = NULL;
    ALLEGRO_FONT *police30 = NULL;

    int etatPause = 0;
    int niveau = 0;
    int minutes = 0;
    int x, y    = 0;
    int clicX = 0;
    int clicY = 0;
    int impots = 0;
    int info = 0;

    srand(time(NULL));
    al_init_font_addon();
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_mouse());
    assert(al_install_keyboard());
    assert(al_init_image_addon());
    assert(al_init_ttf_addon());

    timer = al_create_timer(1.0 / 40.0);
    timer1s = al_create_timer(1);
    if (timer == NULL) {
        al_destroy_display(fenetre);
        exit(EXIT_FAILURE);
    }
    if (queue == NULL) {
        al_destroy_display(fenetre);
        al_destroy_timer(timer);
        exit(EXIT_FAILURE);
    }

    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_timer_event_source(timer1s));
    al_register_event_source(queue, al_get_display_event_source(fenetre));  ///fermer la fenetre
    al_register_event_source(queue, al_get_keyboard_event_source());        ///Capter les donnés claviers
    al_register_event_source(queue, al_get_mouse_event_source());           ///Capter les donnés souris

    interf = al_load_bitmap("../Images/interfaceSimcity2.png");
    pause = al_load_bitmap("../Images/boutonPause.png");
    maison1 = al_load_bitmap("../Images/maison1.png");
    maison2 = al_load_bitmap("../Images/maison2.png");
    maison3 = al_load_bitmap("../Images/maison3.png");
    maison4 = al_load_bitmap("../Images/maison4.png");
    maison5 = al_load_bitmap("../Images/maison5.png");
    elecPNG = al_load_bitmap("../Images/eoliennes.png");
    eauPNG = al_load_bitmap("../Images/chateauEau.png");
    road = al_load_bitmap("../Images/route.png");
    statue = al_load_bitmap("../Images/monument.png");
    ecole = al_load_bitmap("../Images/ecole.png");
    transport = al_load_bitmap("../Images/transport.png");
    parc = al_load_bitmap("../Images/parc.png");
    police30 = al_load_ttf_font("../Lato/Lato-BoldItalic.ttf", 30, 0);
    police20 = al_load_ttf_font("../Lato/Lato-BoldItalic.ttf", 20, 0);
    al_clear_to_color(COULEUR_FOND);



    al_start_timer(timer);
    al_start_timer(timer1s);
    while (!close) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE: {
                close = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                al_get_mouse_state(&mouse);
                clicX= mouse.x;
                clicY = mouse.y;
                sauvegarder(plateau);
                clicsPartie(interf, mouse.x, mouse.y, timer1s, minutes, niveau, &etatPause);
                if ((etatPause >= 3) && (X_DEPART_TRACE < clicX && X_FIN_TRACE > clicX &&
                                         Y_DEPART_TRACE < clicY && Y_FIN_TRACE > clicY)) {
                    {///On veut placer sur le plateau
                        poserObjet(clicX, clicY, &plateau, info);
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_KEY_DOWN : {
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_1: {
                        niveau = 0;
                        break;
                    }
                    case ALLEGRO_KEY_2: {
                        niveau = 1;
                        break;
                    }
                    case ALLEGRO_KEY_3: {
                        niveau = 2;
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_TIMER :{
                for (int i = 0; i < plateau->nbMaisons; ++i) {
                    if (plateau->tabBatiment[i].timerEvo < 902){
                        plateau->tabBatiment[i].timerEvo++;
                    }
                }
                if (mode == CAPITALISTE){
                    evolutionMaisonsCapitaliste(&plateau);
                }
                if (mode == COMMUNISTE){
                    evolutionMaisonsCommuniste(&plateau);
                }
                impots = fImpots(plateau, impots);
                minutes = dessinerTout(mode, plateau, interf, fenetre, timer1s, minutes, niveau, &etatPause, pause, road,
                                       maison1, maison2, maison3, maison4, maison5, eauPNG, elecPNG, x, y, police20, police30,
                                       statue, ecole, transport, parc, &info, clicX, clicY);
                if(minutes==100){
                    close = true;
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES : {
                x = event.mouse.x;
                y = event.mouse.y;
                break;
            }
        }
    }
    al_destroy_timer(timer);
    al_destroy_timer(timer1s);
    al_destroy_bitmap(interf);
    al_destroy_bitmap(pause);
    al_destroy_bitmap(eauPNG);
    al_destroy_bitmap(elecPNG);
    al_destroy_bitmap(road);
    al_destroy_bitmap(statue);
    al_destroy_bitmap(ecole);
    al_destroy_bitmap(transport);
    al_destroy_bitmap(parc);
    al_destroy_font(police30);
    al_destroy_font(police20);
}
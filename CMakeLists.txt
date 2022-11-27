cmake_minimum_required(VERSION 3.23)
project(ece-city-2-e)

set(CMAKE_C_STANDARD 11)

add_executable(ece-city-2-e
        main.c
        fonctionPrincipale.c fonctionPrincipale.h
        fctsReutilisables.c fctsReutilisables.h
        sauvegarde.c sauvegarde.h
        affichage.h affichage.c
        Partie
        Partie/clciPartie.h Partie/clciPartie.c
        Partie/poserObj.h Partie/poserObj.c
        timer.c timer.c timer.h
        Partie/maisons.c Partie/maisons.h
        menuPrincipal/menuPrincip.c menuPrincipal/menuPrincip.h graphe.c graphe.h)


IF(WIN32)
    target_link_libraries(ece-city-2-e -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.7.0/include)
    LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.7.0/lib)
    file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.7.0/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(ece-city-2-e ${LIBRARIES})
ENDIF(WIN32)

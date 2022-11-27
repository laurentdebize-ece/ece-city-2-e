cmake_minimum_required(VERSION 3.23)
project(ece-city-2-e)

set(CMAKE_C_STANDARD 11)

add_executable(ece-city-2-e
        main.c
        Partie
        affichage1.c affichage1.h ftcsReutilisables1.c ftcsReutilisables1.h fctPrincipale.c fctPrincipale.h graphe1.c graphe1.h sauvegarde1.c sauvegarde1.h timer1.c timer1.h Partie/clcPartie1.c Partie/clcPartie1.h Partie/maisons1.c Partie/maisons1.h Partie/poserObj1.c Partie/poserObj1.h menuPrincipal/menuPrincipal1.c menuPrincipal/menuPrincipal1.h)


IF(WIN32)
    target_link_libraries(ece-city-2-e -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.7.0/include)
    LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.7.0/lib)
    file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.7.0/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(ece-city-2-e ${LIBRARIES})
ENDIF(WIN32)

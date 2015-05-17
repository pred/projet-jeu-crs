#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

    #define TAILLE_BLOC         34 /* Taille d'un bloc (carré) en pixels */
    #define NB_BLOCS_LARGEUR    25
    #define NB_BLOCS_HAUTEUR    18
=======
    #define TAILLE_BLOC         32 /* Taille d'un bloc (carré) en pixels */
    #define NB_BLOCS_LARGEUR    12
    #define NB_BLOCS_HAUTEUR    12
>>>>>>> 36c6464a5522ccf5aeece2d95c0b44a2049c1ac8
    #define LARGEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_LARGEUR
    #define HAUTEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_HAUTEUR


    enum {HAUT, DROITE, BAS, GAUCHE};
    enum {CIEL, MUR, FROMAGE, SOURIS, PIEGE, PORTE, FLECHED, FLECHEG,CHAT};
    typedef struct Contenu {
    	SDL_Window *window;
    	SDL_Renderer *renderer;
    	SDL_Surface *surface;
    	SDL_Texture *texture;


    } Contenu;

#endif

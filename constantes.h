#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#include <SDL2/SDL.h>


    #define TAILLE_BLOC         34 /* Taille d'un bloc (carré) en pixels */
    #define NB_BLOCS_LARGEUR    25
    #define NB_BLOCS_HAUTEUR    18
    #define LARGEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_LARGEUR
    #define HAUTEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_HAUTEUR


    enum {HAUT, DROITE, BAS, GAUCHE};
    enum {CIEL, MUR, FROMAGE,  PIEGE, PORTE, FLECHED, FLECHEG,CHAT};
    typedef struct Contenu {
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Surface *surface;
        SDL_Texture *texture;


    } Contenu;
   


#endif

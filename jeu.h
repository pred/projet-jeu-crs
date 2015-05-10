#ifndef DEF_JEU
#define DEF_JEU
	#include "constantes.h"
    void jouer(SDL_Window* ecran, SDL_Renderer* renderer, SDL_Surface* surface,int* a);
    void deplacerJoueur(int** carte, SDL_Rect *pos, int direction);
    void map();
    

#endif

#ifndef AFFICHER_H
#define AFFICHER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "constantes.h"


	void createtexte(char* mot,Contenu* C, int i,int j,TTF_Font *police);
	void chargerimage(Contenu* C, int i, int j, SDL_Surface*);
	void afficherimage(Contenu* C,SDL_Surface* surface, int l,int m);
	
	void win(int* h);
	void gameOver();
	Contenu* creerFenetre(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture);

#endif

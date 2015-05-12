#ifndef AFFICHER_H
#define AFFICHER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

	void createtexte(char* mot, SDL_Surface* surface, SDL_Texture* texture,SDL_Renderer* renderer, SDL_Window* window, int i,int j,TTF_Font *police);
	void chargerimage(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface *surface,SDL_Texture *texture, int i, int j, char *image);
	void afficherimage(SDL_Window* ecran, SDL_Renderer* renderer, SDL_Surface *surface, SDL_Texture* texture,int l,int m);
	char attrapefromage(int i, int j, char c);
	void win(char* h);
	void gameOver();

#endif

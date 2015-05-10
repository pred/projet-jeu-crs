#ifndef DEF_MENU
#define DEF_MENU

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>



#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Trip Trap"


void menu(int* terminer,SDL_Window *window,SDL_Renderer *renderer, SDL_Surface *surface, SDL_Texture *texture);

#endif


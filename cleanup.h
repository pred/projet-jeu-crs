#ifndef CLEANUP_H
#define CLEANUP_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>




void cleanup(SDL_Texture* texture, SDL_Surface* souris, SDL_Surface* jouer, SDL_Surface* options, SDL_Renderer* renderer, SDL_Window* window, TTF_Font* police);

#endif // CLEANUP_H

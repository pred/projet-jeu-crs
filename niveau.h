#ifndef NIVEAU_H
#define NIVEAU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#include <SDL2/SDL_ttf.h>
#include "constantes.h"

void chargerImageNiveau();
void freeImageNiveau();

void afficheNiveau(Contenu* C,int fromage[6]);

void niveau(Contenu* C, int *terminermenu);

#endif // NIVEAU_H

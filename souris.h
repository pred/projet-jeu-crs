#ifndef DEF_SOURIS
#define DEF_SOURIS

#include <SDL2/SDL.h>
 
typedef struct Souris {
        SDL_Rect* coordonneeActuelle;        
        int direction;
        int position;
} Souris;

Souris* creerSouris(SDL_Rect* coordonneeActuelle,int direction, int position);
void freeSouris(Souris* souris);
int estFaceMur(Souris* souris,int** carte);
int prochaineDirection(Souris* souris,int** carte);
int prochainePosition(Souris* souris,int** carte);
SDL_Rect* prochaineCoordonnees(Souris* souris,int** carte);
int doitTourner(Souris* souris,int** carte);

#endif

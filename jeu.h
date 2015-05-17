#ifndef DEF_JEU
#define DEF_JEU
	#include "constantes.h"

	int** chargerMap(char *s);
    void afficheJeu(Contenu* C,int** carte,int direction);
   void chargerImage();
    int map(Contenu* C,char* s);
    SDL_Rect positionS(int **carte);
    void freeMap(int **carte);
    int evenement(int* terminer, int** carte,SDL_Rect* positionSouris,int* direction,Contenu* C, int* fromage,int* position);
    void collisionMur(int** carte,int* direction,int* position,SDL_Rect* positionSouris,int* terminer,Contenu* C,int* fromage);
    int collisionPorte(int** carte,SDL_Rect* positionSouris,int direction,int* terminer,Contenu* C,int* fromage);
    int collisionPiege(int** carte,SDL_Rect* pos,int direction,int* terminer,Contenu* C,int* fromage);
    int collisionFromage(int** carte,SDL_Rect* pos,int direction,Contenu* C,int* fromage);
    int collisionFleche(int** carte,SDL_Rect* pos,int* direction,Contenu* C);
    SDL_Rect positionC(int **carte);
    void freeImage();

#endif

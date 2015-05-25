#ifndef DEF_JEU
#define DEF_JEU
	#include "constantes.h"
    #include "souris.h"

	int** chargerMap(char *s);
    void freeMap(int **carte);
    void chargerImage();
    void freeImage();
    void afficheJeu(Contenu* C,int** carte);
   
    int map(Contenu* C,char* s,Souris* coordonneeInitiale);
    void mouvement(int** carte,Souris* souris, int* fromage,int* terminer,Contenu* C);
    int evenement(int** carte,Souris* souris,Contenu* C,int* fromage,int *terminer);
   void deplacementChat(int** carte,int* directionChat);
   SDL_Rect* positionChat(int** carte);
   int* contientChat(int** carte);
    
#endif

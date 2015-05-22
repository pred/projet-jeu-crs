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
    void mouvement(int** carte,Souris* souris, int* fromage,int* terminer);
    
   
    
#endif

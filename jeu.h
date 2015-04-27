#ifndef DEF_JEU
#define DEF_JEU

    void jouer(SDL_Window* ecran,SDL_Surface* surface, SDL_Renderer* renderer,int* a);
    void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos, int direction);
    void deplacerCaisse(int *premiereCase, int *secondeCase);


#endif

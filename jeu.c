#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "fichiers.h"
#include "constantes.h"
#include "jeu.h"
#include "afficher.h"
#include "constantes.h"
#include "souris.h"

SDL_Surface** sourisImage;
SDL_Surface *mur ; 
SDL_Surface *fromage;
SDL_Surface *piege;

SDL_Surface *porte;
SDL_Surface *ciel;
SDL_Surface *fleched;
SDL_Surface *flecheg;
SDL_Surface *chat; 
Souris* souris;



int** chargerMap(char *s){
    int h, erreur;
    
    int **carte ;
    carte= (int **) malloc(sizeof(int *)*NB_BLOCS_HAUTEUR);
    if (carte!=NULL)
    {
        h=0;
        erreur=0;
        while ((h<NB_BLOCS_HAUTEUR) && !erreur)
        {
            carte[h]=(int *) malloc(sizeof(int)*NB_BLOCS_LARGEUR);
            if (carte==NULL)
            {
                erreur=1;
            }
            else 
            {
                h++;
            }
        }
        if (erreur)
        {
            while (h)
            {
                h--;
                free(carte[h]);

            }
            free(carte);
        }
    }
    if (!chargerNiveau(carte,s))
        exit(EXIT_FAILURE);

    return carte;
}
void freeMap(int ** carte){
    int h;
    for (h=0; h<NB_BLOCS_HAUTEUR;h++){
        free(carte[h]);
    }
    free(carte);
}
void chargerImage(){
    int i = 0;
    sourisImage = (SDL_Surface**) malloc (sizeof(SDL_Surface*)*5);
    if (sourisImage == NULL) {
        
        for (i=0; i<5;i++) {
            SDL_FreeSurface(sourisImage[i]);
        }
        free(sourisImage);
    }
    mur = IMG_Load("Image/brique.png");
    ciel=IMG_Load("Image/ciel2.png");
    fromage = IMG_Load("Image/fromage.jpg");
    piege = IMG_Load("Image/piege.png");
    porte= IMG_Load("Image/porte.png");
    sourisImage[BAS] = IMG_Load("Image/souris.png");
    sourisImage[GAUCHE] = IMG_Load("Image/sourisgauche.png");
    sourisImage[HAUT] = IMG_Load("Image/sourishaut.png");
    sourisImage[DROITE] = IMG_Load("Image/sourisdroite.png");
    fleched=IMG_Load("Image/fleched.png");
    flecheg=IMG_Load("Image/flecheg.png");
    chat=IMG_Load("Image/chat.png");
}
void freeImage(){
    SDL_FreeSurface(mur);
    SDL_FreeSurface(ciel);
    SDL_FreeSurface(fromage);
    SDL_FreeSurface(piege);
    SDL_FreeSurface(porte);
    int i;
    for (i=0; i<5;i++) {
            SDL_FreeSurface(sourisImage[i]);
        }
        free(sourisImage);
    SDL_FreeSurface(fleched);
    SDL_FreeSurface(flecheg);
    SDL_FreeSurface(chat);

}
void afficheJeu(Contenu* C,int** carte){
    
    
    
    int i,j;
    
            
        
    for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
        {
            if (carte[i][j]==CIEL)
            {
                afficherimage(C, ciel,j,i);

            }
            if (carte[i][j]==MUR)
            {   
                afficherimage(C, mur,j,i);

            }
        
            if (carte[i][j]==FROMAGE)
            {
                afficherimage(C, fromage,j,i);      
            }
            if (carte[i][j]==PIEGE)
            {
                afficherimage(C, piege, j,i);        
            }
            if (carte[i][j]==PORTE)
            {
                afficherimage(C, porte, j,i);        
            }
            if (carte[i][j]==FLECHED)
            {
                afficherimage(C, fleched, j,i);        
            }
            if (carte[i][j]==FLECHEG)
            {
                afficherimage(C, flecheg, j,i);        
            }
            if (carte[i][j]==CHAT)
            {
                afficherimage(C, chat, j,i);        
            }

        }
    }
    afficherimage(C,sourisImage[souris->direction],souris->coordonneeActuelle->x,souris->coordonneeActuelle->y);
    SDL_UpdateWindowSurface(C->window);
    
    
}



int map(Contenu* C,char* s,Souris* coordonneeInitiale)
{       
            int terminer=0;
            int fromage=0;
            int **carte=chargerMap(s);
            souris=creerSouris(coordonneeInitiale->coordonneeActuelle,coordonneeInitiale->direction,coordonneeInitiale->position);
            Souris* sourisavant=souris;    

            chargerImage();
            afficheJeu(C,carte);
       
              
            while(terminer==0){
                switch(carte[prochaineCoordonnees(sourisavant,carte)->y][prochaineCoordonnees(sourisavant,carte)->x])
                {   
                    case FROMAGE:
                        fromage++;
                        souris->coordonneeActuelle=prochaineCoordonnees(sourisavant,carte);
                        break;
                    case PIEGE:             
                        gameOver();
                        terminer=1;
                        break;

                    case PORTE:
                        win(&fromage);
                        terminer=1;
                        break;
                    case CIEL:
                        souris->coordonneeActuelle=prochaineCoordonnees(sourisavant,carte);
                        
                        break;
                }
                souris->direction=prochaineDirection(sourisavant,carte);
                souris->position=prochainePosition(sourisavant,carte);
                sourisavant=souris;
                afficheJeu(C,carte);
                printf("on passe pas la\n");
            }
            
            return fromage;
            freeImage();
            freeSouris(souris);
            freeSouris(sourisavant);
            freeMap(carte);    
}

void mouvement(int** carte,Souris* souris, int* fromage,int* terminer){
      
    switch(carte[prochaineCoordonnees(souris,carte)->y][prochaineCoordonnees(souris,carte)->x])
    {   
        case FROMAGE:
            (*fromage)++;
            souris->coordonneeActuelle=prochaineCoordonnees(souris,carte);
            break;
        case PIEGE:             
            gameOver();
            *terminer=1;
            break;

        case PORTE:
            win(fromage);
            *terminer=1;
            break;
        case CIEL:
            souris->coordonneeActuelle=prochaineCoordonnees(souris,carte);
            *terminer=0;
            break;
    }
    souris->position=prochaineDirection(souris,carte);
    souris->position=prochainePosition(souris,carte);
}

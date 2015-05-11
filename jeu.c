#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "fichiers.h"
#include "constantes.h"
#include "jeu.h"
#include "afficher.h"

void map()
{
    SDL_Window* ecran;
  
    
    SDL_Init(SDL_INIT_VIDEO);   
    
    ecran=SDL_CreateWindow("triptrap",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,TAILLE_BLOC*NB_BLOCS_LARGEUR,TAILLE_BLOC*NB_BLOCS_HAUTEUR, 0);
    
    SDL_Renderer * renderer = SDL_CreateRenderer(ecran, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderPresent(renderer);

    SDL_Surface *surface=NULL;
    SDL_UpdateWindowSurface(ecran);
          
    
    SDL_Surface** souris = NULL;
    souris = (SDL_Surface**) malloc (sizeof(SDL_Surface*)*5);
    if (souris == NULL) {
        int i;
        for (i=0; i<5;i++) {
            SDL_FreeSurface(souris[i]);
        }
        free(souris);
    }
    SDL_Surface *mur = NULL, *fromage = NULL, *piege = NULL, *sourisActuel = NULL, *porte=NULL, *ciel=NULL; 
    SDL_Rect position, positionJoueur;
    SDL_Event event;
    TTF_Init(); 

    
    int h, erreur;
    int continuer = 1,  i = 0, j = 0;
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

    //memset(carte, 0, sizeof(carte));
    SDL_Texture* texture;

    mur = IMG_Load("brique.png");
    ciel=IMG_Load("ciel2.png");
    fromage = IMG_Load("fromage.jpg");
    piege = IMG_Load("piege.png");
    porte= IMG_Load("porte.png");
    souris[BAS] = IMG_Load("souris.png");
    souris[GAUCHE] = IMG_Load("sourisgauche.png");
    souris[HAUT] = IMG_Load("sourishaut.png");
    souris[DROITE] = IMG_Load("sourisdroite.png");

    sourisActuel=souris[DROITE];
    
    char* s="niveaux.lvl";
    
    if (!chargerNiveau(carte,s))
            exit(EXIT_FAILURE);

    
    for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
        {
        for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
        {
            if (carte[i][j]==CIEL)
            {
                afficherimage(ecran,renderer, ciel, texture,i,j);
                        
            }
            if (carte[i][j]==MUR)
            {   
                afficherimage(ecran,renderer, mur, texture,i,j);
                        
            }
            if (carte[i][j]==SOURIS)
            {
                afficherimage(ecran,renderer, souris[DROITE], texture,i,j);
        
            }
            if (carte[i][j]==FROMAGE)
            {
                afficherimage(ecran,renderer, fromage, texture,i,j);      
            }
            if (carte[i][j]==PIEGE)
            {
                afficherimage(ecran,renderer, piege, texture,i,j);        
            }
            if (carte[i][j]==PORTE)
            {
                afficherimage(ecran,renderer, porte, texture,i,j);        
            }
        }
           }
    char* nbrfromage="0";
    
    
    for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
        {
        for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
        {
            if (carte[i][j] == SOURIS)  
            {
                positionJoueur.x = i;
                positionJoueur.y = j;
                carte[i][j] = CIEL;
            }
        }
        }
        

     while (continuer==1)
    {   
    
        
        
   while (SDL_PollEvent(&event)) {

    switch(event.type)
    {
    case SDL_QUIT:
        continuer = 0;
        
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel ,texture,positionJoueur.x,positionJoueur.y);
                 if(deplacerJoueur(carte, &positionJoueur, HAUT)==1)
                    {

                        sourisActuel=souris[DROITE];
                        afficherimage(ecran,renderer,souris[DROITE],texture,positionJoueur.x,positionJoueur.y);
                        SDL_UpdateWindowSurface(ecran);
                    }
                else if (deplacerJoueur(carte, &positionJoueur, HAUT)==0)
                {   
                    win(nbrfromage);
                       
                        continuer=0;
                }
            break;
        
            case SDLK_DOWN:
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel, texture,positionJoueur.x,positionJoueur.y);        
                if(deplacerJoueur(carte, &positionJoueur, BAS)==1)
                {
                    carte[positionJoueur.x][positionJoueur.y]=SOURIS;
                    sourisActuel=souris[GAUCHE];
                    afficherimage(ecran,renderer, souris[GAUCHE], texture,positionJoueur.x,positionJoueur.y);
                    SDL_UpdateWindowSurface(ecran);
                }
                else if(deplacerJoueur(carte, &positionJoueur, BAS)==0)
                {
                     win(nbrfromage);
                        
                        continuer=0;
                }
                break;
    }
}
   
    
}

if (sourisActuel==souris[DROITE] && continuer==1)
    {
        if (carte[positionJoueur.x+1][positionJoueur.y+1]==MUR)
        {   
            if(carte[positionJoueur.x+1][positionJoueur.y]==PORTE){
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                    SDL_UpdateWindowSurface(ecran);
                win(nbrfromage);
                
                continuer=0;
                
            }
            else if (carte[positionJoueur.x+1][positionJoueur.y+1]==PIEGE)
            {
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                    SDL_UpdateWindowSurface(ecran);
                gameOver();
                continuer=0;    
            }
            else
            {    
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                positionJoueur.x++;
                carte[positionJoueur.x][positionJoueur.y]=SOURIS;
                afficherimage(ecran,renderer, souris[DROITE], texture,positionJoueur.x,positionJoueur.y);
                
                SDL_UpdateWindowSurface(ecran);
                SDL_Delay(200);
            }
        }
        else if (carte[positionJoueur.x+1][positionJoueur.y-1]==MUR)
        {   if(carte[positionJoueur.x+1][positionJoueur.y]==PORTE){
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                    SDL_UpdateWindowSurface(ecran);
                win(nbrfromage);
                
                continuer=0;
                 
            }
            else if (carte[positionJoueur.x+1][positionJoueur.y]==PIEGE)
            {
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                    SDL_UpdateWindowSurface(ecran);
                gameOver();
                continuer=0; 
            }
            else
            {
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                positionJoueur.x++;
                carte[positionJoueur.x][positionJoueur.y]=SOURIS;
                afficherimage(ecran,renderer, souris[DROITE], texture,positionJoueur.x,positionJoueur.y);
                
                SDL_UpdateWindowSurface(ecran);
                SDL_Delay(200);
            }
        }
        else if (carte[positionJoueur.x][positionJoueur.y-1]==MUR && carte[positionJoueur.x+1][positionJoueur.y-1]==CIEL)
             {  carte[positionJoueur.x][positionJoueur.y]=CIEL;
            afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
            positionJoueur.x++;
            positionJoueur.y--;
            sourisActuel=souris[HAUT];
            
            carte[positionJoueur.x][positionJoueur.y]=SOURIS;
            afficherimage(ecran,renderer, souris[HAUT], texture,positionJoueur.x,positionJoueur.y);
            SDL_UpdateWindowSurface(ecran);
            SDL_Delay(200);
            carte[positionJoueur.x][positionJoueur.y]=CIEL; 
            afficherimage(ecran,renderer, ciel, texture,positionJoueur.x,positionJoueur.y); 
        
            positionJoueur.x--;
            positionJoueur.y--;
            sourisActuel=souris[GAUCHE];
            
            carte[positionJoueur.x][positionJoueur.y]=SOURIS;
            afficherimage(ecran,renderer, souris[GAUCHE], texture,positionJoueur.x,positionJoueur.y);
            SDL_UpdateWindowSurface(ecran);
            SDL_Delay(200);
              }
            else if (carte[positionJoueur.x][positionJoueur.y+1]==MUR && carte[positionJoueur.x+1][positionJoueur.y+1]==CIEL)
            {   
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                positionJoueur.x++;
                positionJoueur.y++;
                sourisActuel=souris[BAS];
                carte[positionJoueur.x][positionJoueur.y]=SOURIS;
                afficherimage(ecran,renderer, souris[BAS], texture,positionJoueur.x,positionJoueur.y);
                SDL_UpdateWindowSurface(ecran);
                SDL_Delay(200);
                carte[positionJoueur.x][positionJoueur.y]=CIEL; 
                afficherimage(ecran,renderer, ciel, texture,positionJoueur.x,positionJoueur.y); 
                
                positionJoueur.x--;
                positionJoueur.y++;
                sourisActuel=souris[GAUCHE];
                carte[positionJoueur.x][positionJoueur.y]=SOURIS;
                afficherimage(ecran,renderer, souris[GAUCHE], texture,positionJoueur.x,positionJoueur.y);
                SDL_UpdateWindowSurface(ecran);
                SDL_Delay(200);
        
            }
    }
    else if (sourisActuel==souris[GAUCHE]  && continuer==1)
    {   if (carte[positionJoueur.x-1][positionJoueur.y+1]==MUR)
        {   if(carte[positionJoueur.x-1][positionJoueur.y]==PORTE){
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                SDL_UpdateWindowSurface(ecran);
                win(nbrfromage);
                
                continuer=0; 
            }
            
            else if(carte[positionJoueur.x-1][positionJoueur.y]==PIEGE)
            {
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                    SDL_UpdateWindowSurface(ecran);
                gameOver();
                continuer=0; 
            }
            else
            {
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                positionJoueur.x--;
                carte[positionJoueur.x][positionJoueur.y]=SOURIS;
                afficherimage(ecran,renderer, souris[GAUCHE], texture,positionJoueur.x,positionJoueur.y);
                
                SDL_UpdateWindowSurface(ecran);
                SDL_Delay(200);
            }
        }
        else if (carte[positionJoueur.x-1][positionJoueur.y-1]==MUR)
        {   if(carte[positionJoueur.x-1][positionJoueur.y]==PORTE){
            carte[positionJoueur.x][positionJoueur.y]=CIEL;
            afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
            SDL_UpdateWindowSurface(ecran);         
                win(nbrfromage);
                
                continuer=0;
            }
            else if(carte[positionJoueur.x-1][positionJoueur.y]==PIEGE)
            {
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                    SDL_UpdateWindowSurface(ecran);
                gameOver();
                continuer=0; 
            }
            else
            {
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
                afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
                positionJoueur.x--;
                carte[positionJoueur.x][positionJoueur.y]=SOURIS;
                afficherimage(ecran,renderer, souris[GAUCHE], texture,positionJoueur.x,positionJoueur.y);
                
                SDL_UpdateWindowSurface(ecran);
                SDL_Delay(200);
            }
        }
        else if (carte[positionJoueur.x][positionJoueur.y-1]==MUR && carte[positionJoueur.x-1][positionJoueur.y-1]==CIEL)
             {  carte[positionJoueur.x][positionJoueur.y]=CIEL;
            afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
            positionJoueur.x--;
            positionJoueur.y--;
            sourisActuel=souris[HAUT];
        carte[positionJoueur.x][positionJoueur.y]=SOURIS;
            afficherimage(ecran,renderer, souris[HAUT], texture,positionJoueur.x,positionJoueur.y);
            SDL_UpdateWindowSurface(ecran);
            SDL_Delay(200);
            carte[positionJoueur.x][positionJoueur.y]=CIEL; 
        afficherimage(ecran,renderer, ciel, texture,positionJoueur.x,positionJoueur.y); 
        
        positionJoueur.x++;
        positionJoueur.y--;
        sourisActuel=souris[DROITE];
        carte[positionJoueur.x][positionJoueur.y]=SOURIS;
            afficherimage(ecran,renderer, souris[DROITE], texture,positionJoueur.x,positionJoueur.y);
            SDL_UpdateWindowSurface(ecran);
            SDL_Delay(200);
              }
              else if (carte[positionJoueur.x][positionJoueur.y+1]==MUR && carte[positionJoueur.x-1][positionJoueur.y+1]==CIEL)
            {   carte[positionJoueur.x][positionJoueur.y]=CIEL;
            afficherimage(ecran,renderer, ciel,texture,positionJoueur.x,positionJoueur.y);
            positionJoueur.x--;
            positionJoueur.y++;
            sourisActuel=souris[BAS];
        carte[positionJoueur.x][positionJoueur.y]=SOURIS;
            afficherimage(ecran,renderer, souris[BAS], texture,positionJoueur.x,positionJoueur.y);
            SDL_UpdateWindowSurface(ecran);
            SDL_Delay(200);
            carte[positionJoueur.x][positionJoueur.y]=CIEL; 
        afficherimage(ecran,renderer, ciel, texture,positionJoueur.x,positionJoueur.y); 
        
        positionJoueur.x++;
        positionJoueur.y++;
        sourisActuel=souris[DROITE];
        carte[positionJoueur.x][positionJoueur.y]=SOURIS;
            afficherimage(ecran,renderer, souris[DROITE], texture,positionJoueur.x,positionJoueur.y);
            SDL_UpdateWindowSurface(ecran);
            SDL_Delay(200);
        
            }
        
        
        }   
    

 SDL_FillRect(surface, NULL, 0);



        

    position.x = positionJoueur.x * TAILLE_BLOC;
        position.y = positionJoueur.y * TAILLE_BLOC;
        SDL_BlitSurface(sourisActuel, NULL, surface, &position);

    SDL_UpdateWindowSurface(ecran);
}
    SDL_FreeSurface(mur);
    
    SDL_FreeSurface(piege);
    SDL_FreeSurface(fromage);
    for (i = 0 ; i < 4 ; i++)
        SDL_FreeSurface(souris[i]);
    free(souris);
    SDL_FreeSurface(surface);
    
    
        SDL_DestroyTexture(texture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(ecran);
        
}


int deplacerJoueur(int** carte, SDL_Rect *pos, int direction)
{   
    switch(direction)
    {
        case HAUT:
            if (pos->y - 1 < 0) 
                break;
            if (carte[pos->x][pos->y - 1] == MUR) 
        break;
        int h=pos->y;
        while (carte[pos->x][pos->y-1]!=MUR)
        {   
        pos->y--;
        if (pos->y==0){
            pos->y=h;
            return 1;
            break;
        }
        else if (carte[pos->x][pos->y]==PORTE){
                return 0;
            }
        }
        
        break;

    case BAS:
            if (pos->y + 1 >= NB_BLOCS_HAUTEUR)
                break;
            if (carte[pos->x][pos->y + 1] == MUR)
                break;
        int g=pos->y;
        while (carte[pos->x][pos->y+1]!=MUR)
        {
            pos->y++;
            if (pos->y==NB_BLOCS_HAUTEUR){
                pos->y=g;
                return 1;
                break;
            }
            else if (carte[pos->x][pos->y]==PORTE){
                return 0;
            }
        }
        
        break;
     
    }
    return 2;
}



    

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
Souris* sourisavant;
SDL_Rect* tempoCoord;


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
    for (i=0; i<4;i++) {
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

            chargerImage();
            afficheJeu(C,carte);
       
              
            while(terminer==0){
                while(evenement(carte,souris,C,&fromage,&terminer)==0 && terminer==0){
                        mouvement(carte,souris,&fromage,&terminer,C);
                        afficheJeu(C,carte);
                        SDL_Delay(150);
                        
                }
            }
            freeImage();
            freeSouris(souris);
            freeMap(carte);
            return fromage;
    
}
void mouvement(int** carte,Souris* souris, int* fromage,int* terminer,Contenu* C){
    sourisavant=creerSouris(souris->coordonneeActuelle,souris->direction,souris->position); 
    tempoCoord = prochaineCoordonnees(souris,carte);
    switch(carte[tempoCoord->y][tempoCoord->x])
                {   
                    case FROMAGE:
                        
                        (*fromage)++;

                        carte[tempoCoord->y][tempoCoord->x]=CIEL;
                    
                        //free(prochaineCoordonnees(souris,carte));
                        souris->coordonneeActuelle=prochaineCoordonnees(sourisavant,carte);
                        souris->direction=prochaineDirection(sourisavant,carte);
                        souris->position=prochainePosition(sourisavant,carte);
                        
                        break;
                    case PIEGE:
                                   
                        gameOver();
                        *fromage=0;
                        *terminer=1;
                        break;

                    case PORTE:
                        
                        win(fromage);
                        *terminer=1;
                        break;
                    case CIEL:
                        souris->coordonneeActuelle=prochaineCoordonnees(sourisavant,carte);
                        souris->direction=prochaineDirection(sourisavant,carte);
                        souris->position=prochainePosition(sourisavant,carte);
                       
                        break;
                    case FLECHEG:
                        
                        switch(souris->direction){
                        case DROITE:
                            souris->direction=GAUCHE;
                            
                            break;
                        case GAUCHE: 
                            souris->coordonneeActuelle=prochaineCoordonnees(sourisavant,carte);
                            souris->direction=prochaineDirection(sourisavant,carte);
                            souris->position=prochainePosition(sourisavant,carte);
                            
                            break;
                        break;
                        }
                        break;
                    case FLECHED:
                        
                        switch(souris->direction){
                        case DROITE:
                            souris->coordonneeActuelle=prochaineCoordonnees(sourisavant,carte);
                            souris->direction=prochaineDirection(sourisavant,carte);
                            souris->position=prochainePosition(sourisavant,carte);
                            
                            break;
                        case GAUCHE: 
                            souris->direction=DROITE;
                            
                            break;
                        break;
                        }
                        break;
                    case CHAT:
                        
                         gameOver();
                         *fromage=0;
                        *terminer=1;
                        
                        break;
                }
                
               //free(tempoCoord);
                afficheJeu(C,carte);                
                //freeSouris(sourisavant);
                
}

int evenement(int** carte,Souris* souris,Contenu* C,int* fromage,int *terminer){
     SDL_Event event;

      while (SDL_PollEvent(&event)){
   
           
            switch(event.type)
            {
                case SDL_QUIT:
                    *fromage=0;
                    *terminer=1;
                    free(tempoCoord);
                    return 1;
                    break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    { case SDLK_UP:
                        if(souris->direction==DROITE|| souris->direction==GAUCHE){
                            if ((souris->coordonneeActuelle->y)-1 < 0){
                                return 0;
                                
                            }
                            else if (carte[souris->coordonneeActuelle->y-1][souris->coordonneeActuelle->x] == MUR){
                                return 0;
                                 
                            }                             
                            else {       
                                int h=souris->coordonneeActuelle->y;
                                while (carte[souris->coordonneeActuelle->y-1][souris->coordonneeActuelle->x]!=MUR)
                                {   
                                    (souris->coordonneeActuelle->y)--;
                                    if (souris->coordonneeActuelle->y==0){
                                        souris->coordonneeActuelle->y=h;
                                        return 0;    
                                        
                                    }
                                    else if (carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]==PORTE){
                                        
                                        afficheJeu(C, carte);
                                        win(fromage);
                                        *terminer=1;
                                        return 1;
                                        
                                    }
                                    else if (carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]==PIEGE){
                                            
                                            afficheJeu(C, carte);
                                            gameOver();
                                            *fromage=0;
                                            *terminer=1;
                                            return 1;
                                            
                                    }
                                    else if (carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]==FROMAGE){
                                            (*fromage)++;
                                            carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]=CIEL;
                                            afficheJeu(C, carte);
                                            souris->position=BAS;
                                           
                                            return 1;
                                            
                                    }
                                    else if (carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]==CHAT){
                                            
                                            afficheJeu(C, carte);
                                            gameOver();
                                            *fromage=0;
                                            *terminer=1;
                                            return 1;
                                            
                                    }
                                        
                                }
                                
                                afficheJeu(C,carte);
                                souris->position=BAS;
                                return 1;
                                
                            }
                        }
                            break;                    
                            
                            

                        case SDLK_DOWN:
                            if(souris->direction==DROITE|| souris->direction==GAUCHE){
                        
                            if (souris->coordonneeActuelle->y+1 >= NB_BLOCS_HAUTEUR){
                                return 0;
                                
                            }
                            else if (carte[souris->coordonneeActuelle->y+1][souris->coordonneeActuelle->x] == MUR){
                                return 0;
                                
                            }
                            else {
                                int g=souris->coordonneeActuelle->y;
                                while (carte[souris->coordonneeActuelle->y+1][souris->coordonneeActuelle->x]!=MUR)
                                {
                                    (souris->coordonneeActuelle->y)++;
                                    if (souris->coordonneeActuelle->y==NB_BLOCS_HAUTEUR-1){
                                        
                                        souris->coordonneeActuelle->y=g;
                                        return 0;
                                        
                                    }
                                    else if (carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]==PORTE){
                                       
                                        
                                         afficheJeu(C, carte);
                                         win(fromage);
                                        *terminer=1;
                                        return 1;
                                        
                                    }
                                    else if (carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]==PIEGE){
                                        
                                        
                                         afficheJeu(C, carte);
                                         gameOver();
                                        *fromage=0;
                                        *terminer=1;
                                        return 1;
                                        
                                    }
                                     else if (carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]==FROMAGE){
                                            (*fromage)++;
                                            carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]=CIEL;
                                            afficheJeu(C, carte);
                                            souris->position=HAUT;
                                            return 1;
                                            
                                    }
                                    else if (carte[souris->coordonneeActuelle->y][souris->coordonneeActuelle->x]==CHAT){
                                        
                                        
                                         afficheJeu(C, carte);
                                         gameOver();
                                        
                                        *fromage=0;
                                        *terminer=1;
                                        return 1;
                                        
                                    }
                               
                                } 
                               
                                 souris->position=HAUT;
                                 
                                 afficheJeu(C,carte);  
                                
                                 return 1;              
                            }  
                            }                  
                            break;
                    }
                           
                          
               
                    break; 
            }
    }   
    return 0;
}


#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "fichiers.h"
#include "constantes.h"
#include "jeu.h"
#include "afficher.h"
<<<<<<< HEAD
#include "constantes.h"
=======
#define FPS 10
>>>>>>> 36c6464a5522ccf5aeece2d95c0b44a2049c1ac8


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
void afficheJeu(Contenu* C,int** carte,int direction){
    
    int i = 0, j = 0;   
    SDL_Surface** souris = NULL;
    souris = (SDL_Surface**) malloc (sizeof(SDL_Surface*)*5);
    if (souris == NULL) {
        
        for (i=0; i<5;i++) {
            SDL_FreeSurface(souris[i]);
        }
        free(souris);
    }
    SDL_Surface *mur = NULL, *fromage = NULL, *piege = NULL, *sourisActuel = NULL, *porte=NULL, *ciel=NULL,*fleched=NULL, *flecheg=NULL, *chat=NULL; 
          
    mur = IMG_Load("brique.png");
    ciel=IMG_Load("ciel2.png");
    fromage = IMG_Load("fromage.jpg");
    piege = IMG_Load("piege.png");
    porte= IMG_Load("porte.png");
    souris[BAS] = IMG_Load("souris.png");
    souris[GAUCHE] = IMG_Load("sourisgauche.png");
    souris[HAUT] = IMG_Load("sourishaut.png");
    souris[DROITE] = IMG_Load("sourisdroite.png");
    fleched=IMG_Load("fleched.png");
    flecheg=IMG_Load("flecheg.png");
    chat=IMG_Load("chat.png");

    sourisActuel=souris[direction];
            
        
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
            if (carte[i][j]==SOURIS)
            {
                afficherimage(C, sourisActuel,j,i);
                

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
    SDL_UpdateWindowSurface(C->window);
    
    
}

SDL_Rect positionS(int **carte){
    SDL_Rect positionSouris;
    int i,j;
     for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
        {
        for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
        {
            if (carte[i][j] == SOURIS)  
            {
                positionSouris.x=j;
                positionSouris.y=i;
               
            }
        }
<<<<<<< HEAD
        }
        return positionSouris ;
}
SDL_Rect positionC(int **carte){
    SDL_Rect positionChat;
    int i,j;
     for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
        {
        for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
        {
            if (carte[i][j] == SOURIS)  
            {
                positionChat.x=j;
                positionChat.y=i;
               
            }
        }
        }
        return positionChat ;
}

=======
<<<<<<< HEAD
        }
        
int limit;
int test;
     while (continuer==1)
    {  
    test = SDL_GetTicks();
     if (limit> test + FPS){
           SDL_Delay(FPS);
}
else{
SDL_Delay(limit - test);
}
       limit = SDL_GetTicks() + FPS; 
        
   while (SDL_PollEvent(&event)) {
=======
    }


    while (continuer==1)
    {   
>>>>>>> cd8c16a4f0ee0f33f5ced8813a96069a2461337f
>>>>>>> 36c6464a5522ccf5aeece2d95c0b44a2049c1ac8

int evenement(int* terminer, int** carte,SDL_Rect* positionSouris,int* direction,Contenu* C,int* fromage,int* position){
     SDL_Event event;

      while (SDL_PollEvent(&event)){


      
            
            switch(event.type)
            {
                case SDL_QUIT:
                printf("on quitte");
                *fromage=0;
                *terminer=1;
                return 1;
                break;

                case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {   
                    case SDLK_UP:
                    if(*direction==DROITE || *direction==GAUCHE){                        
                        printf("key up");
                        if (positionSouris->y-1 < 0){
                            return 0;
                            break;
                        }
                        else if (carte[positionSouris->y-1][positionSouris->x] == MUR){
                            return 0;
                             break;
                        }                             
                        else {       
                            int h=positionSouris->y;
                            while (carte[positionSouris->y-1][positionSouris->x]!=MUR)
                            {   
                                (positionSouris->y)--;
                                if (positionSouris->y==0){
                                    positionSouris->y=h;
                                    return 0;    
                                    break;
                                }
                                else if (carte[positionSouris->y][positionSouris->x]==PORTE){
                                    carte[h][positionSouris->x]=CIEL;
                                    afficheJeu(C, carte, *direction);
                                    win(fromage);
                                    *terminer=1;
                                    return 1;
                                    break;
                                }
                                else if (carte[positionSouris->y][positionSouris->x]==PIEGE){
                                        carte[h][positionSouris->x]=CIEL;
                                        afficheJeu(C, carte, *direction);
                                        gameOver();
                                        *terminer=1;
                                        return 1;
                                        break;
                                }
                                    
                            }
                            carte[h][positionSouris->x]=CIEL;
                            carte[positionSouris->y][positionSouris->x]=SOURIS;
                            afficheJeu(C,carte,*direction);
                            *position=BAS;
                            return 1;
                            
                        }
                    }
                    break;                    
                        
                        

                    case SDLK_DOWN:
                        printf("key down");
                    if(*direction==DROITE || *direction==GAUCHE){
                        if (positionSouris->y+1 >= NB_BLOCS_HAUTEUR){
                            return 0;
                            break;
                        }
                        else if (carte[positionSouris->y+1][positionSouris->x] == MUR){
                            return 0;
                            break;
                        }
                        else {
                            int g=positionSouris->y;
                            while (carte[positionSouris->y+1][positionSouris->x]!=MUR)
                            {
                                (positionSouris->y)++;
                                if (positionSouris->y==NB_BLOCS_HAUTEUR){
                                    printf("trop bas");
                                    positionSouris->y=g;
                                    return 0;
                                    break;
                                }
                                else if (carte[positionSouris->y][positionSouris->x]==PORTE){
                                    printf("porte\n");
                                    carte[g][positionSouris->x]=CIEL;
                                     afficheJeu(C, carte, *direction);
                                     win(fromage);
                                    *terminer=1;
                                    return 1;
                                    break;
                                }
                                else if (carte[positionSouris->y][positionSouris->x]==PIEGE){
                                    printf("piege\n");
                                    carte[g][positionSouris->x]=CIEL;
                                     afficheJeu(C, carte, *direction);
                                     gameOver();
                                    *fromage=0;
                                    *terminer=1;
                                    return 1;
                                    break;
                                }
                           
                            } 
                            carte[g][positionSouris->x]=CIEL;
                             carte[positionSouris->y][positionSouris->x]=SOURIS;
                             *position=HAUT;
                             printf("on passe ici\n");
                             afficheJeu(C,carte,*direction);  
                            
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
int collisionPorte(int** carte,SDL_Rect* pos,int direction,int* terminer,Contenu* C,int* fromage){
        switch(direction){
            case 0:
                if(carte[pos->y-1][pos->x+1]==PORTE || carte[pos->y-1][pos->x-1]==PORTE){
                    carte[pos->y][pos->x]=CIEL;
                    afficheJeu(C,carte,direction);
                    win(fromage);
                    *terminer=1;
                    return 1;
                }
                break;
            case 1:
                if(carte[pos->y][pos->x+1]==PORTE){
                    carte[pos->y][pos->x]=CIEL;
                    afficheJeu(C,carte,direction);
                    win(fromage);
                    *terminer=1;
                    return 1;
                }
                break;
            case 2:
                if(carte[pos->y+1][pos->x+1]==PORTE || carte[pos->y+1][pos->x-1]==PORTE){
                    carte[pos->y][pos->x]=CIEL;
                    afficheJeu(C,carte,direction);
                    win( fromage);
                    *terminer=1;
                    return 1;
                }
                break;
            case 3:
                if(carte[pos->y][pos->x-1]==PORTE){
                    carte[pos->y][pos->x]=CIEL;
                    afficheJeu(C,carte,direction);
                    win( fromage);
                    *terminer=1;
                    return 1;
                }
                break;
        }
        return 0;
}
int collisionPiege(int** carte,SDL_Rect* pos,int direction,int* terminer,Contenu* C,int* fromage){
   
        switch(direction){
            case 0:
                if(carte[pos->y-1][pos->x+1]==PIEGE || carte[pos->y-1][pos->x-1]==PIEGE){
                    carte[pos->y][pos->x]=CIEL;
                    afficheJeu(C,carte,direction);
                    gameOver();
                    *fromage=0;
                    *terminer=1;
                    return 1;
                }
                break;
            case 1:
                if(carte[pos->y][pos->x+1]==PIEGE){
                    carte[pos->y][pos->x]=CIEL;
                    afficheJeu(C,carte,direction);
                    gameOver();
                    *fromage=0;
                    *terminer=1;
                    return 1;
                }
                break;
            case 2:
                if(carte[pos->y+1][pos->x+1]==PIEGE || carte[pos->y+1][pos->x-1]==PIEGE){
                    carte[pos->y][pos->x]=CIEL;
                    afficheJeu(C,carte,direction);
                    gameOver();
                    *fromage=0;
                    *terminer=1;
                    return 1;
                }
                break;
            case 3:
                if(carte[pos->y][pos->x-1]==PIEGE){
                    carte[pos->y][pos->x]=CIEL;
                    afficheJeu(C,carte,direction);
                    gameOver();
                    *fromage=0;
                    *terminer=1;
                    return 1;
                }
                break;
        }
        return 0;

}
int collisionFromage(int** carte,SDL_Rect* pos,int direction,Contenu* C,int* fromage){
    

    switch(direction){
            case 0:
                if(carte[pos->y-1][pos->x+1]==FROMAGE ){
                    (*fromage)++;
                    carte[pos->y][pos->x]=CIEL;
                    carte[pos->y-1][pos->x+1]=SOURIS;
                    afficheJeu(C,carte,direction);                    
                    return 1;
                }
                else if (carte[pos->y-1][pos->x-1]==FROMAGE){
                   (*fromage)++;
                    carte[pos->y][pos->x]=CIEL;
                    carte[pos->y-1][pos->x-1]=SOURIS;
                    afficheJeu(C,carte,direction);                    
                    return 1;
                }
                break;
            case 1:
                if(carte[pos->y][pos->x+1]==FROMAGE){
                    (*fromage)++;
                    carte[pos->y][pos->x]=CIEL;
                    carte[pos->y][pos->x+1]=SOURIS;
                    afficheJeu(C,carte,direction);
                    return 1;
                }
                break;
            case 2:
                if(carte[pos->y+1][pos->x+1]==FROMAGE ){
                    (*fromage)++;
                    carte[pos->y][pos->x]=CIEL;
                    carte[pos->y+1][pos->x+1]=SOURIS;
                    afficheJeu(C,carte,direction);
                    return 1;
                }
                else if(carte[pos->y+1][pos->x-1]==FROMAGE){
                    (*fromage)++;
                    carte[pos->y][pos->x]=CIEL;
                    carte[pos->y+1][pos->x-1]=SOURIS;
                    afficheJeu(C,carte,direction);
                    return 1; 
                }
                break;
            case 3:
                if(carte[pos->y][pos->x-1]==FROMAGE){
                    (*fromage)++;
                    carte[pos->y][pos->x]=CIEL;
                    carte[pos->y][pos->x-1]=SOURIS;
                    afficheJeu(C,carte,direction);                    
                    return 1;
                }
                break;
        }
       
        return 0;

}
void collisionMur(int** carte,int* direction,int* position, SDL_Rect* pos,int* terminer,Contenu* C,int* fromage){
    if(collisionFleche(carte,pos,direction,C)==0 && collisionPorte(carte,pos,*direction,terminer,C,fromage)==0 && collisionPiege(carte,pos,*direction,terminer,C,fromage)==0 && collisionFromage(carte,pos,*direction,C,fromage)==0){
        
        switch(*direction){
            case 0:
                switch(*position){
                    case 1:
                        if(carte[pos->y-1][pos->x-1]==MUR && carte[pos->y-1][pos->x]!=MUR){
                            carte[pos->y][pos->x]=CIEL;
                             carte[pos->y-1][pos->x]=SOURIS;
                        }
                        else if(carte[pos->y-1][pos->x-1]==MUR && carte[pos->y-1][pos->x]==MUR) {
                            *direction=DROITE;
                            *position=BAS;
                        }
                        else {
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y-1][pos->x-1]=SOURIS;  
                            *direction=GAUCHE;
                            *position=HAUT;
                        }
                        break;
                    case 3:
                        if(carte[pos->y-1][pos->x+1]==MUR && carte[pos->y-1][pos->x]!=MUR){
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y-1][pos->x]=SOURIS;
                        }
                        else if (carte[pos->y-1][pos->x+1]==MUR && carte[pos->y-1][pos->x]==MUR){
                            *direction=GAUCHE;
                            *position=BAS;
                        }
                        else {
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y-1][pos->x+1]=SOURIS;
                            *direction=DROITE;
                            *position=HAUT;
                        }
                        break;
                }
                break;
            case 1:
                switch(*position){
                    case 0:
                        if(carte[pos->y+1][pos->x+1]==MUR && carte[pos->y][pos->x+1]!=MUR){
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y][pos->x+1]=SOURIS;
                        }
                        else if(carte[pos->y+1][pos->x+1]==MUR && carte[pos->y][pos->x+1]==MUR){
                            *direction=HAUT;
                            *position=GAUCHE;
                        }
                        else {    
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y+1][pos->x+1]=SOURIS;  
                            *direction=BAS;
                            *position=DROITE;
                        }
                        break;
                    case 2:
                        if(carte[pos->y-1][pos->x+1]==MUR && carte[pos->y][pos->x+1]!=MUR){
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y][pos->x+1]=SOURIS;
                        }
                        else if(carte[pos->y-1][pos->x+1]==MUR && carte[pos->y][pos->x+1]==MUR){
                            *direction=BAS;
                            *position=GAUCHE;
                        }
                        else {
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y-1][pos->x+1]=SOURIS;
                            *direction=HAUT;
                            *position=DROITE;
                        }
                        break;
                }
                break;
            case 2:
                switch(*position){
                    case 1:
                        if( carte[pos->y+1][pos->x-1]==MUR && carte[pos->y+1][pos->x]!=MUR){
                            carte[pos->y][pos->x]=CIEL;
                             carte[pos->y+1][pos->x]=SOURIS;
                        }
                        else if(carte[pos->y+1][pos->x-1]==MUR && carte[pos->y+1][pos->x]==MUR){
                            *direction=DROITE;
                            *position=HAUT;
                        }
                        else {
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y+1][pos->x-1]=SOURIS;
                            *direction=GAUCHE;
                            *position=BAS;
                        }
                        break;
                    case 3:
                        if(carte[pos->y+1][pos->x+1]==MUR && carte[pos->y+1][pos->x]!=MUR){
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y+1][pos->x]=SOURIS;
                        }
                        else if(carte[pos->y+1][pos->x+1]==MUR && carte[pos->y+1][pos->x]==MUR){
                            *direction=GAUCHE;
                            *position=HAUT;
                        }
                        else {
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y+1][pos->x+1]=SOURIS;  
                            *direction=DROITE;
                            *position=BAS;
                        }
                        break;
                }
                break;
                
            case 3:
                switch(*position){
                    case 0:
                        if(carte[pos->y+1][pos->x-1]==MUR && carte[pos->y][pos->x-1]!=MUR){
                            carte[pos->y][pos->x]=CIEL;
                             carte[pos->y][pos->x-1]=SOURIS;
                        }
                        else if(carte[pos->y+1][pos->x-1]==MUR && carte[pos->y][pos->x-1]==MUR){
                            *direction=HAUT; 
                            *position=DROITE;
                        }
                        else {
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y+1][pos->x-1]=SOURIS;
                            *direction=BAS; 
                            *position=GAUCHE;
                        }
                        break;
                    case 2:
                        if(carte[pos->y-1][pos->x-1]==MUR && carte[pos->y][pos->x-1]!=MUR){
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y][pos->x-1]=SOURIS;
                        }
                        else if(carte[pos->y-1][pos->x-1]==MUR && carte[pos->y][pos->x-1]==MUR){
                            *direction=BAS; 
                            *position=DROITE;
                        }
                        else {
                            carte[pos->y][pos->x]=CIEL;
                            carte[pos->y-1][pos->x-1]=SOURIS;  
                            *direction=HAUT; 
                            *position=GAUCHE;
                        }
                        break;

                }
               
                break;
            }

    
    
            
    }


}
int collisionFleche(int** carte,SDL_Rect* pos,int* direction,Contenu* C){
    if(carte[pos->y][pos->x+1]==FLECHEG  && *direction!=GAUCHE){
        *direction=GAUCHE;
        return 1;
    }
    else if(carte[pos->y][pos->x-1]==FLECHED && *direction!=DROITE){
        *direction=DROITE;
        return 1;
    }
    return 0;
}

int map(Contenu* C,char* s)
{       
            int terminer=0;
            int fromage=0;
            int **carte=chargerMap(s);
            int direction=DROITE;
            int position=HAUT;
            SDL_Rect positionSouris=positionS(carte);
            afficheJeu(C,carte,direction);
       
              
            while(terminer==0){
            while(evenement(&terminer,carte,&positionSouris,&direction,C,&fromage,&position)==0 && terminer==0){
                positionSouris=positionS(carte);
                collisionMur(carte,&direction,&position,&positionSouris,&terminer,C,&fromage);
                
                afficheJeu(C,carte,direction);
                positionSouris=positionS(carte);
                SDL_Delay(20);
            }
            }
            printf("%d",fromage);
            return fromage;
      
}



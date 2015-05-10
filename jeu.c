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
	SDL_Window* screen;
	SDL_Event event;
	
	SDL_Init(SDL_INIT_VIDEO);	
	
	screen=SDL_CreateWindow("triptrap",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,TAILLE_BLOC*NB_BLOCS_LARGEUR,TAILLE_BLOC*NB_BLOCS_HAUTEUR, 0);
	
	SDL_Renderer * renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderPresent(renderer);

	SDL_Surface *surface=NULL;
	SDL_UpdateWindowSurface(screen);
	int terminerMap=0;
	jouer(screen, renderer, surface, &terminerMap); 
	
	
	while (terminerMap==0)        
        {        
           SDL_WaitEvent(&event);        
            
           switch(event.type)        
           {        
           case SDL_QUIT:        
              terminerMap=1; 
				  
               break;
	    }
	}
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	SDL_Quit();
	
}



void jouer(SDL_Window* ecran, SDL_Renderer* renderer, SDL_Surface* surface, int* terminerMap)
{
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
	SDL_Texture* texture[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] ;
	memset(texture, 0, sizeof(texture));

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
				afficherimage(ecran,renderer, ciel, texture[i][j],i,j);
						
			}
			if (carte[i][j]==MUR)
			{	
				afficherimage(ecran,renderer, mur, texture[i][j],i,j);
						
			}
			if (carte[i][j]==SOURIS)
			{
				afficherimage(ecran,renderer, souris[DROITE], texture[i][j],i,j);
		
			}
			if (carte[i][j]==FROMAGE)
			{
				afficherimage(ecran,renderer, fromage, texture[i][j],i,j);		
			}
			if (carte[i][j]==PIEGE)
			{
				afficherimage(ecran,renderer, piege, texture[i][j],i,j);		
			}
			if (carte[i][j]==PORTE)
			{
				afficherimage(ecran,renderer, porte, texture[i][j],i,j);		
			}
		}
	       }
	char* nbrfromage="0";
	
	TTF_Font *police = NULL;
	police = TTF_OpenFont("gargi.ttf", 20);
	SDL_Color color={255,255,255};
	SDL_Surface *numfromage;
	numfromage =TTF_RenderText_Solid(police,nbrfromage,color);
	SDL_Texture *TT=SDL_CreateTextureFromSurface(renderer,numfromage);
	SDL_Rect dd={0,0,100,100};
	SDL_RenderCopy(renderer,TT,NULL,&dd);
	SDL_BlitSurface(numfromage,NULL,SDL_GetWindowSurface(ecran),&dd);
	
	SDL_UpdateWindowSurface(ecran);
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
	
		
		
       while (SDL_PollEvent(&event) != 0) {

	switch(event.type)
	{
    case SDL_QUIT:
        continuer = 0;
	*terminerMap=1;
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
                carte[positionJoueur.x][positionJoueur.y]=CIEL;
		afficherimage(ecran,renderer, ciel ,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
	        deplacerJoueur(carte, &positionJoueur, HAUT);
		sourisActuel=souris[DROITE];
		afficherimage(ecran,renderer,souris[DROITE],texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
		SDL_UpdateWindowSurface(ecran);
		
                break;
            case SDLK_DOWN:
		carte[positionJoueur.x][positionJoueur.y]=CIEL;
		afficherimage(ecran,renderer, ciel, texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);        
                deplacerJoueur(carte, &positionJoueur, BAS);
		carte[positionJoueur.x][positionJoueur.y]=SOURIS;
		sourisActuel=souris[GAUCHE];
		afficherimage(ecran,renderer, souris[GAUCHE], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
		SDL_UpdateWindowSurface(ecran);
		
                break;
	}
}
   
    
}

if (sourisActuel==souris[DROITE])
	{
		if (carte[positionJoueur.x+1][positionJoueur.y+1]==MUR)
		{	
			if(carte[positionJoueur.x+1][positionJoueur.y]==PORTE){
				carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
					SDL_UpdateWindowSurface(ecran);
				win(nbrfromage);
				*terminerMap=1;
				continuer=0;
				
			}
			carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			positionJoueur.x++;
			carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[DROITE], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
		}
		else if (carte[positionJoueur.x+1][positionJoueur.y-1]==MUR)
		{	if(carte[positionJoueur.x+1][positionJoueur.y]==PORTE){
				carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
					SDL_UpdateWindowSurface(ecran);
				win(nbrfromage);
				*terminerMap=1; 
				continuer=0;
				 
			}
			carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			positionJoueur.x++;
			carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[DROITE], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
		}
		else if (carte[positionJoueur.x][positionJoueur.y-1]==MUR && carte[positionJoueur.x+1][positionJoueur.y-1]==CIEL)
		     {	carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			positionJoueur.x++;
			positionJoueur.y--;
			sourisActuel=souris[HAUT];
		carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[HAUT], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
			carte[positionJoueur.x][positionJoueur.y]=CIEL;	
		afficherimage(ecran,renderer, ciel, texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);	
		
		positionJoueur.x--;
		positionJoueur.y--;
		sourisActuel=souris[GAUCHE];
		carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[GAUCHE], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
		      }
		      else if (carte[positionJoueur.x][positionJoueur.y+1]==MUR && carte[positionJoueur.x+1][positionJoueur.y+1]==CIEL)
			{	carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			positionJoueur.x++;
			positionJoueur.y++;
			sourisActuel=souris[BAS];
		carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[BAS], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
			carte[positionJoueur.x][positionJoueur.y]=CIEL;	
		afficherimage(ecran,renderer, ciel, texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);	
		
		positionJoueur.x--;
		positionJoueur.y++;
		sourisActuel=souris[GAUCHE];
		carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[GAUCHE], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
		
			}
	}
	else if (sourisActuel==souris[GAUCHE])
	{	if (carte[positionJoueur.x-1][positionJoueur.y+1]==MUR)
		{	if(carte[positionJoueur.x-1][positionJoueur.y]==PORTE){
		        carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			SDL_UpdateWindowSurface(ecran);
				win(nbrfromage);
				*terminerMap=1;
				continuer=0; 
			}
			
			carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			positionJoueur.x--;
			carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[GAUCHE], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
		}
		else if (carte[positionJoueur.x-1][positionJoueur.y-1]==MUR)
		{	if(carte[positionJoueur.x-1][positionJoueur.y]==PORTE){
			carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			SDL_UpdateWindowSurface(ecran);			
				win(nbrfromage);
				*terminerMap=1;
				continuer=0;
			}
			carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			positionJoueur.x--;
			carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[GAUCHE], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
		}
		else if (carte[positionJoueur.x][positionJoueur.y-1]==MUR && carte[positionJoueur.x-1][positionJoueur.y-1]==CIEL)
		     {	carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			positionJoueur.x--;
			positionJoueur.y--;
			sourisActuel=souris[HAUT];
		carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[HAUT], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
			carte[positionJoueur.x][positionJoueur.y]=CIEL;	
		afficherimage(ecran,renderer, ciel, texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);	
		
		positionJoueur.x++;
		positionJoueur.y--;
		sourisActuel=souris[DROITE];
		carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[DROITE], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
		      }
		      else if (carte[positionJoueur.x][positionJoueur.y+1]==MUR && carte[positionJoueur.x-1][positionJoueur.y+1]==CIEL)
			{	carte[positionJoueur.x][positionJoueur.y]=CIEL;
			afficherimage(ecran,renderer, ciel,texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			positionJoueur.x--;
			positionJoueur.y++;
			sourisActuel=souris[BAS];
		carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[BAS], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
			SDL_UpdateWindowSurface(ecran);
			SDL_Delay(200);
			carte[positionJoueur.x][positionJoueur.y]=CIEL;	
		afficherimage(ecran,renderer, ciel, texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);	
		
		positionJoueur.x++;
		positionJoueur.y++;
		sourisActuel=souris[DROITE];
		carte[positionJoueur.x][positionJoueur.y]=SOURIS;
			afficherimage(ecran,renderer, souris[DROITE], texture[positionJoueur.x][positionJoueur.y],positionJoueur.x,positionJoueur.y);
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
}

void deplacerJoueur(int** carte, SDL_Rect *pos, int direction)
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
			break;
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
			break;
		}
	    }
	    break;
	 
	}
}



	

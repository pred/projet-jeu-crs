
#include "jeu.c"
#include "menu.h"

void map()
{
	SDL_Window* screen;
	SDL_Event event;
	
	SDL_Init(SDL_INIT_VIDEO);	
	
	screen=SDL_CreateWindow("niveau1",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,TAILLE_BLOC*NB_BLOCS_LARGEUR,TAILLE_BLOC*NB_BLOCS_HAUTEUR, 0);
	
	SDL_Renderer * renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderPresent(renderer);

	SDL_Surface *surface=NULL;
	SDL_UpdateWindowSurface(screen);
	int* terminer=0;
	jouer(screen,surface,renderer,terminer); 
	
	
	while (terminer==0)        
        {        
           SDL_WaitEvent(&event);        
            
           switch(event.type)        
           {        
           case SDL_QUIT:        
              terminer=1; 
				  
               break;
	    }
	}
	SDL_Quit();
	
}
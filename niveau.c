#include "niveau.h"
#include "menu.h"
#include "jeu.h"
#include "afficher.h"
void niveau(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface *surface, SDL_Texture *texture, int *terminermenu){
	int terminer=0;
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);

	chargerimage(window, renderer,surface,texture,50,50, "souris.bmp");
	chargerimage(window, renderer,surface,texture,300,50, "souris2b.bmp");
	chargerimage(window, renderer,surface,texture,550,50, "souris3.bmp");
	chargerimage(window, renderer,surface,texture,50,350, "souris4.bmp");
	chargerimage(window, renderer,surface,texture,300,350, "souris5.bmp");
	chargerimage(window, renderer,surface,texture,550,350, "souris6.bmp");
	SDL_UpdateWindowSurface(window);	

	 while (terminer==0)        
        {        
           SDL_WaitEvent(&event);        
            
           switch(event.type)        
           {        
           case SDL_QUIT:        
              terminer=1;
              *terminermenu=1;
		
		     
              break;
	   case SDL_MOUSEBUTTONDOWN:
		/*cas ou l'on clique sur niveau1 */
		if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=50 && event.button.y>50 && event.button.x<=300 && 		event.button.y<=250){
		/* on desemcombre */ 
		  
		
		/* redirection vers les niveaux */ 
		map();
		
		break;
		}
	}

	}
	
}


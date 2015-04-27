#include "menu.h"
#include "niveau11.c"
void niveau(){
	int terminer=0;
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);

	/*creation fenetre */
	SDL_Window* window1 = SDL_CreateWindow("niveaux",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,800, 600, 0);
	SDL_Renderer* renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderPresent(renderer1);

	/*affichage niveau */
	SDL_Surface* niveau1 = SDL_LoadBMP("souris.bmp");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer1,
        niveau1);
	SDL_Rect dstrect1 = {50, 50, 200,200 };
	SDL_RenderCopy(renderer1, texture, NULL, &dstrect1);
	SDL_BlitSurface(niveau1,NULL,SDL_GetWindowSurface(window1),&dstrect1);

	SDL_Surface* niveau2 = SDL_LoadBMP("souris2b.bmp");
	SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer1,
        niveau2);
	SDL_Rect dstrect2 = {300, 50, 200,200 };
	SDL_RenderCopy(renderer1, texture2, NULL, &dstrect2);
	SDL_BlitSurface(niveau2,NULL,SDL_GetWindowSurface(window1),&dstrect2);

	SDL_Surface* niveau3 = SDL_LoadBMP("souris3.bmp");
	SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer1,
        niveau3);
	SDL_Rect dstrect3 = {550, 50, 200,200 };
	SDL_RenderCopy(renderer1, texture3, NULL, &dstrect3);
	SDL_BlitSurface(niveau3,NULL,SDL_GetWindowSurface(window1),&dstrect3);

	SDL_Surface* niveau4 = SDL_LoadBMP("souris4.bmp");
	SDL_Texture* texture4 = SDL_CreateTextureFromSurface(renderer1,
        niveau4);
	SDL_Rect dstrect4 = {50, 350, 200,200 };
	SDL_RenderCopy(renderer1, texture4, NULL, &dstrect1);
	SDL_BlitSurface(niveau4,NULL,SDL_GetWindowSurface(window1),&dstrect4);

	SDL_Surface* niveau5 = SDL_LoadBMP("souris5.bmp");
	SDL_Texture* texture5 = SDL_CreateTextureFromSurface(renderer1,
        niveau5);
	SDL_Rect dstrect5 = {300, 350, 200,200 };
	SDL_RenderCopy(renderer1, texture5, NULL, &dstrect5);
	SDL_BlitSurface(niveau5,NULL,SDL_GetWindowSurface(window1),&dstrect5);

	SDL_Surface* niveau6 = SDL_LoadBMP("souris6.bmp");
	SDL_Texture* texture6 = SDL_CreateTextureFromSurface(renderer1,
        niveau6);
	SDL_Rect dstrect6 = {550, 350, 200,200 };
	SDL_RenderCopy(renderer1, texture6, NULL, &dstrect6);
	SDL_BlitSurface(niveau6,NULL,SDL_GetWindowSurface(window1),&dstrect6);
	
	SDL_UpdateWindowSurface(window1);	

	 while (terminer==0)        
        {        
           SDL_WaitEvent(&event);        
            
           switch(event.type)        
           {        
           case SDL_QUIT:        
              terminer=1;
		
		SDL_DestroyRenderer(renderer1);
		SDL_DestroyWindow(window1);  
		
		SDL_Quit()  ;     
              break;
	   case SDL_MOUSEBUTTONDOWN:
		/*cas ou l'on clique sur niveau1 */
		if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=50 && event.button.y>50 && event.button.x<=300 && 		event.button.y<=250){
		/* on desemcombre */ 
		 SDL_DestroyRenderer(renderer1);
		SDL_DestroyWindow(window1);  
		
		/* redirection vers les niveaux */ 
		map();
		terminer=1;
		break;
		}
	}

	}
	
}



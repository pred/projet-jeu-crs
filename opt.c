#include "opt.h"

void opt(SDL_Window *window,SDL_Renderer* renderer, SDL_Surface *surface, SDL_Texture *texture, int *terminermenu){
	int termineropt=0;
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	/*creation fenetre */
	TTF_Font *police1 = NULL;

	
	createtexte("800*1200", surface, texture,renderer,  window, 250, 150,police1);
	createtexte("1200*1400", surface, texture,renderer,  window, 250, 225, police1);
	createtexte("1400*1800", surface, texture,renderer,  window, 250, 300, police1);

	SDL_UpdateWindowSurface(window);
	TTF_CloseFont(police1);  
		TTF_Quit(); 
	 free(police1);
	
	
	 while (termineropt==0)        
        {        
           SDL_WaitEvent(&event);        
            
           switch(event.type)        
           {        
           case SDL_QUIT:        
              termineropt=1;
			  *terminermenu=1;
		
               break;
	}

	}

}

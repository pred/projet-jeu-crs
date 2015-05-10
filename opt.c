#include "menu.h"

void opt(){
	int terminer=0;
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);

	/*creation fenetre */
	SDL_Window* window2 = SDL_CreateWindow("options",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,800, 600, 0);
	SDL_Renderer * renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderPresent(renderer2);
	
	 while (terminer==0)        
        {        
           SDL_WaitEvent(&event);        
            
           switch(event.type)        
           {        
           case SDL_QUIT:        
              terminer=1;
		
		SDL_DestroyRenderer(renderer2);
		SDL_DestroyWindow(window2);  
		
		SDL_Quit()  ;     
               break;
	}

	}

}

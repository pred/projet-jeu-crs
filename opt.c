#include "opt.h"
#include "constantes.h"

void opt(Contenu* C, int *terminermenu){
	int termineropt=0;
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	/*creation fenetre */
	TTF_Font *police1 = NULL;

	
	createtexte("800*1200", C, 250, 150, 50);
	createtexte("1200*1400", C, 250, 225, 50);
	createtexte("1400*1800", C, 250, 300, 50);

	SDL_UpdateWindowSurface(C->window);
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



#include "menu.h"
#include "niveau.h"
#include "cleanup.h"
#include "afficher.h"
#include "opt.h"

void menu();	

int main() {
	int terminer=0;
	
	/*initialisation sdl et ttf*/    
        SDL_Init(SDL_INIT_VIDEO);        
        TTF_Init(); 

	/*creation fenetre*/    
        SDL_Window * window = SDL_CreateWindow("Trip",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,800, 600, 0);
    if (window == NULL)
     {   SDL_ShowSimpleMessageBox(0, "Window init error", SDL_GetError(),
            window);
	}    
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
    if (renderer == NULL)
    {    SDL_ShowSimpleMessageBox(0, "Renderer init error",
            SDL_GetError(), window);
	}    
	
	SDL_RenderPresent(renderer);

	/*afficher une image (souris)*/
	SDL_Surface * surface = SDL_LoadBMP("souris2.bmp");
    if (surface == NULL)
    {    SDL_ShowSimpleMessageBox(0, "Image init error", SDL_GetError(),
            window);
	}    
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
        surface);
    if (texture == NULL)
    {    SDL_ShowSimpleMessageBox(0, "Texture init error",
            SDL_GetError(), window);
    }
	  	
		
	
    	
	
	while(terminer==0){
	
	menu(&terminer, window, renderer, surface, texture);
	}	
	
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return 0;
}


       
void menu(int* terminer,SDL_Window *window,SDL_Renderer *renderer, SDL_Surface *surface, SDL_Texture *texture){        
        int terminermenu = 0;        
	SDL_Event event;        
                 
	SDL_Rect dstrect = { 575, 400, 400,200 };
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	 SDL_BlitSurface(surface,NULL,SDL_GetWindowSurface(window),&dstrect);

	TTF_Font *police = NULL;

	
	createtexte("JOUER", surface, texture,renderer,  window, 250, 150,police);
	createtexte("OPTIONS", surface, texture,renderer,  window, 250, 225, police);
	createtexte("QUITTER", surface, texture,renderer,  window, 250, 300, police);
	SDL_UpdateWindowSurface(window);
	TTF_CloseFont(police);  
		TTF_Quit(); 
	 free(police);

        while (terminermenu==0)        
        {        
           SDL_WaitEvent(&event);        
            
           switch(event.type)        
           {        
           case SDL_QUIT:        
              *terminer=1; 
		terminermenu=1;
	 
               break;
	   case SDL_MOUSEBUTTONDOWN:
		/*cas ou l'on clique sur jouer */
		if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=250 && event.button.y>150 && event.button.x<=400 && 		event.button.y<=200){
	chargerimage(window, renderer,surface ,texture ,0,0,"noir.bmp");
	 
	niveau(window,renderer,surface,texture,&terminermenu);	
	chargerimage(window, renderer,surface ,texture ,0,0,"noir.bmp");	
		 
		
		
		/* redirection vers les niveaux */ 
		 
		break;
		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=250 && event.button.y>225 && event.button.x<=400 && event.button.y<=275){
		chargerimage(window, renderer,surface ,texture ,0,0,"noir.bmp");
		 opt();
		 
		break;
		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=250 && event.button.y>300 && event.button.x<=400 && 			event.button.y<=350){
		terminermenu=1;
		*terminer=1;
		/* on desemcombre */
		 
		/* quitter */  
		break;
		}
           }    
        }        
	 
	  
     
    }
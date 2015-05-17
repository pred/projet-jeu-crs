#include "menu.h"
#include "niveau.h"
#include "constantes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "afficher.h"
#include "opt.h"
#include "constantes.h"


SDL_Surface * noir1;

	

int main() {
	
	int terminer=0;
	
	/*initialisation sdl*/    
        SDL_Init(SDL_INIT_VIDEO);        
         

	/*creation fenetre*/    
        SDL_Window * window = SDL_CreateWindow("Trip",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,850, 612, 0);
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
	Contenu* C=creerFenetre(window, renderer, surface,  texture);  	
		
	SDL_UpdateWindowSurface(C->window);
    	
	
	while(terminer==0){
	
	menu(&terminer, C);
	}	
	
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_FreeSurface(noir1);
	free(C);
	return 0;
}


       
void menu(int* terminer,Contenu* C){  
	noir1= SDL_LoadBMP("noir.bmp");      
    int terminermenu = 0;        
	SDL_Event event;        
                 
	SDL_Rect dstrect = { 575, 400, 400,200 };
	SDL_RenderCopy(C->renderer, C->texture, NULL, &dstrect);
	 SDL_BlitSurface(C->surface,NULL,SDL_GetWindowSurface(C->window),&dstrect);
	TTF_Init();
	TTF_Font *police = NULL;

	
	createtexte("JOUER", C, 250, 150,police);
	createtexte("OPTIONS", C, 250, 225, police);
	createtexte("QUITTER", C, 250, 300, police);
	SDL_UpdateWindowSurface(C->window);
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
					if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=250 && event.button.y>150 && event.button.x<=400 && 		event.button.y<=200)
					{
					chargerimage(C,0,0,noir1);
	 
						niveau(C,&terminermenu);	
						chargerimage(C,0,0,noir1);	
		 
		
		
		/* redirection vers les niveaux */ 
		 
		break;
						}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=250 && event.button.y>225 && event.button.x<=400 && event.button.y<=275){
		chargerimage(C,0,0,noir1);
		 opt(C, &terminermenu);
		 chargerimage(C,0,0,noir1);
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
#include "menu.h"
#include "niveau.h"
#include "cleanup.h"

void menu();	

int main() {
	menu();
	return 0;
}
       
void menu(){        
        int terminer = 0;        
        SDL_Event event;        
         
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
	SDL_Surface * souris = SDL_LoadBMP("souris2.bmp");
    if (souris == NULL)
    {    SDL_ShowSimpleMessageBox(0, "Image init error", SDL_GetError(),
            window);
	}    
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
        souris);
    if (texture == NULL)
    {    SDL_ShowSimpleMessageBox(0, "Texture init error",
            SDL_GetError(), window);
    }
	SDL_Rect dstrect = { 575, 400, 400,200 };
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	 SDL_BlitSurface(souris,NULL,SDL_GetWindowSurface(window),&dstrect);
    	
		
	/* recuperer la police */
	TTF_Font *police = NULL;
	police = TTF_OpenFont("gargi.ttf", 50);
	if(!police){
		printf("erreur ttf open font");
	}
	/*choix de la couleur de l'ecriture */ 
	SDL_Color color={255,255,255};
	/*ecriture de jouer */
	SDL_Surface *jouer;
	jouer =TTF_RenderText_Solid(police,"JOUER",color);
	SDL_Texture *J=SDL_CreateTextureFromSurface(renderer,jouer);
	SDL_Rect d={250,150,500,500};
	SDL_RenderCopy(renderer,J,NULL,&d);
	SDL_BlitSurface(jouer,NULL,SDL_GetWindowSurface(window),&d);
	
	/*ecriture de options */ 
	SDL_Surface *options;
	options =TTF_RenderText_Solid(police,"OPTIONS",color);
	SDL_Texture *O=SDL_CreateTextureFromSurface(renderer,jouer);
	SDL_Rect d1={250,225,500,500};
	SDL_RenderCopy(renderer,O,NULL,&d1);
	SDL_BlitSurface(options,NULL,SDL_GetWindowSurface(window),&d1);
	
	/* ecriture de quitter */ 	
	SDL_Surface *quitter;
	quitter =TTF_RenderText_Solid(police,"QUITTER",color);
	SDL_Texture *Q=SDL_CreateTextureFromSurface(renderer,quitter);
	SDL_Rect d2={250,300,500,500};
	SDL_RenderCopy(renderer,Q,NULL,&d2);
	SDL_BlitSurface(quitter,NULL,SDL_GetWindowSurface(window),&d2);
	
	/*actualisation de l'écran pour azfficher toutes les modifications*/
	SDL_UpdateWindowSurface(window);
	   


        while (terminer==0)        
        {        
           SDL_WaitEvent(&event);        
            
           switch(event.type)        
           {        
           case SDL_QUIT:        
              terminer=1; 
		/*on desencombre */ 
		cleanup(texture,  souris,jouer, options, renderer,  window, police);  
		  
               break;
	   case SDL_MOUSEBUTTONDOWN:
		/*cas ou l'on clique sur jouer */
		if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=250 && event.button.y>150 && event.button.x<=400 && 		event.button.y<=200){
		/* on desemcombre */ 
		cleanup(texture,  souris, jouer, options, renderer,  window, police); 
		/* redirection vers les niveaux */ 
		 niveau();
		break;
		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=250 && event.button.y>225 && event.button.x<=400 && 			event.button.y<=275){
		/* on desemcombre */
		cleanup(texture,  souris, jouer, options, renderer,  window, police); 
		/* redirection vers les options */
		 opt();
		break;
		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=250 && event.button.y>300 && event.button.x<=400 && 			event.button.y<=350){
		terminer=1;
		/* on desemcombre */
		cleanup(texture,  souris, jouer, options, renderer,  window, police); 
		/* quitter */  
		break;
		}
           }    
        }        
	 
	  
     
    }

#include "afficher.h"
#include "constantes.h"
#include <stdio.h>

void createtexte(char* mot, Contenu* C, int i,int j,TTF_Font *police){

	/* recuperer la police */
	
	police = TTF_OpenFont("gargi.ttf", 50);
	if(!police){
		printf("erreur ttf open font");
	}
	/*choix de la couleur de l'ecriture */ 
	SDL_Color color={255,255,255};
	/*ecriture de jouer */
	
	C->surface =TTF_RenderText_Solid(police,mot,color);
	C->texture=SDL_CreateTextureFromSurface(C->renderer,C->surface);
	SDL_Rect d={i,j,500,500};
	SDL_RenderCopy(C->renderer,C->texture,NULL,&d);
	SDL_BlitSurface(C->surface,NULL,SDL_GetWindowSurface(C->window),&d);
	

}
void chargerimage(Contenu* C, int i, int j, char *image){
	 C->surface = SDL_LoadBMP(image);
	 C->texture = SDL_CreateTextureFromSurface(C->renderer,
        C->surface);
	SDL_Rect dstrect1 = {i, j, 200,200 };
	SDL_RenderCopy(C->renderer, C->texture, NULL, &dstrect1);
	SDL_BlitSurface(C->surface,NULL,SDL_GetWindowSurface(C->window),&dstrect1);

	SDL_UpdateWindowSurface(C->window);
}

void afficherimage(Contenu* C,SDL_Surface* surface,int l,int m){
	C->surface=surface;
	C->texture=SDL_CreateTextureFromSurface(C->renderer,C->surface);
		
	SDL_Rect Rect={l*34,m*34, 34,34};

	SDL_RenderCopy(C->renderer, C->texture, NULL, &Rect);
	SDL_BlitSurface(C->surface,NULL,SDL_GetWindowSurface(C->window),&Rect);


}



void win(int* h){
		
	int f=*h;
	char nbre[100]="";
	sprintf(nbre,"Vous avez gagne %d fromage(s)",f);	
	
	SDL_Window * window = SDL_CreateWindow("C'est Gagne!!",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,300, 200, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderPresent(renderer);
	TTF_Init();
	TTF_Font *police = NULL;
	police = TTF_OpenFont("gargi.ttf", 10);
	SDL_Color color={255,255,255};
	SDL_Surface *gagne;
	gagne =TTF_RenderText_Solid(police,nbre,color);
	SDL_Texture *V=SDL_CreateTextureFromSurface(renderer,gagne);
	SDL_Rect d={50,50,100,100};
	SDL_RenderCopy(renderer,V,NULL,&d);
	SDL_BlitSurface(gagne,NULL,SDL_GetWindowSurface(window),&d);
		
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);  
	
		
		     	
}

void gameOver()
{
	SDL_Window * window = SDL_CreateWindow("Vous avez perdu ...",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,300, 200, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderPresent(renderer);
	
	TTF_Font *police = NULL;
	police = TTF_OpenFont("gargi.ttf", 10);
	SDL_Color color={255,255,255};
	SDL_Surface *gagne;
	gagne =TTF_RenderText_Solid(police,"Vous avez perdu! Vous avez touche un piege",color);
	SDL_Texture *V=SDL_CreateTextureFromSurface(renderer,gagne);
	SDL_Rect d={50,50,100,100};
	SDL_RenderCopy(renderer,V,NULL,&d);
	SDL_BlitSurface(gagne,NULL,SDL_GetWindowSurface(window),&d);
	
	
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);  
}

Contenu* creerFenetre(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture){
	Contenu* C;
	C=(Contenu*) malloc(sizeof(Contenu));
	if(C==NULL){
		return NULL;
	}
	else {
		C->window=window;
		C->renderer=renderer;
		C->surface=surface;
		C->texture=texture;
		return C;
	}
	
}


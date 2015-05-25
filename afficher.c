#include "afficher.h"
#include "constantes.h" 
#include <stdio.h>

SDL_Surface* text;

void createtexte(char* mot, Contenu* C, int i,int j, int taille){

	/* recuperer la police */
	
	TTF_Font* police = TTF_OpenFont("gargi.ttf", taille);
	if(!police){
		printf(" afficher.c ligne 13 erreur ttf open font");
	}
	/*choix de la couleur de l'ecriture */ 
	SDL_Color color={255,255,255};
	/*ecriture de jouer */
	
	text = TTF_RenderUTF8_Blended(police, mot, color);
	SDL_Rect d={i,j,500,500};

	SDL_BlitSurface(text,NULL,SDL_GetWindowSurface(C->window), &d );
	TTF_CloseFont(police);
	SDL_FreeSurface(text);

	/*C->surface =TTF_RenderText_Solid(police,mot,color);
	C->texture=SDL_CreateTextureFromSurface(C->renderer,C->surface);
	SDL_Rect d={i,j,500,500};
	SDL_RenderCopy(C->renderer,C->texture,NULL,&d);
	SDL_BlitSurface(C->surface,NULL,SDL_GetWindowSurface(C->window),&d);*/
	
}
void chargerimage(Contenu* C, int i, int j, SDL_Surface* surface){
	C->surface=surface;
	C->texture = SDL_CreateTextureFromSurface(C->renderer,
    C->surface);
	SDL_Rect dstrect1 = {i, j, 200,200 };
	SDL_RenderCopy(C->renderer, C->texture, NULL, &dstrect1);
	SDL_BlitSurface(C->surface,NULL,SDL_GetWindowSurface(C->window),&dstrect1);

	SDL_UpdateWindowSurface(C->window);

}

void afficherimage(Contenu* C,SDL_Surface* surface,int l,int m){
	C->surface=surface;
	//C->texture=SDL_CreateTextureFromSurface(C->renderer,C->surface);
		
	SDL_Rect Rect={l*34,m*34, 34,34};

	//SDL_RenderCopy(C->renderer, C->texture, NULL, &Rect);
	SDL_BlitSurface(C->surface,NULL,SDL_GetWindowSurface(C->window),&Rect);


}
/* Adrien Wehrung donne des sous si vous ne regardez pas la suite*/


void win(int* h){
		
	int f=*h;
	char nbre[100]="";
	sprintf(nbre,"Vous avez gagne %d fromage(s)",f);	
	SDL_Window * window = SDL_CreateWindow("C'est Gagne!!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,300, 200, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderPresent(renderer);
	TTF_Init();
	Contenu* c = creerFenetre( window, renderer, NULL, NULL);

	
	

	createtexte(nbre, c, 60,80, 10);

	SDL_UpdateWindowSurface(c->window);
	SDL_Delay(2000);
	TTF_Quit(); 
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	freeFenetre(c); 
	
		
		     	
}

void gameOver()
{	
	SDL_Window * window = SDL_CreateWindow("Vous avez perdu ...",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,300, 200, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderPresent(renderer);

	TTF_Init();
	Contenu* c = creerFenetre( window, renderer, NULL, NULL);

	createtexte("Vous avez perdu", c, 70,80, 10);
	
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	TTF_Quit(); 
	freeFenetre(c);

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
void freeFenetre(Contenu* c) {

	SDL_DestroyTexture(c->texture);
	SDL_FreeSurface(c->surface);
	SDL_DestroyRenderer(c->renderer);
	SDL_DestroyWindow(c->window);

	free(c);
}



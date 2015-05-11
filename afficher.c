#include "afficher.h"

void createtexte(char* mot, SDL_Surface* surface, SDL_Texture* texture,SDL_Renderer* renderer, SDL_Window* window, int i,int j,TTF_Font *police){

	/* recuperer la police */
	
	police = TTF_OpenFont("gargi.ttf", 50);
	if(!police){
		printf("erreur ttf open font");
	}
	/*choix de la couleur de l'ecriture */ 
	SDL_Color color={255,255,255};
	/*ecriture de jouer */
	
	surface =TTF_RenderText_Solid(police,mot,color);
	texture=SDL_CreateTextureFromSurface(renderer,surface);
	SDL_Rect d={i,j,500,500};
	SDL_RenderCopy(renderer,texture,NULL,&d);
	SDL_BlitSurface(surface,NULL,SDL_GetWindowSurface(window),&d);
	

}
void chargerimage(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface *surface,SDL_Texture *texture, int i, int j, char *image){
	 surface = SDL_LoadBMP(image);
	 texture = SDL_CreateTextureFromSurface(renderer,
        surface);
	SDL_Rect dstrect1 = {i, j, 200,200 };
	SDL_RenderCopy(renderer, texture, NULL, &dstrect1);
	SDL_BlitSurface(surface,NULL,SDL_GetWindowSurface(window),&dstrect1);

	SDL_UpdateWindowSurface(window);
}

void afficherimage(SDL_Window* ecran, SDL_Renderer* renderer, SDL_Surface *surface, SDL_Texture* texture,int l,int m){

	texture=SDL_CreateTextureFromSurface(renderer,surface);
		
	SDL_Rect Rect={l*34,m*34, 34,34};

	SDL_RenderCopy(renderer, texture, NULL, &Rect);
	SDL_BlitSurface(surface,NULL,SDL_GetWindowSurface(ecran),&Rect);


}

char attrapefromage(int i, int j, char c){

	if (i==j){
		int k= (int) c;
		k++;
		char l= (char) k;
		return k;
	}
return c;
}

void win(char* h){
	SDL_Window * window = SDL_CreateWindow("C'est Gagné!!",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,200, 200, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderPresent(renderer);
	
	TTF_Font *police = NULL;
	police = TTF_OpenFont("gargi.ttf", 10);
	SDL_Color color={255,255,255};
	SDL_Surface *gagne;
	gagne =TTF_RenderText_Solid(police,"Vous avez gagne!",color);
	SDL_Texture *V=SDL_CreateTextureFromSurface(renderer,gagne);
	SDL_Rect d={50,50,100,100};
	SDL_RenderCopy(renderer,V,NULL,&d);
	SDL_BlitSurface(gagne,NULL,SDL_GetWindowSurface(window),&d);
	
	SDL_Surface *n;
	n=TTF_RenderText_Solid(police,h,color);
	SDL_Texture *W=SDL_CreateTextureFromSurface(renderer,n);
	SDL_Rect dd={50,70,100,100};
	SDL_RenderCopy(renderer,W,NULL,&dd);
	SDL_BlitSurface(n,NULL,SDL_GetWindowSurface(window),&dd);
	SDL_UpdateWindowSurface(window);

	SDL_Surface *o;
	o=TTF_RenderText_Solid(police,"fromage(s)",color);
	SDL_Texture *Y=SDL_CreateTextureFromSurface(renderer,o);
	SDL_Rect ddd={70,70,100,100};
	SDL_RenderCopy(renderer,Y,NULL,&ddd);
	SDL_BlitSurface(o,NULL,SDL_GetWindowSurface(window),&ddd);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);  
		
		     	
}

void gameOver()
{
	SDL_Window * window = SDL_CreateWindow("C'est Gagné!!",
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

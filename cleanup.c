#include "cleanup.h"

#include "menu.h"

void cleanup(SDL_Texture* texture, SDL_Surface* souris, SDL_Surface* jouer, SDL_Surface* options, SDL_Renderer* renderer, SDL_Window* window, TTF_Font* police){
		SDL_DestroyTexture(texture);
		
		SDL_FreeSurface(souris);
		
		SDL_FreeSurface(jouer);
		SDL_FreeSurface(options);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);  
		TTF_CloseFont(police);  
		TTF_Quit(); 
		SDL_Quit();

}


#include "niveau.h"
#include "menu.h"
#include "jeu.h"
#include "afficher.h"
#include "constantes.h"
#include "souris.h"


SDL_Surface* noir;
SDL_Surface* niveau1;
SDL_Surface* fromage1;
SDL_Surface* fromage2;
SDL_Surface* fromage3;
SDL_Surface* niveau2;
SDL_Surface* niveau3;
SDL_Surface* niveau4;
SDL_Surface* niveau5;
SDL_Surface* niveau6;
Souris* souris;

void chargerImageNiveau(){
	noir=SDL_LoadBMP("Image/noir.bmp");
	niveau1=SDL_LoadBMP("Image/souris.bmp");
	fromage1=SDL_LoadBMP("Image/fromage1.bmp");
	fromage2=SDL_LoadBMP("Image/fromage2.bmp");
	fromage3=SDL_LoadBMP("Image/fromage3.bmp");
	niveau2=SDL_LoadBMP("Image/souris2b.bmp");
	niveau3=SDL_LoadBMP("Image/souris3.bmp");
	niveau4=SDL_LoadBMP("Image/souris4.bmp");
	niveau5=SDL_LoadBMP("Image/souris5.bmp");
	niveau6=SDL_LoadBMP("Image/souris6.bmp");

}
void freeImageNiveau(){
	SDL_FreeSurface(noir);
	SDL_FreeSurface(niveau1);
	SDL_FreeSurface(niveau2);
	SDL_FreeSurface(niveau3);
	SDL_FreeSurface(niveau4);
	SDL_FreeSurface(niveau5);
	SDL_FreeSurface(niveau6);
	SDL_FreeSurface(fromage1);
	SDL_FreeSurface(fromage2);
	SDL_FreeSurface(fromage3);
}
void afficheNiveau(Contenu* C,int fromage[6])
{	
	chargerimage(C,0,0,noir);
	
	chargerimage(C,50,50, niveau1);
	switch(fromage[0]){
		case 0:
			break;
		case 1:
			chargerimage(C,100,250,fromage1);
			break;
		case 2:
			chargerimage(C,100,250,fromage2);
			break;
		case 3:
			chargerimage(C,100,250,fromage3);
			break;
	};
	chargerimage(C,300,50, niveau2);
	switch(fromage[1]){
		case 0:
			break;
		case 1:
			chargerimage(C,350,250,fromage1);
			break;
		case 2:
			chargerimage(C,350,250,fromage2);
			break;
		case 3:
			chargerimage(C,350,250,fromage3);
			break;
	};	
	chargerimage(C,550,50, niveau3);
	switch(fromage[2]){
		case 0:
			break;
		case 1:
			chargerimage(C,600,250,fromage1);
			break;
		case 2:
			chargerimage(C,600,250,fromage2);
			break;
		case 3:
			chargerimage(C,600,250,fromage3);
			break;
	};
	chargerimage(C,50,350, niveau4);
	switch(fromage[3]){
		case 0:
			break;
		case 1:
			chargerimage(C,100,550,fromage3);
			break;
		case 2:
			chargerimage(C,100,550,fromage2);
			break;
		case 3:
			chargerimage(C,100,550,fromage3);
			break;
	};
	chargerimage(C,300,350, niveau5);
	switch(fromage[4]){
		case 0:
			break;
		case 1:
			chargerimage(C,350,550,fromage1);
			break;
		case 2:
			chargerimage(C,350,550,fromage2);
			break;
		case 3:
			chargerimage(C,350,550,fromage3);
			break;
	};
	chargerimage(C,550,350, niveau6);
	switch(fromage[5]){
		case 0:
			break;
		case 1:
			chargerimage(C,500,550,fromage1);
			break;
		case 2:
			chargerimage(C,500,550,fromage2);
			break;
		case 3:
			chargerimage(C,500,550,fromage3);
			break;
	};
	SDL_UpdateWindowSurface(C->window);

}
void niveau(Contenu* C, int *terminermenu){
	int terminerniveau=0;
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);
	int fromage[6]={0,0,0,0,0,0};
	chargerImageNiveau();
	afficheNiveau(C,fromage);

	 while (terminerniveau==0)        
        {        
           SDL_WaitEvent(&event);        
            
           switch(event.type)        
           {        
           case SDL_QUIT:        
              terminerniveau=1;
              *terminermenu=1;
		
		     
              break;
	   case SDL_MOUSEBUTTONDOWN:
		/*cas ou l'on clique sur niveau1 */
	    if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=50 && event.button.y>50 && event.button.x<=250 && event.button.y<=300){
			
			chargerimage(C,0,0,noir);
			SDL_UpdateWindowSurface(C->window);
			SDL_Rect rect={14,1,34,34};
			
			/* redirection vers les niveaux */ 
			souris=creerSouris(&rect,DROITE,HAUT);
			int f0=map(C,"niveau1.lvl",souris);

			if(f0>fromage[0]){
				fromage[0]=f0;
			}

			afficheNiveau(C,fromage);
		}
		else if (event.button.button ==SDL_BUTTON_LEFT && event.button.x>=300 && event.button.y>50 && event.button.x<=500 && event.button.y<=300){
			chargerimage(C,0,0,noir);
			SDL_UpdateWindowSurface(C->window);
			SDL_Rect rect={17,2,34,34};
			
			/* redirection vers les niveaux */ 
			souris=creerSouris(&rect,DROITE,HAUT);
			
			int f1=map(C,"niveau2.lvl",souris);

			if(f1>fromage[1]){
				fromage[1]=f1;
			}
			fprintf(stderr, "affiche");
			afficheNiveau(C,fromage);

		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=550 && event.button.y>50 && event.button.x<=750 && event.button.y<=300){
			chargerimage(C,0,0,noir);
			SDL_UpdateWindowSurface(C->window);
			SDL_Rect rect={19,11,34,34};
			
			/* redirection vers les niveaux */ 
			souris=creerSouris(&rect,DROITE,HAUT);
			int f2=map(C,"niveau3.lvl",souris);

			if(f2>fromage[2]){
				fromage[2]=f2;
			}
			afficheNiveau(C,fromage);

		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=50 && event.button.y>350 && event.button.x<=250 && event.button.y<=750){
			chargerimage(C,0,0,noir);
			SDL_UpdateWindowSurface(C->window);
			SDL_Rect rect={19,11,34,34};
			
			/* redirection vers les niveaux */ 
			souris=creerSouris(&rect,DROITE,HAUT);
			int f3=map(C,"niveau4.lvl",souris);

			if(f3>fromage[3]){
				fromage[3]=f3;
			}
			afficheNiveau(C,fromage);

		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=300 && event.button.y>350 && event.button.x<=500 && event.button.y<=750){
			chargerimage(C,0,0,noir);
			SDL_UpdateWindowSurface(C->window);
			SDL_Rect rect={12,9,34,34};
			
			/* redirection vers les niveaux */ 
			souris=creerSouris(&rect,DROITE,HAUT);
			int f4=map(C,"niveau5.lvl",souris);
			
			if(f4>fromage[4]){
				fromage[4]=f4;
			}
			afficheNiveau(C,fromage);

		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=550 && event.button.y>350 && event.button.x<=750 && event.button.y<=750){
			chargerimage(C,0,0,noir);
			SDL_UpdateWindowSurface(C->window);
			SDL_Rect rect={17,9,34,34};
			
			/* redirection vers les niveaux */ 
			souris=creerSouris(&rect,DROITE,HAUT);
			int f5=map(C,"niveau6.lvl",souris);

			if(f5>fromage[5]){
				fromage[5]=f5;
			}
			afficheNiveau(C,fromage);

		}
		break;
		
	}

	}
	freeImageNiveau();
	
}


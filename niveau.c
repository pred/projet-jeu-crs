#include "niveau.h"
#include "menu.h"
#include "jeu.h"
#include "afficher.h"
#include "constantes.h"

void afficheNiveau(Contenu* C,int fromage[6])
{	
	chargerimage(C,0,0,"noir.bmp");
	
	chargerimage(C,50,50, "souris.bmp");
	switch(fromage[0]){
		case 0:
			break;
		case 1:
			chargerimage(C,100,250,"fromage1.bmp");
			break;
		case 2:
			chargerimage(C,100,250,"fromage2.bmp");
			break;
		case 3:
			chargerimage(C,100,250,"fromage3.bmp");
			break;
	};
	chargerimage(C,300,50, "souris2b.bmp");
	switch(fromage[1]){
		case 0:
			break;
		case 1:
			chargerimage(C,350,250,"fromage1.bmp");
			break;
		case 2:
			chargerimage(C,350,250,"fromage2.bmp");
			break;
		case 3:
			chargerimage(C,350,250,"fromage3.bmp");
			break;
	};	
	chargerimage(C,550,50, "souris3.bmp");
	switch(fromage[2]){
		case 0:
			break;
		case 1:
			chargerimage(C,600,250,"fromage1.bmp");
			break;
		case 2:
			chargerimage(C,600,250,"fromage2.bmp");
			break;
		case 3:
			chargerimage(C,600,250,"fromage3.bmp");
			break;
	};
	chargerimage(C,50,350, "souris4.bmp");
	switch(fromage[3]){
		case 0:
			break;
		case 1:
			chargerimage(C,100,550,"fromage1.bmp");
			break;
		case 2:
			chargerimage(C,100,550,"fromage2.bmp");
			break;
		case 3:
			chargerimage(C,100,550,"fromage3.bmp");
			break;
	};
	chargerimage(C,300,350, "souris5.bmp");
	switch(fromage[4]){
		case 0:
			break;
		case 1:
			chargerimage(C,350,550,"fromage1.bmp");
			break;
		case 2:
			chargerimage(C,350,550,"fromage2.bmp");
			break;
		case 3:
			chargerimage(C,350,550,"fromage3.bmp");
			break;
	};
	chargerimage(C,550,350, "souris6.bmp");
	switch(fromage[5]){
		case 0:
			break;
		case 1:
			chargerimage(C,500,550,"fromage1.bmp");
			break;
		case 2:
			chargerimage(C,500,550,"fromage2.bmp");
			break;
		case 3:
			chargerimage(C,500,550,"fromage3.bmp");
			break;
	};
	SDL_UpdateWindowSurface(C->window);

}
void niveau(Contenu* C, int *terminermenu){
	int terminerniveau=0;
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);
	int fromage[6]={0,0,0,0,0,0};
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
			
			chargerimage(C,0,0,"noir.bmp");
			SDL_UpdateWindowSurface(C->window);
			/* redirection vers les niveaux */ 
			int f0=map(C,"niveau1.lvl");
			if(f0>fromage[0]){
				fromage[0]=f0;
			}
			afficheNiveau(C,fromage);
		}
		else if (event.button.button ==SDL_BUTTON_LEFT && event.button.x>=300 && event.button.y>50 && event.button.x<=500 && event.button.y<=300){
			chargerimage(C,0,0,"noir.bmp");
			SDL_UpdateWindowSurface(C->window);
			/* redirection vers les niveaux */ 
			int f1=map(C,"niveau2.lvl");
			if(f1>fromage[1]){
				fromage[1]=f1;
			}
			afficheNiveau(C,fromage);
		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=550 && event.button.y>50 && event.button.x<=750 && event.button.y<=300){
			chargerimage(C,0,0,"noir.bmp");
			SDL_UpdateWindowSurface(C->window);
			/* redirection vers les niveaux */ 
			int f2=map(C,"niveau3.lvl");
			if(f2>fromage[2]){
				fromage[2]=f2;
			}
			afficheNiveau(C,fromage);
		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=50 && event.button.y>350 && event.button.x<=250 && event.button.y<=750){
			chargerimage(C,0,0,"noir.bmp");
			SDL_UpdateWindowSurface(C->window);
			/* redirection vers les niveaux */ 
			int f3=map(C,"niveau4.lvl");
			if(f3>fromage[3]){
				fromage[3]=f3;
			}
			afficheNiveau(C,fromage);
		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=300 && event.button.y>350 && event.button.x<=500 && event.button.y<=750){
			chargerimage(C,0,0,"noir.bmp");
			SDL_UpdateWindowSurface(C->window);
			/* redirection vers les niveaux */ 
			int f4=map(C,"niveau5.lvl");
			if(f4>fromage[4]){
				fromage[4]=f4;
			}
			afficheNiveau(C,fromage);
		}
		else if(event.button.button ==SDL_BUTTON_LEFT && event.button.x>=550 && event.button.y>350 && event.button.x<=750 && event.button.y<=750){
			chargerimage(C,0,0,"noir.bmp");
			SDL_UpdateWindowSurface(C->window);
			/* redirection vers les niveaux */ 
			int f5=map(C,"niveau6.lvl");
			if(f5>fromage[5]){
				fromage[5]=f5;
			}
			afficheNiveau(C,fromage);
		}
		break;
		
	}

	}
	
}


#include "opt.h"
#include "constantes.h"

void opt(Contenu* C, int *terminermenu){
	int termineropt=0;
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	/*creation fenetre */
	TTF_Font *police1 = NULL;

	
		createtexte("Bonjour, bienvenue dans Trip Trap!", C, 30, 50, 20);
	createtexte("Ici nous allons vous expliquer comment  jouer.", C, 30, 80, 12);
	createtexte("Principe et but du jeu :", C, 30, 110, 20);
	createtexte("Le principe du jeu est tres simple : il faut aider la souris a trouver le chemin afin de ramasser le plus de fromages possibles,", C, 30, 140, 12);
	createtexte("puis d’atteindre la porte. Les fromages sont dissemines un peu partout sur les murets, mais attention a ne pas se faire manger", C, 30, 155, 12);
	 createtexte("par le chat ou bien a ne pas tomber dans un piege!", C, 30, 170, 12);
createtexte("Le but est de ramasser tous les fromages jusqu’au dernier niveau.", C, 30, 185, 12);
createtexte("Diriger la souris :", C, 30, 215, 20);
createtexte("La souris est toujours en mouvement, c’est-a-dire que si vous ne faites rien, elle continuera d’avancer jusqu’a ce qu’elle", C, 30, 245, 12);
createtexte("rencontre un obstacle (la porte, un chat ou un piege).", C, 30, 260, 12);
createtexte("Pour guider la souris, il vous suffit d’utiliser les touches haut (fleche du haut) et bas (fleche du bas) de votre clavier pour la faire", C, 30, 275, 12);
createtexte("descendre ou monter sur un autre muret. En revanche, aucune commande n’est effectuable lorsque votre souris se trouve sur le", C, 30, 290, 12);
createtexte("cote d’un muret.", C, 30, 305, 12);
createtexte("Obstacles :", C, 30, 335, 20);
createtexte("Au fur et a mesure des niveaux, vous allez rencontrer differents obstacles :", C, 30, 365, 12);
createtexte("-les pieges : si vous tentez de faire marcher votre souris dessus, vous perdez et votre partie recommence au debut du niveau tous", C, 30, 380, 12);
createtexte("les fromages recoltes durant la partie sont perdus).", C, 30, 395, 12);
createtexte("-le chat : si vous entrez en collision avec un chat, vous recommencez aussi le niveau depuis le debut.", C, 30, 415, 12);
createtexte("-les fromages : lorsque votre souris arrive vers un fromage, elle le recolte et garde avec elle jusqu’a la porte. Le nombre de fromages", C, 30, 435, 12);
createtexte("gagnes par niveau est ensuite inscrit sous le logo du niveau dans le menu des niveaux.", C, 30, 450, 12);
createtexte("-les fleches de redirection vertes : durant votre partie vous allez rencontrer deux sortes de fleches : les fleches droites et les", C, 30, 470, 12);
createtexte("fleches gauches. Des que votre souris entre en contact avec l’une d’elle, elle prend immediatement le sens indique par la fleche.", C, 30, 485, 12);
createtexte("-la porte : des que votre souris est parvenue a atteindre celle-ci, le niveau est termine et une fenetre vous indique le nombre de", C, 30, 505, 12);
createtexte(" fromages gagnes dans ce niveau.", C, 30, 520, 12);
createtexte("Et maintenant, a vous de jouer !", C, 30, 550, 12);


	

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



#include <SDL2/SDL.h>
#include "souris.h"
#include "constantes.h"

Souris* creerSouris(SDL_Rect* coordonneeActuelle,int direction, int position){
	Souris* souris =malloc(sizeof(Souris));
	if(souris==NULL){
		free(souris);
	}
	else {
		souris->coordonneeActuelle=coordonneeActuelle;		
		souris->direction=direction;
		souris->position=position;
	}
	return souris;

}

void freeSouris(Souris* souris){
	free(souris);
}

SDL_Rect* prochaineCoordonnees(Souris* souris,int** carte){

    SDL_Rect* prochaineCoordonnees;
    prochaineCoordonnees=(SDL_Rect*) malloc(sizeof(SDL_Rect));
    if(prochaineCoordonnees==NULL){
        free(prochaineCoordonnees);
        return NULL;
    }
    else {
        int t = doitTourner(souris,carte);
        int d = souris->direction;
        int p = souris->position;

        if(p%2 == d%2){
            return NULL;
        }

        if(estFaceMur(souris,carte)){
            return souris->coordonneeActuelle;
        }

        prochaineCoordonnees->x = (t+d%2)*((1-t)*(2-d)+t*((1-d%2)*((p%3-1)*(p%3-2)-(p%3))+(d%2)*(2-d)));
        if (prochaineCoordonnees->x!=0){
            prochaineCoordonnees->x /= fabs(prochaineCoordonnees->x);
        } 
        prochaineCoordonnees->x +=souris->coordonneeActuelle->x;
        prochaineCoordonnees->y = (t+1-(d%2))*((1-t)*(d-1)+t*((1-d%2)*(d-1)+(d%2)*((p%3-1)*(p%3-2)-(p%3))));
        if (prochaineCoordonnees->y!=0){
            prochaineCoordonnees->y /= fabs(prochaineCoordonnees->y);
        }
        prochaineCoordonnees->y +=souris->coordonneeActuelle->y;
        return prochaineCoordonnees;
    }

    

}



int doitTourner(Souris* souris,int** carte){
    int d = souris->direction;
    switch(d){
        case HAUT:return(carte[souris->coordonneeActuelle->y-1][souris->coordonneeActuelle->x+1]==CIEL && carte[souris->coordonneeActuelle->y-1][souris->coordonneeActuelle->x-1]==CIEL);
        break;
        case DROITE:return(carte[souris->coordonneeActuelle->y+1][souris->coordonneeActuelle->x+1]==CIEL && carte[souris->coordonneeActuelle->y-1][souris->coordonneeActuelle->x+1]==CIEL);
        break;
        case BAS:return(carte[souris->coordonneeActuelle->y+1][souris->coordonneeActuelle->x+1]==CIEL && carte[souris->coordonneeActuelle->y+1][souris->coordonneeActuelle->x-1]==CIEL);
        break;
        case GAUCHE:return(carte[souris->coordonneeActuelle->y+1][souris->coordonneeActuelle->x-1]==CIEL && carte[souris->coordonneeActuelle->y-1][souris->coordonneeActuelle->x-1]==CIEL);
        break;
    }
    return 0;

}

int estFaceMur(Souris* souris,int** carte){
    int d = souris->direction;
    return(carte[souris->coordonneeActuelle->y+((1-(souris->direction)%2)*(d-1))][souris->coordonneeActuelle->x+(((souris->direction)%2)*(2-(souris->direction)))]==MUR);
}

int prochaineDirection(Souris* souris,int** carte){
    if(estFaceMur(souris,carte))
        return (souris->position);

    if(doitTourner(souris,carte) == 0)
        return (souris->direction);

    if((souris->direction)%2 == 1 && (prochaineCoordonnees(souris,carte)->y < souris->coordonneeActuelle->y))
        return HAUT;
    else if((souris->direction)%2==1 && (prochaineCoordonnees(souris,carte)->y > souris->coordonneeActuelle->y))
        return BAS;
    else if((souris->direction)%2 == 0 && (prochaineCoordonnees(souris,carte)->x < souris->coordonneeActuelle->x))
        return GAUCHE;
    else
        return DROITE;
}

int prochainePosition(Souris* souris,int** carte){
    if(doitTourner(souris,carte) == 0)
        return (souris->position);
    if(estFaceMur(souris,carte))
        return ((souris->direction)+2)%4;
    return (souris->direction);
}
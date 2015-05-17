#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constantes.h"
#include "fichiers.h"

int chargerNiveau(int** niveau,char* c)
{
    FILE* fichier = NULL;
    char ligneFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};
    int i = 0, j = 0;

    fichier = fopen(c, "r");
    if (fichier == NULL)
        return 0;

    fgets(ligneFichier, NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1, fichier);

    for (i = 0 ; i < NB_BLOCS_HAUTEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_LARGEUR ; j++)
        {
            switch (ligneFichier[(i * NB_BLOCS_LARGEUR) + j])
            {
                case '0':
                    niveau[i][j] = 0;
                    break;
                case '1':
                    niveau[i][j] = 1;
                    break;
                case '2':
                    niveau[i][j] = 2;
                    break;
                case '3':
                    niveau[i][j] = 3;
                    break;
                case '4':
                    niveau[i][j] = 4;
                    break;
		        case '5':
                    niveau[i][j] = 5;
                    break;
                case '6':
                    niveau[i][j]=6;
                    break;
                case '7':
                    niveau[i][j]=7;
                    break;
                case '8':
                    niveau[i][j]=8;
                    break;   
            }
        }
    }

    fclose(fichier);
    return 1;
}


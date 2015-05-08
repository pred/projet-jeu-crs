all: menu

cleanup.o: cleanup.c menu.h 
	gcc -std=c99 -o cleanup.o -c cleanup.c -W -Wall -ansi -pedantic -lSDL2 -lSDL2_ttf -lSDL2_image

menu: menu.o niveau.o opt.o cleanup.o 
	gcc -std=c99 -o menu menu.o niveau.o opt.o cleanup.o -lSDL2 -lSDL2_ttf -lSDL2_image

menu.o: menu.c menu.h
	gcc -std=c99 -o menu.o -c menu.c -W -Wall -ansi -pedantic -lSDL2 -lSDL2_ttf -lSDL2_image

niveau.o: niveau.c menu.h niveau11.o
	gcc -std=c99 -o niveau.o niveau11.o -c niveau.c niveau11.o cleanup.o   -W -Wall -ansi -pedantic -lSDL2 -lSDL2_ttf -lSDL2_image

opt.o: opt.c menu.h
	gcc -std=c99 -o opt.o -c opt.c -W -Wall -ansi -pedantic -lSDL2 -lSDL2_ttf -lSDL2_image

niveau11.o: niveau11.c menu.h jeu.o
	gcc -std=c99 -o niveau11.o jeu.o -c niveau11.c jeu.o -W -Wall -ansi -pedantic -lSDL2 -lSDL2_ttf -lSDL2_image

jeu.o: jeu.c jeu.h constantes.h fichiers.o afficher.o
	gcc -std=c99 -o jeu.o fichiers.o afficher.o -c jeu.c fichiers.o afficher.o -W -Wall -ansi -pedantic -lSDL2 -lSDL2_ttf -lSDL2_image

fichiers.o: fichiers.c fichiers.h constantes.h
	gcc -std=c99 -o fichiers.o -c fichiers.c -W -Wall -ansi -pedantic -lSDL2 -lSDL2_ttf -lSDL2_image	

afficher.o: afficher.c menu.h
	gcc -std=c99 -o afficher.o -c afficher.c -W -Wall -ansi -pedantic -lSDL2 -lSDL2_ttf -lSDL2_image

clean:
	rm -rf *.o menu



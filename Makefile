CC_FLAGS=-std=gnu99 -Wall -pedantic
LD_FLAGS=-lSDL2 -lSDL2_ttf -g -lSDL2_image

all: menu clean

menu: menu.o niveau.o opt.o afficher.o jeu.o fichiers.o
	gcc -o menu menu.o niveau.o opt.o afficher.o jeu.o fichiers.o ${LD_FLAGS}

menu.o: menu.c 
	gcc ${CC_FLAGS} -c menu.c

niveau.o: niveau.c 
	gcc ${CC_FLAGS} -c niveau.c

opt.o: opt.c
	gcc ${CC_FLAGS} -c opt.c

jeu.o: jeu.c 
	gcc ${CC_FLAGS} -c jeu.c

fichiers.o: fichiers.c
	gcc ${CC_FLAGS} -c fichiers.c	

afficher.o: afficher.c
	gcc ${CC_FLAGS} -c afficher.c

clean:
	rm -rf *.o



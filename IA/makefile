CC = gcc
CCOPTS = -Wall

all: executable.othello.exe

main.o: main.c
	$(CC) $(CCOPTS) -c main.c

coup.o: coup.c
	$(CC) $(CCOPTS) -c coup.c

affichage.o: affichage.c
	$(CC) $(CCOPTS) -c affichage.c

executable.othello.exe: main.o affichage.o coup.o
	$(CC) $(CCOPTS) -o executable main.o affichage.o coup.o

clean:
	rm *.o executable.othello.exe
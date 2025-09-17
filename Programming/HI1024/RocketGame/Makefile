# -*- MakeFile -*-
SRCDIR = ./src
INCDIR = ./include
CC = gcc
INCLUDE = -I/usr/include/SDL2 -I$(INCDIR)
CFLAGS = -g $(INCLUDE) -c
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

rocket: main.c rocket.c text.c
	$(CC) -o rocket main.o rocket.o text.o $(LDFLAGS)

main.c: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) $(SRCDIR)/main.c

rocket.c: $(SRCDIR)/rocket.c $(INCDIR)/rocket.h
	$(CC) $(CFLAGS) $(SRCDIR)/rocket.c

text.c: $(SRCDIR)/text.c $(INCDIR)/text.h
	$(CC) $(CFLAGS) $(SRCDIR)/text.c

clean:
	rm *.o rocket

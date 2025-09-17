# -*- Makefile -*-
SRCDIR = ./src
INCDIR = ./include
CC = gcc
INCLUDE = -I/usr/include/SDL2 -I$(INCDIR)
CFLAGS = -g $(INCLUDE) -c
LDFLAGS = -lSDL2 -lSDL2_image -lm

start: main.c car.c
	$(CC) -o start main.o car.o $(LDFLAGS)

main.c: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) $(SRCDIR)/main.c

car.c: $(SRCDIR)/car.c $(INCDIR)/car.h
	$(CC) $(CFLAGS) $(SRCDIR)/car.c

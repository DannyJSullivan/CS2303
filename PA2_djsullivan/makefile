# Danny Sullivan PA2_djsullivan
# makefile for PA2

# This makefile is used to regenerate files for the life program
# 	make life.o 			-- regenerates life.o by compiling
#	make board.o			-- regenerates board.o by compiling
#	make life   			-- regenerates the executable life file by compiling
#	make 					-- same as make life

CFLAGS = -g

life: board.o life.o
	gcc $(CFLAGS) -Wall life.o board.o -o life

board.o: board.c
	gcc $(CFLAGS) -Wall -c board.c

life.o: life.h life.c
	gcc $(CFLAGS) -Wall -c life.c

clean:
	rm -f life.o board.o life

all: life
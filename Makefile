# Makefile for TCP/IP Stack Proj
# 
# Includes build rules for glue thread class, graph class
#
# Last updated: 8/31/2023


# compiler
CC = gcc 

## compile flags
CFLAGS = -g


############### Rules ###############

all:
	make

gluethread/glthread.o: gluethread/glthread.c
	${CC} ${CFLAGS} -c -I gluethread gluethread/glthread.c -o gluethread/glthread.o

graph.o: graph.c
	${CC} ${CFLAGS} -c -I . graph.c -o graph.o


clean:
	rm -f *.o
	rm -f gluethread/glthread.o
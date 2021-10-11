SHELL = /bin/bash
CC = gcc
#skylake為CPU的型號
CFLAGS = -g -O3 -lm -pthread -march=skylake
SRC = $(wildcard *.c)
EXE = $(patsubst %.c, %, $(SRC))

all: ${EXE}

%:	%.c
	${CC} ${CFLAGS} $@.c -o $@ -lm

clean:
	rm ${EXE}


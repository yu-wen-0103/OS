SHELL = /bin/bash
CC = gcc
CFLAGS = -g -pthread -O3 -march=skylake	
SRC = $(wildcard *.c)
EXE = $(patsubst %.c, %, $(SRC))

all: ${EXE}

%:	%.c
	${CC} ${CFLAGS} $@.c -o $@

exp1:perf_bench-1.c perf_bench-2.c
	${CC} ${CFLAGS} perf_bench-1.c -o perf_bench-1
	${CC} ${CFLAGS} perf_bench-2.c -o perf_bench-2
	${CC} ${CFLAGS} infini-loop-1.c -o infini-loop-1
	${CC} ${CFLAGS} infini-loop-2.c -o infini-loop-2
	#rm text.txt
	#touch text.txt
	./perf_bench-1 infini-loop-1
	#rm text.txt
	#touch text.txt
	./perf_bench-2 infini-loop-1

exp2:perf_bench-1.c perf_bench-2.c
	${CC} ${CFLAGS} perf_bench-1.c -o perf_bench-1
	${CC} ${CFLAGS} perf_bench-2.c -o perf_bench-2
	${CC} ${CFLAGS} infini-loop-1.c -o infini-loop-1
	${CC} ${CFLAGS} infini-loop-2.c -o intini-loop-2
	./perf_bench-2 infini-loop-2
	./perf_bench-1 infini-loop-2

clean:
	rm ${EXE}


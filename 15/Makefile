CC=gcc
CFLAGS=-g -Wall -Wextra -Wpedantic -std=c89

all: justify qsort

justify: justify.o line.o word.o
	@$(CC) -o justify justify.o line.o word.o

justify.o: justify.c line.h word.h
	@$(CC) -c justify.c

line.o: line.c line.h
	@$(CC) -c line.c

word.o: word.c word.h
	@$(CC) -c word.c

qsort: qsort.o quicksort.o
	@$(CC) -o qsort qsort.o quicksort.o

qsort.o: qsort.c quicksort.h
	@$(CC) -c qsort.c

quicksort.o: quicksort.c quicksort.h
	@$(CC) -c quicksort.c

clean:
	@rm -f justify qsort *.o

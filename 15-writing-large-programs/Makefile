CC=gcc
CFLAGS=-g -Wall -Wextra -Wpedantic -std=c89

all: calc justify qsort remind

calc: calc.o stack.o
	@$(CC) -o calc calc.o stack.o

calc.o: calc.c stack.h
	@$(CC) -c calc.c

stack.o: stack.c stack.h
	@$(CC) -c stack.c

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

remind: remind.o readline.o
	@$(CC) -o remind remind.o readline.o

remind.o: remind.c readline.h
	@$(CC) -c remind.c

readline.o: readline.c readline.h
	@$(CC) -c readline.c

clean:
	@rm -f calc justify qsort remind *.o

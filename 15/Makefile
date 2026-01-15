CC=gcc
CFLAGS=-g -Wall -Wextra -Wpedantic -std=c89

justify: justify.o line.o word.o
	@$(CC) -o justify justify.o line.o word.o

justify.o: justify.c line.h word.h
	@$(CC) -c justify.c

line.o: line.c line.h
	@$(CC) -c line.c

word.o: word.c word.h
	@$(CC) -c word.c

clean:
	@rm -f justify *.o

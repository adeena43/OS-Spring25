CC = g++
CFLAGS = -Wall -std=c++11

all: main

main: LetterCount.o WordCount.o LineCount.o main.o
	$(CC) $(CFLAGS) LetterCount.o WordCount.o LineCount.o main.o -o main

LetterCount.o: LetterCount.cpp LetterCount.h
	$(CC) $(CFLAGS) -c LetterCount.cpp

WordCount.o: WordCount.cpp WordCount.h
	$(CC) $(CFLAGS) -c WordCount.cpp

LineCount.o: LineCount.cpp LineCount.h
	$(CC) $(CFLAGS) -c LineCount.cpp

main.o: main.cpp LetterCount.h WordCount.h LineCount.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o main

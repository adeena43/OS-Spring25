CC = gcc
CFLAGS = -Wall -std=c11

all: temperature_converter

temperature_converter: main.o convert.o
	$(CC) $(CFLAGS) main.o convert.o -o temperature_converter

main.o: main.c temperature.h
	$(CC) $(CFLAGS) -c main.c

convert.o: convert.c temperature.h
	$(CC) $(CFLAGS) -c convert.c

clean:
	rm -f *.o temperature_converter

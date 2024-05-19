CC=gcc
CFLAGS=--std=gnu17 -Warray-bounds -g
LDFLAGS=-lm
OBJECTS=simulation.o main.o

main: $(OBJECTS) 

main.o: constants.h

simulation.o: constants.h

run: main
	./main

clean:
	rm -f main $(OBJECTS)

.PHONY: clean run
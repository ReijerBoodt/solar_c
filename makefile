CC=gcc
CFLAGS=--std=gnu17 -Warray-bounds -g
LDFLAGS=-lm -lraylib
OBJECTS=simulation.o main.o

all: main examples/raylib_demo

main: $(OBJECTS) 

main.o: constants.h main.h

simulation.o: constants.h simulation.h

raylib_demo: examples/raylib_demo
	./examples/raylib_demo
examples/raylib_demo:
examples/raylib_demo.o: 

run: main
	./main

clean:
	rm -f main $(OBJECTS)

.PHONY: all run clean
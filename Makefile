CC=gcc
CFLAGS=--std=gnu17 -Warray-bounds -g -I/opt/homebrew/include -O3
LDFLAGS=-lm -lraylib -L/opt/homebrew/lib
OBJECTS=simulation.o main.o

all: main examples/raylib_demo

main: $(OBJECTS) 

main.o: constants.h main.h bodies.h

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
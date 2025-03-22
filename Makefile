FLAGS = -pedantic-errors -std=c++11

all: main run clean

main: main.o screen.o game.o input.o player.o
	g++ $(FLAGS) $^ -o $@ 

player.o: player.cpp player.h
	g++ $(FLAGS) -c $<

input.o: input.cpp input.h
	g++ $(FLAGS) -c $<

screen.o: screen.cpp screen.h
	g++ $(FLAGS) -c $<

game.o: game.cpp game.h
	g++ $(FLAGS) -c $<

main.o: main.cpp text.h screen.h game.h input.h player.h
	g++ $(FLAGS) -c $<

run:
	./main
clean: 
	rm -f *.o main

.PHONY: clean run all
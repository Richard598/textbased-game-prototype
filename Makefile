FLAGS = -pedantic-errors -std=c++11

main: main.o screen.o game.o
	g++ $(FLAGS) $^ -o $@ -lncurses

screen.o: screen.cpp screen.h
	g++ $(FLAGS) -c $<

game.o: game.cpp game.h
	g++ $(FLAGS) -c $<

main.o: main.cpp text.h screen.h game.h
	g++ $(FLAGS) -c $<

clean:
	rm -f *.o 

.PHONY: clean
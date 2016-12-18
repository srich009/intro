all: main.o f.o
	g++ main.o f.o -W -Wall -Werror

main.o: main.cpp f.h
	g++ -c main.cpp -W -Wall -Werror

f.o: f.cpp f.h
	g++ -c f.cpp -W -Wall -Werror
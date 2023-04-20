all: compile link

compile:
	g++ -Isrc/include -c main.cpp animation.cpp player.cpp

link:
	g++ main.o animation.o player.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
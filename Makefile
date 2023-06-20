all: compile link

compile:
	g++ -Isrc/include -c main.cpp animation.cpp player.cpp enemy.cpp

link:
	g++ main.o animation.o player.o enemy.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
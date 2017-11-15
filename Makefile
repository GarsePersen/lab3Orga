FLAGS=-Wall -g -std=c++11

all: Archivo.o Cache.o 
	g++ $(FLAGS) Cache.o Archivo.o Main.cpp -o lab3

Archivo.o: Archivo.cpp Archivo.hpp
	g++ $(FLAGS) -c Archivo.cpp -o Archivo.o

Cache.o: Cache.cpp Cache.hpp
	g++ $(FLAGS) -c Cache.cpp -o Cache.o

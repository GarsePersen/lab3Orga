FLAGS=-Wall -g -std=c++11

all: Archivo.o 
	g++ $(FLAGS) Archivo.o Main.cpp -o lab3

Archivo.o: Archivo.cpp Archivo.hpp
	g++ $(FLAGS) -c Archivo.cpp -o Archivo.o

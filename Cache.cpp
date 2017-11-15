#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Cache.hpp"
using namespace std;

Cache::Cache(int bloques, int vias, int palabras, string politicaReemplazo, int cantidadDatosIngresar){
	this->politicaReemplazo = politicaReemplazo;
	int cantidadColumnas = palabras*bloques+2;
	vector<vector<string>> matriz(cantidadDatosIngresar+3, vector<string>(cantidadColumnas));
	this->datosCache = matriz;
	int auxVias = 0;
	int auxBloques = 0;
	int auxPalabras = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < cantidadColumnas-2; j++){
			switch(i){
				case 0:
					if(j%(cantidadColumnas-2)/(palabras*vias) == 0){
						datosCache[i][j] = "s"+to_string(auxVias);
						auxVias++;
					} else {
						datosCache[i][j] = "  ";

					}	
					break;
				case 1:
					if(j%(cantidadColumnas-2)/bloques == 0){
						datosCache[i][j] = "b" + to_string(auxBloques);
						auxBloques = 0;
					} else {
						auxBloques++;
						datosCache[i][j] = "  ";
					}
					break;
				case 2:
					if(j%palabras == 0){
						auxPalabras = 0;
						datosCache[i][j] = "w"+to_string(auxPalabras);
					} else {
						auxPalabras++;
						datosCache[i][j] = "w"+to_string(auxPalabras);	
					}
					break;
				default:
					break;
			}
		}
	}
	for(int i = 0; i < cantidadDatosIngresar+3; i++){
		for(int j = 0; j < cantidadColumnas; j++){
			cout << datosCache[i][j] << " ";
		}
		cout << "\n";
	}

}

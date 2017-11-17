#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "Cache.hpp"
#include "Datos.hpp"

Cache::Cache(int bloques, int vias, int palabras, char* politicaReemplazo, int cantidadDatosIngresar){
    Datos datos;
    this->politicaReemplazo = politicaReemplazo;
    this->cantidadColumnas = palabras*bloques+2;
    vector<vector<Datos>> matriz(cantidadDatosIngresar+3, vector<Datos>(cantidadColumnas));
    this->datosCache = matriz;
    this->bloques = bloques;
    this->vias = vias;
    this->palabras = palabras;
    this->cantidadDatosIngresar = cantidadDatosIngresar;
    inicializarCache();
    imprimirCache();   
}

void Cache::imprimirCache(){
    for(int i = 0; i < this->cantidadDatosIngresar+3; i++){
        for(int j = 0; j < this->cantidadColumnas; j++){
            cout << this->datosCache[i][j].auxiliar << " ";
        }
        cout << "\n";
    }
}

void Cache::inicializarCache(){
    int auxVias = 0;
    int auxBloques = 0;
    int auxPalabras = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < this->cantidadColumnas-2; j++){
            switch(i){
                case 0:
                    if(j<this->bloques){
                        if(j%(this->vias) == 0 ){
                            this->datosCache[i][j].auxiliar = "s"+to_string(auxVias);
                            auxVias++;
                        } else {
                            this->datosCache[i][j].auxiliar = ";";

                        }	

                    }	
                    break;
                case 1:
                    if(j%(this->cantidadColumnas-2)/this->bloques == 0){
                        this->datosCache[i][j].auxiliar = "b" + to_string(auxBloques);
                        auxBloques = 0;
                    } else {
                        auxBloques++;
                        this->datosCache[i][j].auxiliar = "  ";
                    }
                    break;
                case 2:
                    if(j%this->palabras == 0){
                        auxPalabras = 0;
                        this->datosCache[i][j].auxiliar = "w"+to_string(auxPalabras);
                    } else {
                        auxPalabras++;
                        this->datosCache[i][j].auxiliar = "w"+to_string(auxPalabras);	
                    }
                    break;
                default:
                    break;
            }
        }
    }
}


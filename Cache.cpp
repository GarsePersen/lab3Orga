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
    int cantidadColumnas = palabras*bloques+2;
    vector<vector<Datos>> matriz(cantidadDatosIngresar+3, vector<Datos>(cantidadColumnas));
    this->datosCache = matriz;
    int auxVias = 0;
    int auxBloques = 0;
    int auxPalabras = 0;
	cout << cantidadColumnas-2 << endl;
	cout << bloques << endl;
	cout << vias << endl;
	cout << ((bloques)/(vias)) << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < cantidadColumnas-2; j++){
            switch(i){
                case 0:
		    if(j<bloques){
			    if(j%(vias) == 0 ){
				    datosCache[i][j].auxiliar = "s"+to_string(auxVias);
				    auxVias++;
			    } else {
				    datosCache[i][j].auxiliar = ";";

			    }	

		    }	
		    break;
                case 1:
                    if(j%(cantidadColumnas-2)/bloques == 0){
                        datosCache[i][j].auxiliar = "b" + to_string(auxBloques);
                        auxBloques = 0;
                    } else {
                        auxBloques++;
                        datosCache[i][j].auxiliar = "  ";
                    }
                    break;
                case 2:
                    if(j%palabras == 0){
                        auxPalabras = 0;
                        datosCache[i][j].auxiliar = "w"+to_string(auxPalabras);
                    } else {
                        auxPalabras++;
			datosCache[i][j].auxiliar = "w"+to_string(auxPalabras);	
		    }
		    break;
		default:
		    break;
	    }
	}
    }
    for(int i = 0; i < cantidadDatosIngresar+3; i++){
        for(int j = 0; j < cantidadColumnas; j++){
            cout << datosCache[i][j].auxiliar << " ";
        }
        cout << "\n";
    }
}



#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "Cache.hpp"
#include "Datos.hpp"

Cache::Cache(int bloques, int vias, int palabras, const char* politicaReemplazo, int cantidadDatosIngresar){
    this->politicaReemplazo = politicaReemplazo;
    this->cantidadColumnas = palabras*bloques+2;
    this->bloques = bloques;
    this->vias = vias;
    this->palabras = palabras;
    this->posicion = 0;
    this->hit = 0;
    this->miss = 0;
    this->cantidadDatosIngresar = cantidadDatosIngresar;
    vector<vector<vector<Datos>>> matriz;
    matriz.resize((this->bloques/this->vias));
    for(int i = 0; i<(this->bloques/this->vias); i++){
        matriz[i].resize(this->vias);
	for(int j = 0; j<this->vias; j++){
	    matriz[i][j].resize(this->palabras);
	}
    }
    this->datosCache = matriz;

    inicializarCache();
}

int Cache::calcularPalabra(int direccion){
    int w;
    w = (int)direccion%this->palabras;
    return w;
}

int Cache::calcularConjunto(int direccion){
    int s;
    s = (int) direccion/this->palabras;
    s = s%(this->bloques/this->vias);
    return s;
}

bool Cache::comprobarHit(int direccion){
    for(int i = 0; i<this->bloques/this->vias; i++){
	    for(int j = 0; j<this->vias; j++){
		    for(int k = 0; k<this->palabras; k++){
			    if(this->datosCache[i][j][k].direcciones[this->posicion] == direccion){
				if(string(this->politicaReemplazo) == "FIFO"){ //En fifo los hit no se toman en cuenta
				} else {
		    			for(int k = 0; k<this->palabras; k++){
						this->datosCache[i][j][k].antiguedad = 0;					
					}
				}
				return true;
			    } 
		    }
	    }
    }
    
    return false;
}

int Cache::calcularMayorAntiguedad(int s){
	int bloque = 0;
	int mayor = 0;
	for(int j = 0; j<this->vias; j++){
		for(int k = 0; k<this->palabras; k++){
			if(mayor < this->datosCache[s][j][k].antiguedad){
				mayor = this->datosCache[s][j][k].antiguedad;
				bloque = j;
			}
		}
	}
	return bloque;

}

int Cache::calcularMenorAntiguedad(int s){
	int bloque = 0;
	int menor = this->cantidadDatosIngresar;
	for(int j = 0; j<this->vias; j++){
		for(int k = 0; k<this->palabras; k++){
			if(menor > this->datosCache[s][j][k].antiguedad){
				menor = this->datosCache[s][j][k].antiguedad;
				bloque = j;
			}
		}
	}
	return bloque;

}

void Cache::ingresarDirecciones(int direccion){
	int s = calcularConjunto(direccion);
	int w = calcularPalabra(direccion);
	int i = 0;

	bool hit = comprobarHit(direccion);
	if(hit){
		this->hit++;
	} else {
		this->miss++;
		while(this->datosCache[s][i][w].direcciones[this->posicion] != -1){
			i++;
			if(i >= this->vias){ //Si ya no quedan bloques, se aplica politica de reemplazo
				if(string(this->politicaReemplazo) == "MRU"){
					int bloque = calcularMenorAntiguedad(s);	//Se calcula bloque con menor antiguedad
					for(int j = 0, aux = this->palabras-1; j<this->palabras; j++, aux--){
						this->datosCache[s][bloque][j].direcciones[this->posicion] = direccion-(w-j);
						this->datosCache[s][bloque][j].antiguedad = 0;
					}


				}else{ //Si es FIFO o MRU
					int bloque = calcularMayorAntiguedad(s);	//Se calcula bloque con mayor antiguedad
					cout << "B: " << bloque << endl;
					for(int j = 0, aux = this->palabras-1; j<this->palabras; j++, aux--){
						this->datosCache[s][bloque][j].direcciones[this->posicion] = direccion-(w-j);
						this->datosCache[s][bloque][j].antiguedad = 0;
					}
				}


				break;
			}
		}
		if(i < this->vias){
			for(int j = 0, aux = this->palabras-1; j<this->palabras; j++, aux--){
				this->datosCache[s][i][j].direcciones[this->posicion] = direccion-(w-j);
			}

	    }

    }
    this->posicion++;
    for(int i = 0; i<this->bloques/this->vias; i++){
	    for(int j = 0; j<this->vias; j++){
		    for(int k = 0; k<this->palabras; k++){
			    this->datosCache[i][j][k].direcciones[this->posicion] = 
				    this->datosCache[i][j][k].direcciones[this->posicion-1];
			    if(this->datosCache[i][j][k].direcciones[this->posicion] != -1){
				this->datosCache[i][j][k].antiguedad++;
			    }
		    }
	    }
    }
}

void Cache::imprimirCache(){
    for(int i = 0; i<this->bloques/this->vias; i++){
    	cout << "s" << to_string(i) << " ";
    }
    cout << "\n";
    for(int i = 0; i<this->bloques/this->vias; i++){
	for(int j = 0; j<this->vias; j++){
	    cout <<"b" <<to_string(j) << " ";
	}
    }
    cout << "\n";
    for(int i = 0; i<this->bloques/this->vias; i++){
	for(int j = 0; j<this->vias; j++){
	    for(int k = 0; k<this->palabras; k++){
	        cout << "w" << to_string(k) << " ";
	    }
	}
    }
    cout << "\n";
    int aux = 0;
    while(aux<this->cantidadDatosIngresar){
	    for(int i = 0; i<this->bloques/this->vias; i++){
		    for(int j = 0; j<this->vias; j++){
			    for(int k = 0; k<this->palabras; k++){
				    cout << this->datosCache[i][j][k].direcciones[aux] << " ";
			//	cout <<"("<< this->datosCache[i][j][k].antiguedad << ")";
			    }
		    }
	    }
	    cout << "\n";
	    aux = aux+1;

    }
    cout << "\n";
    cout << "Cantidad de hit: " << this->hit;
    cout << ", Tasa de hit: " << (float)this->hit/this->cantidadDatosIngresar << endl;
    cout << "Cantidad de miss: " << this->miss;
    cout << ", Tasa de miss: " << (float)this->miss/this->cantidadDatosIngresar << endl;

}

void Cache::inicializarCache(){
    for(int i = 0; i<this->bloques/this->vias; i++){
	for(int j = 0; j<this->vias; j++){
	    for(int k = 0; k<this->palabras; k++){
		for(int aux = 0; aux<this->cantidadDatosIngresar; aux++){
    			this->datosCache[i][j][k].direcciones.push_back(-1);

		}
	    }
	}
    }

}


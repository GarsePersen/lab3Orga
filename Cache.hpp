#ifndef _H_CACHE_
#define _H_CACHE_

#include <string>
#include <vector>
using namespace std;

/* Clase Archivo, se encarga de leer y escribir los archivos necesarios */
class Cache{
    private:
	string politicaReemplazo;
    public:
	Cache(int bloques, int vias, int palabras, string politicaReemplazo, int cantidadDatosIngresar);
	vector<vector<string>> datosCache;
	
};

#endif
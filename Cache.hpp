#ifndef _H_CACHE_
#define _H_CACHE_

#include <string>
#include <vector>
using namespace std;
#include "Datos.hpp"

/* Clase Archivo, se encarga de leer y escribir los archivos necesarios */
class Cache{
    private:
        string politicaReemplazo;
        int bloques;
        int vias;
        int palabras;
        int cantidadColumnas;
        int cantidadDatosIngresar;
        void inicializarCache();
        void imprimirCache();
    public:
        Cache(int bloques, int vias, int palabras, char* politicaReemplazo, int cantidadDatosIngresar);
        vector<vector<Datos>> datosCache;

};

#endif

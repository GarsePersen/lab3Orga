#ifndef _H_CACHE_
#define _H_CACHE_

#include <string>
#include <vector>
using namespace std;
#include "Datos.hpp"

/* Clase Archivo, se encarga de leer y escribir los archivos necesarios */
class Cache{
    private:
        const char *politicaReemplazo;
        int bloques;
        int vias;
        int palabras;
        int cantidadColumnas;
        void inicializarCache();
        int calcularPalabra(int direccion);
        int posicion;
        int calcularConjunto(int direccion);
        bool comprobarHit(int direccion);
        int calcularMenorAntiguedad(int s);
        int calcularMayorAntiguedad(int s);
    public:
        Cache(int bloques, int vias, int palabras, const char* politicaReemplazo, int cantidadDatosIngresar);
        vector<vector<vector<Datos>>> datosCache;
        string crearStringCache();
        int hit;
        int miss;
        int cantidadDatosIngresar;
        void ingresarDirecciones(int direccion);

};

#endif

#ifndef _H_ARCHIVO_
#define _H_ARCHIVO_

#include <string>
#include <vector>
using namespace std;

/* Clase Archivo, se encarga de leer y escribir los archivos necesarios */
class Archivo{
    public:
        vector<int> archivoEntrada(const char *nombre);
};

#endif

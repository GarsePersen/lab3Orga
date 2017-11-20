#define _GLIBCXX_USE_CXX11_ABI 0

#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Archivo.hpp"
#include "Cache.hpp"

int main(int argc, char **argv){
    Archivo archivo;
    string politicaReemplazo;
    int vias = -1;
    int palabras = -1;
    int bloques = -1;
    int c = -1;
    vector<int> datosConsulta;
    string nombreArchivoEntrada;	

    while((c = getopt(argc, argv, "r:v:p:t:")) != -1){
        switch(c){
            case 'r':
                politicaReemplazo = optarg;
                break;
            case 'v':
                vias = atoi(optarg);
                break;
            case 'p':
                palabras = atoi(optarg);
                break;
            case 't':
                bloques = atoi(optarg);
                break;

        }
    }
    cout << politicaReemplazo << endl;
    cout << vias << endl;
    cout << palabras << endl;
    cout << bloques << endl;	

    cout << "Ingrese el nombre del archivo con los datos a consultar: ";
    cin >> nombreArchivoEntrada;

    datosConsulta = archivo.archivoEntrada(nombreArchivoEntrada.c_str());
    Cache cache(bloques, vias, palabras, politicaReemplazo.c_str(), datosConsulta.size());	
    for(unsigned int i = 0; i<datosConsulta.size(); i++){
    	cache.ingresarDirecciones(datosConsulta[i]);
        cache.imprimirCache();

    }
    cache.imprimirCache();   
    return 0;
}

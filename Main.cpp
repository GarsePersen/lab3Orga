#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>

using namespace std;

#include "Archivo.hpp"
#include "Cache.hpp"


int main(int argc, char **argv){
    Archivo archivo;
    char *politicaReemplazo;
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


    datosConsulta = archivo.archivoEntrada(nombreArchivoEntrada);
    Cache cache(bloques, vias, palabras, politicaReemplazo, datosConsulta.size());	

    return 0;
}

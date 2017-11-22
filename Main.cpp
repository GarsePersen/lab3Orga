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
    string politicaReemplazo = "p";
    int vias = -1;
    int palabras = -1;
    int bloques = -1;
    int c = -1;
    vector<int> datosConsulta;
    string nombreArchivoEntrada;	
    string nombreArchivoSalida;
    string nombreArchivoSalida2;	

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

    //Comprobaciones
    if(politicaReemplazo == "p" or vias == -1 or palabras == -1 or bloques == -1){
        cout << "\nNo se ingreso correctamente un parametro. " <<endl;
        return 0;
    }
    if((vias%4 != 0 or bloques%4 != 0 ) and (vias != 1 and bloques != 1) and (vias != 2 and bloques != 2)){
        cout << "\nCompruebe que las vias y los bloques son multiplos de 4. " << endl;
        return 0;
    }
    if(vias>bloques){
        cout << "\nLas vias no pueden ser mayores a los bloques. " << endl;
        return 0;
    }
    if(politicaReemplazo == "FIFO" or politicaReemplazo == "LRU" or politicaReemplazo == "MRU"){
        //Camino correcto
        cout << "Ingrese el nombre del archivo con los datos a consultar: ";
        cin >> nombreArchivoEntrada;
        cout << "Ingrese el nombre del archivo de salida de la traza: ";
        cin >> nombreArchivoSalida;
        cout << "Ingrese el nombre del archivo de salida de las tasas de hit/miss: ";
        cin >> nombreArchivoSalida2;

        datosConsulta = archivo.archivoEntrada(nombreArchivoEntrada.c_str());
        Cache cache(bloques, vias, palabras, politicaReemplazo.c_str(), datosConsulta.size());	

        for(unsigned int i = 0; i<datosConsulta.size(); i++){
            cache.ingresarDirecciones(datosConsulta[i]);
        }
        float tasaHit = (float) cache.hit/cache.cantidadDatosIngresar*100;
        float tasaMiss = (float) cache.miss/cache.cantidadDatosIngresar*100;

        archivo.archivoSalida(nombreArchivoSalida.c_str(), nombreArchivoSalida2.c_str(), tasaHit, tasaMiss, cache.crearStringCache().c_str());
        cout << "Archivos de salida creados" << endl;

    } else {
        cout << "\nPolitica de reemplazo mal escrita. (Debe ser FIFO, LRU o MRU)" << endl;
        return 0;

    }

    return 0;
}

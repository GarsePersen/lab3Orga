#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>
using namespace std;
#include "Archivo.hpp"


/* Funcion que obtiene un vector de enteros desde el archivo de entrada
 * Entrada: String nombre
 * Salida: vector<int>
 * */
vector<int> Archivo::archivoEntrada(const char *nombre){
    string linea;
    string::iterator it;
    vector<int> datosConsulta;
    ifstream archivo (nombre);
    if(!archivo.good()){
        throw logic_error("El archivo con los datos a consultar no existe.\n");
        return datosConsulta;
    }
    if (archivo.is_open()){
        while ( getline (archivo, linea)){
            datosConsulta.push_back(atoi(linea.c_str()));
        }
        archivo.close();
    }else{
        throw logic_error("Error al abrir el archivo.");
        return datosConsulta;
    }
    return datosConsulta;
}

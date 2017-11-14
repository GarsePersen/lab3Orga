#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Archivo.hpp"
using namespace std;


/* Funcion que obtiene un vector de enteros desde el archivo de entrada
 * Entrada: String nombre
 * Salida: vector<int>
 * */
vector<int> Archivo::archivoEntrada(string nombre){
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

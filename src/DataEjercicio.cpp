#ifndef DTEJERCICIO_H
#define DTEJERCICIO_H

#include <string>
#include "DataEjercicio.h"

using namespace std;

TipoEjercicio DataEjercicio::getTipo() {
    return this->tipo;
}

string DataEjercicio::getDescripcion() {
    return this->descripcion;
}

string DataEjercicio::getLetra(){
    return this->letra;
}
 
 string DataEjercicio::getSolucion(){
    return this->solucion;
 }
 DataEjercicio::DataEjercicio(Ejercicio *ej){
    this->tipo=ej->getTipo();
    this->descripcion=ej->getDescripcion();
    this->letra=ej->getLetra();
    this->solucion=ej->getSolucion();
 }
DataEjercicio::DataEjercicio(TipoEjercicio tipo, string descripcion, string letra){
    this->tipo=tipo;
    this->descripcion=descripcion;
    this->letra=letra;
    this->solucion=solucion;
}
#endif
#include "CEjercicio.h"
#include "Ejercicio.h"
#include "Estudiante.h"
#include "Curso.h"
#include "completar.h"
#include <string>
#include <iostream>
using namespace std;

completar::~completar()
{
}

void completar::setLetra(string letra)
{
    this->letra = letra;
}
TipoEjercicio completar::getTipo(){
    return this->tipo;
}
string completar::getLetra()
{
    return this->letra;
}

void completar::setSolucion(string solucion)
{
    this->solucion = solucion;
}

string completar::getSolucion()
{
    return this->solucion;
}

completar::completar(TipoEjercicio tipo, string descripcion, string letra, string solucion)
{
    setTipo(tipo);
    setDescripcion(descripcion);
    setLetra(letra);
    setSolucion(solucion);
}

void completar::setTipo(TipoEjercicio tipo)
{
    this->tipo = tipo;
}

void completar::setDescripcion(string desc)
{
    this->descipcion = desc;
}

string completar:: getDescripcion() {
    return this-> descipcion;
}


// void completar::eliminarEjercicio()
// {
//     delete this;
// }
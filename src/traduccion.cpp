#include "CEjercicio.h"
#include "Ejercicio.h"
#include "traduccion.h"
#include <string>
using namespace std;

traduccion::~traduccion()
{
}

void traduccion::setLetra(string Letra)
{
    this->Letra = Letra;
}
string traduccion::getLetra()
{
    return this->Letra;
}
void traduccion::setSolucion(string Letra)
{
    this->solucion = Letra;
}
string traduccion::getSolucion()
{
    return this->solucion;
}
void traduccion::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}
string traduccion::getDescripcion()
{
    return this->descripcion;
}

void traduccion::setTipo(TipoEjercicio tipo)
{
    this->tipo = tipo;
}
TipoEjercicio traduccion::getTipo(){
    return this->tipo;
}

traduccion::traduccion(TipoEjercicio tipo, string descripcion, string Letra, string solucion)
{
    this->setTipo(tipo);
    this->setDescripcion(descripcion);
    this->setLetra(Letra);
    this->setSolucion(solucion);
}

// void traduccion::eliminarEjercicio()
// {
//     delete this;
// }
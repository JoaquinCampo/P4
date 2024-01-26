#include "Leccion.h"
#include <iostream>

Leccion::Leccion(string nomLeccion, string tema, string objetivo, int cantEjercicios)
{
    setNombreLeccion(nomLeccion);
    setTema(tema);
    setObjetivo(objetivo);
    setCantEjercicios(cantEjercicios);
    this-> ejercicios = vector<Ejercicio*>();
};

Leccion::~Leccion(){
    for (Ejercicio *ejABorrar : this->getEjercicios())
    {
        delete ejABorrar;
    };
    this->ejercicios.clear();
};

string Leccion::getNombreLeccion()
{
    return this->nomLeccion;
};

string Leccion::getTema()
{
    return this->tema;
};

string Leccion::getObjetivo()
{
    return this->objetivo;
};

int Leccion::getCantEjercicios()
{
    return this->cantEjercicios;
};

vector<Ejercicio *> Leccion::getEjercicios()
{
    return this->ejercicios;
}

void Leccion::setNombreLeccion(string nomLeccion)
{
    this->nomLeccion = nomLeccion;
}

void Leccion::setTema(string tema)
{
    this->tema = tema;
};

void Leccion::setObjetivo(string objetivo)
{
    this->objetivo = objetivo;
};

void Leccion::setCantEjercicios(int cantEjercicios)
{
    this->cantEjercicios = cantEjercicios;
};

// iAltaCurso
void Leccion::agregarLink(Ejercicio *ej)
{
    this-> ejercicios.push_back(ej);
}


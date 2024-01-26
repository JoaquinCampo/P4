#include "DataInfoProfesor.h"

DataInfoProfesor::DataInfoProfesor(string nomCurso, float promedio)
{
    this->nomCurso = nomCurso;
    this->promedio = promedio;
}

string DataInfoProfesor::getNomCurso()
{
    return this->nomCurso;
}

float DataInfoProfesor::getPromedio()
{
    return this->promedio;
}

void DataInfoProfesor::setNomCurso(string nomCurso)
{
    this->nomCurso = nomCurso;
}

void DataInfoProfesor::setPromedio(int promedio)
{
    this->promedio = promedio;
}

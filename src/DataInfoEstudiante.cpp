#include "DataInfoEstudiante.h"

DataInfoEstudiante::DataInfoEstudiante(string nomCurso, int progreso)
{
    this->nomCurso = nomCurso;
    this->progreso = progreso;
}

string DataInfoEstudiante::getNomCurso()
{
    return this->nomCurso;
}

double DataInfoEstudiante::getProgreso()
{
    return this->progreso;
}

void DataInfoEstudiante::setNomCurso(string nomCurso)
{
    this->nomCurso = nomCurso;
}

void DataInfoEstudiante::setProgreso(int progreso)
{
    this->progreso = progreso;
}

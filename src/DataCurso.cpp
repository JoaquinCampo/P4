#include "DataCurso.h"

using namespace std;

DataCurso ::DataCurso(string nombre, string Descripcion, Dificultad Complejidad, int CantLecciones, bool Habilitado, float Promedio, string IdiomaC, string ProfesorC)
{
    this->Nombre = nombre;
    this->Descripcion = Descripcion;
    this->Complejidad = Complejidad;
    this->CantLecciones = CantLecciones;
    this->Habilitado = Habilitado;
    this->Promedio = Promedio;
    this->IdiomaC = IdiomaC;
    this->ProfesorC = ProfesorC;
}

DataCurso ::~DataCurso() {}

string DataCurso ::getNombre()
{
    return this->Nombre;
}

string DataCurso ::getDescripcion()
{
    return this->Descripcion;
}

Dificultad DataCurso ::getComplejidad()
{
    return this->Complejidad;
}

int DataCurso ::getCantLecciones()
{
    return this->CantLecciones;
}

bool DataCurso ::getHabilitado()
{
    return this->Habilitado;
}

float DataCurso ::getPromedio()
{
    return this->Promedio;
}

string DataCurso ::getIdiomaC()
{
    return this->IdiomaC;
}

string DataCurso ::getProfesorC()
{
    return this->ProfesorC;
}

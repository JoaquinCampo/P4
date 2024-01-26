#ifndef DataCurso_h
#define DataCurso_h

#include <string>
#include <iostream>

#include "DataEjercicio.h"

using namespace std;

class DataCurso
{
private:
    string Nombre;
    string Descripcion;
    Dificultad Complejidad;
    int CantLecciones;
    bool Habilitado;
    float Promedio;
    string IdiomaC;
    string ProfesorC;

public:
    DataCurso(string, string, Dificultad, int, bool, float, string, string);
    ~DataCurso();

    string getNombre();
    string getDescripcion();
    Dificultad getComplejidad();
    int getCantLecciones();
    bool getHabilitado();
    float getPromedio();
    string getIdiomaC();
    string getProfesorC();
};

#endif
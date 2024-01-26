#ifndef DATAINFOCURSO_H
#define DATAINFOCURSO_H

#include "Curso.h"
#include <string>


using namespace std;

class dataInfoCurso
{
private:
    string Nombre;
    string Descripcion;
    Dificultad Complejidad;
    int CantLecciones;
    bool Habilitado;
    int Promedio;
    string IdiomaC;
    string ProfesorC;

public:
    dataInfoCurso(string, string, Dificultad, int, bool, int, string, string);
    ~dataInfoCurso();

    string getNombre();
    string getDescripcion();
    Dificultad getComplejidad();
    int getCantLecciones();
    bool getHabilitado();
    int getPromedio();
    string getIdiomaC();
    string getProfesorC();
};    

#endif
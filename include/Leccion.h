#ifndef Leccion_h
#define Leccion_h

#include <string>
#include <set>
#include <map>
#include "Ejercicio.h"
// #include "DataEjercicio.h"
#include "DataLeccion.h"
#include "Estudiante.h"
#include <vector>

using namespace std;

class Leccion
{
private:
    string nomLeccion;
    string tema;
    string objetivo;
    int cantEjercicios;
    vector<Ejercicio *> ejercicios;

public:
    Leccion(string, string, string, int);
    ~Leccion();

    string getNombreLeccion();
    string getTema();
    string getObjetivo();
    int getCantEjercicios();
    vector<Ejercicio*> getEjercicios();

    void setNombreLeccion(string);
    void setTema(string);
    void setObjetivo(string);
    void setCantEjercicios(int);

    void borrarSetEjercicios();
    

    //void addEjercicio(Ejercicio*);

    //iAltaCurso
    void agregarLink(Ejercicio*); // agrega ejercicio a leccion

    //iRealizarEjercicios
    set<DataEjercicio*> getEjerciciosIncompletos(Estudiante*);
};

#endif

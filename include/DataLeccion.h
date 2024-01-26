#ifndef DataLeccion_h
#define DataLeccion_h

class Leccion;
#include "Leccion.h"
#include "DataEjercicio.h"

using namespace std;

class DataLeccion
{
private:
    string nomLeccion;
    string tema;
    string objetivo;
    int cantEjercicios;
    map<int, DataEjercicio*> ejercicios;

public:
    DataLeccion(string, string, string,int, map<int, DataEjercicio*>);
    ~DataLeccion();
    
    string getNomLeccion();
    string getTema();
    string getObjetivo();
    int getCantEjercicios();
    map<int, DataEjercicio*> getEjercicios();

    void setNomLeccion(string);
    void setTema(string);
    void setObjetivo(string);
    void setCantEjercicios(int);
    void agregarLink(DataEjercicio*, int); // agrega dataejercicio a dataleccion
    
    set <DataEjercicio*> getEjerciciosIncompletos();
};

#endif
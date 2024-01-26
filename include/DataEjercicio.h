#ifndef DATAEJERCICIO_H
#define DATAEJERCICIO_H

#include <string>
#include "Ejercicio.h"

enum Dificultad{
    Principiante,
    Medio,
    Avanzado
};

using namespace std;


class DataEjercicio {
    private:
        TipoEjercicio tipo;
        string descripcion;
        string letra;
        string solucion;
    
    public:
        DataEjercicio(Ejercicio*);
        DataEjercicio(TipoEjercicio,string,string);
        TipoEjercicio getTipo();
        string getDescripcion();
        string getLetra();
        string getSolucion();
        };

#endif
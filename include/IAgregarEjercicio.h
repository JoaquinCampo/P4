#ifndef IAgregarEjercicio_h
#define IAgregarEjercicio_h

#include <set>
#include <string>

#include "DataCurso.h"
#include "DataLeccion.h"

using namespace std;

class IAgregarEjercicio
{
public:
    virtual set<DataCurso *> listarCursosNoHabilitados_CCurso() = 0;
    virtual set<DataLeccion *> listarLeccion_CCurso(string) = 0;
    virtual void ingresarEjercicio(string, TipoEjercicio, string) = 0;
    virtual void ejCompletar(string,  string) = 0;
    virtual void ejTraduccion(string, string) = 0;
};

#endif
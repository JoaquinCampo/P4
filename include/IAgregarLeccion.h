#ifndef IAgregarLeccion_h
#define IAgregarLeccion_h

using namespace std;

#include <set>
#include <string>
#include "Ejercicio.h"
#include "Estructuras.h"
#include "DataCurso.h"

class IAgregarLeccion
{
public:
    virtual set<DataCurso *> listarCursosNoHabilitados() = 0; 
    virtual void agregarLeccionAL(string, string, string, string, int) = 0;
    virtual void agregarEjercicioAL(TipoEjercicio, string) = 0;
    virtual void ejCompletarAL(string, string, string) = 0;
    virtual void ejTraducirAL(string, string, string) = 0;
    virtual void actualizarCantEjs(string, int) = 0;
    virtual bool existeLeccion(string, string) = 0;
};

#endif
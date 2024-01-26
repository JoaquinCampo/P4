#ifndef IConsultarCurso_H
#define IConsultarCurso_H

#include <set>
#include <string>

#include "DataCurso.h"
#include "DataEstudiante.h"
#include "Estructuras.h"
#include "DataLeccion.h"

using namespace std;

class IConsultarCurso
{
public:
    virtual set<DataCurso *> listarCursos() = 0;
    virtual bool existe_Curso(string) = 0;
    virtual DataCurso *obtenerCurso(string) = 0;
    virtual int getCantLecciones(string) = 0;
    virtual set<DataLeccion *> getLecciones(string) = 0;
    virtual set<DataEstudiante *> getInscriptos(string) = 0;
    virtual Fecha getFechaInscripcion(string, string) = 0;
};

#endif
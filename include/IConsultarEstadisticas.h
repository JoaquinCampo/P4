#ifndef IConsultarEstadisticas_h
#define IConsultarEstadisticas_h

using namespace std;

#include <set>
#include <string>
#include "DataInfoEstudiante.h"
#include "DataInfoProfesor.h"
#include "DataCurso.h"

class IConsultarEstadisticas
{
public:
    virtual set<string> listarEstudiantes() = 0;
    virtual set<DataInfoEstudiante *> listarCurso_y_Avance(string) = 0;
    virtual set<string> listarProfesores() = 0;
    virtual set<DataInfoProfesor *> listarInfoProfe(string) = 0;
    virtual set<string> listarCursos() = 0;
    virtual DataCurso *listarInfoCurso(string) = 0;
};

#endif
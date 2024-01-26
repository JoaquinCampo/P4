#ifndef CEstadisticas_h
#define CEstadisticas_h

class CCurso;
class CUsuario;
#include "IConsultarEstadisticas.h"
#include "CUsuario.h"
#include "CCurso.h"

class CEstadisticas : public IConsultarEstadisticas
{
private:
public:
    CEstadisticas();
    ~CEstadisticas();
    set<string> listarEstudiantes();
    set<DataInfoEstudiante *> listarCurso_y_Avance(string);
    set<string> listarProfesores();
    set<DataInfoProfesor *> listarInfoProfe(string);
    set<string> listarCursos();
    DataCurso *listarInfoCurso(string);
};

#endif
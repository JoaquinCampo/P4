#ifndef IInscribirseACurso_h
#define IInscribirseACurso_h

using namespace std;

#include "DataCurso.h"

class IInscribirseACurso{
    public:
        virtual set <DataCurso *> listarCursos_Disponibles(string nickname) = 0;
        virtual void inscribirseACurso() = 0;
        virtual bool existe_usuario(string nickname) = 0;
        virtual bool existe_cursoII(string nombreCurso) = 0;
        virtual bool es_profesor(string nickname) = 0;
        virtual void RecordarNombreCurso(string) = 0;
        virtual void RecordarNickname(string) = 0;
        virtual void RecordarFechaInscripcion(Fecha) = 0;

};

#endif
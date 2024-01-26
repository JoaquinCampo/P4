#ifndef IHabilitarCurso_h
#define IHabilitarCurso_h

#include "DataCurso.h"

using namespace std;

class IHabilitarCurso{
    public:
        virtual set<DataCurso *> listarCursosHabilitables() = 0;
        virtual void habilitarCurso() = 0;
        virtual void RecordarNombreCurso(string) = 0;
};

#endif
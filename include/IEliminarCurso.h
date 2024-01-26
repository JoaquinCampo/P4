#ifndef IEliminarCurso_h
#define IEliminarCurso_h

#include <string>
#include <set>

using namespace std;

class IEliminarCurso
{
public:
    virtual set<string> mostrarCursos() = 0;
    virtual void eliminarCurso() = 0;
    virtual void RecordarNombreCurso(string) = 0;
};

#endif
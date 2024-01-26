#ifndef IEliminarSuscripciones_h
#define IEliminarSuscripciones_h

using namespace std;

class IEliminarSuscripciones
{
public:
    virtual set<string> listarSuscripciones(string nickname) = 0;
    virtual void eliminarSuscripciones(string nickname, string Idioma) = 0;
};

#endif
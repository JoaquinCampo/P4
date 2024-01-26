
#ifndef IDIOMA_H
#define IDIOMA_H
class Usuario;
class Curso;

#include <string>
#include "Usuario.h"
#include "DataNotificacion.h"
#include <set>
#include <map>

using namespace std;

class Idioma
{
private:
    string nombre;
    set<Usuario *> ColObservadores;
    map<string, Curso *> cursos;
public:
    Idioma(string nombre);
    virtual ~Idioma();
    string getNombre();
    void setNombre(string nombre);
    set<Usuario *> getColObservadores();

    void agregarCurso(Curso *curso, string nomCurso);
    void quitarCurso(Curso *curso, string nomCurso);
    void agregarObservador(Usuario *obs);
    void eliminarObservador(Usuario *obs);
    bool estaSuscrito(string nickname);
    void notificar(DataNotificacion notificacion);
};
#endif

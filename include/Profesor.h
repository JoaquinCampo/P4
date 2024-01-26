#ifndef PROFESOR_H
#define PROFESOR_H
class Curso;
class Idioma;
#include "Curso.h"
#include "Usuario.h"
#include <string>
#include <set>
#include "Idioma.h"

class Profesor : public Usuario
{
private:
    std::string instituto;
    set<Idioma *> especializaciones;
    set<Curso *> misCursos;

public:
    Profesor(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion, std::string instituto, set<Idioma *> especializaciones);
    virtual ~Profesor();

    std::string getInstituto();
    set<Idioma *> getEspecializaciones();
    set<std::string> getSetIdiomas();
    set<Curso *> getMisCursos();

    void setEspecializaciones(set<Idioma *> especializaciones);

    void setInstituto(std::string instituto);

    // *Funciones IEliminarCurso
    void quitarMisCursos(Curso *c); 

    // *Funciones IAltaCurso
    void agregarMisCursos(Curso *c);

    // set<string> getProfe();
    //  void agregarLink(Idioma idi);
    //  void notificar(DataNotificacion notificacion) override;
    //  set<DataNotif> leerNotificaciones() override;
};

#endif
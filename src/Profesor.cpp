#include "Profesor.h"

Profesor::Profesor(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion, std::string instituto, set<Idioma *> especializaciones) : Usuario(nombre, nickname, contrasenia, descripcion)
{
    setInstituto(instituto);
    setEspecializaciones(especializaciones);
};

Profesor::~Profesor(){};

std::string Profesor::getInstituto()
{
    return this->instituto;
};

void Profesor::setInstituto(std::string instituto)
{
    this->instituto = instituto;
};

void Profesor::setEspecializaciones(set<Idioma *> especializaciones)
{
    this->especializaciones = especializaciones;
};

set<Idioma *> Profesor::getEspecializaciones()
{
    return this->especializaciones;
};

set<std::string> Profesor::getSetIdiomas()
{
    set<std::string> idiomas;
    set<Idioma *>::iterator it = this->especializaciones.begin();
    while (it != this->especializaciones.end())
    {
        idiomas.insert((*it)->getNombre());
        ++it;
    }
    return idiomas;
};

set<Curso*> Profesor::getMisCursos(){
    return this->misCursos;
}

// void Profesor::agregarLink(Idioma idi) {
//     // TODO
// }

//  set<string> Profesor::getProfe() {

//  }

// void Profesor::notificar(DataNotificacion notificacion) {
//     // TODO
// }

// set<DataNotif> Profesor::leerNotificaciones() {
//     // TODO
// }

void Profesor::quitarMisCursos(Curso *c){
    this->misCursos.erase(c);
}

void Profesor::agregarMisCursos(Curso *c){
    this->misCursos.insert(c);
}
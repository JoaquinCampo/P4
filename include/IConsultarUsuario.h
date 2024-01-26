#ifndef CONSULTARUSUARIO_H
#define CONSULTARUSUARIO_H

#include <string>
#include "DataUsuario.h"
#include "DataProfesor.h"
#include "DataEstudiante.h"

class IConsultarUsuario
{
public:
    virtual DataEstudiante *consultarEstudiante(std::string nickname) = 0;
    virtual DataProfesor *consultarProfesor(std::string nickname) = 0;
    virtual bool existeProfesor(std::string nickname) = 0;
    virtual bool existeEstudiante(std::string nickname) = 0;
    virtual bool existenUsuarios() = 0;
    virtual set<string> mostrarEstudiantesS() = 0;
    virtual set<string> mostrarProfesoresS() = 0;
};

#endif

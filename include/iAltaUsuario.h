#ifndef IALTAUSUARIO_H
#define IALTAUSUARIO_H

#include <string>
#include <vector>
#include "Ejercicio.h"
#include "Estructuras.h"
#include "DataEjercicio.h"

class IAltaUsuario
{
public:
    virtual bool existeUsuario(std::string nickname) = 0;
    virtual void ingresarDatos(std::string nombre, std::string nickname, std::string contrasena, std::string descripcion) = 0;
    virtual set<string *> ingresoInstituto(std::string instituto) = 0;
    virtual bool ingresoEstudiante(std::string pais, Fecha fechaNacimiento) = 0;
    virtual bool ingresoProfesor() = 0;
    virtual bool ingresoIdioma(std::string idioma) = 0;
    virtual bool existeIdioma(string idioma) = 0;
    virtual bool existeIdiomaIngresado() = 0;
};
#endif

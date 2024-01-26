#ifndef DATAESTUDIANTE_H
#define DATAESTUDIANTE_H

#include <string>
#include "Estructuras.h"
#include "DataUsuario.h"

class DataEstudiante : public DataUsuario
{
private:
    std::string pais;
    Fecha fechaNacimiento;

public:
    DataEstudiante(std::string nombre, std::string descripcion, std::string pais, Fecha fechaNacimiento);
    ~DataEstudiante();

    std::string getPais();
    Fecha getFechaNacimiento();
};

#endif

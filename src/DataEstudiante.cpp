#include "DataEstudiante.h"

DataEstudiante::DataEstudiante(std::string nombre, std::string descripcion, std::string pais, Fecha fechaNacimiento) : DataUsuario(nombre, descripcion)
{
    this->pais = pais;
    this->fechaNacimiento = fechaNacimiento;
};

DataEstudiante::~DataEstudiante(){};

std::string DataEstudiante::getPais()
{
    return this->pais;
};

Fecha DataEstudiante::getFechaNacimiento()
{
    return this->fechaNacimiento;
};

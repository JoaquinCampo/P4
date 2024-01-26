#include "DataProfesor.h"

DataProfesor::DataProfesor(std::string nombre, std::string descripcion, std::string instituto, std::set<string> idiomas) : DataUsuario(nombre, descripcion)
{
    this->instituto = instituto;
    this->idiomas = idiomas;
};

DataProfesor::~DataProfesor(){};

std::string DataProfesor::getInstituto()
{
    return this->instituto;
};

std::set<string> DataProfesor::getIdiomas()
{
    return this->idiomas;
};
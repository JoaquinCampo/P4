#include "DataUsuario.h"

DataUsuario::DataUsuario(std::string nombre, std::string descripcion)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
};

DataUsuario::~DataUsuario(){};

std::string DataUsuario::getNombre()
{
    return this->nombre;
};

std::string DataUsuario::getDescripcion()
{
    return this->descripcion;
};

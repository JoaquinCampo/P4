#include "DataProfesorGeneral.h"
#include <iostream>

DataProfesorGeneral::DataProfesorGeneral(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion, std::string instituto, std::set<std::string> idiomas)
{
    this->nombre = nombre;
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->descripcion = descripcion;
    this->instituto = instituto;
    this->idiomas = idiomas;
};

DataProfesorGeneral::~DataProfesorGeneral()
{
    std::set<std::string>::iterator it = this->idiomas.begin();
    while (it != this->idiomas.end())
    {
        this->idiomas.erase(it);
        ++it;
    }
};

std::string DataProfesorGeneral::getNombre()
{
    return this->nombre;
};

std::string DataProfesorGeneral::getNickname()
{
    return this->nickname;
};

std::string DataProfesorGeneral::getContrasenia()
{
    return this->contrasenia;
};

std::string DataProfesorGeneral::getDescripcion()
{
    return this->descripcion;
};

std::string DataProfesorGeneral::getInstituto()
{
    return this->instituto;
};

std::set<std::string> DataProfesorGeneral::getIdiomas()
{
    return this->idiomas;
};

void DataProfesorGeneral::mostrarDatos()
{
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Contrasenia: " << this->contrasenia << std::endl;
    std::cout << "Descripcion: " << this->descripcion << std::endl;
    std::cout << "Instituto: " << this->instituto << std::endl;
    std::cout << "Idiomas: " << std::endl;
    std::set<std::string>::iterator it = this->idiomas.begin();
    while (it != this->idiomas.end())
    {
        std::cout << (*it) << std::endl;
        ++it;
    }
};
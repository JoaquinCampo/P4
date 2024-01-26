#ifndef DATAPROFESORGENERAL_H
#define DATAPROFESORGENERAL_H

#include <string>
#include <set>

class DataProfesorGeneral
{
private:
    std::string nombre;
    std::string nickname;
    std::string contrasenia;
    std::string descripcion;
    std::string instituto;
    std::set<std::string> idiomas;

public:
    DataProfesorGeneral(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion, std::string instituto, std::set<std::string> idiomas);
    ~DataProfesorGeneral();
    std::string getNombre();
    std::string getNickname();
    std::string getContrasenia();
    std::string getDescripcion();
    std::string getInstituto();
    std::set<std::string> getIdiomas();
    void mostrarDatos();
};

#endif
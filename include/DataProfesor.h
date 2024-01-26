#ifndef DATAPROFESOR_H
#define DATAPROFESOR_H

#include <string>
#include <set>
#include "DataUsuario.h"
#include "Idioma.h"

class DataProfesor : public DataUsuario
{
private:
    std::string instituto;
    std::set<string> idiomas;

public:
    DataProfesor(std::string nombre, std::string descripcion, std::string instituto, std::set<string> idiomas);
    ~DataProfesor();

    std::string getInstituto();
    std::set<string> getIdiomas();
};

#endif

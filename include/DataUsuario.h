#ifndef DATAUSUARIO_H
#define DATAUSUARIO_H

#include <string>

using namespace std;

class DataUsuario
{
private:
    string nombre;
    string descripcion;

public:
    DataUsuario(string, string);
    ~DataUsuario();

    string getNombre();
    string getDescripcion();
};

#endif
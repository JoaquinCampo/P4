#include "DataNotificacion.h"

using namespace std;

DataNotificacion::DataNotificacion(string idioma, string curso)
{
    this->idioma = idioma;
    this->curso = curso;
}

string DataNotificacion::getIdioma()
{
    return this->idioma;
}

string DataNotificacion::getCurso()
{
    return this->curso;
}

bool DataNotificacion::operator<(const DataNotificacion& other) const
{
    if (idioma == other.idioma)
    {
        return curso < other.curso;
    }
    else
    {
        return idioma < other.idioma;
    }
};
#ifndef DATANOTIFICACION_H
#define DATANOTIFICACION_H

#include <string>

using namespace std;

class DataNotificacion
{
    private:
    string idioma;
    string curso;
    public:
    DataNotificacion(string idioma, string curso);
    string getIdioma();
    string getCurso();
    bool operator<(const DataNotificacion& other) const;
};

#endif
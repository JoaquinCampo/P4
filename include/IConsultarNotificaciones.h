#ifndef CONSULTARNOTIFICACIONES_H
#define CONSULTARNOTIFICACIONES_H

using namespace std;

#include <string>
#include <set>

#include "DataNotificacion.h"   

class IConsultarNotificaciones {
public:
    virtual set<DataNotificacion> consultarNotificaciones(string nickname) = 0;
};

#endif
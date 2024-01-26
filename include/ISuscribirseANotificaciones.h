#ifndef ISuscribirseANotificaciones_h
#define ISuscribirseANotificaciones_h

#include <set>

using namespace std;

class ISuscribirseANotificaciones{
    public:
        virtual set<string> listarNoSuscriptos(string nickname) = 0;
        virtual void suscribirseANotificaciones(string nickname, string idioma) = 0;       
};

#endif
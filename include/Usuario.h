#ifndef USUARIO_H
#define USUARIO_H
class Idioma;

#include <string>
#include <set>
#include "DataNotificacion.h"
#include "Idioma.h"

// #include "IAltaUsuario.h"
// #include "IConsultarUsuario.h"

class Usuario
{
private:
    std::string nombre;
    std::string nickname;
    std::string contrasenia;
    std::string descripcion;
    set<DataNotificacion> notificaciones;
    set<Idioma *> suscripciones;

public:
    Usuario(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion);

    std::string getNombre();
    std::string getNickname();
    std::string getContrasenia();
    std::string getDescripcion();

    void setNombre(std::string nombre);
    void setNickname(std::string nickname);
    void setContrasenia(std::string contrasenia);
    void setDescripcion(std::string descripcion);


    // Funciones para observer
    virtual void recibirNotificacion(DataNotificacion notificacion);
    virtual bool estaNotificado(DataNotificacion notificacion);
    virtual void borrarNotificacion(DataNotificacion notificacion);
    virtual set<DataNotificacion> leerNotificaciones();
    virtual void borrarDataPorIdioma(string idioma);
    void linkObserver(Idioma *idioma);
    void unlinkObserver(Idioma *idioma);
    set<Idioma *> getObservers();
    void vaciarNotificaciones(string nickname);

    // virtual void notificar(DataNotificacion notificacion);
    // virtual set<DataNotif> leerNotificaciones();
};

#endif
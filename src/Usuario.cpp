#include "Usuario.h"

Usuario::Usuario(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion)
{
    setNombre(nombre);
    setNickname(nickname);
    setContrasenia(contrasenia);
    setDescripcion(descripcion);
};

std::string Usuario::getNombre()
{
    return this->nombre;
};

// set<dataNotificacion> Usuario::getNotificaciones()
// {
//     return this->notificaciones;
// };

// void Usuario::setNotificaciones(set<dataNotificacion> notificaciones)
// {
//     this->notificaciones = notificaciones;
// };

std::string Usuario::getNickname()
{
    return this->nickname;
};

std::string Usuario::getContrasenia()
{
    return this->contrasenia;
};

std::string Usuario::getDescripcion()
{
    return this->descripcion;
};

void Usuario::setNombre(std::string nombre)
{
    this->nombre = nombre;
};

void Usuario::setNickname(std::string nickname)
{
    this->nickname = nickname;
};

void Usuario::setContrasenia(std::string contrasenia)
{
    this->contrasenia = contrasenia;
};

void Usuario::setDescripcion(std::string descripcion)
{
    this->descripcion = descripcion;
};

// virtual void notificar(DataNotificacion notificacion);
// virtual set<DataNotif> leerNotificaciones();

// Funciones para observer

// Ingresa una notificacion al set de notificaciones
void Usuario::recibirNotificacion(DataNotificacion notificacion)
{
    this->notificaciones.insert(notificacion);
};

// Chequea que el usuario este notificado
bool Usuario::estaNotificado(DataNotificacion notificacion)
{
    return this->notificaciones.find(notificacion) != this->notificaciones.end();
};

// Borra una notificacion del set de notificaciones
void Usuario::borrarNotificacion(DataNotificacion notificacion)
{
    this->notificaciones.erase(notificacion);
};

// Devuelve el set de notificaciones
set<DataNotificacion > Usuario::leerNotificaciones()
{
    set<DataNotificacion > notificaciones = set<DataNotificacion>();
    for (set<DataNotificacion>::iterator it = this->notificaciones.begin(); it != this->notificaciones.end(); ++it)
    {
        notificaciones.insert(*it);
    }
    return notificaciones;
};

// Borra todos los dataNotificaciones que tiene un idioma 
void Usuario::borrarDataPorIdioma(string idioma){
    set<DataNotificacion> res = this->notificaciones;
    for (DataNotificacion noti : res){
        if (noti.getIdioma() == idioma){
            this->notificaciones.erase(noti);
        }
    }
};

// Agrega un idioma al set de suscripciones
void Usuario::linkObserver(Idioma *idioma)
{
    this->suscripciones.insert(idioma);
};

// Elimina un idioma del set de suscripciones
void Usuario::unlinkObserver(Idioma *idioma)
{
    this->suscripciones.erase(idioma);
};

// Devuelve el set de suscripciones
set<Idioma *> Usuario::getObservers()
{
    return this->suscripciones;
};

// Vacía el set de notificaciones
void Usuario::vaciarNotificaciones(string nickname){
    this->notificaciones.clear();
};
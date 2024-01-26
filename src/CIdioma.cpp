#include "CIdioma.h"
#include <iostream>

CIdioma *CIdioma::instanciaIdioma = nullptr;

CIdioma &CIdioma::getInstance()
{
    if (instanciaIdioma == nullptr)
    {
        instanciaIdioma = new CIdioma();
    }

    return *instanciaIdioma;
};

CIdioma::CIdioma()
{
    MemNombre = "";
    this->ColIdiomas = map<string, Idioma *>();
};

CIdioma::~CIdioma()
{
    map<string, Idioma *>::iterator it;
    for (it = ColIdiomas.begin(); it != ColIdiomas.end(); ++it)
    {
        Idioma *i = it->second;
        i->~Idioma();
    }
    ColIdiomas.clear();
    delete instanciaIdioma;
};

bool CIdioma::existeIdioma(string nombre)
{
    return ColIdiomas.find(nombre) != ColIdiomas.end();
};

Idioma *CIdioma::encontrarIdioma(string nombre)
{
    return ColIdiomas.find(nombre)->second;
};

set<string *> CIdioma::mostrarIdiomas()
{
    set<string *> s;
    map<string, Idioma *>::iterator it;
    for (it = ColIdiomas.begin(); it != ColIdiomas.end(); ++it)
    {
        Idioma *i = it->second;
        string *d = new string(i->getNombre());
        s.insert(d);
    }
    return s;
};

string *CIdioma::getDataIdioma(string nombre)
{
    Idioma *i = ColIdiomas.find(nombre)->second;
    string *d = new string(i->getNombre());
    return d;
};

bool CIdioma::ingresoDatos(string nombre)
{
    if (!existeIdioma(nombre))
    {
        Idioma *i = new Idioma(nombre);
        ColIdiomas.insert(pair<string, Idioma *>(nombre, i));
        return true;
    }
    else
    {
        return false;
    }
};

set<string> CIdioma::listarIdiomas()
{
    set<string> s;
    map<string, Idioma *>::iterator it;
    for (it = ColIdiomas.begin(); it != ColIdiomas.end(); ++it)
    {
        Idioma *i = it->second;
        string d = i->getNombre();
        s.insert(d);
    }
    return s;
};

void CIdioma::selecIdioma(string idioma)
{
    if (existeIdioma(idioma))
    {
        MemNombre = idioma;
    }
    else
    {
        cout << "El idioma no está en el sistema" << endl;
    }
};

set<string > CIdioma::listarNoSuscriptos(string nickname)
{
    CUsuario *cu = &CUsuario::getInstance();
    if (!(cu->existeUsuario(nickname)))
    {
        return set<string >();
    }
    else
    {
        set<Idioma *> suscripciones = cu->listarIdiomasSuscriptos(nickname);
        set<string > s;
        map<string, Idioma *>::iterator it;
        for(it = ColIdiomas.begin(); it != ColIdiomas.end(); ++it){
            Idioma *i = it->second;
            if(suscripciones.find(i) == suscripciones.end()){
                string d = i->getNombre();
                s.insert(d);
            }
        }
        return s;
    }
};

void CIdioma::suscribirseANotificaciones(string nickname, string idioma)
{

    if (this->ColIdiomas == map<string, Idioma *>())
    {
        cout << "No hay idiomas en el sistema" << endl;
    }
    else
    {
        Idioma *i = ColIdiomas.find(idioma)->second;
        CUsuario *cu = &CUsuario::getInstance();
        if (!(i->estaSuscrito(nickname)) && (cu->existeUsuario(nickname)))
        {
            Usuario *u = cu->buscarUsuario(nickname);
            i->agregarObservador(u);
            u->linkObserver(i);
        }
        else
        {
            cout << "El usuario ya esta suscrito a este idioma" << endl;
        }
    }
    // para probar que se agrega correctamente a la lista
    // set<Idioma *> suscripciones = cu->listarIdiomasSuscriptos(nickname);
    // set<Idioma *>::iterator it;
    // for (it = suscripciones.begin(); it != suscripciones.end(); ++it)
    // {
    //     cout << "El usuario se ha suscrito a: " << (*it)->getNombre() << endl;
    // }
};

set<string> CIdioma::listarSuscripciones(string nickname)
{
    CUsuario *cu = &CUsuario::getInstance();
    if (!(cu->existeUsuario(nickname)))
    {
        cout << "El usuario no existe" << endl;
        return set<string>();
    }
    else
    {
        set<Idioma *> suscripciones = cu->listarIdiomasSuscriptos(nickname);
        set<string> s;
        map<string, Idioma *>::iterator it;
        for(it = ColIdiomas.begin(); it != ColIdiomas.end(); ++it){
            Idioma *i = it->second;
            if(suscripciones.find(i) != suscripciones.end()){
                string d = i->getNombre();
                s.insert(d);
            }
        }
        return s;
    }
};

void CIdioma::eliminarSuscripciones(string nickname, string idioma)
{
    Idioma *i = ColIdiomas.find(idioma)->second;
    CUsuario *cu = &CUsuario::getInstance();
    if (i->estaSuscrito(nickname) && cu->existeUsuario(nickname))
    {
        Usuario *u = cu->buscarUsuario(nickname);
        u->borrarDataPorIdioma(idioma);
        i->eliminarObservador(u);
        u->unlinkObserver(i);
    }
    else
    {
        cout << "El usuario no esta suscrito a este idioma" << endl;
    }
    // para probar que se elimina correctamente de la lista
    //  set<Idioma *> suscripciones = cu->listarIdiomasSuscriptos(nickname);
    //  set<Idioma *>::iterator it;
    //  for (it = suscripciones.begin(); it != suscripciones.end(); ++it)
    //  {
    //      cout << "El usuario se ha suscrito a: " << (*it)->getNombre() << endl;
    //  }
};

set<DataNotificacion> CIdioma::consultarNotificaciones(string nickname)
{
    CUsuario *cu = &CUsuario::getInstance();
    if (!(cu->existeUsuario(nickname)))
    {
        cout << "El usuario no existe" << endl;
        return set<DataNotificacion>();
    }
    Usuario *u = cu->buscarUsuario(nickname);
    set<DataNotificacion> notificaciones = u->leerNotificaciones();
    u->vaciarNotificaciones(nickname);
    return notificaciones;
};

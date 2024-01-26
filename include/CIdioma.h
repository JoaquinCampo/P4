#ifndef CIDIOMA_H
#define CIDIOMA_H

#include <string>

#include <map>

#include "Idioma.h"

#include "IAltaIdioma.h"
#include "IConsultarIdioma.h"
#include "ISuscribirseANotificaciones.h"
#include "IEliminarSuscripciones.h"
#include "IConsultarNotificaciones.h"

#include "CUsuario.h"


using namespace std;

class CIdioma : public IAltaIdioma, public IConsultarIdioma, public ISuscribirseANotificaciones, public IEliminarSuscripciones, public IConsultarNotificaciones
{
private:
    IAltaIdioma *crearIdioma;
    IConsultarIdioma *consultaI;
    static CIdioma *instanciaIdioma;
    CIdioma();
    string MemNombre; // Para uso de memoria
    map<string, Idioma *> ColIdiomas;

public:
    static CIdioma &getInstance();
    virtual ~CIdioma();
    bool existeIdioma(string nombre);
    set<string *> mostrarIdiomas();
    Idioma *encontrarIdioma(string nombre);
    string *getDataIdioma(string nombre);
    void selecIdioma(string idioma);

    // Metodo de IAltaIdioma
    bool ingresoDatos(string nombre) override;

    // Metodo de IConsultarIdioma
    set<string> listarIdiomas() override;

    // Metodo de ISuscribirseANotificaciones
    set<string> listarNoSuscriptos(string nickname) override;
    void suscribirseANotificaciones(string nickname, string idioma) override;

    // Metodo de IEliminarSuscripciones
    set<string> listarSuscripciones(string nickname) override;
    void eliminarSuscripciones(string nickname, string idioma) override;

    // Metodo de IConsultarNotificaciones
    set<DataNotificacion> consultarNotificaciones(string nickname) override;
};

#endif
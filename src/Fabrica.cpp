#include "Fabrica.h"

Fabrica::Fabrica(){};

IAgregarEjercicio *Fabrica::getIAgregarEjercicio()
{
    return CEjercicio::getInstance();
};

IAgregarLeccion *Fabrica::getIAgregarLeccion()
{
    return CLeccion::getInstance();
};

// IAltaIdioma *Fabrica::getIAltaIdioma()
// {
//     return IAltaIdioma::getInstance();
// };

IConsultarIdioma *Fabrica::getIConsultarIdioma()
{
    return &CIdioma::getInstance();
};

IEliminarCurso *Fabrica::getIEliminarCurso()
{
    return CCurso::getInstance();
};

IEliminarSuscripciones *Fabrica::getIEliminarSuscripciones()
{
    return &CIdioma::getInstance();
};

IHabilitarCurso *Fabrica::getIHabilitarCurso()
{
    return CCurso::getInstance();
};

IInscribirseACurso *Fabrica::getIInscribirseACurso()
{
    return CCurso::getInstance();
};

IRealizarEjercicio *Fabrica::getIRealizarEjercicio()
{
    return &CUsuario::getInstance();
};


IAltaCurso *Fabrica::getIAltaCurso()
{
    return CCurso::getInstance();
}

IConsultarCurso *Fabrica::getIConsultarCurso()
{
    return CCurso::getInstance();
}

IAltaUsuario *Fabrica::getIAltaUsuario()
{
    return &CUsuario::getInstance();
};

IConsultarUsuario *Fabrica::getIConsultarUsuario()
{
    return &CUsuario::getInstance();
};

IAltaIdioma *Fabrica::getIAltaIdioma()
{
    return &CIdioma::getInstance();
};

IConsultarNotificaciones * Fabrica::getIConsultarNotificaciones() {
    return &CIdioma::getInstance();
}

ISuscribirseANotificaciones * Fabrica::getISuscribirseANotificaciones() {
    return &CIdioma::getInstance();
}
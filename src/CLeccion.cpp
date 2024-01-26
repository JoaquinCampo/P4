#include "CLeccion.h"

using namespace std;

CLeccion *CLeccion::ControladorLeccion = nullptr;

CLeccion::CLeccion(){};

CLeccion::~CLeccion(){};

CLeccion *CLeccion::getInstance()
{
    if (ControladorLeccion == nullptr)
    {
        ControladorLeccion = new CLeccion();
    }
    return ControladorLeccion;
};

// iAltaCurso
void CLeccion::agregarLeccionAltaCurso(string nomLeccion, string nomCurso, string tema, string objetivo, int cantEjs, set<ejCompletar> comp, set<ejTraduccion> trad)
{
    CCurso *cc = CCurso::getInstance();
    l = new Leccion(nomLeccion, tema, objetivo, cantEjs);
    this->Lecciones.insert({nomLeccion, l});
    cc->LinkLeccion_Curso(l, nomCurso);

    CEjercicio *ce = CEjercicio::getInstance();
    Ejercicio *nuevoEjercicio;
    for (ejCompletar ej : comp)
    {
        nuevoEjercicio = ce->agregarEjercicioCompletar(ej.descripcionEjercicio, ej.frase, ej.solucion);
        l->agregarLink(nuevoEjercicio);
    };

    for (ejTraduccion ej : trad)
    {
        nuevoEjercicio = ce->agregarEjercicioTraduccion(ej.descripcionEjercicio, ej.frase, ej.fraseTraducida);
        l->agregarLink(nuevoEjercicio);
    };
};

// iAgregarLeccion
set<DataCurso *> CLeccion::listarCursosNoHabilitados()
{
    CCurso *cc = CCurso::getInstance();
    return cc->listarCursosNoHabilitados();
};

void CLeccion::agregarLeccionAL(string nomLeccion, string nomCurso, string tema, string objetivo, int cantEjercicios)
{
    l = new Leccion(nomLeccion, tema, objetivo, cantEjercicios);
    this->Lecciones.insert({nomLeccion, l});
    CCurso *cc = CCurso::getInstance();
    cc->LinkLeccion_Curso(l, nomCurso);
};

void CLeccion::agregarEjercicioAL(TipoEjercicio tipo, string descripcion)
{
    CEjercicio *ce = CEjercicio::getInstance();
    ce->agregarEjercicio(tipo, descripcion);
};

void CLeccion::ejCompletarAL(string nomCurso, string frase, string solucion)
{
    CEjercicio *ce = CEjercicio::getInstance();
    Ejercicio* nuevoEjercicio = ce->agregarEjCompletar(frase, solucion);
    l->agregarLink(nuevoEjercicio);

    int ejsTotales = l->getCantEjercicios() + 1;
    l->setCantEjercicios(ejsTotales);

    CCurso* cc = CCurso::getInstance();
    cc->ListoParaHabilitar(nomCurso);
};

void CLeccion::ejTraducirAL(string nomCurso, string frase, string solucion)
{
    CEjercicio *ce = CEjercicio::getInstance();
    Ejercicio* nuevoEjercicio = ce->agregarEjTraduccion(frase, solucion);
    l->agregarLink(nuevoEjercicio);

    int ejsTotales = l->getCantEjercicios() + 1;
    l->setCantEjercicios(ejsTotales);

    CCurso* cc = CCurso::getInstance();
    cc->ListoParaHabilitar(nomCurso);
};

void CLeccion::actualizarCantEjs(string nomLeccion, int ejsTotales)
{
    Leccion *l = this->Lecciones.find(nomLeccion)->second;
    l->setCantEjercicios(ejsTotales);
};


// iAgregarEjercicio
void CLeccion::linkEjercicio_Leccion(string nomLeccion, Ejercicio *ej)
{
    l = this->Lecciones.find(nomLeccion)->second;
    l->agregarLink(ej);
    int cant_ejs = l->getCantEjercicios() + 1;
    l->setCantEjercicios(cant_ejs);
};

void CLeccion::eliminarLeccion(string nomLeccion)
{
    Leccion *l = this->Lecciones.find(nomLeccion)->second;
    this->Lecciones.erase(nomLeccion);
    delete l;
};

bool CLeccion::existeLeccion(string nomLeccion, string nomCurso)
{
    CCurso *cc = CCurso::getInstance();
    return cc->existeLeccion(nomLeccion, nomCurso);
};
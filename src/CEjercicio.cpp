#include "CEjercicio.h"

using namespace std;

CEjercicio *CEjercicio::ControladorEjercicio = nullptr;

CEjercicio::CEjercicio(){};

CEjercicio *CEjercicio::getInstance()
{
    if (ControladorEjercicio == nullptr)
    {
        ControladorEjercicio = new CEjercicio();
    }
    return ControladorEjercicio;
};

void CEjercicio::setTipo(TipoEjercicio tipo)
{
    this->tipo = tipo;
};

TipoEjercicio CEjercicio::getTipo()
{
    return this->tipo;
};

void CEjercicio::setnomLeccion(string nomLeccion)
{
    this->nomLeccion = nomLeccion;
};

string CEjercicio::getnomLeccion()
{
    return this->nomLeccion;
};

void CEjercicio::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
};

string CEjercicio::getDescripcion()
{
    return this->descripcion;
};
void CEjercicio::setNomCurso(string nomCurso)
{
    this->nomCurso = nomCurso;
}
string CEjercicio::getNomCurso()
{
    return this->nomCurso;
}

void CEjercicio::ingresarEjercicio(string nomLeccion, TipoEjercicio tipo, string descripcion)
{
    setnomLeccion(nomLeccion);
    setTipo(tipo);
    setDescripcion(descripcion);
};

void CEjercicio::ejTraduccion(string palabra, string solucion)
{
    string descripcion = getDescripcion();
    TipoEjercicio tipo = getTipo();
    Ejercicio *ej = new traduccion(tipo, descripcion, palabra, solucion);
    ejercicios.push_back(ej);
    string nomLecc = getnomLeccion();
    CLeccion *cl =CLeccion::getInstance();
    cl->linkEjercicio_Leccion(nomLecc, ej);
    string nomCurso = getNomCurso();
    CCurso *CC = CCurso::getInstance();
    Curso *C = CC->getCurso(nomCurso);
    int cant = C->getCantEjercicios();
    C->setCantEjercicios(cant + 1);
    CC->ListoParaHabilitar(nomCurso);
};

void CEjercicio::ejCompletar(string frase, string solucion)
{
    string descripcion = getDescripcion();
    TipoEjercicio tipo = getTipo();
    Ejercicio *ej = new completar(tipo, descripcion, frase, solucion);
    ejercicios.push_back(ej);
    string nomLecc = getnomLeccion();
    CLeccion *cl =CLeccion::getInstance();
    cl->linkEjercicio_Leccion(nomLecc, ej);
    string nomCurso = getNomCurso();
    CCurso *CC = CCurso::getInstance();
    Curso *C = CC->getCurso(nomCurso);
    int cant = C->getCantEjercicios() + 1;
    C->setCantEjercicios(cant);
    CC->ListoParaHabilitar(nomCurso);
};

void CEjercicio::agregarEjercicio(TipoEjercicio tipo, string descripcion)
{
    setTipo(tipo);
    setDescripcion(descripcion);
};

Ejercicio *CEjercicio::agregarEjCompletar(string frase, string solucion)
{
    TipoEjercicio tipo = getTipo();
    string descripcion = getDescripcion();
    Ejercicio *ej = new completar(tipo, descripcion, frase, solucion);
    ejercicios.push_back(ej);
    string nomCurso=getNomCurso();
    CCurso *CC=CCurso::getInstance();
    Curso* C=CC->getCurso(nomCurso);
    C->setCantEjercicios(C->getCantEjercicios()+1);
    return ej;
};

Ejercicio *CEjercicio::agregarEjTraduccion(string frase, string solucion)
{
    TipoEjercicio tipo = getTipo();
    string descripcion = getDescripcion();
    Ejercicio *ej = new traduccion(tipo, descripcion, frase, solucion);
    ejercicios.push_back(ej);
    string nomCurso=getNomCurso();
    CCurso *CC=CCurso::getInstance();
    Curso* C=CC->getCurso(nomCurso);
    C->setCantEjercicios(C->getCantEjercicios()+1);
    return ej;
};

set<DataCurso *> CEjercicio::listarCursosNoHabilitados_CCurso()
{
    CCurso *cc = this->ControladorCurso->getInstance();
    set<DataCurso *> res = cc->listarCursosNoHabilitados();
    return res;
}

set<DataLeccion *> CEjercicio::listarLeccion_CCurso(string nombreCurso)
{
    setNomCurso(nombreCurso);
    CCurso *cc = CCurso::getInstance();
    return cc->listarLecciones(nombreCurso);
}

Ejercicio *CEjercicio::agregarEjercicioCompletar(string descripcion, string frase, string solucion)
{
    TipoEjercicio tipo = Completar;
    Ejercicio *ej = new completar(tipo, descripcion, frase, solucion);
    this->ejercicios.push_back(ej);
    string nomCurso = getNomCurso();
    CCurso *CC = CCurso::getInstance();
    Curso *C = CC->getCurso(nomCurso);
    C->setCantEjercicios(C->getCantEjercicios() + 1);
    return ej;
}

Ejercicio *CEjercicio::agregarEjercicioTraduccion(string descripcion, string frase, string solucion)
{
    TipoEjercicio tipo = Traduccion;
    Ejercicio *ej = new traduccion(tipo, descripcion, frase, solucion);
    this->ejercicios.push_back(ej);
    string nomCurso = getNomCurso();
    CCurso *CC = CCurso::getInstance();
    Curso *C = CC->getCurso(nomCurso);
    C->setCantEjercicios(C->getCantEjercicios() + 1);
    return ej;
}
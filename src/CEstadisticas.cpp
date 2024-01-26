#include "CEstadisticas.h"
#include <iterator>

CEstadisticas::CEstadisticas(){};

set<string> CEstadisticas::listarEstudiantes()
{
    CUsuario *cu = &CUsuario::getInstance();
    return cu->getEstudiantes();
}

set<DataInfoEstudiante *> CEstadisticas::listarCurso_y_Avance(string nickname)
{
    CUsuario *cu = &CUsuario::getInstance();
    set<DataInfoEstudiante *> res;
    map<string, int> cursosInscripto = cu->consultarInfoEstudiante(nickname);
    map<string, int>::iterator it;
    CCurso *cc = CCurso::getInstance();
    for (auto it = cursosInscripto.begin(); it != cursosInscripto.end(); ++it)
    {
        float progreso;
        if (cc->getCurso(it->first)->getCantEjercicios() == 0)
            progreso = 0;
        else
            progreso = 100 * static_cast<float>(it->second) / static_cast<float>(cc->getCurso(it->first)->getCantEjercicios());
        DataInfoEstudiante *dataInfo = new DataInfoEstudiante(it->first, progreso);
        res.insert(dataInfo);
    }
    return res;
}

set<string> CEstadisticas::listarProfesores()
{
    CUsuario *cu = &CUsuario::getInstance();
    return cu->getProfesores();
}

set<DataInfoProfesor *> CEstadisticas::listarInfoProfe(string profesor)
{
    CUsuario *cu = &CUsuario::getInstance();
    set<DataInfoProfesor *> res;
    set<Curso *> cursosPropuestos = cu->consultarInfoProfesor(profesor);
    for (Curso *aux : cursosPropuestos)
    {
        int ejsRealizadosTotales = 0;
        for (Estudiante *est : aux->getEstudiantes_inscriptos())
            ejsRealizadosTotales += est->getCantEjerciciosAprobados(aux->getNombre());

        float promedio;
        if (aux->getCantEjercicios() == 0)
            promedio = 0;
        else {
            int cantEstudiantes = aux->getEstudiantes_inscriptos().size();
            promedio = 100 * static_cast<float>(ejsRealizadosTotales) / (static_cast<float>(aux->getCantEjercicios()) * static_cast<float>(cantEstudiantes));
        }

        DataInfoProfesor *dataInfo = new DataInfoProfesor(aux->getNombre(), promedio);
        res.insert(dataInfo);
    }
    return res;
}

set<string> CEstadisticas::listarCursos()
{
    CCurso *cc = CCurso::getInstance();
    return cc->listarNomCursos();
}

DataCurso *CEstadisticas::listarInfoCurso(string curso)
{
    CCurso *cc = CCurso::getInstance();
    Curso * c = cc->getCurso(curso);
    int ejsRealizadosTotales = 0;
    int cantEstudiantes = c->getEstudiantes_inscriptos().size();
    for (Estudiante *est : c->getEstudiantes_inscriptos())
        ejsRealizadosTotales += est->getCantEjerciciosAprobados(c->getNombre());

    float promedio;
    if (c->getCantEjercicios() == 0)
        promedio = 0;
    else
        promedio = 100 * static_cast<float>(ejsRealizadosTotales) / (static_cast<float>(c->getCantEjercicios()) * static_cast<float>(cantEstudiantes));
    c->actualizarPromedioCurso(promedio);
    return cc->listarInfoCurso(curso);
}
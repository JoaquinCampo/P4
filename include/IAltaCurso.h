#ifndef IALTACURSO_H
#define IALTACURSO_H

#include "Estructuras.h"

#include "DataUsuario.h"
#include "DataCurso.h"
#include "DataProfesorGeneral.h"

using namespace std;

class IAltaCurso
{
public:
    virtual set<DataProfesorGeneral *> listar_nicknames_profesores() = 0;
    virtual set<string> listar_especialidades_profesor(string) = 0;
    virtual set<DataCurso *> listar_cursos_habilitados() = 0;
    virtual ejCompletar crear_estructura_ej_completar(string, string, string, string) = 0;
    virtual ejTraduccion crear_estructura_ej_traduccion(string, string, string, string) = 0;
    virtual void alta_curso() = 0;
    virtual bool hay_idiomas() = 0;
    virtual bool existeLeccion(string nomLeccion, string nombreCurso) = 0;

    virtual void RecordarNicknameProfesor(string nickname) = 0;
    virtual void RecordarNombreCurso(string nombreCurso) = 0;
    virtual void RecordarDescripcion(string descripcion) = 0;
    virtual void RecordarDificultad(string dificultad) = 0;
    virtual void RecordarIdioma(string idioma) = 0;
    virtual void RecordarLecciones(set<leccion_con_ejs> lecciones) = 0;
    virtual void RecordarCursosPrevios(set<string> cursosPrevios) = 0;


};

#endif

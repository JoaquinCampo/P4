#ifndef CCURSO_H
#define CCURSO_H

class CLeccion;
class CUsuario;

#include <iostream>
#include <map>
#include <list>

#include "IAltaCurso.h"
#include "IConsultarCurso.h"
#include "IInscribirseACurso.h"
#include "IHabilitarCurso.h"
#include "IEliminarCurso.h"

#include "CLeccion.h"
#include "CUsuario.h"
#include "CIdioma.h"

#include "Curso.h"
#include "Leccion.h"
#include "Idioma.h"
#include "Usuario.h"
#include "Estudiante.h"
#include "Profesor.h"

#include "DataEjercicio.h"
#include "DataCurso.h"
#include "DataUsuario.h"
#include "dataInfoCurso.h"
#include "DataNotificacion.h"

using namespace std;

class CCurso : public IAltaCurso, public IConsultarCurso, public IInscribirseACurso, public IHabilitarCurso, public IEliminarCurso
{
private:
    static CCurso *ControladorCurso;
    CCurso();

    set<Curso *> cursos;
    set<Curso *> cursos_habilitados;
    set<Curso *> cursos_no_habilitados;
    set<Curso *> cursos_habilitables;

    map<string, set<Curso *>> cursos_aprobados;          // clave: nickname estudiante
    map<string, set<Estudiante *>> estudiantes_anotados; // clave: nombre curso

    // Recuerda
    string Rnickname;
    Fecha RFechaInscripcion;
    string RnicknameProfesor;
    string RnombreCurso;
    string Rdescripcion;
    string Rdificultad;
    string Ridioma;
    set<leccion_con_ejs> Rlecciones;
    set<string> RcursosPrevios;

public:
    static CCurso *getInstance();
    Curso *getCurso(string); // hecho

    set<Curso *> getCursos_habilitados();                                                                       // hecho
    void crearCurso(string, string, Dificultad, int, int, Idioma *, Profesor *, list<Leccion *>, set<Curso *>); // hecho
    void selecCursoPrevio(set<string>, Curso *);                                                                // hecho
    set<DataCurso *> listarCursosHabilitados();                                                                 // hecho
    set<DataCurso *> listarCursosNoHabilitados();                                                               // hecho
    // set<DataEjercicio *> listarEjsPendientes(string, Estudiante *);                                             // hecho
    DataCurso *listarInfoCurso(string);                                                                         // hecho
    void LinkLeccion_Curso(Leccion *, string);                                                                  // hecho
    void addEstudiantes_anotados(string nickname, string nombreCurso);                                          // hecho
    void removeEstudiantes_anotados(string nickname, string nombreCurso);                                       // hecho
    set<Curso *> getCursos_habilitables();
    set<string> listarNomCursos();

    // interfaz iAltaCurso
    set<DataProfesorGeneral *> listar_nicknames_profesores();                    // hecho
    set<string> listar_especialidades_profesor(string);                          // hecho
    set<DataCurso *> listar_cursos_habilitados();                                // hecho
    ejCompletar crear_estructura_ej_completar(string, string, string, string);   // hecho
    ejTraduccion crear_estructura_ej_traduccion(string, string, string, string); // hecho
    bool hay_idiomas();                                                          // hecho
    void linkIdiomaCurso(string idioma, string nomCurso);                        // hecho
    void RecordarNicknameProfesor(string nickname);
    void RecordarNombreCurso(string nombreCurso);
    void RecordarDescripcion(string descripcion);
    void RecordarDificultad(string dificultad);
    void RecordarIdioma(string idioma);
    void RecordarLecciones(set<leccion_con_ejs> lecciones);
    void RecordarCursosPrevios(set<string> cursosPrevios);
    void alta_curso(); // hecho
    bool existeLeccion(string nomLeccion, string nombreCurso);

    // interfaz IConsultarCurso
    set<DataCurso *> listarCursos();             // hecho
    bool existe_Curso(string nombreCurso);       // hecho
    int getCantLecciones(string);                // hecho
    set<DataLeccion *> getLecciones(string);     // hecho
    set<DataEstudiante *> getInscriptos(string); // hecho
    Fecha getFechaInscripcion(string, string);   // hecho
    DataCurso *obtenerCurso(string);             // hecho

    // Interfaz IAgregarEjercicio
    set<DataLeccion *> listarLecciones(string);

    // Interfaz IInscribirseACurso
    set<DataCurso *> listarCursos_Disponibles(string); // hecho
    bool existe_usuario(string);                       // hecho
    void inscribirseACurso();                          // hecho
    set<Curso *> getCursos_aprobados(string nickname); // hecho
    bool existe_cursoII(string nombreCurso);           // hecho
    bool es_profesor(string nickname);                 // hecho
    void RecordarNickname(string);
    void RecordarFechaInscripcion(Fecha);

    // Interfaz IHabilitarCurso
    set<DataCurso *> listarCursosHabilitables(); // hecho
    void habilitarCurso();                       // hecho

    // interfaz IAltaCurso para observer
    void enlazarCursoIdioma(string nomCurso, string Idioma); // hecho
    void notificarCreacion(string nomCurso, string Idioma);  // hecho

    // interfaz IEliminarCurso
    set<string> mostrarCursos(); // hecho
    void eliminarCurso();        // hecho

    // interfaz IAgragarLeccion
    void ListoParaHabilitar(string nombreCurso); // hecho

    // interfaz IRealizarEjercicio
    vector<Ejercicio *> EjerciciosDe(string nombreCurso, int leccion); // hecho

    // interfaz IAgregarEjercicio
    void Chequear_Hab(string nomCurso);
};

#endif

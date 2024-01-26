#ifndef Curso_h
#define Curso_h

class Profesor;
class Estudiante;

#include <set>
#include <map>
#include <list>
#include <string>
#include "Leccion.h"
#include "Idioma.h"
#include "Usuario.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "DataEjercicio.h"
#include "DataCurso.h"
#include "dataInfoCurso.h"
#include "DataEjercicio.h"
#include "Estructuras.h"
#include <ctime>


using namespace std;

class Curso
{
private:
    string Nombre;
    string Descripcion;
    Dificultad Complejidad;
    int CantLecciones;
    int CantEjercicios;

    bool Habilitado;
    float Promedio;

    Idioma *idiomaC;
    Profesor *profesorC;
    list<Leccion *> Lecciones;
    int leccionActual;

    set<Curso *> cursos_previos;

    map<string, Fecha> inscripciones; // se busca la inscripcion de un alumno mediante su nombre
    map<string, float> progreso_estudiantes;
    set<Estudiante *> estudiantes_Inscriptos;

public:
    Curso(string, string, Dificultad, int, int, Idioma *, Profesor *, set<Curso *>);
    ~Curso();

    string getNombre();
    string getDescripcion();
    Dificultad getComplejidad();
    int getCantLecciones();
    int getCantEjercicios();

    bool getHabilitado();
    int getPromedio();
    float getPromedioEstudiante(Estudiante *);

    Idioma *getIdiomaC();
    Profesor *getProfesorC();
    list<Leccion *> getLecciones();
    set<Curso *> getCursos_previos();
    map<string, Fecha> getInscripciones();
    map<string, float> getProgreso_estudiantes();
    set<Estudiante *> getEstudiantes_inscriptos();
    int getLeccionActual();

    void setNombre(string);
    void setDescripcion(string);
    void setComplejidad(Dificultad);
    void setCantLecciones(int);
    void setCantEjercicios(int);

    void setHabilitado(bool);
    void actualizarPromedio(Estudiante *);
    void actualizarPromedioCurso(float promedio);
    void setLeccionActual(int);

    void setIdiomaC(Idioma *);
    void setProfesorC(Profesor *);
    void setLecciones(list<Leccion *>);
    void setCursos_previos(set<Curso *>);

    void addInscripcion(Estudiante *, Fecha);

    DataCurso *crearDataCurso();
    set<DataEjercicio *> getEjsNoAprobados(Estudiante *);
    void addLeccion(Leccion *);
};

#endif
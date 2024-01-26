#include "Curso.h"

using namespace std;

Curso ::Curso(string nombre, string Descripcion, Dificultad Complejidad, int CantLecciones, int cantEjericios, Idioma *idiomaC, Profesor *profesorC, set<Curso *> cursos_previos)
{
    setNombre(nombre);
    setDescripcion(Descripcion);
    setComplejidad(Complejidad);
    setCantLecciones(CantLecciones);
    setCantEjercicios(cantEjericios);
    setHabilitado(false);
    this->Promedio = 0;
    setIdiomaC(idiomaC);
    setProfesorC(profesorC);
    setCursos_previos(cursos_previos);
    this-> leccionActual = 0;
}

Curso ::~Curso()
{
    setIdiomaC(nullptr);
    setProfesorC(nullptr);
    this->Lecciones.clear();
    this->cursos_previos.clear();
    this->inscripciones.clear();
    this->progreso_estudiantes.clear();
    this->estudiantes_Inscriptos.clear();
}

string Curso ::getNombre()
{
    return this->Nombre;
}

string Curso ::getDescripcion()
{
    return this->Descripcion;
}

Dificultad Curso ::getComplejidad()
{
    return this->Complejidad;
}

int Curso ::getCantLecciones()
{
    return this->CantLecciones;
}

int Curso ::getCantEjercicios()
{
    return this->CantEjercicios;
}

bool Curso ::getHabilitado()
{
    return this->Habilitado;
}

int Curso ::getPromedio()
{
    return this->Promedio;
}

float Curso ::getPromedioEstudiante(Estudiante *est)
{
    return this->progreso_estudiantes[est->getNombre()];
}

Idioma *Curso ::getIdiomaC()
{
    return this->idiomaC;
}

Profesor *Curso ::getProfesorC()
{
    return this->profesorC;
}

list<Leccion *> Curso ::getLecciones()
{
    return this->Lecciones;
}

set<Curso *> Curso ::getCursos_previos()
{
    return this->cursos_previos;
}

map<string, Fecha> Curso ::getInscripciones()
{
    return this->inscripciones;
}

map<string, float> Curso ::getProgreso_estudiantes()
{
    return this->progreso_estudiantes;
}

set<Estudiante *> Curso ::getEstudiantes_inscriptos()
{
    return this->estudiantes_Inscriptos;
}

void Curso ::setNombre(string name)
{
    this->Nombre = name;
}

void Curso ::setDescripcion(string desc)
{
    this->Descripcion = desc;
}

void Curso ::setComplejidad(Dificultad difi)
{
    this->Complejidad = difi;
}

void Curso ::setCantLecciones(int cantLec)
{
    this->CantLecciones = cantLec;
}

void Curso ::setCantEjercicios(int cantEj)
{
    this->CantEjercicios = cantEj;
}

void Curso ::setHabilitado(bool hab)
{
    this->Habilitado = hab;
}

void Curso ::actualizarPromedio(Estudiante *)
{
    // hacer
}

void Curso ::actualizarPromedioCurso(float promedio)
{
    this-> Promedio = promedio;
}

void Curso ::setIdiomaC(Idioma *idioma)
{
    this->idiomaC = idioma;
}

void Curso ::setProfesorC(Profesor *profe)
{
    this->profesorC = profe;
}

void Curso ::setLecciones(list<Leccion *> lecc)
{
    this->Lecciones = lecc;
}

void Curso::setLeccionActual(int lec) {
    this-> leccionActual = lec;
}

int Curso::getLeccionActual() {
    return this->leccionActual;
}

void Curso ::setCursos_previos(set<Curso *> cursos)
{
    for (auto it = cursos.begin(); it != cursos.end(); ++it)
    {
        this->cursos_previos.insert(*it);
    }
}

void Curso ::addInscripcion(Estudiante *est, Fecha fec)
{
    this-> inscripciones.insert(pair<string, Fecha>(est->getNombre(), fec));
    this-> estudiantes_Inscriptos.insert(est);
    this-> progreso_estudiantes.insert(pair<string, int>(est->getNombre(), 0));
}

set<DataEjercicio *> Curso ::getEjsNoAprobados(Estudiante *est)
{
    set<DataEjercicio *> res;
    // for (auto it = this-> Lecciones.begin(); it != this-> Lecciones.end(); ++it) {
    //     if ((*it)->progreso(est) != 1) {
    //         set<DataEjercicio *> aux = (*it)-> getEjerciciosIncompletos(est);
    //         for (auto it2 = aux.begin(); it2 != aux.end(); ++it2) {
    //             res.insert(*it2);
    //         }
    //     }
    // }
    return res;
}

void Curso ::addLeccion(Leccion *lec)
{
    this->Lecciones.push_back(lec);
}

DataCurso *Curso::crearDataCurso()
{
    DataCurso *res = new DataCurso(this->Nombre, this->Descripcion, this->Complejidad, this->CantLecciones, this->Habilitado, this->Promedio, this->idiomaC->getNombre(), this->profesorC->getNombre());
    return res;
}
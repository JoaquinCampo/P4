#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
//class Curso;
#include "Usuario.h"
#include <string>
#include <map>
#include <vector>
#include "Estructuras.h"
//#include "Ejercicio.h"
#include "Curso.h"
#include <list>

class Estudiante : public Usuario
{
private:
    std::string pais;
    Fecha fechaNacimiento;

 //Info realizar ejercicio
    vector< Curso *>misCursos;
    map<string, std::vector<Ejercicio *>> EjerciciosPendientes;
    map<string, int> LeccionActual;
    map<string, int> CantEjerciciosAprobados;



public:
    Estudiante(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion, std::string pais, Fecha fechaNacimiento);
    ~Estudiante();

    std::string getPais();
    Fecha getFechaNacimiento();

    void setPais(std::string pais);
    void setFechaNacimiento(Fecha fechaNacimiento);

    // Funciones ConsultarEstadisticas
    map<string, int> getCantEjerciciosAprobados();
    int getCantEjerciciosAprobados(string nomCurso);

    // Funciones IEliminarCurso
    void quitarEjerciciosAprobados_curso(string nomCurso);

    // *Funciones IInscribirseACurso
    void agregarEjerciciosAprobados_curso(Curso *Curso);

    // set<DataCursos> listarCursosNoAprobados(std::string nickname);
    // void eliminarAvance(std::string e);
    // set(dataEjercicio) listarEjerciciosPendientes(std::string nomCurso);
    // DataCurso getCursos();
    // DataEjercicio listarEjercicio();
    // DataEstudiante crearData();
    // set(DatainfoEstudiante) listarInfoCursos();

    // void notificar(DataNotificacion notificacion) override;
    // set<DataNotif> leerNotificaciones() override;
    //Funciones realizar Ejercicio
    vector<Curso *> getMisCursos();
    set<string> listarCursosNoAprobados(std::string nickname);
    vector<Ejercicio*> getEjericiosPendientes(string nomCurso);
    bool marcarAprobado(Estudiante *est,string nomCurso ,int numEj);
    int getLeccionActual(string nomCurso);
    void setLeccionActual(string nomCurso,int l);
    void SetEjerciciosPendientes(string nomCurso,vector<Ejercicio*> pendientes);
    void terminar(string nomCurso);
    void inscribirse(string nomCurso);

    // interfaz IEliminarCurso
    void quitarMisCursos(Curso *C);
};

#endif

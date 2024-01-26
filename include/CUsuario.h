#ifndef CUSUARIO_H_
#define CUSUARIO_H_

class CCurso;

#include <string>
#include <set>
#include "vector"
#include <list>

#include "iAltaUsuario.h"
#include "IConsultarUsuario.h"
#include "IRealizarEjercicio.h"

#include "Usuario.h"
#include "Estudiante.h"
#include "Curso.h"
#include "CCurso.h"

#include "DataUsuario.h"
#include "Profesor.h"
#include "DataProfesorGeneral.h"

class CUsuario : public IAltaUsuario, public IConsultarUsuario, public IRealizarEjercicio
{
private:
    CUsuario();

    // Recuerda
    std::string Rnombre;
    std::string Rnickname;
    std::string Rcontrasenia;
    std::string Rdescripcion;
    std::string Rinstituto;
    set<string> Ridiomas;
    // Realizar Ejercicio
    Estudiante *estudiante;
    string nomCurso;
    Ejercicio *ejer;
    int numEj;
    DataEjercicio *DT;

    // hasta aca

    std::list<Usuario *> Usuarios;
    std::list<Estudiante *> Estudiantes;
    std::list<Profesor *> Profesores;
    static CUsuario *instanciaUsuario;

public:
    static CUsuario &getInstance();
    std::string getNombre();
    std::string getNickname();
    std::string getContrasenia();
    std::string getDescripcion();
    std::string getInstituto();
    set<Idioma *> linkearIdiomas();
    ~CUsuario();

    // funciones de la interfaz

    void ingresarDatos(std::string nombre, std::string nickname, std::string contrasena, std::string descripcion) override;
    bool ingresoEstudiante(std::string pais, Fecha fechaNacimiento) override;
    set<string *> ingresoInstituto(std::string instituto) override;
    DataEstudiante *consultarEstudiante(std::string nickname) override;
    DataProfesor *consultarProfesor(std::string nickname) override;
    bool ingresoProfesor() override;
    bool ingresoIdioma(std::string idioma) override;
    bool existeProfesor(std::string nickname) override;
    bool existeEstudiante(std::string nickname) override;
    bool existeIdioma(std::string idioma) override;

    Estudiante *buscarEstudiante(std::string nickname);
    Profesor *buscarProfesor(std::string nickname);
    set<string> getProfe(string nombre);
    set<DataProfesorGeneral *> mostrarProfesores();
    bool existeUsuario(std::string nickname) override;
    bool existeIdiomaIngresado() override;
    set<string> mostrarEstudiantesS() override;
    set<string> mostrarProfesoresS();
    bool existenUsuarios() override;

    // funciones Consultar Estadisticas
    set<std::string> getEstudiantes();
    set<std::string> getProfesores();
    map<std::string, int> consultarInfoEstudiante(string nickname);
    set<Curso *> consultarInfoProfesor(string nickname);

    set<Idioma *> listarIdiomasSuscriptos(string nickname);
    Usuario *buscarUsuario(std::string nickname);

    // funciones Realizar Ejercio
    Estudiante *getEstudiante();
    Ejercicio *getEjercicio();
    string getNomcurso();
    int getNumEj();
    void setNumEj(int numEj);
    vector<string> listarCursosNoAprobados(string nickname);
    vector<DataEjercicio*> listarEjsPendientes(string nomCurso);
    DataEjercicio *presentarProblema(int Ejercicio);
    bool CompararSoluciones(string solucion);
};

#endif

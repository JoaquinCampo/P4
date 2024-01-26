#ifndef CEjercicio_h
#define CEjercicio_h

// class CLeccion;
class CCurso;


#include "IAgregarEjercicio.h"

#include "CLeccion.h"
#include "CCurso.h"
#include <string>

#include "traduccion.h"
#include "completar.h"
#include "Ejercicio.h"

#include "DataEjercicio.h"

#include <vector>
using namespace std;

class CEjercicio : public IAgregarEjercicio
{
private:
    static CEjercicio *ControladorEjercicio;
    vector<Ejercicio *> ejercicios;
    
    CEjercicio();
    // recuerda
    TipoEjercicio tipo;
    string descripcion;
    string nomLeccion;
    string nomCurso;

    CCurso * ControladorCurso;
    CLeccion *ControladorLeccion;

public:
    static CEjercicio* getInstance();
    void setTipo(TipoEjercicio);
    TipoEjercicio getTipo();
    void setDescripcion(string);
    string getDescripcion();
    void setnomLeccion(string);
    string getnomLeccion();
    void setNomCurso(string);
    string getNomCurso();

    // funciones IAgregarEjercicio
    set<DataCurso *> listarCursosNoHabilitados_CCurso();
    set<DataLeccion *> listarLeccion_CCurso(string);
    void ingresarEjercicio(string, TipoEjercicio, string);
    void ejCompletar(string, string);
    void ejTraduccion(string, string);

    //funciones IAltaUsuario
    void agregarEjercicio(TipoEjercicio,string);
    Ejercicio* agregarEjCompletar(string,string);
    Ejercicio* agregarEjTraduccion(string,string);

    // funciones IAltaCurso
    Ejercicio * agregarEjercicioCompletar(string, string, string);
    Ejercicio * agregarEjercicioTraduccion(string, string, string);

/*
DataEjercicio presentarProblema(string);
void solucionTradu(string solEstudiante);
void solucionCompletar(string solEstudiante);
// void eliminarAvance(ejercicio*);
*/};
#endif

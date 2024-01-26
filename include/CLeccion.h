#ifndef CLeccion_h
#define CLeccion_h

class CCurso;
class CEjercicio;
#include <string>
#include <set>
#include <map>
#include <iterator>
#include "Leccion.h"
#include "CCurso.h"
#include "CEjercicio.h"
#include "DataLeccion.h"
#include "DataCurso.h"
#include "IAgregarLeccion.h"
#include "Estructuras.h"

using namespace std;

class CLeccion : public IAgregarLeccion
{
private:
    static CLeccion *ControladorLeccion;
    map<string, Leccion *> Lecciones; //clave : nombre de la leccion

    set<Leccion *> leccsAAgregar;

    CLeccion();
    ~CLeccion();

    // atributos para memoria

    Leccion *l;
    Ejercicio *ej;

    //string nomCurso;
    string tema;
    string objetivo;
    int cantEjercicios;

    TipoEjercicio tipo;
    string descripcion;

    string frase;
    string solucion;

public:
    static CLeccion *getInstance();

    void agregarLink(Ejercicio*);

    // iAltaCurso
    void agregarLeccionAltaCurso(string, string, string, string, int, set<ejCompletar>, set<ejTraduccion>);

    // iAgregarLeccion
    set<DataCurso *> listarCursosNoHabilitados() override;
    void agregarLeccionAL(string, string, string, string, int) override;
    void agregarEjercicioAL(TipoEjercicio, string) override;
    void ejCompletarAL(string, string, string);
    void ejTraducirAL(string, string, string);
    void actualizarCantEjs(string, int);
    bool existeLeccion(string, string);

    // iAgregarEjercicio
    void linkEjercicio_Leccion(string, Ejercicio *);

    // iEliminarCurso
    void eliminarLeccion(string);
};

#endif
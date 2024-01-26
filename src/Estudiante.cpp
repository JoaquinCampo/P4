#include "Estudiante.h"
#include "Leccion.h"
#include <list>
Estudiante::Estudiante(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion, std::string pais, Fecha fechaNacimiento) : Usuario(nombre, nickname, contrasenia, descripcion)
{
    setPais(pais);
    setFechaNacimiento(fechaNacimiento);
    this-> misCursos = vector<Curso*>();
};

Estudiante::~Estudiante(){};

std::string Estudiante::getPais()
{
    return this->pais;
};

Fecha Estudiante::getFechaNacimiento()
{
    return this->fechaNacimiento;
};

void Estudiante::setPais(std::string pais)
{
    this->pais = pais;
};

void Estudiante::setFechaNacimiento(Fecha fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
};

map<string, int>Estudiante::getCantEjerciciosAprobados(){
    return this->CantEjerciciosAprobados;
}

int Estudiante::getCantEjerciciosAprobados(string nomCurso){
    return this->CantEjerciciosAprobados[nomCurso];
}
void Estudiante::quitarEjerciciosAprobados_curso(string nomCurso){
    this->CantEjerciciosAprobados.erase(nomCurso);
}

void Estudiante::agregarEjerciciosAprobados_curso(Curso *C) {
    string nomCurso=C->getNombre();
    this->CantEjerciciosAprobados.insert(pair<string, int>(nomCurso, 0));
    this->misCursos.push_back(C);
    this->LeccionActual[nomCurso]=0;
    list<Leccion *> listLecc= C->getLecciones();
    Leccion *L=*listLecc.begin();
    // if (L-> getNombreLeccion() == "L1") {
    //     cout << "L1" << endl;
    //     cout << L-> getEjercicios().size() << endl;
    //     cout << L-> getCantEjercicios() << endl;
    // }
    this->EjerciciosPendientes[nomCurso]=L->getEjercicios();
}


// set<DataCursos> listarCursosNoAprobados(std::string nickname);
// void eliminarAvance(std::string e);
// set(dataEjercicio) listarEjerciciosPendientes(std::string nomCurso);
// DataCurso getCursos();
// DataEjercicio listarEjercicio();
// DataEstudiante crearData();
// set(DatainfoEstudiante) listarInfoCursos();

// void notificar(DataNotificacion notificacion) override;
// set<DataNotif> leerNotificaciones() override;

vector<Ejercicio*> Estudiante::getEjericiosPendientes(string nomCurso){
    return this->EjerciciosPendientes[nomCurso];
}
vector<Curso *> Estudiante::getMisCursos(){
    return this->misCursos;
}
bool Estudiante::marcarAprobado(Estudiante* est, string nomCurso, int numEj) {
   this->CantEjerciciosAprobados[nomCurso]++;
    auto it = est->EjerciciosPendientes.find(nomCurso);
    if (it != est->EjerciciosPendientes.end()) {
        vector<Ejercicio*>& ejercicios = it->second;
        int tam=ejercicios.size();
        if (numEj >= 0 && numEj <tam ) {
            ejercicios.erase(ejercicios.begin() + numEj);
        }
        return ejercicios.empty();
    }
    return false;
}

int Estudiante::getLeccionActual(string nomCurso){
    return this->LeccionActual[nomCurso];
}
void Estudiante::setLeccionActual(string nomCurso,int l){
    this->LeccionActual[nomCurso]=l;
}
void Estudiante::SetEjerciciosPendientes(string nomCurso,vector<Ejercicio*> pendientes){
    this->EjerciciosPendientes[nomCurso] = pendientes;
}

void Estudiante::terminar(string nomCurso){
    this->LeccionActual.erase(nomCurso);
    this->EjerciciosPendientes.erase(nomCurso);
}

void Estudiante::quitarMisCursos(Curso *C){
     for (auto it = misCursos.begin(); it != misCursos.end(); ++it) {
        if (*it == C) {
            misCursos.erase(it);
            break;
        }
    }
}
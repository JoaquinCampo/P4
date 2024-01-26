#include "CUsuario.h"
#include "DataEstudiante.h"
#include "DataProfesor.h"
#include "CIdioma.h"

CUsuario::CUsuario()
{
    this->Rnombre = "";
    this->Rnickname = "";
    this->Rcontrasenia = "";
    this->Rdescripcion = "";
    this->Rinstituto = "";
    this->Usuarios = std::list<Usuario *>();
    this->Estudiantes = std::list<Estudiante *>();
    this->Profesores = std::list<Profesor *>();
};

CUsuario *CUsuario::instanciaUsuario = nullptr;

CUsuario &CUsuario::getInstance()
{
    if (instanciaUsuario == nullptr)
    {
        instanciaUsuario = new CUsuario();
    }
    return *instanciaUsuario;
};

void CUsuario::ingresarDatos(std::string nombre, std::string nickname, std::string contrasena, std::string descripcion)
{
    this->Rnombre = nombre;
    this->Rnickname = nickname;
    this->Rcontrasenia = contrasena;
    this->Rdescripcion = descripcion;
};

bool CUsuario::ingresoEstudiante(std::string pais, Fecha fechaNacimiento)
{
    Estudiante *estudiante = new Estudiante(getNombre(), getNickname(), getContrasenia(), getDescripcion(), pais, fechaNacimiento);
    this->Estudiantes.push_back(estudiante);
    this->Usuarios.push_back(estudiante);
    return true;
};

set<string *> CUsuario::ingresoInstituto(std::string instituto)
{
    this->Rinstituto = instituto;
    CIdioma &idioma = CIdioma::getInstance();
    set<string *> idiomas = idioma.mostrarIdiomas();
    return idiomas;
};

bool CUsuario::ingresoIdioma(std::string idioma)
{

    this->Ridiomas.insert(idioma);
    return true;
};

bool CUsuario::ingresoProfesor()
{
    set<Idioma *> idiomas = linkearIdiomas();
    Profesor *profesor = new Profesor(getNombre(), getNickname(), getContrasenia(), getDescripcion(), getInstituto(), linkearIdiomas());

    this->Profesores.push_back(profesor);
    this->Usuarios.push_back(profesor);
    Ridiomas.clear();
    return true;
};

DataEstudiante *CUsuario::consultarEstudiante(std::string nickname)
{
    Estudiante *student = buscarEstudiante(nickname);
    DataEstudiante *dataEstudiante = new DataEstudiante(student->getNombre(), student->getDescripcion(), student->getPais(), student->getFechaNacimiento());
    return dataEstudiante;
};

DataProfesor *CUsuario::consultarProfesor(std::string nickname)
{
    Profesor *profesor = buscarProfesor(nickname);
    DataProfesor *dataProfesor = new DataProfesor(profesor->getNombre(), profesor->getDescripcion(), profesor->getInstituto(), profesor->getSetIdiomas());
    return dataProfesor;
};

Profesor *CUsuario::buscarProfesor(std::string nickname)
{
    std::list<Profesor *>::iterator it = this->Profesores.begin();
    while (it != this->Profesores.end() && (*it)->getNickname() != nickname)
    {
        ++it;
    }
    if (it == this->Profesores.end())
    {
        return nullptr;
    }
    else
    {
        return *it;
    }
};

Estudiante *CUsuario::buscarEstudiante(std::string nickname)
{
    std::list<Estudiante *>::iterator it = this->Estudiantes.begin();
    while (it != this->Estudiantes.end() && (*it)->getNickname() != nickname)
    {
        ++it;
    }
    if (it == this->Estudiantes.end())
    {
        return nullptr;
    }
    else
    {
        return *it;
    }
};

std::string CUsuario::getNombre()
{
    return this->Rnombre;
};

std::string CUsuario::getNickname()
{
    return this->Rnickname;
};

std::string CUsuario::getContrasenia()
{
    return this->Rcontrasenia;
};

std::string CUsuario::getDescripcion()
{
    return this->Rdescripcion;
};

std::string CUsuario::getInstituto()
{
    return this->Rinstituto;
};

set<Idioma *> CUsuario::linkearIdiomas()
{
    set<Idioma *> s;
    set<string>::iterator it = this->Ridiomas.begin();
    CIdioma &idioma = CIdioma::getInstance();
    while (it != this->Ridiomas.end())
    {
        Idioma *I = idioma.encontrarIdioma(*it);
        s.insert(I);
        ++it;
    }
    return s;
};

set<string> CUsuario::getProfe(string nombre)
{
    set<string> s;
    std::list<Profesor *>::iterator it = this->Profesores.begin();

    while (it != this->Profesores.end() && (*it)->getNickname() != nombre)
    {
        ++it;
    }
    if ((*it)->getNickname() == nombre)
    {
        s = (*it)->getSetIdiomas();
    }
    return s;
};

set<DataProfesorGeneral *> CUsuario::mostrarProfesores()
{
    set<DataProfesorGeneral *> s = set<DataProfesorGeneral *>();
    std::list<Profesor *>::iterator it = this->Profesores.begin();
    while (it != this->Profesores.end())
    {
        DataProfesorGeneral *dataProfesor = new DataProfesorGeneral((*it)->getNombre(), (*it)->getNickname(), (*it)->getContrasenia(), (*it)->getDescripcion(), (*it)->getInstituto(), (*it)->getSetIdiomas());
        s.insert(dataProfesor);
        ++it;
    }
    return s;
};

bool CUsuario::existeEstudiante(std::string nickname)
{
    std::list<Estudiante *>::iterator it = this->Estudiantes.begin();
    while (it != this->Estudiantes.end() && (*it)->getNickname() != nickname)
    {
        ++it;
    }
    if (it == this->Estudiantes.end())
    {
        return false;
    }
    else
    {
        return true;
    }
};

bool CUsuario::existeProfesor(std::string nickname)
{
    std::list<Profesor *>::iterator it = this->Profesores.begin();
    while (it != this->Profesores.end() && (*it)->getNickname() != nickname)
    {
        ++it;
    }
    if (it == this->Profesores.end())
    {
        return false;
    }
    else
    {
        return true;
    }
};

bool CUsuario::existeUsuario(std::string nickname)
{
    std::list<Usuario *>::iterator it = this->Usuarios.begin();
    while (it != this->Usuarios.end() && (*it)->getNickname() != nickname)
    {
        ++it;
    }
    if (it == this->Usuarios.end())
    {
        return false;
    }
    else
    {
        return true;
    }
};

bool CUsuario::existeIdiomaIngresado()
{
    CIdioma &idioma = CIdioma::getInstance();
    set<string *> res = idioma.mostrarIdiomas();
    if (res.size() > 0)
        return true;
    else
        return false;
};

map<string, int> CUsuario::consultarInfoEstudiante(string nickname)
{
    Estudiante *est = buscarEstudiante(nickname);
    return est->getCantEjerciciosAprobados();
}
set<Curso *> CUsuario::consultarInfoProfesor(string nickname)
{
    Profesor *prof = buscarProfesor(nickname);
    return prof->getMisCursos();
};

set<string> CUsuario::getEstudiantes()
{
    set<string> s;
    std::list<Estudiante *>::iterator it = this->Estudiantes.begin();
    while (it != this->Estudiantes.end())
    {
        s.insert((*it)->getNickname());
        ++it;
    }
    return s;
};

set<string> CUsuario::getProfesores()
{
    set<string> s;
    std::list<Profesor *>::iterator it = this->Profesores.begin();
    while (it != this->Profesores.end())
    {
        s.insert((*it)->getNickname());
        ++it;
    }
    return s;
};

set<Idioma *> CUsuario::listarIdiomasSuscriptos(string nickname)
{
    set<Idioma *> s;
    Usuario *user = buscarUsuario(nickname);
    s = user->getObservers();
    return s;
}

Usuario *CUsuario::buscarUsuario(std::string nickname)
{
    std::list<Usuario *>::iterator it = this->Usuarios.begin();
    while (it != this->Usuarios.end() && (*it)->getNickname() != nickname)
    {
        ++it;
    }
    if (it == this->Usuarios.end())
    {
        return nullptr;
    }
    else
    {
        return *it;
    }
};
vector<string> CUsuario::listarCursosNoAprobados(string nickname)
{
    Estudiante *est = buscarEstudiante(nickname);
    this->estudiante = est;
    vector<string> devolver = vector<string>();
    vector<Curso *> cursos = est->getMisCursos();
    int cursize = cursos.size();
    for (int i = 0; i < cursize; i++)
    {
        double aprobados = est->getCantEjerciciosAprobados(cursos[i]->getNombre());
        double total = cursos[i]->getCantEjercicios();
        if (((aprobados) / total) < 1)
        {
            string nomCurso = cursos[i]->getNombre();
            devolver.push_back(nomCurso);
        }
    }
    cursos.clear();
    return devolver;
}
Estudiante *CUsuario::getEstudiante()
{
    return this->estudiante;
}
vector<DataEjercicio* > CUsuario::listarEjsPendientes(string nomCurso)
{
    this->nomCurso = nomCurso;
    Estudiante *est = getEstudiante();
    vector<DataEjercicio*> res;
    int tam=est->getEjericiosPendientes(nomCurso).size();
    for (int i=0;i<tam;i++){
        DataEjercicio *dt=new DataEjercicio(est->getEjericiosPendientes(nomCurso)[i]);
        res.push_back(dt);
    }
    return res;
    }

    
void CUsuario::setNumEj(int numEj)
{
    this->numEj = numEj;
}
int CUsuario::getNumEj()
{
    return this->numEj;
}
string CUsuario::getNomcurso()
{
    return this->nomCurso;
}
DataEjercicio *CUsuario::presentarProblema(int numEj)
{
    setNumEj(numEj);
    string nomCurso = this->nomCurso;
    Estudiante *est = getEstudiante();
    vector<Ejercicio *> ejercicios = est->getEjericiosPendientes(nomCurso);
    Ejercicio *ej = ejercicios[numEj];
    DataEjercicio *dt = new DataEjercicio(ej);
    this->DT = dt;
    return dt;
}

bool CUsuario::CompararSoluciones(string SolucionEstudiante)
{
    string sol = this->DT->getSolucion();
    bool bien = SolucionEstudiante == sol;
    if (bien)
    {
        Estudiante *est = getEstudiante();
        int numEj = getNumEj();
        string nomCurso = getNomcurso();
        bool termino = est->marcarAprobado(est, nomCurso, numEj);
        if (termino)
        {
            CCurso *Cc = CCurso::getInstance();
            int C = Cc->getCantLecciones(nomCurso);
            int D=est->getLeccionActual(nomCurso);
            if (D<C-1){
                int n=est->getLeccionActual(nomCurso) + 1;
                est->setLeccionActual(nomCurso, n);
                vector<Ejercicio *> pendientes ;
                pendientes= Cc->EjerciciosDe(nomCurso,n);
                est->SetEjerciciosPendientes(nomCurso, pendientes);
            }
            else
            {
                est->terminar(nomCurso);
            }
        }
    }
    return (bien);
}

set<string> CUsuario::mostrarEstudiantesS()
{
    set<string> s;
    std::list<Estudiante *>::iterator it = this->Estudiantes.begin();
    while (it != this->Estudiantes.end())
    {
        s.insert((*it)->getNickname());
        ++it;
    }
    return s;
};

bool CUsuario::existenUsuarios()
{
    if (this->Usuarios.size() > 0)
        return true;
    else
        return false;
};

set<string> CUsuario::mostrarProfesoresS()
{
    set<string> s;
    std::list<Profesor *>::iterator it = this->Profesores.begin();
    while (it != this->Profesores.end())
    {
        s.insert((*it)->getNickname());
        ++it;
    }
    return s;
};

bool CUsuario::existeIdioma(string idioma)
{
    CIdioma &idiomas = CIdioma::getInstance();
    return idiomas.existeIdioma(idioma);
};

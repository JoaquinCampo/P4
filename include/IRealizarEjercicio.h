#ifndef IREALIZAREJERCICIO_H
#define IRealizarEjercicio_h

using namespace std;

class IRealizarEjercicio{
    public:
    virtual vector<string> listarCursosNoAprobados(string nickname) = 0;
    virtual vector<DataEjercicio *> listarEjsPendientes(string nomCurso) = 0;
    virtual DataEjercicio *presentarProblema(int Ejercicio) = 0;
    virtual bool CompararSoluciones(string solucion) = 0;
    virtual bool existeEstudiante(string nickname) = 0;
    virtual bool existeIdioma(string idioma) = 0;
    virtual bool existeUsuario(std::string nickname) = 0;
};
#endif
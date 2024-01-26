#ifndef TRADUCCION_H
#define TRADUCCION_H
class traduccion : public Ejercicio
{
private:
    TipoEjercicio tipo;
    string Letra;
    string solucion;
    string descripcion;

public:
    traduccion(TipoEjercicio tipo, string descripcion, string Letra, string solucion);
    void setLetra(string Letra);
    string getLetra();
    void setSolucion(string solucion);
    string getSolucion();
    void setTipo(TipoEjercicio tipo);
    TipoEjercicio getTipo();
    void setDescripcion(string descripcion);
    string getDescripcion();
    bool compare(string solEstudiante, string sol);
    ~traduccion();
    // void eliminarEjercicio();
};
#endif
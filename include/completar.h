#ifndef COMPLETAR_H
#define COMPLETAR_H
class completar : public Ejercicio
{
private:
    TipoEjercicio tipo;
    string letra;
    string solucion;
    string descipcion;

public:
    completar(TipoEjercicio completar, string descripcion, string frase, string solucion);
    void setLetra(string letra);
    string getLetra();
    void setSolucion(string solucion);
    string getSolucion();
    void setDescripcion(string descripcion);
    string getDescripcion();
    void setTipo(TipoEjercicio tipo);
    TipoEjercicio getTipo();
    ~completar();
};
#endif
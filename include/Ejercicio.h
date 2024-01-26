#ifndef Ejercicio_h
#define Ejercicio_h

using namespace std;

enum TipoEjercicio
{
    Completar,
    Traduccion
};

class Ejercicio
{
private:
    string descripcion;

public:
    virtual void setDescripcion(string descripcion) = 0;
    virtual ~Ejercicio() {};
    virtual string getDescripcion() = 0;
     virtual TipoEjercicio getTipo()=0;
    virtual string getLetra()=0;
    virtual string getSolucion()=0;    
    // virtual void eliminarEjercicio() = 0;
};


#endif
#ifndef DataInfoProfesor_h
#define DataInfoProfesor_h

#include <string>

using namespace std;

class DataInfoProfesor{
private:
    string nomCurso;
    float promedio;

public:
    DataInfoProfesor(string, float);
    string getNomCurso();
    float getPromedio();
    void setNomCurso(string);
    void setPromedio(int);
};

#endif
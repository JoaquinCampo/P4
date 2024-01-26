#ifndef DataInfoEstudiante_h
#define DataInfoEstudiante_h

#include <string>

using namespace std;

class DataInfoEstudiante
{
private:
    string nomCurso;
    double progreso;

public:
    DataInfoEstudiante(string, int);
    string getNomCurso();
    double getProgreso();
    void setNomCurso(string);
    void setProgreso(int);
};

#endif
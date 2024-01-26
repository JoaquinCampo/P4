#include "DataLeccion.h"

using namespace std;

DataLeccion::DataLeccion(string nomLeccion, string tema, string objetivo, int cantEjercicios, map<int, DataEjercicio *> ejercicios)
{
    this->setNomLeccion(nomLeccion);
    this->setTema(tema);
    this->setObjetivo(objetivo);
    this->setCantEjercicios(cantEjercicios);
    this->ejercicios = ejercicios;
};

DataLeccion::~DataLeccion(){};

string DataLeccion::getNomLeccion()
{
    return this->nomLeccion;
};

string DataLeccion::getTema()
{
    return this->tema;
};

string DataLeccion::getObjetivo()
{
    return this->objetivo;
};

int DataLeccion::getCantEjercicios()
{
    return this->cantEjercicios;
};

map<int, DataEjercicio *> DataLeccion::getEjercicios()
{
    return this->ejercicios;
};

void DataLeccion::setNomLeccion(string nomLeccion)
{
    this->nomLeccion = nomLeccion;
};

void DataLeccion::setTema(string tema)
{
    this->tema = tema;
};

void DataLeccion::setObjetivo(string objetivo)
{
    this->objetivo = objetivo;
};

void DataLeccion::setCantEjercicios(int cantEjercicios)
{
    this->cantEjercicios = cantEjercicios;
};

void DataLeccion::agregarLink(DataEjercicio *DataEj, int numEjercicio)
{
    this->ejercicios.insert({numEjercicio, DataEj});
};
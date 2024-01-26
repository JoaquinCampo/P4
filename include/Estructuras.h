#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>
#include <set>

using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct ejCompletar
{
    string tipoEjercicio;
    string descripcionEjercicio;
    string frase;
    string solucion;

    bool operator==(const ejCompletar &other) const
    {
        return tipoEjercicio == other.tipoEjercicio &&
               descripcionEjercicio == other.descripcionEjercicio &&
               frase == other.frase &&
               solucion == other.solucion;
    }

    bool operator<(const ejCompletar &other) const
    {
        if (tipoEjercicio != other.tipoEjercicio)
        {
            return tipoEjercicio < other.tipoEjercicio;
        }
        if (descripcionEjercicio != other.descripcionEjercicio)
        {
            return descripcionEjercicio < other.descripcionEjercicio;
        }
        if (frase != other.frase)
        {
            return frase < other.frase;
        }
        return solucion < other.solucion;
    }
};

struct ejTraduccion
{
    string tipoEjercicio;
    string descripcionEjercicio;
    string frase;
    string fraseTraducida;

    bool operator==(const ejTraduccion &other) const
    {
        return tipoEjercicio == other.tipoEjercicio &&
               descripcionEjercicio == other.descripcionEjercicio &&
               frase == other.frase &&
               fraseTraducida == other.fraseTraducida;
    }

    bool operator<(const ejTraduccion &other) const
    {
        if (tipoEjercicio != other.tipoEjercicio)
        {
            return tipoEjercicio < other.tipoEjercicio;
        }
        if (descripcionEjercicio != other.descripcionEjercicio)
        {
            return descripcionEjercicio < other.descripcionEjercicio;
        }
        if (frase != other.frase)
        {
            return frase < other.frase;
        }
        return fraseTraducida < other.fraseTraducida;
    }
};

struct leccion_con_ejs
{
    string nomLeccion;
    string temaLeccion;
    string objetivoLeccion;
    set<ejCompletar> ejerciciosCompletar;
    set<ejTraduccion> ejerciciosTraduccion;

    bool operator==(const leccion_con_ejs &other) const
    {
        return temaLeccion == other.temaLeccion &&
               objetivoLeccion == other.objetivoLeccion &&
               ejerciciosCompletar == other.ejerciciosCompletar &&
               ejerciciosTraduccion == other.ejerciciosTraduccion;
    }

    bool operator<(const leccion_con_ejs &other) const
    {
        if (temaLeccion != other.temaLeccion)
        {
            return temaLeccion < other.temaLeccion;
        }
        if (objetivoLeccion != other.objetivoLeccion)
        {
            return objetivoLeccion < other.objetivoLeccion;
        }
        if (ejerciciosCompletar != other.ejerciciosCompletar)
        {
            return ejerciciosCompletar < other.ejerciciosCompletar;
        }
        return ejerciciosTraduccion < other.ejerciciosTraduccion;
    }
};

#endif
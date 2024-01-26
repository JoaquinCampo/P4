#ifndef COLECCIONES_H
#define COLECCIONES_H

#include <list>
#include <iostream>
#include "Usuario.h"
#include "Estudiante.h"
#include "Profesor.h"

class Colecciones
{
private:
    std::list<Usuario *> Usuarios;
    std::list<Estudiante *> Estudiantes;
    std::list<Profesor *> Profesores;
    Colecciones();
    ~Colecciones();
    Colecciones(const Colecciones &) = delete; // Deshabilitar constructor de copia

    static Colecciones *instancia;

public:
    static Colecciones &obtenerInstancia();

    // Operaciones de Usuario
    void agregarUsuario(Usuario *usuario);
    void mostrarUsuarios();
    bool existeUsuario(std::string nickname);

    // Operaciones de Estudiantes
    void agregarEstudiante(Estudiante *estudiante);
    void mostrarEstudiantes();
    bool existeEstudiante(std::string nickname);

    // Operaciones de Profesores
    void agregarProfesor(Profesor *profesor);
    void mostrarProfesores();
    bool existeProfesor(std::string nickname);
};

#endif

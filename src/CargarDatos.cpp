#include "CargarDatos.h"
#include "CIdioma.h"
#include "CUsuario.h"
#include "CCurso.h"
#include "CLeccion.h"
#include "Estructuras.h"
#include <set>
#include <string>
#include "Estructuras.h"

void cargarDatos()
{
    std::string i1 = "Ingles";
    std::string i2 = "Aleman";
    std::string i3 = "Portugues";
    set<string> vacio;
    set<leccion_con_ejs> vacio2;
    set<string> PreviaCurso3;
    set<string> PreviaCurso4;
    set<string> PreviaCurso6;

    // Idiomas
    CIdioma &idiomas = CIdioma::getInstance();

    idiomas.ingresoDatos(i1);
    idiomas.ingresoDatos(i2);
    idiomas.ingresoDatos(i3);

    // Users
    CUsuario &usuarios = CUsuario::getInstance();

    // Estudiante 1
    usuarios.ingresarDatos("Juan Perez", "jpidiom", "asdfg123", "Soy un apasionado del aprendizaje de idiomas.");
    Fecha f1;
    f1.dia = 15;
    f1.mes = 7;
    f1.anio = 1995;
    usuarios.ingresoEstudiante("Argentina", f1);

    // Estudiante 2
    usuarios.ingresarDatos("Maria Silva", "marsilva", "qwer456", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.");
    f1.dia = 28;
    f1.mes = 2;
    f1.anio = 1998;
    usuarios.ingresoEstudiante("Ecuador", f1);

    // Estudiante 3
    usuarios.ingresarDatos("Pedro Rodriguez", "pero12", "789werty", "Soy un entusiasta del aprendizaje de idiomas.");
    f1.dia = 11;
    f1.mes = 10;
    f1.anio = 1994;
    usuarios.ingresoEstudiante("Peru", f1);

    // Estudiante 4
    usuarios.ingresarDatos("Laura Gutierrez", "laugu", "c1v2b3m4", "Estoy fascinada por la forma en que las palabras pueden unir a las personas");
    f1.dia = 22;
    f1.mes = 4;
    f1.anio = 1997;
    usuarios.ingresoEstudiante("Chile", f1);

    // Estudiante 5
    usuarios.ingresarDatos("Carlos Lopez", "carlo22", "tyuipz147", "Emocionado por adquirir fluidez en diferentes lenguas.");
    f1.dia = 3;
    f1.mes = 9;
    f1.anio = 1996;
    usuarios.ingresoEstudiante("Uruguay", f1);

    // Estudiante 6
    usuarios.ingresarDatos("Ana Torres", "anator", "1qsxc36", "Disfruto de la belleza de las diferentes estructuras y sonidos.");
    f1.dia = 12;
    f1.mes = 1;
    f1.anio = 1999;
    usuarios.ingresoEstudiante("Argentina", f1);

    // Estudiante 7
    usuarios.ingresarDatos("Lucia Hernandez", "luher24", "t7h8y5u6", "Emocionada en la riqueza cultural que cada idioma ofrece.");
    f1.dia = 25;
    f1.mes = 06;
    f1.anio = 1993;
    usuarios.ingresoEstudiante("Colombia", f1);

    // Estudiante 8
    usuarios.ingresarDatos("David Gonzalez", "dagon", "1w2e3r4t5", "Aprender nuevas lenguas y sumergirme en diferentes culturas.");
    f1.dia = 8;
    f1.mes = 12;
    f1.anio = 1997;
    usuarios.ingresoEstudiante("Uruguay", f1);

    // Estudiante 9
    usuarios.ingresarDatos("Carmen Morales", "carmor", "6yu7i8m9", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.");
    f1.dia = 17;
    f1.mes = 3;
    f1.anio = 1995;
    usuarios.ingresoEstudiante("Chile", f1);

    // Estudiante 10
    usuarios.ingresarDatos("Jose Fernandez", "jose24", "qwj789p", "Disfruto del proceso de descubrir nuevas formas de comunicarme.");
    f1.dia = 17;
    f1.mes = 3;
    f1.anio = 1995;
    usuarios.ingresoEstudiante("Chile", f1);

    // Profesor 1
    usuarios.ingresarDatos("Marta Grecia", "langMaster", "P4s512", "Soy una profesora apasionada por los idiomas.");
    usuarios.ingresoInstituto("Instituo de Idiomas Moderno");
    usuarios.ingresoIdioma(i1);
    usuarios.ingresoIdioma(i3);
    usuarios.ingresoProfesor();

    // Profesor 2
    usuarios.ingresarDatos("Carlos Petro", "linguaPro", "Pess23", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas");
    usuarios.ingresoInstituto("Centro Global");
    usuarios.ingresoIdioma(i1);
    usuarios.ingresoIdioma(i2);
    usuarios.ingresoIdioma(i3);
    usuarios.ingresoProfesor();

    // Profesor 3
    usuarios.ingresarDatos("Laura Perez", "talkExpert", "Secret1", "Soy una profesora entusiasta del aprendizaje de idiomas");
    usuarios.ingresoInstituto("Instituto de Idiomas Vanguardia");
    usuarios.ingresoIdioma(i2);
    usuarios.ingresoProfesor();

    // Profesor 4
    usuarios.ingresarDatos("Franco Lopez", "lingoSensei", "Secure2", "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos");
    usuarios.ingresoInstituto("Centro de Idiomas");
    usuarios.ingresoIdioma(i3);
    usuarios.ingresoProfesor();

    // Profesor 5
    usuarios.ingresarDatos("Ana Morales", "wordMaestro", "Passw0", "Soy una profesora comprometida en desarrollo de habilidades idiomaticas");
    usuarios.ingresoInstituto("Instituto de Idiomas Progreso");
    usuarios.ingresoIdioma(i1);
    usuarios.ingresoProfesor();

    // Cursos
    CCurso *cursos = CCurso::getInstance();
    CLeccion *lecciones = CLeccion::getInstance();
    CEjercicio *ejercicios = CEjercicio::getInstance();

    // Curso 1
    cursos-> RecordarNicknameProfesor("langMaster");
    cursos-> RecordarNombreCurso("Ingles para principiantes");
    cursos-> RecordarDescripcion("Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion");
    cursos-> RecordarDificultad("Principiante");
    cursos-> RecordarIdioma(i1);
    cursos-> RecordarLecciones(vacio2);
    cursos-> RecordarCursosPrevios(vacio);
    cursos-> alta_curso();


    lecciones->agregarLeccionAL("L1", "Ingles para principiantes", "Saludos y Presentaciones", "Aprender a saludar y despedirse", 0);

    ejercicios->ingresarEjercicio("L1", Traduccion, "Presentaciones");
    ejercicios-> setNomCurso("Ingles para principiantes");
    ejercicios->ejTraduccion("Mucho gusto en conocerte", "Nice to meet you");

    ejercicios->ingresarEjercicio("L1", Completar, "Presentaciones formales");
    ejercicios->ejCompletar("Please — me to introduce —", "allow, myself");

    lecciones->agregarLeccionAL("L2", "Ingles para principiantes", "Articulos y Plurales", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos", 0);

    ejercicios->ingresarEjercicio("L2", Traduccion, "Plurales regulares");
    ejercicios->ejTraduccion("I have two brothers and three sisters", "Tengo dos hermanos y tres hermanas");

    ejercicios->ingresarEjercicio("L2", Completar, "Sustantivos contables en plural");
    ejercicios->ejCompletar("Can I have — water, please?", "some");

    // Curso 2
    cursos-> RecordarNicknameProfesor("langMaster");
    cursos-> RecordarNombreCurso("Curso de ingles basico");
    cursos-> RecordarDescripcion("Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.");
    cursos-> RecordarDificultad("Principiante");
    cursos-> RecordarIdioma(i1);
    cursos-> RecordarLecciones(vacio2);
    cursos-> RecordarCursosPrevios(vacio);
    cursos-> alta_curso();

    lecciones->agregarLeccionAL("L3", "Curso de ingles basico", "Actividades Cotidianas", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos", 0);
    lecciones->agregarLeccionAL("L4", "Curso de ingles basico", "Presente Simple", "Aprender el uso del presente simple", 0);

    ejercicios-> setNomCurso("Curso de ingles basico");
    ejercicios->ingresarEjercicio("L3", Completar, "Actividades diarias");
    ejercicios->ejCompletar(" Wake —", "up");

    // Curso 3
    PreviaCurso3.insert("Ingles para principiantes");
    cursos-> RecordarNicknameProfesor("talkExpert");
    cursos-> RecordarNombreCurso("Ingles intermedio: mejora tu nivel");
    cursos-> RecordarDescripcion("Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.");
    cursos-> RecordarDificultad("Medio");
    cursos-> RecordarIdioma(i1);
    cursos-> RecordarLecciones(vacio2);
    cursos-> RecordarCursosPrevios(PreviaCurso3);
    cursos-> alta_curso();

    lecciones->agregarLeccionAL("L5", "Ingles intermedio: mejora tu nivel", "Conversaciones cotidianas", "Aprender a hacer preguntas y respuestas en situaciones comunes", 0);

    ejercicios-> setNomCurso("Ingles intermedio: mejora tu nivel");
    ejercicios->ingresarEjercicio("L5", Completar, "Consultas de la hora");
    ejercicios->ejCompletar("Do you — the time?, A: Yes, it is half — 4", "have, past");

    // Curso 4
    PreviaCurso4.insert("Ingles para principiantes");
    PreviaCurso4.insert("Ingles intermedio: mejora tu nivel");
    cursos-> RecordarNicknameProfesor("talkExpert");
    cursos-> RecordarNombreCurso("Curso avanzado de ingles");
    cursos-> RecordarDescripcion("Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.");
    cursos-> RecordarDificultad("Avanzado");
    cursos-> RecordarIdioma(i1);
    cursos-> RecordarLecciones(vacio2);
    cursos-> RecordarCursosPrevios(PreviaCurso4);
    cursos->alta_curso();

    lecciones->agregarLeccionAL("L6", "Curso avanzado de ingles", "Uso de modales avanzados", "Explorar el uso de los modales complejos", 0);

    ejercicios-> setNomCurso("Curso avanzado de ingles");
    ejercicios->ingresarEjercicio("L6", Traduccion, "Dar consejos o expresar obligacion");
    ejercicios->ejTraduccion("You should visit that museum", "Deberias visitar ese museo");

    // Curso 5
    cursos-> RecordarNicknameProfesor("talkExpert");
    cursos-> RecordarNombreCurso("Portugues intermedio");
    cursos-> RecordarDescripcion("Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.");
    cursos-> RecordarDificultad("Medio");
    cursos-> RecordarIdioma(i3);
    cursos-> RecordarLecciones(vacio2);
    cursos-> RecordarCursosPrevios(vacio);
    cursos->alta_curso();

    lecciones->agregarLeccionAL("L7", "Portugues intermedio", "Lectura y comprension de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas", 0);

    ejercicios-> setNomCurso("Portugues intermedio");
    ejercicios->ingresarEjercicio("L7", Traduccion, "Imperativo");
    ejercicios->ejTraduccion("Fale comigo", "Habla conmigo");

    // Curso 6
    PreviaCurso6.insert("Portugues intermedio");
    cursos-> RecordarNicknameProfesor("lingoSensei");
    cursos-> RecordarNombreCurso("Portugues avanzado");
    cursos-> RecordarDescripcion("Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.");
    cursos-> RecordarDificultad("Avanzado");
    cursos-> RecordarIdioma(i3);
    cursos-> RecordarLecciones(vacio2);
    cursos-> RecordarCursosPrevios(PreviaCurso6);
    cursos->alta_curso();

    cursos-> RecordarNombreCurso("Ingles para principiantes");
    cursos-> habilitarCurso();
    cursos-> RecordarNombreCurso("Ingles intermedio: mejora tu nivel");
    cursos-> habilitarCurso();
    cursos-> RecordarNombreCurso("Curso avanzado de ingles");
    cursos-> habilitarCurso();
    cursos-> RecordarNombreCurso("Portugues intermedio");
    cursos-> habilitarCurso();

    // Insrcripcion a cursos
    f1.dia = 1;
    f1.mes = 1;
    f1.anio = 2022;
    cursos-> RecordarNickname("jpidiom");
    cursos-> RecordarNombreCurso("Ingles para principiantes");
    cursos-> RecordarFechaInscripcion(f1);
    cursos->inscribirseACurso();
    f1.dia = 12;
    f1.mes = 6;
    f1.anio = 2022;
    cursos-> RecordarNombreCurso("Ingles intermedio: mejora tu nivel");
    cursos-> RecordarFechaInscripcion(f1);
    cursos->inscribirseACurso();
    f1.dia = 2;
    f1.mes = 3;
    f1.anio = 2023;
    cursos-> RecordarNombreCurso("Curso avanzado de ingles");
    cursos-> RecordarFechaInscripcion(f1);
    cursos->inscribirseACurso();
    f1.dia = 2;
    f1.mes = 1;
    f1.anio = 2022;
    cursos-> RecordarNickname("marsilva");
    cursos-> RecordarNombreCurso("Portugues intermedio");
    cursos-> RecordarFechaInscripcion(f1);
    cursos-> inscribirseACurso();
    cursos-> RecordarNickname("pero12");
    cursos-> RecordarNombreCurso("Ingles para principiantes");
    cursos-> RecordarFechaInscripcion(f1);
    cursos-> inscribirseACurso();
    f1.dia = 3;
    f1.mes = 1;
    f1.anio = 2023;
    cursos-> RecordarNickname("laugu");
    cursos-> RecordarNombreCurso("Ingles para principiantes");
    cursos-> RecordarFechaInscripcion(f1);
    cursos->inscribirseACurso();
    cursos-> RecordarNombreCurso("Portugues intermedio");
    cursos->inscribirseACurso();
    f1.dia = 5;
    f1.mes = 1;
    f1.anio = 2023;
    cursos-> RecordarNickname("carlo22");
    cursos-> RecordarNombreCurso("Portugues intermedio");
    cursos-> RecordarFechaInscripcion(f1);
    cursos->inscribirseACurso();

    // Ejercicios Aprobados
};
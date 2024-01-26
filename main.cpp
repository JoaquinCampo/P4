// 16/06 13:39

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <limits>

#include "include/Fabrica.h"

#include "include/DataCurso.h"
#include "include/DataEstudiante.h"
#include "include/DataEjercicio.h"
#include "include/Estructuras.h"
#include "include/DataUsuario.h"
#include "include/DataLeccion.h"

#include "include/CargarDatos.h"

#include "include/CEstadisticas.h"

using namespace std;

void volver()
{
    sleep(1.5);
    cout << "Redireccionando al inicio..." << endl;
    sleep(2);
    system("clear");
}

string toHabilitado(bool hab)
{
    if (hab)
        return "Habilitado";
    else
        return "No habilitado";
};

string toFecha(Fecha fecha)
{
    string res = "";
    res += to_string(fecha.dia);
    res += "/";
    res += to_string(fecha.mes);
    res += "/";
    res += to_string(fecha.anio);
    return res;
};

void menu()
{
    bool salir = false;
    int opcion;
    Fabrica F;
    IAltaCurso *iac = F.getIAltaCurso(); // poner en cadaa caso de uso
    IConsultarCurso *icc = F.getIConsultarCurso();
    IAgregarLeccion *iAL = F.getIAgregarLeccion();
    IAltaUsuario *altaUsuario = F.getIAltaUsuario();
    IConsultarUsuario *consultaUsuario = F.getIConsultarUsuario();
    IAltaIdioma *altaIdioma = F.getIAltaIdioma();
    IConsultarIdioma *consultaIdioma = F.getIConsultarIdioma();
    IInscribirseACurso *iic = F.getIInscribirseACurso();
    IHabilitarCurso *ihc = F.getIHabilitarCurso();
    ISuscribirseANotificaciones *suscribirse = F.getISuscribirseANotificaciones();
    IConsultarNotificaciones *consultarNotificaciones = F.getIConsultarNotificaciones();
    IEliminarSuscripciones *eliminarSuscripciones = F.getIEliminarSuscripciones();
    IEliminarCurso *iec = F.getIEliminarCurso();

    do
    {
        cout << "|===========================================|" << endl;
        cout << "|                    MENU                   |" << endl;
        cout << "|===========================================|" << endl;
        cout << "| 1)  Dar de alta un usuario                |" << endl;
        cout << "| 2)  Consultar información sobre un usuario|" << endl;
        cout << "| 3)  Dar de alta un idioma                 |" << endl;
        cout << "| 4)  Consultar idiomas                     |" << endl;
        cout << "| 5)  Dar de alta un curso                  |" << endl;
        cout << "| 6)  Agregar una lección                   |" << endl;
        cout << "| 7)  Agregar un ejercicio                  |" << endl;
        cout << "| 8)  Habilitar un curso                    |" << endl;
        cout << "| 9)  Eliminar un curso                     |" << endl;
        cout << "| 10) Consultar información sobre un curso  |" << endl;
        cout << "| 11) Inscribirse a un curso                |" << endl;
        cout << "| 12) Realizar un ejercicio                 |" << endl;
        cout << "| 13) Consultar estadísticas                |" << endl;
        cout << "| 14) Suscribirse a notificaciones          |" << endl;
        cout << "| 15) Consultar notificaciones              |" << endl;
        cout << "| 16) Eliminar suscripciones                |" << endl;
        cout << "| 17) Cargar Datos                          |" << endl;
        cout << "| 0)  Salir                                 |" << endl;
        cout << "|===========================================|" << endl;
        cout << "Ingrese el número de la opción deseada: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
        case 1:
        {
            system("clear");
            cout << "Dando de alta un usuario..." << endl;
            bool opcion2 = false;
            string nombre;
            string nickname;
            string contrasenia;
            string descripcion;
            string nombreIdioma;
            string YesOrNot;
            bool resP = false;
            bool opcion5 = false;

            printf("Ingrese Nombre\n");

            cin.ignore();
            getline(cin, nombre);
            printf("Ingrese Nickname\n");
            while (!opcion5)
            {
                getline(cin, nickname);
                if (altaUsuario->existeUsuario(nickname))
                {
                    printf("El nickname ya existe\n");
                    printf("Ingrese otro nickname\n");
                }
                else
                {
                    opcion5 = true;
                }
            }

            while (!opcion2)
            {
                printf("Ingrese Contrasenia\n");
                std::cin >> contrasenia;
                if (contrasenia.length() <= 5)
                {
                    printf("La contrasenia debe tener al menos 6 caracteres\n");
                }
                else
                {
                    opcion2 = true;
                }
            }
            printf("Ingrese Descripcion\n");
            std::cin.ignore();
            std::getline(std::cin, descripcion);

            altaUsuario->ingresarDatos(nombre, nickname, contrasenia, descripcion);
            printf("Ingrese 1 si es estudiante o 2 si es profesor\n");
            std::cin >> YesOrNot;
            if (YesOrNot == "1")
            {
                string pais;
                string fechaNacimiento;
                int dia;
                int mes;
                int anio;
                bool opcion3 = false;
                bool resE = false;
                Fecha fechaNacimientoF;

                printf("Ingrese Pais\n");
                std::getline(std::cin, pais);

                while (!opcion3)
                {
                    printf("Ingrese Fecha de Nacimiento de la siguiente manera:\n DIA MES AÑO \n");
                    std::cin >> dia;
                    std::cin >> mes;
                    std::cin >> anio;
                    if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 1900 && anio <= 2023)
                    {
                        opcion3 = true;
                    }
                    else
                    {
                        printf("Fecha invalida\n");
                    }
                }
                fechaNacimientoF.dia = dia;
                fechaNacimientoF.mes = mes;
                fechaNacimientoF.anio = anio;

                resE = altaUsuario->ingresoEstudiante(pais, fechaNacimientoF);
                if (resE)
                {
                    printf("Estudiante ingresado con exito\n");
                    system("clear");
                }
                else
                {
                    printf("No se pudo ingresar el estudiante\n");
                    system("clear");
                }
            }
            else if (YesOrNot == "2")
            {
                if (!altaUsuario->existeIdiomaIngresado())
                {
                    printf("Aun no hay idiomas ingresados, es necesario ingresar al menos uno primero\n");
                    break;
                }
                string instituto;
                bool opcion4 = false;
                printf("Ingrese Instituto\n");
                std::cin.ignore();
                std::getline(std::cin, instituto);
                set<string *> res = altaUsuario->ingresoInstituto(instituto);
                printf("Los idiomas disponibles son:\n");
                for (string *idioma : res)
                {
                    cout << *idioma << endl;
                }
                while (!opcion4)
                {
                    bool resI = false;
                    string idioma;
                    printf("Ingrese alguno de los idiomas mostrados anteriormente\n");
                    std::cin >> idioma;
                    while (!altaUsuario->existeIdioma(idioma))
                    {
                        printf("El idioma ingresado no existe\n");
                        printf("Ingrese alguno de los idiomas mostrados anteriormente\n");
                        std::cin >> idioma;
                    }
                    resI = altaUsuario->ingresoIdioma(idioma);
                    if (resI)
                        printf("Idioma ingresado con exito\n");
                    else
                        printf("No se pudo ingresar el idioma\n");

                    printf("Ingrese 1 si desea agregar otro idioma o 2 si no\n");
                    std::cin >> YesOrNot;
                    if (YesOrNot == "2")
                    {
                        opcion4 = true;
                    }
                }
                resP = altaUsuario->ingresoProfesor();
                if (resP)
                {
                    printf("Profesor ingresado con exito\n");
                    system("clear");
                }
                else
                {
                    printf("No se pudo ingresar el profesor\n");
                    system("clear");
                }
            }
            else
            {
                printf("Numero invalido, redireccionando al inicio...\n");
            }
        }

        break;
        case 2:
        {
            system("clear");
            string nickname;
            string opcion9;

            cout << "Consultando información sobre un usuario..." << endl;
            if (!consultaUsuario->existenUsuarios())
            {
                cout << "No hay usuarios en el sistema. No se pudo realizar la operacion." << endl;
                break;
            }
            cout << "Ingrese 1 si usted quiere consultar la informacion de un estudiante o 2 si usted quiere consultar la informacion de un profesor." << endl;

            cin >> opcion9;
            system("clear");
            if (opcion9 == "1")
            {
                cout << "Los estudiantes cargados en el sistema son los siguientes..:" << endl;
                set<string> estudiantes = consultaUsuario->mostrarEstudiantesS();
                for (string estudiante : estudiantes)
                {
                    cout << estudiante << endl;
                }
                cout << "Ingrese el nickname del estudiante que desea consultar: " << endl;
                cin >> nickname;
                system("clear");
                if (consultaUsuario->existeEstudiante(nickname))
                {
                    DataEstudiante *data = consultaUsuario->consultarEstudiante(nickname);
                    cout << "Nombre: " << data->getNombre() << endl;
                    cout << "Descripcion: " << data->getDescripcion() << endl;
                    cout << "Pais: " << data->getPais() << endl;
                    cout << "Fecha de nacimiento: " << toFecha(data->getFechaNacimiento()) << endl;
                }
                else
                {
                    cout << "No existe un estudiante con ese nickname." << endl;
                }
            }
            else if (opcion9 == "2")
            {
                cout << "Los profesores cargados en el sistema son los siguientes..:" << endl;
                set<string> profesores = consultaUsuario->mostrarProfesoresS();
                for (string profesor : profesores)
                {
                    cout << profesor << endl;
                }
                cout << "Ingrese el nickname del profesor que desea consultar: " << endl;
                cin >> nickname;
                system("clear");
                if (consultaUsuario->existeProfesor(nickname))
                {
                    DataProfesor *data = consultaUsuario->consultarProfesor(nickname);
                    cout << "Nombre: " << data->getNombre() << endl;
                    cout << "Descripcion: " << data->getDescripcion() << endl;
                    cout << "Instituto: " << data->getInstituto() << endl;
                    cout << "Idiomas: " << endl;
                    set<string> idiomas = data->getIdiomas();
                    for (string idioma : idiomas)
                    {
                        cout << idioma << endl;
                    }
                }
                else
                {
                    cout << "No existe un profesor con ese nickname." << endl;
                }
            }
            else
            {
                cout << "Opcion invalida, redireccionando al inicio... " << endl;
            }
        }
        break;
        case 3:
        {
            system("clear");
            string nombreIdioma;
            bool res = false;
            cout << "Dando de alta un idioma..." << endl;
            cout << "Ingrese el nombre del idioma: " << endl;
            cin.ignore();
            getline(cin, nombreIdioma);
            res = altaIdioma->ingresoDatos(nombreIdioma);
            if (res)
            {
                cout << "Idioma ingresado con exito." << endl;
            }
            else
            {
                cout << "No se pudo ingresar el idioma. Ya existe el idioma en el sistema." << endl;
            }
        }
        break;
        case 4:
        {
            system("clear");
            cout << "Consultando idiomas..." << endl;
            cout << "Los idiomas cargados en el sistema son los siguientes..:" << endl;
            set<string> idiomas = consultaIdioma->listarIdiomas();
            for (string idioma : idiomas)
            {
                cout << idioma << endl;
            }
        }
        break;
        case 5:
        {
            system("clear");
            cout << "Dando de alta un curso..." << endl;

            bool hay_idiomas = iac->hay_idiomas();
            if (!hay_idiomas)
            {
                cout << "No hay idiomas en el sistema. No se pudo realizar la operacion." << endl;
                break;
            }
            set<DataProfesorGeneral *> res = iac->listar_nicknames_profesores();

            if (res.size() == 0)
            {
                cout << "No hay profesores en el sistema. No se pudo realizar la operacion." << endl;
                break;
            }

            cout << "Los profesores en el sistema son los siguientes:" << endl;
            for (DataProfesorGeneral *dtUsr : res)
                cout << dtUsr->getNickname() << endl;

            cout << "Ingrese el nickname del profesor que dictara el curso: " << endl;
            string nickname;
            bool existe = false;
            while (!existe)
            {
                cin >> nickname;
                for (DataProfesorGeneral *dtUsr : res)
                    if (dtUsr->getNickname() == nickname)
                    {
                        existe = true;
                        break;
                    }
                if (!existe)
                    cout << "Nickname invalido. Intente nuevamente." << endl;
            }
            iac->RecordarNicknameProfesor(nickname);
            system("clear");

            cout << "Ingrese el nombre del curso: " << endl;
            string nombreCurso;
            cin.ignore();
            getline(cin, nombreCurso);
            iac->RecordarNombreCurso(nombreCurso);

            cout << "Ingrese la descripcion del curso: " << endl;
            string descripcion;
            cin.ignore();
            getline(cin, descripcion);
            iac->RecordarDescripcion(descripcion);

            cout << "Ingrese la dificultad del curso (Principiante, Medio, Avanzado): " << endl;
            string dificultad;
            bool dificValida = false;
            while (!dificValida)
            {
                cin >> dificultad;
                if (dificultad == "Principiante" || dificultad == "principiante" || dificultad == "PRINCIPIANTE" || dificultad == "Medio" || dificultad == "medio" || dificultad == "MEDIO" || dificultad == "Avanzado" || dificultad == "avanzado" || dificultad == "AVANZADO")
                    dificValida = true;
                else
                    cout << "Dificultad invalida. Intente nuevamente." << endl;
            }
            iac->RecordarDificultad(dificultad);

            string idioma;
            bool idiomaValido = false;
            system("clear");
            cout << "Estos son los idiomas disponibles para dictar el curso: " << endl;
            set<string> dtIdiomas = iac->listar_especialidades_profesor(nickname);
            for (string dtIdioma : dtIdiomas)
                cout << dtIdioma << endl;
            cout << "Ingrese el idioma en el que se dictara el curso: " << endl;
            cin >> idioma;
            for (string dtIdioma : dtIdiomas)
                if (dtIdioma == idioma)
                    idiomaValido = true;

            while (!idiomaValido)
            {
                system("clear");
                cout << "Idioma invalido. Intente nuevamente." << endl;
                cout << "Estos son los idiomas disponibles para dictar el curso: " << endl;
                set<string> dtIdiomas = iac->listar_especialidades_profesor(nickname);
                for (string dtIdioma : dtIdiomas)
                    cout << dtIdioma << endl;
                cout << "Ingrese el idioma en el que se dictara el curso: " << endl;
                cin >> idioma;
                for (string dtIdioma : dtIdiomas)
                    if (dtIdioma == idioma)
                        idiomaValido = true;
            }

            iac->RecordarIdioma(idioma);
            system("clear");

            set<string> cursosPrevios = set<string>();
            set<DataCurso *> cursos_hab = iac->listar_cursos_habilitados();
            if (cursos_hab.size() > 0)
            {
                cout << "El curso " << nombreCurso << " requerira de cursos previos? (si/no)" << endl;
                string respuesta;
                cin >> respuesta;
                system("clear");
                if (respuesta == "SI" || respuesta == "si" || respuesta == "Si" || respuesta == "sI" || respuesta == "Sí" || respuesta == "sí" || respuesta == "SÍ" || respuesta == "Sí")
                {

                    string mas = "si";
                    while (mas == "si" || mas == "Si" || mas == "SI" || mas == "sI" || mas == "Sí" || mas == "sí" || mas == "SÍ" || mas == "Sí" || mas == "s" || mas == "S")
                    {
                        system("clear");
                        for (DataCurso *dtCurso : cursos_hab)
                            cout << dtCurso->getNombre() << endl;
                        string nombreCursoPrevio;
                        bool existe = false;
                        cout << endl;
                        cout << "Ingrese el nombre del curso previo: " << endl;
                        cin.ignore();
                        getline(cin, nombreCursoPrevio);
                        for (DataCurso *dtCurso : cursos_hab)
                            if (dtCurso->getNombre() == nombreCursoPrevio)
                                existe = true;
                        while (!existe)
                        {
                            system("clear");
                            cout << "No existe curso con nombre " << nombreCursoPrevio << endl;
                            cout << endl;
                            for (DataCurso *dtCurso : cursos_hab)
                                cout << dtCurso->getNombre() << endl;
                            cout << endl;
                            cout << "Ingrese un nombre valido para el curso previo: " << endl;
                            getline(cin, nombreCursoPrevio);
                            for (DataCurso *dtCurso : cursos_hab)
                                if (dtCurso->getNombre() == nombreCursoPrevio)
                                    existe = true;
                        }

                        cursosPrevios.insert(nombreCursoPrevio);
                        for (DataCurso *dtCurso : cursos_hab)
                        {
                            if (dtCurso->getNombre() == nombreCursoPrevio)
                            {
                                cursos_hab.erase(dtCurso);
                                break;
                            }
                        }
                        cout << "Desea agregar otro curso previo? (si/no)" << endl;
                        cin >> mas;
                    }
                    for (DataCurso *dtCurso : cursos_hab)
                        delete dtCurso;
                    cursos_hab.clear();
                }
            }

            // recordar conjunto "cursoPrevios" para crear el curso
            system("clear");

            string respuesta;
            cout << "Desea agregar lecciones? (si/no)" << endl;
            cin >> respuesta;

            set<leccion_con_ejs> lecciones = set<leccion_con_ejs>();
            while (respuesta == "SI" || respuesta == "si" || respuesta == "Si" || respuesta == "sI" || respuesta == "Sí" || respuesta == "sí" || respuesta == "SÍ" || respuesta == "Sí")
            {

                string nomLeccion;

                cout << "Recuerde ingresar las lecciones en el orden que debe realizarlas el estudiante. " << endl;
                cout << endl;
                cout << "Ingrese el nombre de la leccion: " << endl;
                cin.ignore();
                getline(cin, nomLeccion);

                bool existe = false;
                for (leccion_con_ejs leccion : lecciones)
                    {   
                        existe = true;
                        break;
                    }
                while (existe)
                {
                    cout << "Ya existe una leccion con ese nombre. Ingrese otro nombre para la leccion: " << endl;
                    cout << endl;
                    getline(cin, nomLeccion);
                    existe = false;
                    for (leccion_con_ejs leccion : lecciones)
                        if (leccion.nomLeccion == nomLeccion)
                        {
                            existe = true;
                            break;
                        }
                }
                
                string tema;
                cout << "Ingrese el tema sobre el que tratara la leccion: " << endl;
                cin.ignore();
                getline(cin, tema);

                cout << "Ingrese el objetivo de la leccion: " << endl;
                string objetivo;
                cin.ignore();
                getline(cin, objetivo);

                cout << "Quiere agregar un ejercicio a la leccion? (si/no)" << endl;
                string quiereEjercicio;
                cin >> quiereEjercicio;

                set<ejCompletar> ejerciciosCompletar = set<ejCompletar>();
                set<ejTraduccion> ejerciciosTraduccion = set<ejTraduccion>();
                while (quiereEjercicio == "SI" || quiereEjercicio == "si" || quiereEjercicio == "Si" || quiereEjercicio == "sI" || quiereEjercicio == "Sí" || quiereEjercicio == "sí" || quiereEjercicio == "SÍ" || quiereEjercicio == "Sí")
                {
                    cout << "Ingrese el tipo de ejercicio (recuerde que los tipos disponibles son Completar y Traduccion): " << endl;
                    string tipoEjercicio;
                    bool ejValido = false;
                    while (!ejValido)
                    {
                        cin >> tipoEjercicio;
                        if (tipoEjercicio == "completar" || tipoEjercicio == "COMPLETAR" || tipoEjercicio == "Completar" || tipoEjercicio == "traduccion" || tipoEjercicio == "TRADUCCION" || tipoEjercicio == "Traduccion" || tipoEjercicio == "traducción" || tipoEjercicio == "TRADUCCIÓN" || tipoEjercicio == "Traducción")
                            ejValido = true;
                        else
                            cout << "Tipo de ejercicio invalido. Intente nuevamente." << endl;
                    }
                    system("clear");
                    cout << "Ingrese la descripcion del ejercicio: " << endl;
                    string descripcionEjercicio;
                    cin.ignore();
                    getline(cin, descripcionEjercicio);

                    if (tipoEjercicio == "completar" || tipoEjercicio == "COMPLETAR" || tipoEjercicio == "Completar")
                    {
                        cout << "Ingrese la frase a completar (las palabras faltantes se representan mediante 3 guiones): " << endl;
                        string frase;
                        cin.ignore();
                        getline(cin, frase);

                        cout << "Ingrese la respuesta correcta (separe mediante comas (,) cada palabra): " << endl; // revisar si solucion tiene que ser set<string>
                        string solucion;
                        cin.ignore();
                        getline(cin, solucion);

                        // crear struct ejercicio completar
                        ejCompletar agregar = iac->crear_estructura_ej_completar(tipoEjercicio, descripcionEjercicio, frase, solucion);
                        // agregar ejercicio completar al set de ejercicios de la leccion
                        ejerciciosCompletar.insert(agregar);
                    }
                    else
                    {
                        cout << "Ingrese la frase a traducir: " << endl;
                        string frase;
                        cin.ignore();
                        getline(cin, frase);

                        cout << "Ingrese la frase traducida" << endl;
                        string fraseTraducida;
                        cin.ignore();
                        getline(cin, fraseTraducida);

                        // crear struct ejercicio traduccion
                        ejTraduccion agregar = iac->crear_estructura_ej_traduccion(tipoEjercicio, descripcionEjercicio, frase, fraseTraducida);

                        // agregar ejercicio traduccion al set de ejercicios de la leccion
                        ejerciciosTraduccion.insert(agregar);
                    }
                    cout << "Quiere agregar otro ejercicio a la leccion? (si/no)" << endl;
                    cin >> quiereEjercicio;
                }
                // crear struct leccion
                leccion_con_ejs agregar;
                agregar.nomLeccion = nomLeccion;
                agregar.temaLeccion = tema;
                agregar.objetivoLeccion = objetivo;
                agregar.ejerciciosCompletar = ejerciciosCompletar;
                agregar.ejerciciosTraduccion = ejerciciosTraduccion;
                // agregar leccion al set de lecciones del curso
                lecciones.insert(agregar);
                cout << "Desea agregar otra leccion? (si/no)" << endl;
                cin >> respuesta;
            }
            iac->RecordarLecciones(lecciones);
            iac->RecordarCursosPrevios(cursosPrevios);
            // crear curso con lecciones
            iac->alta_curso();
            cout << "Curso creado exitosamente." << endl;
        }
        break;
        case 6:
        {
            cout << "Agregando leccion a un curso existente... " << endl;
            system("clear");
            IAgregarLeccion *iAL = F.getIAgregarLeccion();

            set<DataCurso *> cursosNoHab = iAL->listarCursosNoHabilitados(); // listar Cursos

            if (cursosNoHab.empty())
                cout << "No hay cursos a los que agregar la leccion deseada. No se pudo realizar la operacion." << endl;
            else
            {
                cout << "Listando cursos no habilitados:" << endl;

                for (DataCurso *dtCurso : cursosNoHab)
                    cout << dtCurso->getNombre() << endl;
                cout << endl;
                cout << "Ingrese el curso al que quiere adicionar la leccion" << endl;
                string nomCurso;
                cin.ignore();
                bool valido = false;
                while (!valido)
                {
                    getline(cin, nomCurso);
                    for (DataCurso *iter : cursosNoHab)
                        if (iter->getNombre() == nomCurso)
                        {
                            valido = true;
                            break;
                        }
                    if (!valido)
                        cout << "El nombre del curso ingresado no es valido. Por favor ingrese otro:" << endl;
                };
                cout << endl;

                cout << "Ingrese el nombre de la leccion" << endl;
                string nomLeccion;
                getline(cin, nomLeccion);

                bool existe = iAL->existeLeccion(nomLeccion, nomCurso);
                while (existe)
                {
                    cout << "Ya existe una leccion con ese nombre. Ingrese otro nombre para la leccion: " << endl;
                    cout << endl;
                    getline(cin, nomLeccion);
                    existe = iAL->existeLeccion(nomLeccion, nomCurso);
                }

                cout << "Ingrese el tema de la leccion" << endl;
                string tema;
                getline(cin, tema);

                cout << "Ingrese el objetivo de la leccion" << endl;
                string objetivo;
                getline(cin, objetivo);

                for (DataCurso *dtCurso : cursosNoHab) // borro cursos pedidos
                    delete dtCurso;

                iAL->agregarLeccionAL(nomLeccion, nomCurso, tema, objetivo, 0);

                string quiere_mas_ejercicios;
                cout << "¿Quiere agregar ejercicios a la leccion? (Y/n)" << endl;
                cin >> quiere_mas_ejercicios;

                string tipo;
                string descripcion;
                string frase;
                string solucion;

                TipoEjercicio enumTipo;

                while (quiere_mas_ejercicios == "Y")
                {
                    cout << "Ingrese el tipo de ejercicio que quiere agregar (Completar, Traduccion) " << endl;
                    valido = false;
                    while (!valido)
                    {
                        cin >> tipo;
                        if (tipo == "Completar")
                        {
                            enumTipo = Completar;
                            valido = true;
                        }
                        else if (tipo == "Traduccion")
                        {
                            enumTipo = Traduccion;
                            valido = true;
                        }
                        else
                        {
                            cout << "El tipo de ejercicio ingresado no es valido. Por favor ingrese otro:" << endl;
                        };
                    };
                    cout << "Ingrese la descripcion del ejercicio" << endl;
                    cin.ignore();
                    getline(cin, descripcion);

                    iAL->agregarEjercicioAL(enumTipo, descripcion);

                    switch (enumTipo)
                    {
                    case Completar:
                    {
                        cout << "Ingrese la frase a completar, junto con su solucion:" << endl;
                        getline(cin, frase);
                        getline(cin, solucion);
                        iAL->ejCompletarAL(nomCurso, frase, solucion);
                        break;
                    }
                    case Traduccion:
                    {
                        cout << "Ingrese la frase a traducir, junto con su solucion:" << endl;
                        getline(cin, frase);
                        getline(cin, solucion);
                        iAL->ejTraducirAL(nomCurso, frase, solucion);
                        break;
                    }
                    default:
                        break;
                    }
                    cout << "¿Quiere agregar mas ejercicios a la leccion? (Y/n)" << endl;
                    cin >> quiere_mas_ejercicios;
                }
                cout << "Leccion agregada correctamente" << endl;
            }
            break;
        }
        case 7:
        {
            IAgregarEjercicio *iAE = F.getIAgregarEjercicio();
            set<DataCurso *> cursosNoHab = iAE->listarCursosNoHabilitados_CCurso(); // listar Cursos
            if (cursosNoHab.empty())
            {
                cout << "Actualmente no hay cursos a los que se le puedan agregar un ejercicio. " << endl;
            }
            else
            {
                cout << "Agregando un ejercicio..." << endl;
                cout << "¿A que curso deseas agregarle un ejercicio?" << endl;

                for (DataCurso *dtCurso : cursosNoHab)
                {
                    cout << dtCurso->getNombre() << endl;
                }
                string nomCurso;
                cin.ignore();
                getline(cin, nomCurso);
                bool valido = false;
                while (!valido)
                {
                    for (DataCurso *iter : cursosNoHab)
                    {
                        if (iter->getNombre() == nomCurso)
                        {
                            valido = true;
                            break;
                        };
                    };
                    if (!valido)
                    {
                        cout << "El curso " << nomCurso << "no pertenece al conjunto, por favor, ingrese un curso valido." << endl;
                        getline(cin, nomCurso);
                    };
                }
                for (DataCurso *dtCurso : cursosNoHab)
                    delete dtCurso;
                cursosNoHab.clear();
                set<DataLeccion *> lecciones = iAE->listarLeccion_CCurso(nomCurso);
                if (lecciones.empty())
                    cout << "Actualmente el curso " + nomCurso + " no cuenta con ninguna leccion. Si quieres, puedes comenzar agregandole una leccion." << endl;
                else
                {
                    cout << "¿A cuál de las siguientes lecciones de " + nomCurso + " deseas agregar un ejercicio?" << endl;
                    for (DataLeccion *dtLeccion : lecciones)
                        cout << dtLeccion->getNomLeccion() << endl;
                    string nomLeccion;
                    getline(cin, nomLeccion);
                    valido = false;
                    while (!valido)
                    {
                        for (DataLeccion *iter : lecciones)
                        {
                            if (iter->getNomLeccion() == nomLeccion)
                            {
                                valido = true;
                                break;
                            };
                            if (!valido)
                            {
                                cout << nomLeccion + " no pertenece a las lecciones dentro de " + nomCurso + ".Por favor, ingrese una leccion valida." << endl;
                                getline(cin, nomLeccion);
                                ;
                            }
                        };
                    }
                    for (DataLeccion *dtLeccion : lecciones)
                        delete dtLeccion;
                    lecciones.clear();
                    string tipo;
                    cout << "Ingrese el tipo de ejercicio(Actualmente los tipos de ejercicio validos son 'Completar' y 'Traduccion')" << endl;
                    cin >> tipo;
                    TipoEjercicio t;
                    while (tipo != "Completar" && tipo != "Traduccion")
                    {
                        cout << "Por favor, ingrese un tipo valido de ejercicio. Actualmente los tipos de ejercicio validos son 'Completar' y 'Traduccion'" << endl;
                        cin >> tipo;
                    }
                    if (tipo == "Completar")
                        t = Completar;
                    else
                        t = Traduccion;
                    string descripcion;
                    cout << "Ingrese la descripcion del ejercicio" << endl;
                    cin.ignore();
                    getline(cin, descripcion);
                    TipoEjercicio ti;
                    iAE->ingresarEjercicio(nomLeccion, t, descripcion);
                    if (ti == Completar)
                    {
                        string frase;
                        cout << "Ingresa la frase a completar, donde las palabras faltantes se representen mediante 3 guiones, por ejemplo, “Mi --- es Juan y tengo 21 ---”" << endl;
                        cin.ignore();
                        getline(cin, frase);
                        string solucion;
                        cout << "Ingrese el conjunto ordenado de palabras separados por una coma que conforman la solución (en el caso anterior, con la frase “Mi --- es Juan y tengo 21 ---”, la solucion sería: “nombre, años”)" << endl;
                        cin.ignore();
                        getline(cin, solucion);
                        iAE->ejCompletar(frase, solucion);
                        cout << "Ejercicio ingresado con exito" << endl;
                    }
                    else
                    {
                        string frase;
                        cout << "Ingresa la frase a traducir" << endl;
                        cin.ignore();
                        getline(cin, frase);
                        string solucion;
                        cout << "Ingrese la traduccion de '" + frase + "'" << endl;
                        cin.ignore();
                        getline(cin, solucion);
                        iAE->ejTraduccion(frase, solucion);
                        cout << "Ejercicio ingresado con exito" << endl;
                    }
                }
            }
        }
        break;
        case 8:
            cout << "Habilitando un curso..." << endl;
            {
                set<DataCurso *> res = ihc->listarCursosHabilitables();
                if (res.size() == 0)
                {
                    cout << "No hay cursos disponibles para ser habilitados." << endl;
                    volver();
                    break;
                }

                for (DataCurso *dtCurso : res)
                    cout << dtCurso->getNombre() << endl;
                string nombreCurso;
                bool existe = false;
                while (!existe)
                {
                    cout << "Ingrese el nombre del curso a habilitar." << endl;
                    cin.ignore();
                    getline(cin, nombreCurso);
                    for (DataCurso *dtCurso : res)
                        if (dtCurso->getNombre() == nombreCurso)
                        {
                            existe = true;
                        }
                    if (!existe)
                        cout << "No existe curso con nombre " << nombreCurso << endl;
                }
                ihc->RecordarNombreCurso(nombreCurso);
                ihc->habilitarCurso();
                cout << "Curso habilitado con exito." << endl;
            }
            break;
        case 9:
            system("clear");
            cout << "Eliminando un curso..." << endl;
            {
                set<string> res = iec->mostrarCursos();
                if (res.size() == 0)
                {
                    cout << "No hay cursos disponibles para ser eliminados." << endl;
                    volver();
                    break;
                }

                for (string nom : res)
                    cout << nom << endl;
                cin.ignore();
                string nombreCurso;
                bool existe = false;
                while (!existe)
                {
                    cout << endl;
                    cout << "Ingrese el nombre del curso a eliminar." << endl;
                    getline(cin, nombreCurso);
                    for (string nom : res)
                        if (nom == nombreCurso)
                        {
                            existe = true;
                            break;
                        }
                    if (!existe)
                        cout << "No existe curso con nombre " << nombreCurso << endl;
                }
                iec->RecordarNombreCurso(nombreCurso);
                iec->eliminarCurso();
                cout << "Curso eliminado con exito." << endl;
            }
            break;
        case 10:
        {
            system("clear");
            cout << "Consultando información sobre un curso..." << endl;
            set<DataCurso *> res = icc->listarCursos();
            if (res.size() == 0)
            {
                cout << "No hay cursos." << endl;
                break;
            }

            cout << "Cursos:" << endl;
            for (DataCurso *dtCurso : res)
            {
                cout << dtCurso->getNombre() << endl;
                delete dtCurso;
            }

            res.clear();
            cout << endl;
            string opcion;

            cin.ignore();
            bool existe = false;
            while (!existe)
            {
                cout << "Elija un curso." << endl;
                string nombreCurso;
                getline(cin, opcion);
                existe = icc->existe_Curso(opcion);
                if (!existe)
                    cout << "No existe curso con nombre " << opcion << endl;
            }
            system("clear");

            DataCurso *dtCurso = icc->obtenerCurso(opcion);
            cout << "Nombre: " << dtCurso->getNombre() << endl;
            cout << "Descripcion: " << dtCurso->getDescripcion() << endl;
            Dificultad DFC = dtCurso->getComplejidad();
            if (DFC == Principiante)
                cout << "Dificultad: Principiante" << endl;
            else if (DFC == Medio)
                cout << "Dificultad: Medio" << endl;
            else if (DFC == Avanzado)
                cout << "Dificultad: Avanzado" << endl;
            cout << "Idioma: " << dtCurso->getIdiomaC() << endl;
            cout << "Profesor: " << dtCurso->getProfesorC() << endl;
            cout << toHabilitado(dtCurso->getHabilitado()) << endl;
            delete dtCurso;
            cout << endl;

            set<DataLeccion *> lecciones = icc->getLecciones(opcion);
            if (lecciones.size() > 0)
            {
                cout << "Lecciones:" << endl;
                for (DataLeccion *dtLeccion : lecciones)
                {
                    cout << "Nombre: " << dtLeccion->getNomLeccion() << endl;
                    cout << "Tema: " << dtLeccion->getTema() << endl;
                    cout << "Objetivo: " << dtLeccion->getObjetivo() << endl;
                    map<int, DataEjercicio *> ejercicios = dtLeccion->getEjercicios();
                    if (ejercicios.size() > 0)
                    {
                        cout << endl;
                        cout << "Ejercicios de la leccion: " << endl;
                        for (const auto &elemento : ejercicios)
                        {
                            TipoEjercicio tipo = elemento.second->getTipo();
                            if (tipo == Completar)
                                cout << "Tipo: Completar" << endl;
                            else if (tipo == Traduccion)
                                cout << "Tipo: Traduccion" << endl;
                            cout << "Descripcion: " << elemento.second->getDescripcion() << endl;
                            cout << endl;
                            delete elemento.second;
                        }
                    }
                    ejercicios.clear();
                    delete dtLeccion;
                    cout << endl;
                }
            }
            lecciones.clear();

            set<DataEstudiante *> inscriptos = icc->getInscriptos(opcion);
            if (inscriptos.size() > 0)
            {
                cout << "Inscriptos:" << endl;
                for (DataEstudiante *dtEstudiante : inscriptos)
                {
                    cout << "Nombre: " << dtEstudiante->getNombre() << endl;
                    Fecha fechaInscripcion = icc->getFechaInscripcion(opcion, dtEstudiante->getNombre());
                    cout << "Fecha de inscripcion: " << toFecha(fechaInscripcion) << endl;
                    delete dtEstudiante;
                }
            }
            inscriptos.clear();
        }
        break;
        case 11:
            system("clear");
            cout << "Inscribiéndose a un curso..." << endl;
            {
                cout << "Ingrese su Nickname: " << endl;
                string nickname;
                cin >> nickname;

                bool es_profe = iic->es_profesor(nickname);
                if (es_profe)
                {
                    cout << "Usted es profesor. No puede inscribirse a un curso." << endl;
                    break;
                }

                bool existe = false;
                while (!existe)
                {
                    existe = iic->existe_usuario(nickname);
                    if (!existe)
                    {
                        cout << "No existe usuario con nickname " << nickname << endl;
                        sleep(1.5);
                        system("clear");
                        cout << "Ingrese un nickname valido: " << endl;
                        cin >> nickname;
                    }
                }

                system("clear");

                set<DataCurso *> cursos_est = iic->listarCursos_Disponibles(nickname);
                if (cursos_est.size() == 0)
                {
                    cout << "No hay cursos disponibles para el usuario " << nickname << endl;
                    break;
                }
                cout << "Cursos disponibles:" << endl;
                for (DataCurso *dtCurso : cursos_est)
                    cout << dtCurso->getNombre() << endl;

                cout << "Ingrese el nombre del curso al que desea inscribirse: " << endl;

                string nombreCurso;
                cin.ignore();
                getline(cin, nombreCurso);

                bool existe_curso = false;
                while (!existe_curso)
                {
                    for (DataCurso *dtCurso : cursos_est)
                        if (dtCurso->getNombre() == nombreCurso)
                        {
                            existe_curso = true;
                            break;
                        }
                    if (!existe_curso)
                    {
                        system("clear");
                        cout << "No existe un curso llamado " << nombreCurso << endl;
                        for (DataCurso *dtCurso : cursos_est)
                            cout << dtCurso->getNombre() << endl;
                        cout << "Ingrese un nombre valido: " << endl;
                        getline(cin, nombreCurso);
                    }
                }

                time_t now = time(0);
                tm *fechaRegistro = localtime(&now);
                Fecha fechaInscripcion;
                fechaInscripcion.dia = fechaRegistro->tm_mday;
                fechaInscripcion.mes = fechaRegistro->tm_mon + 1;
                fechaInscripcion.anio = fechaRegistro->tm_year + 1900;

                iic->RecordarNickname(nickname);
                iic->RecordarNombreCurso(nombreCurso);
                iic->RecordarFechaInscripcion(fechaInscripcion);
                iic->inscribirseACurso();
                cout << "Inscripcion exitosa." << endl;
            }
            break;
        case 12:
        {
            IRealizarEjercicio *ire = F.getIRealizarEjercicio();
            cout << "Realizando un ejercicio..." << endl;
            cout << "Por favor, identificate a traves de tu nickname para realizar un ejercicio" << endl;
            string nick;
            cin >> nick;
            while (!ire->existeEstudiante(nick))
            {
                cout << nick + "no es un nickname de un usuario que se encuentre en el sistema. Por favor, intentelo de nuevo" << endl;
                cin >> nick;
            }
            vector<string> cursos = ire->listarCursosNoAprobados(nick);
            if (cursos.size() == 0)
            {
                cout << nick + ",actualmente no cuentas con cursos sin completar. Si deseas, puedes inscribirte a uno." << endl;
                ;
                break;
            }
            cout << "¿De que curso es el ejercicio que deseas resolver" << endl;
            for (int i = 0; i < cursos.size(); i++)
            {
                cout << cursos[i] << endl;
            }
            string nomCur;
            cin.ignore();
            getline(cin, nomCur);
            bool pertenece = false;
            vector<DataEjercicio *> EjerciciosPendientes;
            while (!pertenece)
            {
                for (int i = 0; i < cursos.size(); i++)
                {
                    if (cursos[i] == nomCur)
                    {
                        pertenece = true;
                        EjerciciosPendientes = ire->listarEjsPendientes(nomCur);
                        break;
                    }
                }
                if (!pertenece)
                {
                    cout << "¿Por favor, ingrese un curso valido. Los cursos validos son" << endl;
                    for (int i = 0; i < cursos.size(); i++)
                    {
                        cout << cursos[i] << endl;
                    }
                    getline(cin, nomCur);
                }
            }
            system("clear");
            cout << "Cual es el numero del ejercicio de " + nomCur + " que quieres realizar? Tus ejercicios pendientes son:" << endl;
            cout << endl;

            for (int i = 0; i < EjerciciosPendientes.size(); i++)
            {
                DataEjercicio *dt = EjerciciosPendientes[i];
                cout << "EJERCICIO " + to_string(i) + ")" << endl;
                cout << "Tipo:";
                if (dt->getTipo() == Completar)
                    cout << "Completar" << endl;
                else
                    cout << "Traduccion" << endl;
                string descripcion = dt->getDescripcion();
                cout << "Descripcion:" + descripcion;
                cout << endl;
                cout << endl;
                delete dt;
            }

            bool valido = false;
            int numEj;
            while (!valido)
            {
                if (cin >> numEj && numEj >= 0 && numEj < EjerciciosPendientes.size())
                {
                    valido = true;
                    break;
                }
                cout << "Ingrese un número de ejercicio válido" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            system("clear");
            DataEjercicio *dt = ire->presentarProblema(numEj);
            if (dt->getTipo() == Completar)
            {
                cout << "Tipo: Completar" << endl;
                string descripcion = dt->getDescripcion();
                string letra = dt->getLetra();
                cout << "Descripcion: " + descripcion << endl;
                cout << "Letra: " + letra << endl;
                cout << "Ingrese la solucion a el problema,por cada ´---´ingrese la palabra, separe con comas las palabras." << endl;
                cout << endl;
            }
            else
            {
                cout << "Tipo: Traduccion" << endl;
                string descripcion = dt->getDescripcion();
                string letra = dt->getLetra();
                cout << "Descripcion: " + descripcion << endl;
                cout << "Letra: " + letra << endl;
                cout << "Ingrese la traduccion de dicha frase" << endl;
                cout << endl;
            }
            string sol;
            cin.ignore();
            getline(cin, sol);
            bool bien = ire->CompararSoluciones(sol);
            while (!bien)
            {
                cout << "La solucion no es correcta." << endl;
                getline(cin, sol);
                bien = ire->CompararSoluciones(sol);
            }
            cout << "Felicitaciones, el ejercicio fue realizado con exito" << endl;
        }
        break;

        case 13:
        {
            cout << "Consultando estadísticas..." << endl;

            IConsultarEstadisticas *iCE = new CEstadisticas();
            cout << "¿Quiere consultar estadisticas de un estudiante, profesor o curso?" << endl;

            string tipoEstadisticas;
            cin >> tipoEstadisticas;
            system("clear");
            set<string> aImprimir;
            if (tipoEstadisticas == "Estudiante")
            {
                aImprimir = iCE->listarEstudiantes();
                if (aImprimir.empty())
                {
                    cout << "No hay estudiantes ingresados al sistema." << endl;
                }
                else
                {
                    cout << "Seleccione de que estudiante desea obtener las estadisticas:" << endl;
                    set<string> estudiantesListados;
                    for (string aux : aImprimir)
                    {
                        cout << aux << endl;
                        estudiantesListados.insert(aux);
                    }
                    string estudiante;
                    cin >> estudiante;

                    set<string>::iterator pertenece = estudiantesListados.find(estudiante);
                    if (pertenece == estudiantesListados.end())
                    {
                        cout << "El estudiante ingresado no pertence al sistema.";
                        break;
                    }
                    system("clear");
                    set<DataInfoEstudiante *> estadisticasEstudiante;
                    estadisticasEstudiante = iCE->listarCurso_y_Avance(estudiante);
                    if (estadisticasEstudiante.empty())
                    {
                        cout << "El estudiante no esta inscripto a ningun curso.";
                        break;
                    }
                    else
                    {
                        for (auto it : estadisticasEstudiante)
                        {
                            cout << it->getNomCurso() << endl;
                            cout << fixed << setprecision(1) << it->getProgreso() << "%" << endl;
                        }
                    };
                    estudiantesListados.clear();
                }
            }
            else if (tipoEstadisticas == "Profesor")
            {
                aImprimir = iCE->listarProfesores();
                if (aImprimir.empty())
                {
                    cout << "No hay profesores ingresados al sistema." << endl;
                }
                else
                {
                    cout << "Seleccione de que profesor desea obtener las estadisticas:" << endl;
                    set<string> profesoresListados;
                    for (string aux : aImprimir)
                    {
                        cout << aux << endl;
                        profesoresListados.insert(aux);
                    }
                    string profesor;
                    cin >> profesor;

                    set<string>::iterator pertenece = profesoresListados.find(profesor);
                    if (pertenece == profesoresListados.end())
                    {
                        cout << "El profesor ingresado no pertence al sistema.";
                        break;
                    }

                    system("clear");
                    set<DataInfoProfesor *> estadisticasProfesor;
                    estadisticasProfesor = iCE->listarInfoProfe(profesor);
                    if (estadisticasProfesor.empty())
                    {
                        cout << "El profesor no ha propuesto ningun curso.";
                        break;
                    }
                    else
                    {
                        for (DataInfoProfesor *it : estadisticasProfesor)
                        {
                            cout << "Curso: "<< it->getNomCurso() << endl;
                            cout << "Promedio de avance: " << fixed << setprecision(1) << it->getPromedio() << "%" << endl;
                            cout << endl;
                        }
                    }
                    profesoresListados.clear();
                }
            }
            else if (tipoEstadisticas == "Curso")
            {
                aImprimir = iCE->listarCursos();
                if (aImprimir.empty())
                {
                    cout << "No hay cursos ingresados al sistema." << endl;
                }
                else
                {
                    cout << "Seleccione de que curso desea obtener las estadisticas:" << endl;
                    set<string> cursosListados;
                    for (string aux : aImprimir)
                    {
                        cout << aux << endl;
                        cursosListados.insert(aux);
                    }

                    string curso;
                    cin.ignore();
                    getline(cin, curso);
                    set<string>::iterator pertenece = cursosListados.find(curso);
                    if (pertenece == cursosListados.end())
                    {
                        cout << "El curso ingresado no pertence al sistema.";
                        break;
                    }
                    system("clear");
                    DataCurso *estadisticasCurso;

                    estadisticasCurso = iCE->listarInfoCurso(curso);

                    cout << "Nombre: " << estadisticasCurso->getNombre() << endl
                         << endl;
                    cout << "Descripcion: " << endl;
                    cout << estadisticasCurso->getDescripcion() << endl
                         << endl;
                    switch (estadisticasCurso->getComplejidad())
                    {
                    case Principiante:
                    {
                        cout << "Dificultad: Principiante" << endl;
                        break;
                    }
                    case Medio:
                    {
                        cout << "Dificultad: Medio" << endl;
                        break;
                    }
                    case Avanzado:
                    {
                        cout << "Dificultad: Avanzado" << endl;
                        break;
                    }
                    default:
                        break;
                    }

                    int cantLecciones = estadisticasCurso->getCantLecciones();
                    cout << "Cantidad de lecciones: " << to_string(cantLecciones) << endl;

                    bool hab = estadisticasCurso->getHabilitado();
                    if (hab)
                        cout << "Habilitado" << endl;
                    else
                        cout << "No habilitado" << endl;

                    cout << "Promedio de avance: " << fixed << setprecision(1) << estadisticasCurso->getPromedio() << "%" << endl;

                    cout << "Idioma enseñado: " << estadisticasCurso->getIdiomaC() << endl;
                    cout << "Profesor que lo dicta: " << estadisticasCurso->getProfesorC() << endl;
                }
            }
            delete iCE;
            aImprimir.clear();
        }
        break;
        case 14:
        {
            cout << "Suscribiéndose a notificaciones..." << endl;
            string agregarOtra = "1";
            string nickname;
            cout << "Ingrese su nickname: " << endl;
            cin >> nickname;
            while (agregarOtra == "1")
            {
                set<string> idiomas = suscribirse->listarNoSuscriptos(nickname);
                if (idiomas.size() == 0)
                {
                    cout << "No hay idiomas a los que suscribirse." << endl;
                    break;
                }
                if (idiomas.size() == 0)
                {
                    cout << "No hay idiomas a los que suscribirse." << endl;
                    break;
                }
                cout << "Seleccione un idioma al que desea suscribirse: " << endl;
                for (string idioma : idiomas)
                {
                    cout << idioma << endl;
                }
                string selIdioma;
                cin.ignore();
                getline(cin, selIdioma);
                if (idiomas.find(selIdioma) == idiomas.end())
                {
                    cout << "El idioma ingresado no existe." << endl;
                    break;
                }
                suscribirse->suscribirseANotificaciones(nickname, selIdioma);
                cout << "Suscripción realizada correctamente." << endl;
                cout << "1 si desea agregar otra suscripcion, 0 si no" << endl;
                cin >> agregarOtra;
            }
        }
        break;
        case 15:
        {
            cout << "Consultando notificaciones..." << endl;
            string nickname;
            cout << "Ingrese su nickname: " << endl;
            cin >> nickname;
            set<DataNotificacion> notificaciones = consultarNotificaciones->consultarNotificaciones(nickname);
            if (notificaciones.size() == 0)
            {
                cout << "No hay notificaciones." << endl;
                break;
            }
            for (DataNotificacion notificacion : notificaciones)
            {
                cout << "Idioma: " << notificacion.getIdioma() << " Curso: " << notificacion.getCurso() << endl;
            }
        }
        break;
        case 16:
        {
            string nickname;
            cout << "Ingrese su nickname: " << endl;
            string agregarOtra = "1";
            cin >> nickname;
            while (agregarOtra == "1")
            {
                set<string> idiomas = eliminarSuscripciones->listarSuscripciones(nickname);
                if (idiomas.size() == 0)
                {
                    cout << "No hay idiomas a los que desuscribirse." << endl;
                    break;
                }
                for (string idioma : idiomas)
                {
                    cout << idioma << endl;
                }
                string selIdioma;
                cout << "Seleccione un idioma del que desea desuscribirse: " << endl;
                cin.ignore();
                getline(cin, selIdioma);

                if (idiomas.find(selIdioma) == idiomas.end())
                {
                    cout << "El idioma ingresado no existe." << endl;
                    break;
                }
                eliminarSuscripciones->eliminarSuscripciones(nickname, selIdioma);
                cout << "Suscripción eliminada correctamente." << endl;
                cout << "1 si desea eliminar otra suscripcion, 0 si no" << endl;
                cin >> agregarOtra;
            }
        }
        break;
        case 17:
            system("clear");
            if (salir)
            {
                cout << "Los datos ya fueron cargados." << endl;
                break;
            }
            cout << "Cargando Datos Predefinidos..." << endl;
            {
                system("clear");
                cargarDatos();
                cout << "Datos cargados correctamente." << endl;
                salir = true;
            }
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
            break;
        }

        cout << endl;
    } while (opcion != 0);
}

int main()
{
    system("clear");
    menu();
    sleep(2);
    system("clear");
    return 0;
}
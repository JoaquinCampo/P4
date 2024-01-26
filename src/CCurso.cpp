#include "CCurso.h"

CCurso *CCurso::ControladorCurso = nullptr;

CCurso::CCurso() {}

CCurso *CCurso::getInstance()
{
    if (ControladorCurso == nullptr)
        ControladorCurso = new CCurso();
    return ControladorCurso;
}

void CCurso::crearCurso(string nombre, string descripcion, Dificultad dificultad, int cantLecc, int cantEjs, Idioma *idioma, Profesor *profesor, list<Leccion *> Lecciones, set<Curso *> cursos_previos)
{
    Curso *curso = new Curso(nombre, descripcion, dificultad, cantLecc, cantEjs, idioma, profesor, cursos_previos);
    cursos.insert(curso);
    cursos_no_habilitados.insert(curso);
}

void CCurso::selecCursoPrevio(set<string> previos, Curso *cur)
{
    set<Curso *> res = set<Curso *>();
    for (const string &previo : previos)
    {
        for (Curso *curso : this->cursos)
        {
            if (curso->getNombre() == previo)
            {
                res.insert(curso);
                break;
            }
        }
    }
    cur->setCursos_previos(res);
}

bool CCurso::existe_Curso(string nombre)
{
    bool res = false;
    for (Curso *curso : this->cursos)
    {
        if (curso->getNombre() == nombre)
        {
            res = true;
            break;
        }
    }
    return res;
}

// pre: existe_curso(nombre)
Curso *CCurso::getCurso(string nombre)
{
    Curso *res = nullptr;
    for (Curso *curso : this->cursos)
    {
        if (curso->getNombre() == nombre)
        {
            res = curso;
            break;
        }
    }
    return res;
}

set<DataCurso *> CCurso::listarCursos()
{
    set<DataCurso *> res = set<DataCurso *>();
    for (Curso *curso : cursos)
        res.insert(curso->crearDataCurso());
    return res;
}

set<DataCurso *> CCurso::listarCursosHabilitados()
{
    set<DataCurso *> res = set<DataCurso *>();
    for (Curso *curso : cursos_habilitados)
        res.insert(curso->crearDataCurso());
    return res;
}

set<DataCurso *> CCurso::listarCursosNoHabilitados()
{
    set<DataCurso *> res = set<DataCurso *>();
    for (Curso *curso : this->cursos_no_habilitados)
        res.insert(curso->crearDataCurso());
    return res;
}

// set<DataEjercicio *> CCurso::listarEjsPendientes(string nombreCurso, Estudiante *estudiante)
// {
//     set<DataEjercicio *> res = set<DataEjercicio *>();
//     bool existe = this->existe_Curso(nombreCurso);
//     if (existe)
//     {
//         Curso *curso = this->getCurso(nombreCurso);
//         set<DataEjercicio *> res = curso->getEjsNoAprobados(estudiante);
//     }
//     else
//         cout << "No existe curso con nombre" << nombreCurso << endl;
//     return res;
// }

// pre : existe_curso(nombreCurso)
DataCurso *CCurso::listarInfoCurso(string nombreCurso)
{
    Curso *curso = this->getCurso(nombreCurso);
    DataCurso *res = curso->crearDataCurso();
    return res;
}


bool CCurso::existe_cursoII(string nombreCurso)
{
    return this->existe_Curso(nombreCurso);
}

set<DataCurso *> CCurso::listarCursos_Disponibles(string nickname)
{
    set<Curso *> cursosAprobados = this->getCursos_aprobados(nickname);
    set<Curso *> cursos_hab = this->getCursos_habilitados();
    set<Curso *> res = set<Curso *>(); // cursos en los cuales se puede inscribir el estudiante
    if (!cursos_hab.empty())
    {
        for (Curso *curso : cursos_hab)
        {
            bool esta_inscripto = false;
            set<Estudiante *> estudiantes = curso->getEstudiantes_inscriptos();
            for (Estudiante *estudiante : estudiantes)
            {
                if (estudiante->getNickname() == nickname)
                {
                    esta_inscripto = true;
                    break;
                }
            }
            if (!esta_inscripto)
            {
                bool previos_aprobados = true;
                set<Curso *> cursos_previos = curso->getCursos_previos();

                for (Curso *curso_previo : cursos_previos)
                {
                    bool esta_aprobado = false;

                    for (Curso *curso_aprobado : cursosAprobados)
                    {
                        if (curso_aprobado->getNombre() == curso_previo->getNombre())
                        {
                            esta_aprobado = true;
                            break;
                        }
                    }

                    if (!esta_aprobado)
                    { // tienen que estar TODOS los cursos previos aprobados
                        previos_aprobados = false;
                        break;
                    }
                }
                if (previos_aprobados)
                    res.insert(curso);
            }
        }
    }

    set<DataCurso *> devolver = set<DataCurso *>();
    for (Curso *cur : res)
        devolver.insert(cur->crearDataCurso());

    return devolver;
}

void CCurso::inscribirseACurso()
{
    string nickname = this-> Rnickname;
    string nombreCurso = this-> RnombreCurso;
    Fecha fechaInscripcion = this-> RFechaInscripcion;
    Curso *cur = this->getCurso(nombreCurso);
    CUsuario *cu = &CUsuario::getInstance();
    Estudiante *est = cu->buscarEstudiante(nickname);

    cur->addInscripcion(est, fechaInscripcion);
    this->addEstudiantes_anotados(nickname, nombreCurso);
    est-> agregarEjerciciosAprobados_curso(cur);
}

void CCurso::addEstudiantes_anotados(string nickname, string nombreCurso)
{
    CUsuario *cu = &CUsuario::getInstance();
    Estudiante *est = cu->buscarEstudiante(nickname);
    this->estudiantes_anotados[nombreCurso].insert(est);
}

void CCurso::removeEstudiantes_anotados(string nickname, string nombreCurso)
{
    CUsuario *cu = &CUsuario::getInstance();
    Estudiante *est = cu->buscarEstudiante(nickname);
    this->estudiantes_anotados[nombreCurso].erase(est);
}

set<Curso *> CCurso::getCursos_aprobados(string nickname)
{
    set<Curso *> res = set<Curso *>();
    set<Curso *> cursos = this->cursos_aprobados[nickname];
    for (Curso *curso : cursos)
        res.insert(curso);
    return res;
}

set<DataProfesorGeneral *> CCurso::listar_nicknames_profesores()
{
    CUsuario *cu = &CUsuario::getInstance();
    set<DataProfesorGeneral *> res = cu->mostrarProfesores();
    return res;
}

set<string> CCurso::listar_especialidades_profesor(string nombre)
{
    CUsuario *cu = &CUsuario::getInstance();
    set<string> res = cu->getProfe(nombre);
    return res;
}

set<DataCurso *> CCurso::listar_cursos_habilitados()
{
    set<DataCurso *> res = this->listarCursosHabilitados();
    return res;
}

ejCompletar CCurso::crear_estructura_ej_completar(string tipoEjercicio, string descripcionEjercicio, string frase, string solucion)
{
    ejCompletar res = ejCompletar();
    res.tipoEjercicio = tipoEjercicio;
    res.descripcionEjercicio = descripcionEjercicio;
    res.frase = frase;
    res.solucion = solucion;
    return res;
}

ejTraduccion CCurso::crear_estructura_ej_traduccion(string tipoEjercicio, string descripcionEjercicio, string frase, string fraseTraducida)
{
    ejTraduccion res = ejTraduccion();
    res.tipoEjercicio = tipoEjercicio;
    res.descripcionEjercicio = descripcionEjercicio;
    res.frase = frase;
    res.fraseTraducida = fraseTraducida;
    return res;
}

void CCurso::alta_curso()
{
    int cant_ejs_total = 0;
    set<string> cursosPrevios = this-> RcursosPrevios;
    set<leccion_con_ejs> lecciones = this-> Rlecciones;
    int cant_lec = lecciones.size();
    CLeccion *cl = CLeccion::getInstance();
    if (lecciones.size() > 0 ) {
        for (leccion_con_ejs lec : lecciones)
        {
            set<ejCompletar> comp = lec.ejerciciosCompletar;
            set<ejTraduccion> trad = lec.ejerciciosTraduccion;
            int cant_ejs = comp.size() + trad.size();
            cant_ejs_total += cant_ejs;
        }
    }

    CIdioma *ci = &CIdioma::getInstance();
    CUsuario *cu = &CUsuario::getInstance();
    Idioma *id = ci->encontrarIdioma(this-> Ridioma);
    Profesor *profe = cu->buscarProfesor(this-> RnicknameProfesor);

    Dificultad dif;
    if (this->Rdificultad == "Principiante" || this->Rdificultad == "principiante" || this->Rdificultad == "PRINCIPIANTE")
        dif = Principiante;
    else if (this->Rdificultad == "Medio" || this->Rdificultad == "medio" || this->Rdificultad == "MEDIO")
        dif = Medio;
    else if (this->Rdificultad == "Avanzado" || this->Rdificultad == "avanzado" || this->Rdificultad == "AVANZADO")
        dif = Avanzado;

    set<Curso *> previos = set<Curso *>();
    if (cursosPrevios.size() > 0) {
        for (string previo : cursosPrevios)
        {
            Curso *agregar = this->getCurso(previo);
            previos.insert(agregar);
        }
    }

    Curso *cur = new Curso(this-> RnombreCurso, this-> Rdescripcion, dif, cant_lec, cant_ejs_total, id, profe, previos);
    this->cursos.insert(cur);
    this->cursos_no_habilitados.insert(cur);

    if (lecciones.size() > 0) {
        for (leccion_con_ejs lec : lecciones)
        {
            set<ejCompletar> comp = lec.ejerciciosCompletar;
            set<ejTraduccion> trad = lec.ejerciciosTraduccion;
            int cant_ejs = comp.size() + trad.size();
            cl->agregarLeccionAltaCurso(lec.nomLeccion, this-> RnombreCurso, lec.temaLeccion, lec.objetivoLeccion, cant_ejs, comp, trad);
        }
    }

    this->estudiantes_anotados.insert(pair<string, set<Estudiante *>>(this-> RnombreCurso, set<Estudiante *>()));

    if (cur->getCantLecciones() > 0)
    {
        bool todas_con_ej = true;
        list<Leccion *> Lecciones = cur->getLecciones();
        for (Leccion *lec : Lecciones)
        {
            int cantEjs = lec->getCantEjercicios();
            if (cantEjs == 0)
            {
                todas_con_ej = false;
                break;
            }
        }
        if (todas_con_ej)
            this->cursos_habilitables.insert(cur);
    }
    this-> enlazarCursoIdioma(this-> RnombreCurso, this-> Ridioma);
    this-> notificarCreacion(this-> RnombreCurso, this-> Ridioma);    
    profe-> agregarMisCursos(cur);
}

void CCurso::linkIdiomaCurso(string nomCurso, string idioma)
{
    Curso *curso = this->getCurso(nomCurso);
    Idioma *id = CIdioma::getInstance().encontrarIdioma(idioma);
    id->agregarCurso(curso, nomCurso);
}

// pre : existe_curso(nombreCurso)
int CCurso::getCantLecciones(string nombreCurso)
{
    int res;
    Curso *curso = this->getCurso(nombreCurso);
    res = curso->getCantLecciones();
    return res;
}

// pre : existe_curso(nombreCurso)
set<DataLeccion *> CCurso::getLecciones(string nombreCurso)
{
    set<DataLeccion *> res = set<DataLeccion *>();
    Curso* cur = this -> getCurso(nombreCurso);
    list <Leccion *> inter = cur -> getLecciones();
    for (Leccion * lec : inter) {
        vector <Ejercicio *> ejs =  lec -> getEjercicios();
        int cant_ejs = ejs.size();
        map <int, DataEjercicio *> ejs_data = map <int, DataEjercicio *>();
        for (int i = 0; i < cant_ejs; i++) {
            DataEjercicio * dtEj = new DataEjercicio(ejs[i]);
            ejs_data.insert(pair<int, DataEjercicio *>(i, dtEj));
        }
        DataLeccion * dtLec =  new DataLeccion(lec-> getNombreLeccion(), lec -> getTema(), lec -> getObjetivo(), lec -> getCantEjercicios(), ejs_data);
        res.insert(dtLec);
    }
    return res;
}

set<DataEstudiante *> CCurso::getInscriptos(string nombreCurso)
{
    Curso *curso = this->getCurso(nombreCurso);
    set<Estudiante *> intr = curso->getEstudiantes_inscriptos();
    set<DataEstudiante *> res = set<DataEstudiante *>();
    for (Estudiante *est : intr)
    {
        DataEstudiante *dtEst = new DataEstudiante(est->getNombre(), est->getDescripcion(), est->getPais(), est->getFechaNacimiento());
        res.insert(dtEst);
    }
    return res;
}

Fecha CCurso::getFechaInscripcion(string nombreCurso, string nombreEstudiante)
{
    Curso *curso = this->getCurso(nombreCurso);
    map<string, Fecha> inscripciones = curso->getInscripciones();
    Fecha res = inscripciones[nombreEstudiante];
    return res;
}

// pre : existe_curso(nombreCurso)
DataCurso *CCurso::obtenerCurso(string nombreCurso)
{
    DataCurso *res = nullptr;
    Curso *curso = this->getCurso(nombreCurso);
    res = curso->crearDataCurso();
    return res;
}

// pre: existe_curso(nombreCurso)
void CCurso::LinkLeccion_Curso(Leccion *lec, string nombreCurso)
{
    Curso *curso = this->getCurso(nombreCurso);
    curso->addLeccion(lec);
    int cant = curso-> getCantLecciones();
    curso-> setCantLecciones(cant + 1);
}

set<DataLeccion *> CCurso::listarLecciones(string nombreCurso)
{
    set<DataLeccion *> res = set<DataLeccion *>();
    Curso *curso = this->getCurso(nombreCurso);
    list<Leccion *> lecciones = curso->getLecciones();
    map < int, DataEjercicio *> ejercicios = map < int, DataEjercicio *>();
    for (Leccion *lec : lecciones)
    {
        DataLeccion *dtLec = new DataLeccion(lec-> getNombreLeccion(), lec->getTema(), lec->getObjetivo(), lec->getCantEjercicios(), ejercicios);
        res.insert(dtLec);
    }
    return res;
}

bool CCurso::hay_idiomas()
{
    CIdioma *ci = &CIdioma::getInstance();
    set<string *> res = ci->mostrarIdiomas();
    bool hay = res.size() > 0;
    return hay;
}

bool CCurso::existe_usuario(string nickname)
{
    CUsuario *cu = &CUsuario::getInstance();
    return cu->existeEstudiante(nickname) | cu->existeProfesor(nickname);
}

set<DataCurso *> CCurso::listarCursosHabilitables()
{
    set<DataCurso *> res = set<DataCurso *>();
    set<Curso *> cursos_no_hab = this->cursos_habilitables;
    for (Curso *curso : cursos_no_hab)
        res.insert(curso->crearDataCurso());
    return res;
}

void CCurso::habilitarCurso()
{
    Curso *curso = this->getCurso(this-> RnombreCurso);
    curso->setHabilitado(true);
    this->cursos_habilitados.insert(curso);
    this->cursos_no_habilitados.erase(curso);
    this->cursos_habilitables.erase(curso);
}

set<Curso *> CCurso::getCursos_habilitables()
{
    return this->cursos_habilitables;
}

bool CCurso::es_profesor(string nickname)
{
    CUsuario *cu = &CUsuario::getInstance();
    return cu->existeProfesor(nickname);
}

set<string> CCurso::listarNomCursos()
{
    set<string> res = set<string>();
    set<Curso *> cursos = this->cursos;
    for (Curso *cur : cursos)
        res.insert(cur->getNombre());
    return res;
}

set<Curso*> CCurso::getCursos_habilitados()
{
    return this->cursos_habilitados;
}

// Funciones para observer (agrego pablo)


void CCurso::enlazarCursoIdioma(string nomCurso, string idioma){
    this->linkIdiomaCurso(nomCurso, idioma);
}

void CCurso::notificarCreacion(string nomCurso, string idioma){
    CIdioma * ci = &CIdioma::getInstance();
    Idioma * id = ci->encontrarIdioma(idioma);
    DataNotificacion notificacion = DataNotificacion(idioma, nomCurso);
    id->notificar(notificacion);
}

void CCurso::eliminarCurso()
{
    Curso *curso = this->getCurso(this-> RnombreCurso);

    list<Leccion *> lec = curso->getLecciones();
    CLeccion *cl = CLeccion::getInstance();

    for (Leccion *l : lec)
        cl->eliminarLeccion(l->getNombreLeccion());
    
    Idioma * id = curso-> getIdiomaC();
    id->quitarCurso(curso, this-> RnombreCurso);

    set<Estudiante *> estudiantes_Inscriptos = curso-> getEstudiantes_inscriptos();
    for (Estudiante *e : estudiantes_Inscriptos) {
        e-> quitarEjerciciosAprobados_curso(this-> RnombreCurso);
        e-> quitarMisCursos(curso);
    }
    Profesor * prof = curso-> getProfesorC();
    prof->quitarMisCursos(curso);

    bool hab = curso-> getHabilitado();
    if (hab)
        this->cursos_habilitados.erase(curso);
    else {
        this->cursos_no_habilitados.erase(curso);
        this->cursos_habilitables.erase(curso);
    }
    this->cursos.erase(curso);
    delete curso;
};

set<string> CCurso::mostrarCursos() {
    set<string> res = set<string>();
    for (Curso * c : this->cursos)
        res.insert(c->getNombre());
    return res;
}

void CCurso::RecordarNicknameProfesor(string nickname){
    this->RnicknameProfesor = nickname;
}

void CCurso::RecordarNombreCurso(string nombreCurso){
    this->RnombreCurso = nombreCurso;
}

void CCurso::RecordarDescripcion(string descripcion){
    this->Rdescripcion = descripcion;
}

void CCurso::RecordarDificultad(string dificultad){
    this->Rdificultad = dificultad;
}

void CCurso::RecordarIdioma(string idioma){
    this->Ridioma = idioma;
}

void CCurso::RecordarLecciones(set<leccion_con_ejs> lecciones){
    this->Rlecciones = lecciones;
}

void CCurso::RecordarCursosPrevios(set<string> cursosPrevios){
    this->RcursosPrevios = cursosPrevios;
}

void CCurso::RecordarNickname(string nickname){
    this->Rnickname = nickname;
}

void CCurso::RecordarFechaInscripcion(Fecha fechaInscripcion){
    this->RFechaInscripcion = fechaInscripcion;
}

void CCurso::ListoParaHabilitar(string nombreCurso) {
    Curso * curso = this-> getCurso(nombreCurso);
    list <Leccion *> leccs = curso-> getLecciones();
    bool todas_con_ej = true;
    int cant_ejs_total = 0;
    for (Leccion * lec : leccs) {
        int ejs_lec = lec-> getCantEjercicios();
        cant_ejs_total += ejs_lec;
        if (ejs_lec == 0) {
            todas_con_ej = false;
        }
    }
    if (todas_con_ej)
        this-> cursos_habilitables.insert(curso);
    curso-> setCantEjercicios(cant_ejs_total);
}

vector<Ejercicio*> CCurso::EjerciciosDe(string nombreCurso, int numLeccion) {
    Curso* cur = getCurso(nombreCurso);
    list<Leccion*>lecciones = cur->getLecciones();
    auto it = std::next(lecciones.begin(), numLeccion);
    Leccion* leccion = *it;     
    return leccion->getEjercicios();
}

void CCurso::Chequear_Hab(string nomCurso) {
    Curso * curso = this-> getCurso(nomCurso);
    list <Leccion *> leccs = curso-> getLecciones();
    bool todas_con_ej = true;
    for (Leccion * lec : leccs) {
        if (lec-> getCantEjercicios() == 0) {
            todas_con_ej = false;
            break;
        }
    }
    bool esta = false;
    for (Curso * cur : this-> cursos_habilitables) {
        if (cur-> getNombre() == nomCurso) {
            esta = true;
            break;
        }
    }
    if (todas_con_ej && !esta)
        this-> cursos_habilitables.insert(curso);
}


bool CCurso::existeLeccion(string nomLeccion, string nombreCurso) {
    Curso * curso = this-> getCurso(nombreCurso);
    list <Leccion *> leccs = curso-> getLecciones();
    bool esta = false;
    for (Leccion * lec : leccs) {
        if (lec-> getNombreLeccion() == nomLeccion) {
            esta = true;
            break;
        }
    }
    return esta;
}
#include "panelActividades.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

void panelActividades::buscarActividad() {
    
}

void panelActividades::mostrarActividades() {
    
}
 // Historia de usuario : Mostrar actividades
void panelActividades::introducirActividad(actividad actividadNueva, bool& flagActividadGuardada) {

    std::string lineaActividad; // Linea con todo el anuncio. Se escribe en el fichero
    std::string auxfechaInicio, auxfechaFin;

    std::ostringstream aux; // Tipo de string para manejar la funcion put_time

    std::ofstream fout; // Fichero de escritura    

    // Abrimos el fichero para escribir
    fout.open(get_listaActividades());

    if(!fout.is_open()){ // Manejo de errores, caso donde no se abra bien el fichero
        std::cout << "ERROR: No se ha podido abrir el fichero de actividades" << std::endl;
        flagActividadGuardada = false;
    } else { // Caso donde abrimos correctamente
        
        // Procesamos las fechas para guardarlas como string
        aux << std::put_time(&actividadNueva.get_fechaInicio(), "%d/%m/%Y");
        auxfechaInicio = aux.str();
        
        aux << std::put_time(&actividadNueva.get_fechaFinal(), "%d/%m/%Y");
        auxfechaFin = aux.str();
        
        // Guardamos todas las propiedades en una unica cadena separada por ;
        // Se pone en varias lineas para una mejor legibilidad del codigo
        lineaActividad = actividadNueva.get_idActividad() + ";" 
                       + actividadNueva.get_tipo() + ";"
                       + actividadNueva.get_director() + ";"
                       + std::to_string(actividadNueva.get_asistencia()) + ";"
                       + actividadNueva.get_nombre()
                       + actividadNueva.get_descripcion() + ";"
                       + actividadNueva.get_tema() + ";"
                       + actividadNueva.get_ubicacion() + ";"
                       + std::to_string(actividadNueva.get_aforo()) + ";"
                       + std::to_string(actividadNueva.get_precio()) + ";"
                       + actividadNueva.get_ponente() + ";"
                       + auxfechaInicio + ";"
                       + auxfechaFin + ";"
                       + actividadNueva.get_tipoDebate() + ";"
                       + actividadNueva.get_duracion() + ";"
                       + actividadNueva.get_tareas() + ";"
                       + actividadNueva.get_nivel() + ";"
                       + actividadNueva.get_dias() + ";"
                       + std::to_string(actividadNueva.get_estado()) + ";"
                       //Añadir los que estan en lista de espera
                       //Añadir los preeinscritos
                       //Añadir los inscritos
                       ;  

        // Añadimos la cadena al final del fichero y ponemos un salto de linea
        fout << lineaActividad << std::endl;    
        flagActividadGuardada = true;                  
    }

    fout.close();
}
 // Historia de usuario : Crear actividad
void panelActividades::borrarActividad() {
    
}

void panelActividades::numeroActividades() {
    
}

void panelActividades::preinscribirUsuario() {
    
}
 // Historia de usuario : Preeinscripcion en una actividad
void panelActividades::inscribirListaEspera() {
    
}

std::string panelActividades::tiposActividades() {
    std::string cadenaTipos;
    // Obtenemos la variable privada de esta clase

    for(std::string i : this->get_listaTiposActividades()){ // Iteramos sobre el vector de strings con los tipos
        cadenaTipos = i + " - " + cadenaTipos; // Vamos metiendo los diferentes tipos en una unica cadena
    }

    if(!cadenaTipos.empty()) {// Si la cadena no esta vacia
        cadenaTipos.pop_back(); // entonces borramos los
        cadenaTipos.pop_back();
    }

    return cadenaTipos;
}
 // Historia de usuario : Crear actividad - Necesario para su funcionamiento
void panelActividades::introducirDirectores() {
    
}

void panelActividades::borrarDirectores() {
    
}

void panelActividades::verDirectores() {
    for(std::string i : this->get_listaDirectoresAcademicos()){ // Iteramos sobre el vector de directores
        std::cout<< "| " << i << std::endl; 
    }
}



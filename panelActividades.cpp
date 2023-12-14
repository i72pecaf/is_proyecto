#include "panelActividades.hpp"
#include <iostream>

void panelActividades::buscarActividad() {
    
}

void panelActividades::mostrarActividades() {
    
}
 // Historia de usuario : Mostrar actividades
void panelActividades::introducirActividad() {

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



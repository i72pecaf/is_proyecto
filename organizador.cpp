#include "organizador.hpp"
#include "panelActividades.hpp"
#include "actividad.hpp"
#include <iostream>

organizador::organizador() {

}

void organizador::crearActividad() {
    /* PARTE DE LA HISTORIA DE USUARIO OBLIGATORIA : CREAR ANUNCIO*/
    std::string cadenaTiposActividades; // Cadena que guarda los tipos de actividades
    std::string tipoAnuncio; // Tipo del anuncio nuevo a crear
    std::vector<std::string> vector_tiposActividades;

    bool flagTipo = false; // Por defecto, el tipo introducido no se reconoce

    actividad actividadNueva; // Creamos la actividad para ir completandola.
    panelActividades panel;

    
    std::cout << std::endl;
    std::cout << "Formulario de creacion de una actividad" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    // Pedimos al usuario el tipo comprobando que sea correcto
    while(!flagTipo){
        std::cout << "Introduce uno: de los siguientes tipos para el anuncio:" << std::endl;
        cadenaTiposActividades = panel.tiposActividades();
        std::cout << cadenaTiposActividades << std::endl;

        std::cout << "\n> ";
        std::cin >> tipoAnuncio;

        vector_tiposActividades = panel.get_listaTiposActividades();

        for(std::string i : vector_tiposActividades){ // Iteramos sobre el vector de strings con los tipos
            if(tipoAnuncio == i) { // Comprobamos que el valor introducido por el usuario es correcto
                flagTipo = true;
            }
        }

        if(!flagTipo) {
            std::cout << "ERROR: El tipo introducido no es correcto, vuelve a intentarlo" << std::endl;
        }
    }

}

void organizador::verTodasActividades() {

}

void organizador::buscarActividad() {
    /* Método sin implementar. No obligatorio*/
}

void organizador::borrarActividad() {
    /* Método sin implementar. No obligatorio*/
}

void organizador::publicarAnuncio() {
    /* Método sin implementar. No obligatorio*/
}

void organizador::redactarCorreo() {
    /* Método sin implementar. No obligatorio*/
}

void organizador::pasarInscritoUsuario() {
    /* Método sin implementar. No obligatorio*/
}


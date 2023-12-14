#include "organizador.hpp"
#include "panelActividades.hpp"
#include "actividad.hpp"
#include <iostream>

organizador::organizador() {

}

void organizador::crearActividad() {
    /* PARTE DE LA HISTORIA DE USUARIO OBLIGATORIA : CREAR ACTIVIDAD*/
    int opt; // Para el switch

    // Variables para obtener los datos de la actividad que quiere crear el usuario
    int aforoActividad;
    
    float asistenciaActividad;
    float precioActividad;

    std::string cadenaTiposActividades; // Cadena que guarda los tipos de actividades
    std::string tipoActividad; // Tipo del actividad nuevo a crear
    std::string directorActividad;
    std::string nombreActividad;
    std::string descripcionActividad;
    std::string temaActividad;
    std::string ubicacionActividad;
    std::string ponenteActividad;

    // Banderas para controlar errores
    bool flagTipo = false; // Por defecto, el tipo introducido no se reconoce
    bool flagDirectores = false; // Por defecto, el tipo introducido no se reconoce
    bool flagAsistencia = false; // Por defecto, no se ha introducido un valor valido
    bool flagFechas = false; // Por defecto, las fechas introducidas no son correctas

    // Objetos para manejar los anuncios
    actividad actividadNueva; // Creamos la actividad para ir completandola.
    panelActividades panel;

    // Comienzo del rellenado del anuncio
    std::cout << std::endl;
    std::cout << "Formulario de creacion de una actividad" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    // ----- Pedimos al usuario el tipo comprobando que sea correcto -----
    while(!flagTipo){
        std::cout << "Introduce uno de los siguientes tipos para el anuncio:" << std::endl;
        cadenaTiposActividades = panel.tiposActividades();
        std::cout << cadenaTiposActividades << std::endl;

        std::cout << "\n> ";
        std::cin >> tipoActividad;

        //vector_tiposActividades = panel.get_listaTiposActividades();

        for(std::string i : panel.get_listaTiposActividades()){ // Iteramos sobre el vector de strings con los tipos
            if(tipoActividad == i) { // Comprobamos que el valor introducido por el usuario es correcto
                flagTipo = true;
            }
        }

        if(!flagTipo) {
            std::cout << "ERROR: El tipo introducido no es correcto, vuelve a intentarlo" << std::endl;
        }
    }

    actividadNueva.set_tipo(tipoActividad); // Añadimos el valor al nuevo actividad
    // ---------------

    // ----- Pedimos al usuario el director a asignar para la actividad -----
    while(!flagDirectores){
        std::cout << "Introduce un unico director para el anuncio:" << std::endl;
        panel.verDirectores();

        std::cout << "\n> ";
        std::cin >> directorActividad;
        
        for(std::string i : panel.get_listaDirectoresAcademicos()){ // Iteramos sobre el vector de strings con los tipos
            if(directorActividad == i) { // Comprobamos que el valor introducido por el usuario es correcto
                flagDirectores = true;
            }
        }

        if(!flagDirectores) {
            std::cout << "ERROR: El director introducido no es correcto, vuelve a intentarlo" << std::endl;
        }
    }

    actividadNueva.set_director(directorActividad); // Añadimos el valor al nuevo actividad
    // ---------------

    // ----- Pedimos al usuario el porcentaje de asistencia -----
    while(!flagAsistencia){    
        std::cout << "Introduce un porcentaje de asistencia (De 0 a 100): ";
        std::cin >> asistenciaActividad;

        if(asistenciaActividad>=0.0 && asistenciaActividad<=100.00){
            flagAsistencia = true;
        }
        
        if(!flagAsistencia) {
            std::cout << "ERROR: El porcentaje de asistencia no es correcto, vuelve a intentarlo" << std::endl;
        }
    }

    actividadNueva.set_asistencia(asistenciaActividad); // Añadimos el valor al nuevo actividad
    // ---------------

    // ----- El coordinador decide si terminar de completar el anuncio o no -----
    std::cout << "Indica si quieres completar la actividad o dejar solo los valores obligatorios ya rellenados" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "[1] - Completar anuncio" << std::endl;
    std::cout << "[2] - Guardar anuncio solo con los valores obligatorios" << std::endl;
    std::cout << "[Cualquier otro numero] - Salir sin guardar nada" << std::endl;
    std::cout << "\n> ";
    
    std::cin >> opt;

    switch (opt) {
        case 1: // Caso en el que completamos el anuncio
            
            // ----- Pedimos al usuario el nombre de la actividad -----
            std::cout << "Introduce el nombre de la actividad: ";
            std::cin >> nombreActividad;
            actividadNueva.set_nombre(nombreActividad); // Añadimos el valor al nuevo actividad
            // ---------------

            // ----- Pedimos al usuario la descripcion de la actividad -----
            std::cout << "Introduce la descripcion de la actividad: ";
            std::cin >> descripcionActividad;
            actividadNueva.set_descripcion(descripcionActividad); // Añadimos el valor al nuevo actividad
            // ---------------

            // ----- Pedimos al usuario el tema de la actividad -----
            std::cout << "Introduce el tema de la actividad: ";
            std::cin >> temaActividad;
            actividadNueva.set_tema(temaActividad); // Añadimos el valor al nuevo actividad
            // ---------------

            // ----- Pedimos al usuario la ubicacion de la actividad -----
            std::cout << "Introduce la ubicacion de la actividad: ";
            std::cin >> ubicacionActividad;
            actividadNueva.set_ubicacion(ubicacionActividad); // Añadimos el valor al nuevo actividad
            // ---------------

            // ----- Pedimos al usuario el aforo de la actividad -----
            std::cout << "Introduce el aforo de la actividad: ";
            std::cin >> aforoActividad;
            actividadNueva.set_aforo(aforoActividad); // Añadimos el valor al nuevo actividad
            // ---------------

            // ----- Pedimos al usuario el precio de la actividad -----
            std::cout << "Introduce el precio de la actividad: ";
            std::cin >> precioActividad;
            actividadNueva.set_precio(precioActividad); // Añadimos el valor al nuevo actividad
            // ---------------

            // ----- Pedimos al usuario los ponentes de la actividad -----
            std::cout << "Introduce informacion sobre el/los ponente/s de la actividad: ";
            std::cin >> ponenteActividad;
            actividadNueva.set_ponente(ponenteActividad); // Añadimos el valor al nuevo actividad
            // ---------------

            // ----- Pedimos al usuario los ponentes de la actividad -----
            while(!flagFechas){ // Pedimos las fechas hasta que sean validas
                std::cout << "Introduce la fecha de inicio y la fecha de fin de la actividad" << std::endl;



                
                if(!flagFechas) {
                    std::cout << "ERROR: Las fechas no son correctas, vuelve a intentarlo" << std::endl;
                }
            }
            // ---------------
        break;
        
        case 2: // Caso en el que guardamos el anuncio solo con los valores obligatorios
            
        break;
        
        default: // Caso de salir sin guardar
        
        break;
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


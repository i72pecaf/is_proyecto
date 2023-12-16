#include "organizador.hpp"
#include "panelActividades.hpp"
#include "actividad.hpp"

#include <iostream>
#include <ctime> // Para el manejo de fechas
#include <iomanip> // Para el manejo de fechas
#include <limits> // Para limpiar el buffer de entrada


organizador::organizador() {

}

void organizador::crearActividad() {
    /* PARTE DE LA HISTORIA DE USUARIO OBLIGATORIA : CREAR ACTIVIDAD*/
    int opt, optGuardar; // Para el switch
    int contador; // Para el control de un unico ponente
    // Variables para obtener los datos de la actividad que quiere crear el usuario
    int aforoActividad;
    int idActividad;
    
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
    std::string duracionActividad;
    std::string tareasActividad;
    std::string nivelActividad;
    std::string diasActividad;
    std::string tipoDebateActividad;

    // Usamos la libreria ctime de C para el tratamiento de fechas 
    struct tm fechaInicioActividad, fechaFinActividad;

    // Banderas para controlar errores
    bool flagTipo = false; // Por defecto, el tipo introducido no se reconoce
    bool flagDirectores = false; // Por defecto, el tipo introducido no se reconoce
    bool flagAsistencia = false; // Por defecto, no se ha introducido un valor valido
    bool flagPonente = false; // Por defecto, no se ha introducido un unico ponente
    bool flagFechas = false; // Por defecto, las fechas introducidas no son correctas
    bool flagTipoDebate = false; // Por defecto, el tipo del debate no es correcto
    bool flagActividadGuardada = false; // Por defecto, no se ha guardado la actividad

    // Objetos para manejar los anuncios
    actividad actividadNueva; // Creamos la actividad para ir completandola.
    panelActividades panel;

    // Comienzo del rellenado del anuncio
    std::cout << std::endl;
    std::cout << "Formulario de creacion de una actividad" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    // ----- Generamos un identificador para el anuncios -----
    idActividad = static_cast<int>(std::time(nullptr)); // Generamos un id aleatorio, usamos el tiempo para ello
    // Necesitamos hacer un casteo para pasar de time_t a int
    actividadNueva.set_idActividad(idActividad); 
    // ---------------

    // ----- Pedimos al usuario el tipo comprobando que sea correcto -----
    while(!flagTipo){
        std::cout << "Introduce uno de los siguientes tipos para el anuncio:" << std::endl;
        cadenaTiposActividades = panel.tiposActividades();
        std::cout << cadenaTiposActividades << std::endl;

        std::cout << "\n> ";
        std::cin >> tipoActividad;

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

            // ----- Pedimos al usuario el ponente de la actividad -----
            while(!flagPonente){
                std::cout << "Introduce el ponente de la actividad (Si la actividad es una ponencia, mas tarde podras añadir mas): ";
                std::cin >> ponenteActividad;
                
                // Comprobamos que haya solo un @, osea, que haya solo un ponente
                for (char c : ponenteActividad) {
                    if (c == '@') {
                        contador++;
                    }
                }
                // Si solo hay un correo, continuamos
                if(contador==1){
                    flagPonente = true;
                }

                if(!flagPonente) { // En el caso de que no este bien el ponente, solicitamos de nuevo al usuario
                    std::cout << "ERROR: Has introducido mas de un ponente o no es un correo" << std::endl;
                }
                // Reseteamos el cin para leer correctamente y borramos el buffer de entrada para no leer restos anteriores
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            }
                actividadNueva.set_ponente(ponenteActividad); // Añadimos el valor al nuevo actividad
            // ---------------


            // ----- Pedimos al usuario los ponentes de la actividad -----
            while(!flagFechas){ // Pedimos las fechas hasta que sean validas
                
                std::cout << "Introduce la fecha de inicio de la actividad (day/month/year): ";
                std::cin >> std::get_time(&fechaInicioActividad, "%d/%m/%Y"); // Usamos get_time para leer la fecha y guardarla en la estructura

                if(!std::cin.fail()) { // Comprobamos que la primera fecha esta correctamente escrita
                    
                    std::cout << "Introduce la fecha de fin de la actividad (day/month/year): ";
                    std::cin >> std::get_time(&fechaFinActividad, "%d/%m/%Y"); // Usamos get_time para leer la fecha y guardarla en la estructura

                    if(!std::cin.fail()) { // Comprobamos que la segunda fecha esta correctamente escrita
                        // Ahora comprobamos que la fecha de inicio sea anterior que la fecha final
                        if(std::mktime(&fechaInicioActividad) <= std::mktime(&fechaFinActividad)){ // En caso de que esten bien...
                            flagFechas = true; // ...entonces lo marcamos como que estan bien las fechas
                        }
                    }                
                }

                if(!flagFechas) { // En el caso de que las fechas no sean correctas, solicitamos de nuevo al usuario
                    std::cout << "ERROR: Las fechas no son correctas, vuelve a intentarlo" << std::endl;
                }
                // Reseteamos el cin para leer correctamente y borramos el buffer de entrada para no leer restos anteriores
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            }

            actividadNueva.set_fechaInicio(fechaInicioActividad); // Añadimos el valor al nuevo actividad   
            actividadNueva.set_fechaFinal(fechaFinActividad); // Añadimos el valor al nuevo actividad      
            // ---------------


            // Ahora rellenamos los campos dependiendo del tipo de actividad que sea
            if(tipoActividad == "Debate") {
                
                while(!flagTipoDebate){
                    // ----- Pedimos al usuario el tipo del debate -----
                    std::cout << "Introduce el tipo del dabate (Ordinario o Extraordinario): ";
                    std::cin >> tipoDebateActividad;

                    if(tipoDebateActividad == "Ordinario" || tipoDebateActividad == "Extraordinario") { // Si es correcto...
                        flagTipoDebate = true; // ... actualizamos la bandera
                    }

                    if(!flagTipoDebate) { // En el caso de que el tipo del debate sean incorrecto, solicitamos de nuevo al usuario
                        std::cout << "ERROR: El tipo de debate no es correcto, vuelve a intentarlo" << std::endl;
                    }
                    // ---------------
                }

                actividadNueva.set_tipoDebate(tipoDebateActividad); // Añadimos el valor al nuevo actividad

            } else {
                if(tipoActividad == "Ponencia") {
                    // ----- Pedimos al usuario los ponentes de la actividad -----
                    std::cout << "Introduce informacion sobre el/los ponente/s de la actividad (Escribe el anterior tambien): ";
                    std::cin >> ponenteActividad;
                    actividadNueva.set_ponente(ponenteActividad); // Añadimos el valor al nuevo actividad
                    // ---------------
                
                } else  {
                    if(tipoActividad == "Seminario") {
                        // ----- Pedimos al usuario la duracion de la actividad -----
                        std::cout << "Introduce informacion sobre la duracion de la actividad: ";
                        std::cin >> duracionActividad;
                        actividadNueva.set_duracion(duracionActividad); // Añadimos el valor al nuevo actividad
                        // ---------------
                        
                        // ----- Pedimos al usuario las tareas de la actividad -----
                        std::cout << "Introduce informacion sobre las tareas de la actividad: ";
                        std::cin >> tareasActividad;
                        actividadNueva.set_tareas(tareasActividad); // Añadimos el valor al nuevo actividad
                        // ---------------                    
                    
                    } else {
                        if(tipoActividad == "Taller") {
                            // ----- Pedimos al usuario el nivel de la actividad -----
                            std::cout << "Introduce informacion sobre el nivel de la actividad: ";
                            std::cin >> nivelActividad;
                            actividadNueva.set_nivel(nivelActividad); // Añadimos el valor al nuevo actividad
                            // ---------------
                            
                            // ----- Pedimos al usuario los dias de la actividad -----
                            std::cout << "Introduce informacion sobre los dias de la actividad: ";
                            std::cin >> diasActividad;
                            actividadNueva.set_dias(diasActividad); // Añadimos el valor al nuevo actividad
                            // ---------------     
                        }
                    }
                }
            }

            // Ahora mostramos el anuncio completo al usuario y decide si quiere guardarlo o no
            std::cout << "Preview de la actividad" << std::endl;
            std::cout << "-----------------------" << std::endl;
            std::cout << "Tipo: " << actividadNueva.get_tipo() << std::endl;
            std::cout << "Director: " << actividadNueva.get_director() << std::endl;
            std::cout << "Asistencia: " << actividadNueva.get_asistencia() << std::endl;

            if(opt == 1){ // Si se ha decidido completar el anuncio, se muestra el resto
                
                std::cout << "Nombre: " << actividadNueva.get_nombre() << std::endl;
                std::cout << "Descripcion: " << actividadNueva.get_descripcion() << std::endl;
                std::cout << "Tema: " << actividadNueva.get_tema() << std::endl;
                std::cout << "Ubicacion: " << actividadNueva.get_ubicacion() << std::endl;
                std::cout << "Aforo: " << actividadNueva.get_aforo() << std::endl;
                std::cout << "Precio: " << actividadNueva.get_precio() << std::endl;
                std::cout << "Ponente/es: " << actividadNueva.get_ponente() << std::endl;
                // Para mostrar, usamos put_time con los elementos de la fecha, que en este caso son dia mes y año
                std::cout << "Fecha de inicio: " << std::put_time(&actividadNueva.get_fechaInicio(), "%d/%m/%Y") << std::endl;
                std::cout << "Fecha de finalizacion: " << std::put_time(&actividadNueva.get_fechaFinal(), "%d/%m/%Y") << std::endl;

                if(actividadNueva.get_tipo() == "Debate") {
                    std::cout << "Tipo de debate: " << actividadNueva.get_tipoDebate() << std::endl;

                } else { // La ponencia no hace falta ponerla, ya mostramos antes los ponentes
                    if(actividadNueva.get_tipo() == "Seminario") {
                        std::cout << "Duracion: " << actividadNueva.get_duracion() << std::endl;
                        std::cout << "Tareas: " << actividadNueva.get_tareas() << std::endl;
                    } else {
                        if(actividadNueva.get_tipo() == "Taller") {
                            std::cout << "Nivel: " << actividadNueva.get_nivel() << std::endl;
                            std::cout << "Dias: " << actividadNueva.get_dias() << std::endl;
                        } 
                    }
                }
            }


        break;
        
        case 2: // Caso en el que guardamos el anuncio solo con los valores obligatorios
            std::cout << "Se guardaran solo los valores basicos necesarios para la actividad" << std::endl;
        break;
        
        default: // Caso de salir sin guardar
            std::cout << "Saliendo sin guardar..." << std::endl;
        break;
    }

  
    if(opt == 1 || opt == 2){ // Para los casos donde no se quiera salir sin guardar
        // Ahora mostramos el anuncio completo al usuario y decide si quiere guardarlo o no

        // ----- Mostramos la actividad a guardar ----- 
        std::cout << "Preview de la actividad" << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << "Tipo: " << actividadNueva.get_tipo() << std::endl;
        std::cout << "Director: " << actividadNueva.get_director() << std::endl;
        std::cout << "Asistencia: " << actividadNueva.get_asistencia() << std::endl;

        if(opt == 1){ // Si se ha decidido completar el anuncio, se muestra el resto
            
            std::cout << "Nombre: " << actividadNueva.get_nombre() << std::endl;
            std::cout << "Descripcion: " << actividadNueva.get_descripcion() << std::endl;
            std::cout << "Tema: " << actividadNueva.get_tema() << std::endl;
            std::cout << "Ubicacion: " << actividadNueva.get_ubicacion() << std::endl;
            std::cout << "Aforo: " << actividadNueva.get_aforo() << std::endl;
            std::cout << "Precio: " << actividadNueva.get_precio() << std::endl;
            std::cout << "Ponente/es: " << actividadNueva.get_ponente() << std::endl;
            // Para mostrar, usamos put_time con los elementos de la fecha, que en este caso son dia mes y año
            std::cout << "Fecha de inicio: " << std::put_time(&actividadNueva.get_fechaInicio(), "%d/%m/%Y") << std::endl;
            std::cout << "Fecha de finalizacion: " << std::put_time(&actividadNueva.get_fechaFinal(), "%d/%m/%Y") << std::endl;

            if(actividadNueva.get_tipo() == "Debate") {
                std::cout << "Tipo de debate: " << actividadNueva.get_tipoDebate() << std::endl;

            } else { // La ponencia no hace falta ponerla, ya mostramos antes los ponentes
                if(actividadNueva.get_tipo() == "Seminario") {
                    std::cout << "Duracion: " << actividadNueva.get_duracion() << std::endl;
                    std::cout << "Tareas: " << actividadNueva.get_tareas() << std::endl;
                } else {
                    if(actividadNueva.get_tipo() == "Taller") {
                        std::cout << "Nivel: " << actividadNueva.get_nivel() << std::endl;
                        std::cout << "Dias: " << actividadNueva.get_dias() << std::endl;
                    } 
                }
            }
        }
        // ---------------   

        // ----- Mostramos la actividad a guardar ----- 
        std::cout << "Indica si quieres completar la actividad o dejar solo los valores obligatorios ya rellenados" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "[1] - Guardar anuncio" << std::endl;
        std::cout << "[2] - Salir sin guardar el anuncio" << std::endl;
        std::cout << "\n> ";
        
        std::cin >> optGuardar;

        if(optGuardar == 1) { // Guardamos el anuncio
            panel.introducirActividad(actividadNueva, flagActividadGuardada);
        } else {
            std::cout << " Anuncio no guardado. Saliendo..." << std::endl;
        }

        // ---------------
    }
}

void organizador::verTodasActividades() {
    /* PARTE DE LA HISTORIA DE USUARIO OBLIGATORIA : MOSTRAR ANUNCIOS PUBLICADOS Y SUS PREINSCRITOS*/
    
    // Se muestran tambien los no publicados
    panelActividades panel;

    panel.mostrarActividades(false); 
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


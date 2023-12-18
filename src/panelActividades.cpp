#include "panelActividades.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

void panelActividades::buscarActividad() {
    
}

void panelActividades::mostrarActividades(bool soloPublicadas) { // Con esta variable podremos mostrar solo las publicadas
    
    std::string lineaActividad;
    std::string cadenaAux; // Cadena auxiliar para tratar con las subcadenas de la linea del fichero
    std::string cadEstado; // Igual que la anterior pero solo guardara si esta publicado el anuncio o no
    std::string cadIdActividad;
    std::string tipoActividad; // Necesario para diferenciar el tipo de anuncio y mostrar su informacion unica

    std::ifstream fin; // Fichero de lectura
    std::cout << this->get_listaActividades() << std::endl;
    fin.open(this->get_listaActividades()); // Abrimos el fichero
    if(!fin.is_open()){ // Manejo de errores, caso donde no se abra bien el fichero
        std::cout << "ERROR: No se ha podido abrir el fichero" << std::endl;
    } else {
        // Procedemos a leer el fichero y mostrar las actividades
        while (getline(fin, lineaActividad)) { // Vamos linea por linea, cada linea un anuncio
            std::istringstream streamActividad(lineaActividad); // Objeto para entrada de datos, facilita el manejo de strings
            //std::getline(streamActividad, cadenaAux, ';'

            std::getline(streamActividad, cadIdActividad, ';'); // El primer elemento es el id de la actividad
            std::getline(streamActividad, cadEstado, ';'); // El segundo elemento es el estado de la actividad (publicada o no)
            
            if(soloPublicadas) {// En el caso de que mostremos solo los publicados   
                // En esta parte necesitamos conocer primero el estado del anuncio. Por eso el campo del estado es el segundo
                if(cadEstado=="true"){ // Se muestra informacion del publicado
                    std::cout << "===========================" << std::endl;  
                    std::cout << "| > Mostrando actividad < |" << std::endl;
                    std::cout << "===========================" << std::endl;  

                    std::cout << "Id de la actividad: " << cadIdActividad << std::endl;
                    std::cout << "Actividad publicada: " << cadEstado << std::endl;

                    std::getline(streamActividad, tipoActividad, ';'); // El siguiente elemento, que corresponde con el tipo
                    std::cout << "Tipo de la actividad: " << tipoActividad << std::endl;
                    
                    std::getline(streamActividad, cadenaAux, ';'); // El siguiente elemento, que corresponde con el nombre
                    std::cout << "Director: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Nombre: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Descripcion: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Asistencia: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Tema: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Ubicacion: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Aforo: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Precio: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Ponente: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Fecha de inicio: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Fecha de fin: " << cadIdActividad << std::endl;
                    if(tipoActividad == "Debate"){
                        // Muestro los datos que me interesan
                        std::getline(streamActividad, cadenaAux, ';'); // Si debate leo solo una vez
                        std::cout << "Tipo del debate: " << cadIdActividad << std::endl;
                        // Y salto los demas hasta las listas
                        std::getline(streamActividad, cadenaAux, ';');
                        std::getline(streamActividad, cadenaAux, ';');
                        std::getline(streamActividad, cadenaAux, ';');
                        std::getline(streamActividad, cadenaAux, ';'); // El siguiente leido seran las listas
                    } else {
                        if(tipoActividad == "Seminario"){
                            // Saltamos los datos que no nos interesan
                            std::getline(streamActividad, cadenaAux, ';');
                            // Mostramos los datos que nos interesan
                            std::getline(streamActividad, cadenaAux, ';'); // Este es la duracion
                            std::cout << "Duracion: " << cadIdActividad << std::endl;
                            std::getline(streamActividad, cadenaAux, ';');
                            std::cout << "Tareas: " << cadIdActividad << std::endl;
                            // Y saltamos los demas hasta las listas
                            std::getline(streamActividad, cadenaAux, ';');
                            std::getline(streamActividad, cadenaAux, ';'); // El siguiente leido seran las listas
                        } else {
                            if(tipoActividad == "Taller"){
                            // Saltamos los datos que no interesan 
                            std::getline(streamActividad, cadenaAux, ';');
                            std::getline(streamActividad, cadenaAux, ';'); 
                            std::getline(streamActividad, cadenaAux, ';');
                            // Mostramos los datos que nos interesan
                            std::getline(streamActividad, cadenaAux, ';');
                            std::cout << "Nivel: " << cadIdActividad << std::endl;
                            std::getline(streamActividad, cadenaAux, ';');
                            std::cout << "Dias: " << cadIdActividad << std::endl;
                            // El siguiente dato a leer sera la primera de la listas
                            }
                        }
                    }
                    // Mostramos las listas
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Lista de inscritos: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Lista de preeinscritos: " << cadIdActividad << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Lista de espera: " << cadIdActividad << std::endl;

                    std::cout << std::endl; // Fin de la actividad mostrada
                }

            } else { // Caso donde mostramos todos los anuncios incluso los no publicados
                std::cout << "===========================" << std::endl;  
                std::cout << "| > Mostrando actividad < |" << std::endl;
                std::cout << "===========================" << std::endl;  

                std::cout << "Id de la actividad: " << cadIdActividad << std::endl;
                std::cout << "Actividad publicada: " << cadEstado << std::endl;

                std::getline(streamActividad, tipoActividad, ';'); // El siguiente elemento, que corresponde con el tipo
                std::cout << "Tipo de la actividad: " << tipoActividad << std::endl;
                
                std::getline(streamActividad, cadenaAux, ';'); // El siguiente elemento, que corresponde con el nombre
                std::cout << "Director: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Nombre: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Descripcion: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Asistencia: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Tema: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Ubicacion: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Aforo: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Precio: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Ponente: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Fecha de inicio: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Fecha de fin: " << cadIdActividad << std::endl;

                if(tipoActividad == "Debate"){
                    // Muestro los datos que me interesan
                    std::getline(streamActividad, cadenaAux, ';'); // Si debate leo solo una vez
                    std::cout << "Tipo del debate: " << cadIdActividad << std::endl;
                    // Y salto los demas hasta las listas
                    std::getline(streamActividad, cadenaAux, ';');
                    std::getline(streamActividad, cadenaAux, ';');
                    std::getline(streamActividad, cadenaAux, ';');
                    std::getline(streamActividad, cadenaAux, ';'); // El siguiente leido seran las listas
                } else {
                    if(tipoActividad == "Seminario"){
                        // Saltamos los datos que no nos interesan
                        std::getline(streamActividad, cadenaAux, ';');
                        // Mostramos los datos que nos interesan
                        std::getline(streamActividad, cadenaAux, ';'); // Este es la duracion
                        std::cout << "Duracion: " << cadIdActividad << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Tareas: " << cadIdActividad << std::endl;
                        // Y saltamos los demas hasta las listas
                        std::getline(streamActividad, cadenaAux, ';');
                        std::getline(streamActividad, cadenaAux, ';'); // El siguiente leido seran las listas
                    } else {
                        if(tipoActividad == "Taller"){
                        // Saltamos los datos que no interesan 
                        std::getline(streamActividad, cadenaAux, ';');
                        std::getline(streamActividad, cadenaAux, ';'); 
                        std::getline(streamActividad, cadenaAux, ';');
                        // Mostramos los datos que nos interesan
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Nivel: " << cadIdActividad << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Dias: " << cadIdActividad << std::endl;
                        // El siguiente dato a leer sera la primera de la listas
                        }
                    }
                }
                // Mostramos las listas
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Lista de inscritos: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Lista de preeinscritos: " << cadIdActividad << std::endl;
                std::getline(streamActividad, cadenaAux, ';');
                std::cout << "Lista de espera: " << cadIdActividad << std::endl;
                std::cout << std::endl; // Fin de la actividad mostrada
            }
        }
    }

    fin.close();
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
                       + std::to_string(actividadNueva.get_estado()) + ";" // Guardamos el estado lo segundo para un mejor tratamiento del fichero
                       + actividadNueva.get_tipo() + ";"
                       + actividadNueva.get_director() + ";"
                       + actividadNueva.get_nombre()
                       + actividadNueva.get_descripcion() + ";"
                       + std::to_string(actividadNueva.get_asistencia()) + ";"
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
                       //Añadir los inscritos
                       //Añadir los preeinscritos
                       //Añadir los que estan en lista de espera
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



#include "panelActividades.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>  // Necesario para std::min

void panelActividades::buscarActividad() {
    
}

void panelActividades::mostrarActividades(bool soloPublicadas) { // Con esta variable podremos mostrar solo las publicadas
    
    std::string lineaActividad;
    std::string cadenaAux; // Cadena auxiliar para tratar con las subcadenas de la linea del fichero
    std::string cadEstado; // Igual que la anterior pero solo guardara si esta publicado el anuncio o no
    std::string cadIdActividad;
    std::string tipoActividad; // Necesario para diferenciar el tipo de anuncio y mostrar su informacion unica

    std::ifstream fin; // Fichero de lectura

    fin.open(this->get_listaActividades()); // Abrimos el fichero
    if(!fin.is_open()){ // Manejo de errores, caso donde no se abra bien el fichero
        std::cout << "ERROR: No se ha podido abrir el fichero" << std::endl;
    } else {
        if (fin.peek() == std::ifstream::traits_type::eof()) {
            std::cout << "El fichero esta vacio, no hay actividades para leer" << std::endl;
        } else {
            while (getline(fin, lineaActividad)) { // Vamos linea por linea, cada linea un anuncio
                std::istringstream streamActividad(lineaActividad); // Objeto para entrada de datos, facilita el manejo de strings

                std::getline(streamActividad, cadIdActividad, ';'); // El primer elemento es el id de la actividad
                std::getline(streamActividad, cadEstado, ';'); // El segundo elemento es el estado de la actividad (publicada o no)
                
                if(soloPublicadas) {// En el caso de que mostremos solo los publicados   
                    // En esta parte necesitamos conocer primero el estado del anuncio. Por eso el campo del estado es el segundo
                    if(cadEstado=="1"){ // Se muestra informacion del publicado
                        std::cout << "===========================" << std::endl;  
                        std::cout << "| > Mostrando actividad < |" << std::endl;
                        std::cout << "===========================" << std::endl;  

                        std::cout << "Id de la actividad: " << cadIdActividad << std::endl;
                        std::cout << "Actividad publicada: " << cadEstado << std::endl;

                        std::getline(streamActividad, tipoActividad, ';'); // El siguiente elemento, que corresponde con el tipo
                        std::cout << "Tipo de la actividad: " << tipoActividad << std::endl;
                        
                        std::getline(streamActividad, cadenaAux, ';'); // El siguiente elemento, que corresponde con el nombre
                        std::cout << "Director: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Nombre: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Descripcion: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Asistencia: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Tema: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Ubicacion: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Aforo: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Precio: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Ponente: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Fecha de inicio: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Fecha de fin: " << cadenaAux << std::endl;
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
                                std::cout << "Duracion: " << cadenaAux << std::endl;
                                std::getline(streamActividad, cadenaAux, ';');
                                std::cout << "Tareas: " << cadenaAux << std::endl;
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
                                std::cout << "Nivel: " << cadenaAux << std::endl;
                                std::getline(streamActividad, cadenaAux, ';');
                                std::cout << "Dias: " << cadenaAux << std::endl;
                                // El siguiente dato a leer sera la primera de la listas
                                }
                            }
                        }
                        // Mostramos las listas
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Lista de inscritos: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Lista de preeinscritos: " << cadenaAux << std::endl;
                        std::getline(streamActividad, cadenaAux, ';');
                        std::cout << "Lista de espera: " << cadenaAux << std::endl;

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
                    std::cout << "Director: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Nombre: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Descripcion: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Asistencia: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Tema: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Ubicacion: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Aforo: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Precio: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Ponente: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Fecha de inicio: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Fecha de fin: " << cadenaAux << std::endl;

                    if(tipoActividad == "Debate"){
                        // Muestro los datos que me interesan
                        std::getline(streamActividad, cadenaAux, ';'); // Si debate leo solo una vez
                        std::cout << "Tipo del debate: " << cadenaAux << std::endl;
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
                            std::cout << "Duracion: " << cadenaAux << std::endl;
                            std::getline(streamActividad, cadenaAux, ';');
                            std::cout << "Tareas: " << cadenaAux << std::endl;
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
                            std::cout << "Nivel: " << cadenaAux << std::endl;
                            std::getline(streamActividad, cadenaAux, ';');
                            std::cout << "Dias: " << cadenaAux << std::endl;
                            // El siguiente dato a leer sera la primera de la listas
                            }
                        }
                    }
                    // Mostramos las listas
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Lista de inscritos: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Lista de preeinscritos: " << cadenaAux << std::endl;
                    std::getline(streamActividad, cadenaAux, ';');
                    std::cout << "Lista de espera: " << cadenaAux << std::endl;
                    std::cout << std::endl; // Fin de la actividad mostrada
                }
            }
        
        }
        // Procedemos a leer el fichero y mostrar las actividades

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
    fout.open(get_listaActividades(), std::ios::app);

    if(!fout.is_open()){ // Manejo de errores, caso donde no se abra bien el fichero
        std::cout << "ERROR: No se ha podido abrir el fichero de actividades al guardar" << std::endl;
        flagActividadGuardada = false;
    } else { // Caso donde abrimos correctamente
        
        // Procesamos las fechas para guardarlas como string
        aux << std::put_time(&actividadNueva.get_fechaInicio(), "%d/%m/%Y");
        auxfechaInicio = aux.str();
        
        aux.str("");

        aux << std::put_time(&actividadNueva.get_fechaFinal(), "%d/%m/%Y");
        auxfechaFin = aux.str();
        
        // Guardamos todas las propiedades en una unica cadena separada por ;
        // Se pone en varias lineas para una mejor legibilidad del codigo
        lineaActividad = std::to_string(actividadNueva.get_idActividad()) + ";" 
                       + std::to_string(actividadNueva.get_estado()) + ";" // Guardamos el estado lo segundo para un mejor tratamiento del fichero
                       + actividadNueva.get_tipo() + ";"
                       + actividadNueva.get_director() + ";"
                       + actividadNueva.get_nombre() + ";"
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
                       //Inscritos
                       + actividadNueva.get_listaInscritos() + ";"
                       //Preinscritos
                       + actividadNueva.get_listaPreinscritos() + ";"
                       //Lista de espera
                       + actividadNueva.get_listaEspera() + ";" ;  

        // Añadimos la cadena al final del fichero y ponemos un salto de linea
        fout << lineaActividad << "\n";    
        flagActividadGuardada = true;                  
    }

    fout.close();
}

 // Historia de usuario : Crear actividad
void panelActividades::borrarActividad() {
    
}

void panelActividades::numeroActividades() {
    
}

void panelActividades::preinscribirUsuario(int idActividad, std::string nombreUsuario) {
    
    int aforoActividad = 0;
    int numPreinscritos = 0;
    int numLinea = 0; // Linea del fichero donde esta nuestra actividad
    int lineaActual = 0;
    
    std::string lineaActividad;
    std::string cadIdActividad;
    std::string cadAux;
    std::string cadlistaPreinscritos;
    std::string cadlistaEspera;
    std::string lineaActividadNueva;

    bool flagEncontrado = false; // Por defecto no se encuentra la actividad
    
    std::ifstream fin; // Fichero de lectura

    fin.open(this->get_listaActividades()); // Abrimos el fichero
    if(!fin.is_open()){ // Manejo de errores, caso donde no se abra bien el fichero
        std::cout << "ERROR: No se ha podido abrir el fichero" << std::endl;
    } else {
        // Procedemos a leer el fichero y mostrar las actividades
        while (getline(fin, lineaActividad)) {
            std::istringstream streamActividad(lineaActividad); // Objeto para entrada de datos, facilita el manejo de strings

            std::getline(streamActividad, cadIdActividad, ';'); // El primer elemento es el id de la actividad

            if(std::stoi(cadIdActividad) == idActividad) { // Si encontramos la actividad que quiere el usuario continuamos

                for(int i=0; i<9 ; i++){ // Hasta 9 dado que es la posicion del aforo
                    std::getline(streamActividad, cadAux, ';');
                } 
                // El ultimo campo leido es el aforo
                aforoActividad = std::stoi(cadAux);

                for(int i=0; i<11 ; i++){ // Despues de leer 9 veces, el 10º es la lista de preinscritos
                    std::getline(streamActividad, cadAux, ';');
                } 

                cadlistaPreinscritos = cadAux;

                // La siguiente sera la lista de espera
                std::getline(streamActividad, cadAux, ';');

                cadlistaEspera = cadAux;

                flagEncontrado = true;
                break;
            } 
        }
    }

    fin.close();

    if(flagEncontrado){
        // Para saber cuantos hay en la lista cuento las comas
        for (char c : cadlistaPreinscritos) {
            if (c == ',') {
                numPreinscritos++;
            }
        }
        numPreinscritos++; // Dado que hay que sumar uno de mas, ya que las comas son el numero de personas - 1

        if(numPreinscritos+1 <= aforoActividad){ // Si hay espacio en la lista de espera se añade al usuario

            if(cadlistaPreinscritos.empty()){
                cadlistaPreinscritos = nombreUsuario;
            } else {
                cadlistaPreinscritos = cadlistaPreinscritos + ", " + nombreUsuario;
            }

            // Ahora procedemos a añadir al usuario, dado que hay espacio para el
            fin.open(this->get_listaActividades()); // Abrimos el fichero
            if (!fin.is_open()) {
                std::cout << "ERROR: No se ha podido abrir el fichero" << std::endl;
            } else {
                // Procedemos a leer el fichero y mostrar las actividades
                while (getline(fin, lineaActividad)) {
                    std::istringstream streamActividad(lineaActividad);
                    
                    std::getline(streamActividad, cadIdActividad, ';'); // El primer elemento es el id de la actividad
                    
                    if(std::stoi(cadIdActividad) == idActividad) { // Si encontramos la actividad que quiere el usuario continuamos
                        lineaActividadNueva = cadIdActividad + ';'; // En la linea nueva metemos el id
                        for(int j = 0 ; j<=18 ; j++) { // El siguiente sera la lista de preinscritos que nosotros tenemos
                            // Leemos cada campo y lo guardamos
                            std::getline(streamActividad, cadAux, ';');
                            lineaActividadNueva = lineaActividadNueva + cadAux +';';
                        }

                        // Metemos la lista de preinscritos con el usuario inscrito
                        lineaActividadNueva = lineaActividadNueva + cadlistaPreinscritos +';';

                        // Y solo nos queda la lista de espera, saltandonos la lista de preinscritos existente
                        std::getline(streamActividad, cadAux, ';');
                        std::getline(streamActividad, cadAux, ';');
                        lineaActividadNueva = lineaActividadNueva + cadAux +';';

                        break;
                    }
                    numLinea++;

                }
            }
            fin.close();
  
        // Abre el fichero nuevamente, esta vez para lectura y escritura
        std::fstream file(this->get_listaActividades());

        if (!file.is_open()) {
            std::cout << "ERROR: No se ha podido abrir el fichero" << std::endl;
        } else {
            // Crear un fichero temporal para almacenar las líneas actualizadas
            std::ofstream tempFile("tempfile.txt");

            while (getline(file, lineaActividad)) {
                if (lineaActual == numLinea) {
                    // Si estamos en la línea a modificar, ponemos la nueva
                    tempFile << lineaActividadNueva;
                } else {
                    // Si no estamos en la linea a modificar, ponemos las otras lineas
                    tempFile << lineaActividad;
                }

                // Para no meter un espacio vacio en una linea nueva al final del fichero
                if (lineaActual < numLinea - 1 || !file.eof()) {
                    tempFile << std::endl;
                }

                lineaActual++;
            }

            // Cerramos los ficheros
            file.close();
            tempFile.close();

            // Eliminamos el fichero original
            std::remove(this->get_listaActividades().c_str());

            // Renombramos el fichero temporal al nombre original
            std::rename("tempfile.txt", this->get_listaActividades().c_str());
            
            std::cout << "\nUsuario inscrito en la actividad" << std::endl;
        }

        } else {
            std::cout << "No hay espacio en la lista de preinscritos, se te añadira a la lista de espera" << std::endl;
            // Ahora procedemos a añadir al usuario en la lista de espera
            this->inscribirListaEspera(idActividad, nombreUsuario, cadlistaEspera);
        }
    } else {
        std::cout << "ERROR: No se ha encontrado una actividad con ese Id" << std::endl;
    }

}

// Historia de usuario : Preeinscripcion en una actividad
void panelActividades::inscribirListaEspera(int idActividad, std::string nombreUsuario, std::string cadlistaEspera) {

    int numLinea = 0; // Linea del fichero donde esta nuestra actividad
    int lineaActual = 0;

    std::string lineaActividad;
    std::string cadIdActividad;
    std::string cadAux;
    std::string lineaActividadNueva;
    
    std::ifstream fin; // Fichero de lectura

    if(cadlistaEspera == ""){
        cadlistaEspera = nombreUsuario;
    } else {
        cadlistaEspera = cadlistaEspera + ", " + nombreUsuario;
    }

    // Ahora procedemos a añadir al usuario, dado que hay espacio para el
    fin.open(this->get_listaActividades()); // Abrimos el fichero
    if (!fin.is_open()) {
        std::cout << "ERROR: No se ha podido abrir el fichero" << std::endl;
    } else {
        // Procedemos a leer el fichero y mostrar las actividades
        while (getline(fin, lineaActividad)) {
            std::istringstream streamActividad(lineaActividad);
            
            std::getline(streamActividad, cadIdActividad, ';'); // El primer elemento es el id de la actividad
            
            if(std::stoi(cadIdActividad) == idActividad) { // Si encontramos la actividad que quiere el usuario continuamos
                lineaActividadNueva = cadIdActividad + ';'; // En la linea nueva metemos el id
                for(int j = 0 ; j<=19 ; j++) { // El siguiente sera la lista de espera que nosotros tenemos
                    // Leemos cada campo y lo guardamos
                    std::getline(streamActividad, cadAux, ';');
                    lineaActividadNueva = lineaActividadNueva + cadAux +';';
                }

                // Metemos la lista de espera con el usuario inscrito
                lineaActividadNueva = lineaActividadNueva + cadlistaEspera +';';

                break;
            }
            numLinea++;

        }
    }
    fin.close();

    // Ahora sobreescribimos el fichero con la informacion nueva
    std::fstream file(this->get_listaActividades());

    if (!file.is_open()) {
        std::cout << "ERROR: No se ha podido abrir el fichero" << std::endl;
    } else {
        // Crear un fichero temporal para almacenar las líneas actualizadas
        std::ofstream tempFile("tempfile.txt");

        while (getline(file, lineaActividad)) {
            if (lineaActual == numLinea) {
                // Si estamos en la línea a modificar, ponemos la nueva
                tempFile << lineaActividadNueva;
            } else {
                // Si no estamos en la linea a modificar, ponemos las otras lineas
                tempFile << lineaActividad;
            }

            // Para no meter un espacio vacio en una linea nueva al final del fichero
            if (lineaActual < numLinea - 1 || !file.eof()) {
                tempFile << std::endl;
            }

            lineaActual++;
        }

        // Cerramos los ficheros
        file.close();
        tempFile.close();

        // Eliminamos el fichero original
        std::remove(this->get_listaActividades().c_str());

        // Renombramos el fichero temporal al nombre original
        std::rename("tempfile.txt", this->get_listaActividades().c_str());
    }
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



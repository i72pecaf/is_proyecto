#include "usuarioVisitante.hpp"
#include "panelActividades.hpp"
#include <iostream>
#include <fstream>
#include <sstream> // Para facilitar el manejo de cadenas

usuarioVisitante::usuarioVisitante() {

}

void usuarioVisitante::login(std::string &correo, int &rol, bool &flagCorreo) {
    std::ifstream f; 
    
    std::string linea, subCadena;
    std::string auxRol;
    std::string ficheroDatos = "datosUsuariosUCO.txt"; // Fichero con los datos de los usuarios, su rol y correo
    
    std::cout << "\nIntroduce tu correo de la UCO: "; 
    std::cin >> correo;

    // Se procede a comprobar si existe el usuario con ese correo
    f.open(ficheroDatos); // Abrimos el fichero
    if(!f.is_open()){ // Manejo de errores, caso donde no se abra bien el fichero
        std::cout << "ERROR: No se ha podido abrir el fichero" << std::endl;
        flagCorreo = false;
    } else {
        // En caso de que abramos bien el fichero, continuamos el proceso
        while (getline(f, linea)) { // Vamos linea por linea buscando correos
            std::istringstream stream(linea); // Objeto para leer las palabras de la cadena (linea del fichero)
                    
            while (stream >> subCadena) { // Vamos por cada una de las palabras de la linea del fichero
                if(subCadena == correo){ // Si encontramos el correo actualizamos la flag.
                    flagCorreo = true;
                }

                if(flagCorreo) { // En caso de haber leido el correo, la siguiente palabra es su rol.
                    auxRol = subCadena; // Pasamos la cadena a un numero int, el cual sera el rol.
                }
            }
            if (flagCorreo) { // Si encontramos el correo, dejamos de buscar
                break; // Nos salimos del while de leer el fichero
            } // En caso contrario, seguimos leyendo
        }
    }
    if(flagCorreo){ // Solo modificamos el valor del rol si encontramos un correo
        rol = stoi(auxRol);
    }
    f.close();
}

void usuarioVisitante::verActividadesPublicadas() {
    /* PARTE DE LA HISTORIA DE USUARIO OBLIGATORIA : MOSTRAR ANUNCIOS PUBLICADOS Y SUS PREINSCRITOS*/
    
    // Se muestran solo los anuncios publicados
    panelActividades panel;

    panel.mostrarActividades(true);
}
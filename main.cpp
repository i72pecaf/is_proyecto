#include <iostream>
#include <fstream>
#include <sstream> // Para facilitar el manejo de cadenas

using namespace std;

int main(){
    // -- Bloque de declaración de variables usadas
    int opt;
    int rol = 0 ; // 0: visitante, 1: director academico, 2: organizador, 3: usuario registrado
    
    string email;
    string linea, subCadena;
    string auxRol;
    
    string ficheroDatos = "datosUsuariosUCO.txt"; // Fichero con los datos de los usuarios, su rol y correo

    ifstream f;

    bool flagCorreo = false; // Para saber si se ha encontrado el correo o no.

    
    // -- Bloque de código
    cout << "\n---------------------------------------------" << endl;
    cout << "Bienvenido al gestor de actividades de la UCO" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "[1] - Acceder con correo de la UCO" << endl;
    cout << "[2] - Acceder como visitante (Solo podras ver los anuncios)" << endl;
    cout << "[3] - Cerrar el programa" << endl;
    cout << "\n> ";
    
    cin >> opt;

    switch(opt){
        case 1: // Modo logueado
            cout << "\nIntroduce tu correo de la UCO: "; 
            cin >> email;
           
            // Se procede a comprobar si existe el usuario con ese correo
            f.open(ficheroDatos); // Abrimos el fichero
            if(!f.is_open()){ // Manejo de errores, caso donde no se abra bien el fichero
                cout << "Error al abrir el fichero" << endl;
                break; // Salimos del switch en caso de error
            }

            while (getline(f, linea)) { // Vamos linea por linea buscando correos
                istringstream stream(linea); // Objeto para leer las palabras de la cadena (linea del fichero)
                
                while (stream >> subCadena) { // Vamos por cada una de las palabras de la linea del fichero
                    if(subCadena == email){ // Si encontramos el correo actualizamos la flag.
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

            f.close();

            if(!flagCorreo){
                cout << "Error: No se ha encontrado un usuario con ese correo" << endl;
                break; // Salimos del switch en caso de error
            }
        
            cout << "El rol de tu correo es: " << rol << endl;

        break;
        
        case 2: // Modo visitante
            cout << "\nSe procede a mostrar los anuncios..." << endl;
        break;
        
        case 3: // Salir del programa
            cout << "\nSaliendo del programa..." << endl;
        break;

        default: // Error
            cout << "\nError: Opcion introducida incorrecta" << endl;
    }
    cout << "\nPrograma finalizado" << endl;
}
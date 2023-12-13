#include <iostream>


#include "usuarioVisitante.hpp"

using namespace std;

int main(){
    // -- Bloque de declaración de variables usadas
    int opt, optRol; // Variables para los switches
    int rol = 0 ; // 0: visitante, 1: organizador (admin), 2: director academico, 3: usuario registrado

    string correo;
    bool flagCorreo = false; // Para saber si se ha encontrado el correo o no.

    usuarioVisitante usuario_v;
    
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

            // Se procede a ver quién es el usuario
            usuario_v.login(correo, rol, flagCorreo);

            if(!flagCorreo){
                cout << "ERROR: No se ha encontrado un usuario con ese correo" << endl;
                break; // Salimos del switch en caso de error
            }
            
            cout << "\nLogueado correctamente!" << endl;

            // Ahora, mostramos las diferentes funciones dependiendo de su rol.
            switch (rol) {
                case 1: // Caso del organizador (admin)
                    cout << "\n---------------------------------------------" << endl;
                    cout << "Hola coordinador " << correo << ". Indica qué quieres hacer" << endl;
                    cout << "---------------------------------------------" << endl;
                    cout << "[1] - Crear anuncio" << endl;
                    cout << "[2] - Ver todos los anuncio" << endl;
                    cout << "[3] - Cerrar el programa" << endl;
                    cout << "\n> ";

                    cin >> optRol;

                    switch (optRol)  { // Switch para el coordinador
                        case 1: // Creacion de un anuncio

                        break;
                        
                        case 2: // Creacion de un anuncio

                        break;

                        case 3: // Salir del programa
                            cout << "\nSaliendo del programa..." << endl;
                        break;

                        default: // Error al introducir una opcion no existente
                            cout << "\nERROR: Opcion introducida incorrecta. Finalizando programa..." << endl;
                        break;
                    }

                break; 

                case 2: // Caso del director academico
                    cout << "\n---------------------------------------------" << endl;
                    cout << "Hola director académico " << correo << ". Indica qué quieres hacer" << endl;
                    cout << "---------------------------------------------" << endl;
                    cout << "[3] - Cerrar el programa " << endl;
                    cout << "\n> ";

                break;

                case 3: // Caso del usuario registrado
                    cout << "\n---------------------------------------------" << endl;
                    cout << "Hola usuario " << correo << ". Indica qué quieres hacer" << endl;
                    cout << "---------------------------------------------" << endl;
                    cout << "[1] - Ver anuncios" << endl;
                    cout << "[2] - Preeinscribirse en un anuncio (Necesitas su código)" << endl;
                    cout << "[3] - Cerrar el programa" << endl;
                    cout << "\n> ";

                    cin >> optRol;

                    switch (optRol)  { // Switch para el usuario registrado
                        case 1: // Ver anuncios publicados

                            break;
                        
                        case 2: // Preeinscripción en un anuncio

                            break;

                        case 3: // Salir del programa
                            cout << "\nSaliendo del programa..." << endl;
                            break;

                        default: // Error al introducir una opcion no existente
                            cout << "\nERROR: Opcion introducida incorrecta. Finalizando programa..." << endl;
                            break;
                    }

                break;
            
                default:
                    cout << "ERROR: Rol leido desconocido" << endl;
                break;
            }

        break;
        
        case 2: // Modo visitante
            cout << "\nSe procede a mostrar los anuncios..." << endl;
            usuario_v.verActividadesPublicadas();
        break;
        
        case 3: // Salir del programa
            cout << "\nSaliendo del programa..." << endl;
        break;

        default: // Error
            cout << "\nERROR: Opcion introducida incorrecta. Finalizando programa..." << endl;
    }
    cout << "\nPrograma finalizado" << endl;
}
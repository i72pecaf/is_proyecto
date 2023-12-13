#include <iostream>


#include "usuarioVisitante.hpp"

using namespace std;

int main(){
    // -- Bloque de declaración de variables usadas
    int opt;
    int rol = 0 ; // 0: visitante, 1: director academico, 2: organizador, 3: usuario registrado

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

            usuario_v.login(correo, rol, flagCorreo);

            if(!flagCorreo){
                cout << "Error: No se ha encontrado un usuario con ese correo" << endl;
                break; // Salimos del switch en caso de error
            }
        
            cout << "CORRECTO - Correo: " << correo << " Rol: " << rol << endl;


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
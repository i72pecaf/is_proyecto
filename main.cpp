#include <iostream>

#include "usuarioVisitante.hpp"
#include "usuarioRegistrado.hpp"
#include "organizador.hpp"
#include "director.hpp"
#include "actividad.hpp"

using namespace std;

int main(){
    // -- Bloque de declaración de variables usadas
    int opt, optRol; // Variables para los switches
    int rol = 0 ; // 0: visitante, 1: organizador (admin), 2: director academico, 3: usuario registrado

    string correo;
    bool flagCorreo = false; // Para saber si se ha encontrado el correo o no.
    bool flagOut = false; // Por defecto, el programa pide opciones continuamente

    usuarioVisitante usuario_v;

    /* ====================== Borrar tras desarrollar ======================*/
    organizador org;
    correo = "i72pecaf@uco.es";
    org.crearActividad();

    cout << "\n\n\n";
    /* ===================================================================== */

    // -- Bloque de código
    cout << "\n---------------------------------------------" << endl;
    cout << "Bienvenido al gestor de actividades de la UCO" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "[1] - Acceder con correo de la UCO" << endl;
    cout << "[2] - Acceder como visitante (Solo podras ver las actividades)" << endl;
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
                case 1: { // Caso del organizador (admin)

                    organizador org;
                    while(!flagOut) { // Mientras el usuario no quiera salir, continuamos preguntando opciones
                        cout << "\n---------------------------------------------" << endl;
                        cout << "Hola coordinador " << correo << ". Indica qué quieres hacer" << endl;
                        cout << "---------------------------------------------" << endl;
                        cout << "[1] - Crear actividad" << endl;
                        cout << "[2] - Ver todas las actividades" << endl;
                        cout << "[3] - Cerrar el programa" << endl;
                        cout << "\n> ";

                        cin >> optRol;

                        switch (optRol)  { // Switch para el coordinador
                            case 1: // Creacion de una actividad
                                org.crearActividad();
                            break;
                            
                            case 2: // Ver todas las actividades
                                org.verTodasActividades();
                            break;

                            case 3: // Salir del programa
                                cout << "\nSaliendo del programa..." << endl;
                                flagOut = true;
                            break;

                            default: // Error al introducir una opcion no existente
                                cout << "\nERROR: Opcion introducida incorrecta. Finalizando programa..." << endl;
                                flagOut = true;
                            break;
                        }
                    }
                }
                break; 

                case 2: {// Caso del director academico

                    director dct;

                    while(!flagOut) { // Mientras el usuario no quiera salir, continuamos preguntando opciones
                        cout << "\n---------------------------------------------" << endl;
                        cout << "Hola director académico " << correo << ". Indica qué quieres hacer" << endl;
                        cout << "---------------------------------------------" << endl;
                        cout << "[3] - Cerrar el programa " << endl;
                        cout << "\n> ";

                        dct.completarActividad();
                    }
                }
                break;

                case 3: {// Caso del usuario registrado

                    usuarioRegistrado usuario_r(correo); // Creamos el objeto del usuario registrado con los metodos

                    while(!flagOut) { // Mientras el usuario no quiera salir, continuamos preguntando opciones
                        cout << "\n---------------------------------------------" << endl;
                        cout << "Hola usuario " << correo << ". Indica qué quieres hacer" << endl;
                        cout << "---------------------------------------------" << endl;
                        cout << "[1] - Ver actividades publicadas" << endl;
                        cout << "[2] - Preeinscribirse en un anuncio (Necesitas su código)" << endl;
                        cout << "[3] - Cerrar el programa" << endl;
                        cout << "\n> ";

                        cin >> optRol;

                        switch (optRol)  { // Switch para el usuario registrado
                            case 1: // Ver actividades publicadas
                                usuario_r.verActividadesPublicadas();
                            break;
                            
                            case 2: // Preeinscripción en un anuncio
                                usuario_r.preinscripcionActividad();
                            break;

                            case 3: // Salir del programa
                                cout << "\nSaliendo del programa..." << endl;
                                flagOut = true;
                            break;

                            default: // Error al introducir una opcion no existente
                                cout << "\nERROR: Opcion introducida incorrecta. Finalizando programa..." << endl;
                                flagOut = true;
                            break;
                        }
                    }
                }
                break;
            
                default:
                    cout << "ERROR: Rol leido desconocido" << endl;
                break;
            }

        break;
        
        case 2: // Modo visitante
            cout << "\nSe procede a mostrar las actividades..." << endl;
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
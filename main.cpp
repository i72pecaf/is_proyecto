#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int opt;
    //int rol; // 0: visitante, 1: director academico, 2: organizador, 3: usuario registrado
    string correo;

    ifstream f;
    string ficheroDatos = "datosUsuariosUCO.txt"; // Fichero con los datos de los usuarios, su rol y correo
    
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
            cin >> correo;
            // Se procede a comprobar si existe el usuario con ese correo
            cout << "\nEl correo introducido ha sido" << correo << endl;

            f.open(ficheroDatos);

            if(!f.is_open()){ // Manejo de errores, caso donde no se abra bien el fichero
                cout << "Error al abrir el fichero" << endl;
                break; // Salimos del switch en caso de error
            }

            string var;
            while (getline(f, var, ' '))
            {
                cout << "Un valor: " << lectura << endl;
            }

            f.close();

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
#include <gtest/gtest.h>
#include <fstream>
#include "../src/panelActividades.hpp"

TEST(Test_HistoriaUsuario_3, Test1) {
    // Test para comprobar que se añade a la lista de preinscritos estando la lista con usuarios ya inscritos
    // Cadena con la actividad
    std::string cadActividad = "101;1;Seminario;i72ritom@uco.es;Seminario de Inteligencia artificial;Se habla de la IA;25.000000;IA;Campos de Rabanales, Aulario Averroes, P10;50;5.000000;i92mojip@uco.es;20/12/2023;21/12/2023;;Dos horas;Programacion en Python;;;;i72pecaf@uco.es, i81pegun@uco.es;;";
    // Cadena con el usuario preinscrito
    std::string cadPreinscrito = "101;1;Seminario;i72ritom@uco.es;Seminario de Inteligencia artificial;Se habla de la IA;25.000000;IA;Campos de Rabanales, Aulario Averroes, P10;50;5.000000;i92mojip@uco.es;20/12/2023;21/12/2023;;Dos horas;Programacion en Python;;;;i72pecaf@uco.es, i81pegun@uco.es, i90regad@uco.es;;";
    
    std::string lineaFichero;
    std::string ultimaActividadFichero;

    bool usuarioPreinscrito = false;

    panelActividades panel;

    // Usamos un fichero auxiliar para no machacar lo que ya hay en el original
    std::string ficheroTemp = "tempTest3.txt";

    // Abrir el archivo en modo de escritura
    std::ofstream fout(ficheroTemp);

    // Verificar si el archivo se abrió correctamente
    if (!fout.is_open()) {
            std::cout << "Error al abrir el archivo." << std::endl;
    } else {
        fout << cadActividad << "\n";
    }

    fout.close();

    panel.set_listaActividades(ficheroTemp);

    panel.preinscribirUsuario(101, "i90regad@uco.es");

    // Abrimos el fichero y leemos la ultima linea
    std::ifstream fin(ficheroTemp);

    if (!fin.is_open()) {
        usuarioPreinscrito = false;
    } else {
        while (std::getline(fin, lineaFichero)){
            ultimaActividadFichero = lineaFichero;
        }
    }

    fin.close();

    // Si ambas son iguales, la funcion funciona correctamente
    if(cadPreinscrito == ultimaActividadFichero){
        usuarioPreinscrito = true;
    } else {
        usuarioPreinscrito = false;
    }

    EXPECT_TRUE(usuarioPreinscrito);
    remove(ficheroTemp.c_str());
}

TEST(Test_HistoriaUsuario_3, Test2) {
    // Test para comprobar que se añade a la lista de preinscritos estando la lista vacia
    // Cadena con la actividad
    std::string cadActividad = "101;1;Seminario;i72ritom@uco.es;Seminario de Inteligencia artificial;Se habla de la IA;25.000000;IA;Campos de Rabanales, Aulario Averroes, P10;50;5.000000;i92mojip@uco.es;20/12/2023;21/12/2023;;Dos horas;Programacion en Python;;;;;;";
    // Cadena con el usuario preinscrito
    std::string cadPreinscrito = "101;1;Seminario;i72ritom@uco.es;Seminario de Inteligencia artificial;Se habla de la IA;25.000000;IA;Campos de Rabanales, Aulario Averroes, P10;50;5.000000;i92mojip@uco.es;20/12/2023;21/12/2023;;Dos horas;Programacion en Python;;;;i90regad@uco.es;;";
    
    std::string lineaFichero;
    std::string ultimaActividadFichero;

    bool usuarioPreinscrito = false;

    panelActividades panel;

    // Usamos un fichero auxiliar para no machacar lo que ya hay en el original
    std::string ficheroTemp = "tempTest3.txt";

    // Abrir el archivo en modo de escritura
    std::ofstream fout(ficheroTemp);

    // Verificar si el archivo se abrió correctamente
    if (!fout.is_open()) {
            std::cout << "Error al abrir el archivo." << std::endl;
    } else {
        fout << cadActividad << "\n";
    }

    fout.close();

    panel.set_listaActividades(ficheroTemp);

    panel.preinscribirUsuario(101, "i90regad@uco.es");

    // Abrimos el fichero y leemos la ultima linea
    std::ifstream fin(ficheroTemp);

    if (!fin.is_open()) {
        usuarioPreinscrito = false;
    } else {
        while (std::getline(fin, lineaFichero)){
            ultimaActividadFichero = lineaFichero;
        }
    }

    fin.close();

    // Si ambas son iguales, la funcion funciona correctamente
    if(cadPreinscrito == ultimaActividadFichero){
        usuarioPreinscrito = true;
    } else {
        usuarioPreinscrito = false;
    }

    EXPECT_TRUE(usuarioPreinscrito);
    remove(ficheroTemp.c_str());
}

TEST(Test_HistoriaUsuario_3, Test3) {
    // Test para comprobarla el introducir al usuario en la lista de espera cuando esta tiene ya usuarios
    // Cadena con la actividad
    std::string cadActividad = "101;1;Seminario;i72ritom@uco.es;Seminario de Inteligencia artificial;Se habla de la IA;25.000000;IA;Campos de Rabanales, Aulario Averroes, P10;2;5.000000;i92mojip@uco.es;20/12/2023;21/12/2023;;Dos horas;Programacion en Python;;;;i92mojip@uco.es, i81pegun@uco;a32pecaf@uco.es;";
    // Cadena con el usuario preinscrito
    std::string cadPreinscrito = "101;1;Seminario;i72ritom@uco.es;Seminario de Inteligencia artificial;Se habla de la IA;25.000000;IA;Campos de Rabanales, Aulario Averroes, P10;2;5.000000;i92mojip@uco.es;20/12/2023;21/12/2023;;Dos horas;Programacion en Python;;;;i92mojip@uco.es, i81pegun@uco;a32pecaf@uco.es, i90regad@uco.es;";
    
    std::string lineaFichero;
    std::string ultimaActividadFichero;

    bool usuarioPreinscrito = false;

    panelActividades panel;

    // Usamos un fichero auxiliar para no machacar lo que ya hay en el original
    std::string ficheroTemp = "tempTest3.txt";

    // Abrir el archivo en modo de escritura
    std::ofstream fout(ficheroTemp);

    // Verificar si el archivo se abrió correctamente
    if (!fout.is_open()) {
            std::cout << "Error al abrir el archivo." << std::endl;
    } else {
        fout << cadActividad << "\n";
    }

    fout.close();

    panel.set_listaActividades(ficheroTemp);

    panel.preinscribirUsuario(101, "i90regad@uco.es");

    // Abrimos el fichero y leemos la ultima linea
    std::ifstream fin(ficheroTemp);

    if (!fin.is_open()) {
        usuarioPreinscrito = false;
    } else {
        while (std::getline(fin, lineaFichero)){
            ultimaActividadFichero = lineaFichero;
        }
    }

    fin.close();

    // Si ambas son iguales, la funcion funciona correctamente
    if(cadPreinscrito == ultimaActividadFichero){
        usuarioPreinscrito = true;
    } else {
        usuarioPreinscrito = false;
    }

    EXPECT_TRUE(usuarioPreinscrito);
    remove(ficheroTemp.c_str());
}


TEST(Test_HistoriaUsuario_3, Test4) {
    // Test para comprobarla el introducir al usuario en la lista de espera cuando esta esta vacia
    // Cadena con la actividad
    std::string cadActividad = "101;1;Seminario;i72ritom@uco.es;Seminario de Inteligencia artificial;Se habla de la IA;25.000000;IA;Campos de Rabanales, Aulario Averroes, P10;2;5.000000;i92mojip@uco.es;20/12/2023;21/12/2023;;Dos horas;Programacion en Python;;;;i92mojip@uco.es, i81pegun@uco;;";
    // Cadena con el usuario preinscrito
    std::string cadPreinscrito = "101;1;Seminario;i72ritom@uco.es;Seminario de Inteligencia artificial;Se habla de la IA;25.000000;IA;Campos de Rabanales, Aulario Averroes, P10;2;5.000000;i92mojip@uco.es;20/12/2023;21/12/2023;;Dos horas;Programacion en Python;;;;i92mojip@uco.es, i81pegun@uco;i90regad@uco.es;";
    
    std::string lineaFichero;
    std::string ultimaActividadFichero;

    bool usuarioPreinscrito = false;

    panelActividades panel;

    // Usamos un fichero auxiliar para no machacar lo que ya hay en el original
    std::string ficheroTemp = "tempTest3.txt";

    // Abrir el archivo en modo de escritura
    std::ofstream fout(ficheroTemp);

    // Verificar si el archivo se abrió correctamente
    if (!fout.is_open()) {
            std::cout << "Error al abrir el archivo." << std::endl;
    } else {
        fout << cadActividad << "\n";
    }

    fout.close();

    panel.set_listaActividades(ficheroTemp);

    panel.preinscribirUsuario(101, "i90regad@uco.es");

    // Abrimos el fichero y leemos la ultima linea
    std::ifstream fin(ficheroTemp);

    if (!fin.is_open()) {
        usuarioPreinscrito = false;
    } else {
        while (std::getline(fin, lineaFichero)){
            ultimaActividadFichero = lineaFichero;
        }
    }

    fin.close();

    // Si ambas son iguales, la funcion funciona correctamente
    if(cadPreinscrito == ultimaActividadFichero){
        usuarioPreinscrito = true;
    } else {
        usuarioPreinscrito = false;
    }

    EXPECT_TRUE(usuarioPreinscrito);
    remove(ficheroTemp.c_str());
}
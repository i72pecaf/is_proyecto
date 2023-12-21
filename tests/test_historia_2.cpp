#include <gtest/gtest.h>
#include <fstream>
#include "../src/panelActividades.hpp"

TEST(Test_HistoriaUsuario_2, Test1) {
    // Comprobamos que el mostrar anuncio maneja correctamente el caso donde el fichero este vacio
    std::string ficheroVacio = "tempTest2.txt.txt";
    std::ofstream ftemp(ficheroVacio);
    ftemp.close();

    panelActividades panel;
    panel.set_listaActividades(ficheroVacio);
    EXPECT_NO_THROW(panel.mostrarActividades(true));
    remove(ficheroVacio.c_str());
    // Se muestra correctamente al usuario que el fichero esta vacio
}

TEST(Test_HistoriaUsuario_2, Test2) {
     // Comprobamos que el mostrar anuncio maneja correctamente el caso donde el fichero no exista
    std::string ficheroInexistente = "ficheroInexistente.txt";

    panelActividades panel;
    panel.set_listaActividades(ficheroInexistente);
    EXPECT_NO_THROW(panel.mostrarActividades(true));
    // Se muestra correctamenet al usuario que el fichero no existe
}

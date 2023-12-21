#include <gtest/gtest.h>
#include "../src/panelActividades.hpp"
#include "../src/actividad.hpp"

TEST(Test_HistoriaUsuario_1, Test1) {

    ASSERT_TRUE(true);
}

TEST(Test_HistoriaUsuario_1, Test2) {
    // Test para comprobar que se introduce el anuncio correctamente en el fichero
    bool anuncioIntroducido = false;
    
    panelActividades panel;
    actividad a;

    // Introducimos los datos cuales sean
    a.set_idActividad(999);
    a.set_estado(true);
    a.set_tipo("Seminario");
    a.set_director("i72ritom@uco.es");
    a.set_nombre("Seminario de Inteligencia artificial");
    a.set_descripcion("Se habla de la IA");
    a.set_asistencia(25);
    a.set_tema("IA");
    a.set_ubicacion("Campos de Rabanales, Aulario Averroes, P10");
    a.set_aforo(50);
    a.set_precio(5);
    a.set_ponente("i92mojip@uco.es");
    // Se definen asi las fechas dada la estructura usada para el formato de fechas
    // Variables tipo std::tm
    std::tm fechaInicio = {};
    std::tm fechaFin = {};
    // Fecha de inicio
    fechaInicio.tm_sec = 0;
    fechaInicio.tm_min = 0;
    fechaInicio.tm_hour = 0;
    fechaInicio.tm_mday = 20;   // Dia
    fechaInicio.tm_mon = 11;   // Mes (Del 0-11, Diciembre = 11)
    fechaInicio.tm_year = 123;  // Año (Es desde 1900, es decir, 1900 + 123 = 2023)
    // Fecha de fin
    fechaFin.tm_sec = 0;
    fechaFin.tm_min = 0;
    fechaFin.tm_hour = 0;
    fechaFin.tm_mday = 21;   // Dia
    fechaFin.tm_mon = 11;   // Mes (Del 0-11, Diciembre = 11)
    fechaFin.tm_year = 123;  // Año (Es desde 1900, es decir, 1900 + 123 = 2023)

    a.set_fechaInicio(fechaInicio);
    a.set_fechaFinal(fechaFin);
    // No hay tipo del debate porque no es debate
    a.set_duracion("Dos horas");
    a.set_tareas("Programacion en Python");
    // No hay nivel
    // No hay dias

    // Introducimos el anuncio en el fichero
    panel.introducirActividad(a, anuncioIntroducido);
}
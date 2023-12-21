#include <gtest/gtest.h>
#include <fstream>
#include "../src/panelActividades.hpp"
#include "../src/actividad.hpp"

TEST(Test_HistoriaUsuario_1, Test1) {

    ASSERT_TRUE(true);
}

TEST(Test_HistoriaUsuario_1, Test2) {
    // Test para comprobar que se introduce el anuncio correctamente en el fichero
    // Esta es la cadena que queremos ver si se ha introducido bien al final del fichero
    std::string cadenaAux = "1;Seminario;i72ritom@uco.es;Seminario de Inteligencia artificialSe habla de la IA;25.000000;IA;Campos de Rabanales, Aulario Averroes, P10;50.000000;5.000000;i92mojip@uco.es;20/12/2023;20/12/202321/12/2023;;Dos horas;Programacion en Python;;;;;i72pecaf@uco.es, i81pegun@uco.es;";
    std::string ultimaLineaFichero;

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
    // No hay preinscritos
    a.set_listaEspera("i72pecaf@uco.es, i81pegun@uco.es");
    // No hay lista de espera

    // Introducimos el anuncio en el fichero
    panel.introducirActividad(a, anuncioIntroducido);

    // Abrimos el fichero y leemos la ultima linea
    std::ifstream fin("../actividades.txt");

    if (!fin.is_open()) {
        anuncioIntroducido = false;
    } else {
        while (std::getline(fin, ultimaLineaFichero)){
            // No queremos hacer nada, solo obtener el ultimo valor, la ultima linea sera la introducida
        }
    }

    fin.close();
    // Si ambas son iguales, la funcion de introducirActividad funciona correctamente
    if(cadenaAux == ultimaLineaFichero){
        anuncioIntroducido = true;
    } else {
        anuncioIntroducido = false;
    }

    EXPECT_TRUE(anuncioIntroducido);
}
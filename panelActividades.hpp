#ifndef PANELACTIVIDADES_HPP
#define PANELACTIVIDADES_HPP

#include <iostream>
#include <vector>
#include "actividad.hpp"

class panelActividades {
    
    private:
        /* Atributo relacionado con el fichero con los anuncios. En el manual tecnico, corresponden
           al atributo listaActividades de la clase panelActividades del diagrama de clases*/
        std::string _listaActividades = "actividades.txt"; // Esto es el nombre del fichero
        // Atributos para las actividades y para los directores academicos existentes
        std::vector<std::string> _listaTiposActividades;
        std::vector<std::string> _listaDirectoresAcademicos;

    
    public:
        panelActividades() {
            _listaTiposActividades = {"Congreso", "Debate", "Ponencia", "Seminario", "Taller"}; // Tipos de actividades según los requisitos
        }

        // Getters y setters de los atributos. Implementados pero no son necesarios de cara a las historias de usuario obligatorias
        inline void set_listaActividades(std::string nuevalistaActividades) { _listaActividades = nuevalistaActividades; }
        inline std::string get_listaActividades() { return _listaActividades; }

        inline void set_listaTiposActividades(std::vector<std::string> nuevalistaTiposActividades) { _listaTiposActividades = nuevalistaTiposActividades; }
        inline std::vector<std::string> get_listaTiposActividades() { return _listaTiposActividades; }

        inline void set_listaDirectoresAcademicos(std::vector<std::string> nuevalistaDirectoresAcademicos) { _listaDirectoresAcademicos = nuevalistaDirectoresAcademicos; }
        inline std::vector<std::string> get_listaDirectoresAcademicos() { return _listaDirectoresAcademicos; }

        void buscarActividad();
        void mostrarActividades(); // Historia de usuario : Mostrar actividades
        void introducirActividad(); // Historia de usuario : Crear actividad
        void borrarActividad();
        void numeroActividades();
        void preinscribirUsuario(); // Historia de usuario : Preeinscripcion en una actividad
        void inscribirListaEspera();
        std::string tiposActividades(); // Historia de usuario : Crear actividad - Necesario para su funcionamiento
        void introducirDirectores();
        void borrarDirectores();
        void verDirectoreS();

};

#endif
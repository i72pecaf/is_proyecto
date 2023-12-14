#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include <iostream>
#include <vector>
#include "actividad.hpp"

class panelActividades {
    
    private:
        /* Atributo relacionado con el fichero con los anuncios. En el manual tecnico, corresponden
           al atributo listaActividades de la clase panelActividades del diagrama de clases*/
        std::string _listaActividades = "actividades.txt"; // Esto es el nombre del fichero
        // Atributos para las actividades y para los directores academicos existentes
        std::vector<string> _listaTiposActividades;
        std::vector<string> _listaDirectoresAcademicos;

    
    public:
        panelActividades() {

        }

        // Getters y setters de los atributos. Implementados pero no son necesarios de cara a las historias de usuario obligatorias
        inline void set_listaActividades(std::string listaActividades) { _listaActividades = nuevaLista; }
        inline std::string get_listaActividades() { return _listaActividades; }

        inline void set_listaTiposActividades(std::vector<std::string> listaTiposActividades) { _listaTiposActividades = nuevaLista; }
        inline std::vector<std::string> get_listaTiposActividades() { return _listaTiposActividades; }

        inline void set_listaDirectoresAcademicos(std::vector<std::string> listaDirectoresAcademicos) { _listaDirectoresAcademicos = nuevaLista; }
        inline std::vector<std::string> get_listaDirectoresAcademicos() { return _listaDirectoresAcademicos; }

        void buscarActividad();
        void mostrarActividades(); // Historia de usuario : Mostrar actividades
        void introducirActividad(); // Historia de usuario : Crear actividad
        void borrarActividad();
        void numeroActividades();
        void preinscribirUsuario(); // Historia de usuario : Preeinscripcion en una actividad
        void inscribirListaEspera();
        string tiposActividades(); // Historia de usuario : Crear actividad - Necesario para su funcionamiento
        void introducirDirectores();
        void borrarDirectores();
        void verDirectoreS();

};

#endif
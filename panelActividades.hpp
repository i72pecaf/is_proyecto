#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include <iostream>
#include <vector>
#include "actividad.hpp"

class panelActividades {
    
    private:
        std::vector<actividad> _listaActividades;
        std::vector<string> _listaTiposActividades;
        std::vector<string> _listaDirectoresAcademicos;

    
    public:
        panelActividades() {
            _listaActividades({});
            _listaTiposActividades({});
            _listaDirectoresAcademicos({}); 
        }

        inline void set_listaActividades(std::vector<actividad> listaActividades) { _listaActividades = nuevaLista; }
        inline std::vector<actividad> get_listaActividades() { return _listaActividades; }

        inline void set_listaTiposActividades(std::vector<std::string> listaTiposActividades) { _listaTiposActividades = nuevaLista; }
        inline std::vector<std::string> get_listaTiposActividades() { return _listaTiposActividades; }

        inline void set_listaDirectoresAcademicos(std::vector<std::string> listaDirectoresAcademicos) { _listaDirectoresAcademicos = nuevaLista; }
        inline std::vector<std::string> get_listaDirectoresAcademicos() { return _listaDirectoresAcademicos; }

        void buscarActividad();
        void mostrarActividades();
        void introducirActividad();
        void borrarActividad();
        void numeroActividades();
        void preinscribirUsuario();
        void inscribirListaEspera();
        string tiposActividades();
        void introducirDirectores();
        void borrarDirectores();
        void verDirectoreS();


};

#endif
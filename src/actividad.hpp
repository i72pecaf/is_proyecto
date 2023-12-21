#ifndef ACTIVIDAD_HPP
#define ACTIVIDAD_HPP

#include <iostream>
#include <vector>
#include <ctime> // Para el manejo de fechas

class actividad {
    
    private:
        int _idActividad;
        std::string _tipo;
        std::string _director;
        float _asistencia;
        std::string _nombre;
        std::string _descripcion;
        std::string _tema;
        std::string _ubicacion;
        int _aforo;
        float _precio;
        std::string _ponente;
        std::tm _fechaInicio;
        std::tm _fechaFinal;
        std::string _tipoDebate;
        std::string _duracion;
        std::string _tareas;
        std::string _nivel;
        std::string _dias;
        bool _estado;
        std::string _listaInscritos;
        std::string _listaPreinscritos;
        std::string _listaEspera;

    public:
        actividad() { // Constructor por defecto, con valores por defecto
            _idActividad = 0;
            _tipo = "";
            _director = "";
            _asistencia = 0.0;
            _nombre = "";
            _descripcion = "";
            _tema = "";
            _ubicacion = "";
            _aforo = 0;
            _precio = 0.0;
            _ponente = "";
            _fechaInicio = {};
            _fechaFinal = {};
            _tipoDebate = "";
            _duracion = "";
            _tareas = "";
            _nivel = "";
            _dias = "";
            _estado = false; // Por defecto la actividad no esta publicada
            _listaInscritos = "";
            _listaPreinscritos = "";
            _listaEspera = "";
        }

        inline void set_idActividad(int id) { _idActividad = id; }
        inline int get_idActividad() { return _idActividad; }

        inline void set_tipo(std::string tipo) { _tipo = tipo; }
        inline std::string get_tipo() { return _tipo; }

        inline void set_director(std::string director) { _director = director; }
        inline std::string get_director() { return _director; }

        inline void set_asistencia(float asistencia) { _asistencia = asistencia; }
        inline float get_asistencia() { return _asistencia; }

        inline void set_nombre(std::string nombre) { _nombre = nombre; }
        inline std::string get_nombre() { return _nombre; }

        inline void set_descripcion(std::string descripcion) { _descripcion = descripcion; }
        inline std::string get_descripcion() { return _descripcion; }

        inline void set_tema(std::string tema) { _tema = tema; }
        inline std::string get_tema() { return _tema; }

        inline void set_ubicacion(std::string ubicacion) { _ubicacion = ubicacion; }
        inline std::string get_ubicacion() { return _ubicacion; }

        inline void set_aforo(float aforo) { _aforo = aforo; }
        inline float get_aforo() { return _aforo; }

        inline void set_precio(float precio) { _precio = precio; }
        inline float get_precio() { return _precio; }

        inline void set_ponente(std::string ponente) { _ponente = ponente; }
        inline std::string get_ponente() { return _ponente; }

        inline void set_fechaInicio(std::tm fechaInicio) { _fechaInicio = fechaInicio; }
        inline std::tm& get_fechaInicio() { return _fechaInicio; }

        inline void set_fechaFinal(std::tm fechaFinal) { _fechaFinal = fechaFinal; }
        inline std::tm& get_fechaFinal() { return _fechaFinal; }

        inline void set_tipoDebate(std::string tipoDebate) { _tipoDebate = tipoDebate; }
        inline std::string get_tipoDebate() { return _tipoDebate; }

        inline void set_duracion(std::string duracion) { _duracion = duracion; }
        inline std::string get_duracion() { return _duracion; }

        inline void set_tareas(std::string tareas) { _tareas = tareas; }
        inline std::string get_tareas() { return _tareas; }

        inline void set_nivel(std::string nivel) { _nivel = nivel; }
        inline std::string get_nivel() { return _nivel; }

        inline void set_dias(std::string dias) { _dias = dias; }
        inline std::string get_dias() { return _dias; }

        inline void set_estado(bool estado) { _estado = estado; }
        inline bool get_estado() { return _estado; }

        inline std::string get_listaInscritos() { return _listaInscritos; }
        inline void set_listaInscritos(std::string listaInscritosNueva) { _listaInscritos = listaInscritosNueva; }

        inline std::string get_listaPreinscritos() { return _listaPreinscritos; }
        inline void set_listaPreinscritos(std::string listaPreinscritosNueva) { _listaPreinscritos = listaPreinscritosNueva; }

        inline std::string get_listaEspera() { return _listaEspera; }
        inline void set_listaEspera(std::string listaEsperaNueva) { _listaEspera = listaEsperaNueva; }
};

#endif
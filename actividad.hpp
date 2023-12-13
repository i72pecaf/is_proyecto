#ifndef ACTIVIDAD_HPP
#define ACTIVIDAD_HPP

#include <iostream>
#include <vector>

class activdad {
    
    private:
        int _idAnuncio;
        std::string _tipo;
        std::string _director;
        float _asistencia;
        std::string _nombre;
        std::string _descripcion;
        std::string _tema;
        std::string _ubicacion;
        float _precio;
        std::string _ponente;
        std::string _fechaInicio;
        std::string _fechaFinal;
        std::string _tipoDebate;
        std::string _duracion;
        std::string _tareas;
        std::string _nivel;
        std::string _dias;
        bool _estado;
        std::vector<std::string> _listaEspera; // Vector de strings

    public:
        actividad() { // Constructor por defecto, con valores por defecto
            _idAnuncio = 0;
            _tipo = "";
            _director = "";
            _asistencia = 0.0;
            _nombre = "";
            _descripcion = "";
            _tema = "";
            _ubicacion = "";
            _precio = 0.0;
            _ponente = "";
            _fechaInicio = "";
            _fechaFinal = "";
            _tipoDebate = "";
            _duracion = "";
            _tareas = "";
            _nivel = "";
            _dias = "";
            _estado = false;
            _listaEspera({}) // Establecemos el array vacio por defecto, sin nadie en la lista de espera
        }

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

        inline void set_precio(float precio) { _precio = precio; }
        inline float get_precio() { return _precio; }

        inline void set_ponente(std::string ponente) { _ponente = ponente; }
        inline std::string get_ponente() { return _ponente; }

        inline void set_fechaInicio(std::string fechaInicio) { _fechaInicio = fechaInicio; }
        inline std::string get_fechaInicio() { return _fechaInicio; }

        inline void set_fechaFinal(std::string fechaFinal) { _fechaFinal = fechaFinal; }
        inline std::string get_fechaFinal() { return _fechaFinal; }

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

        inline std::vector<std::string> get_listaEspera() { return _listaEspera; }
        inline void set_listaEspera(std::vector<std::string> listaEsperaNueva) { _listaEspera = listaEsperaNueva; }
};

#endif
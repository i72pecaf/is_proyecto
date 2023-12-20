#ifndef USUARIOREGISTRADO_HPP
#define USUARIOREGISTRADO_HPP

#include <iostream>

class usuarioRegistrado {
    
    private:
        std::string _nombreUsuario;

    public:
    
        usuarioRegistrado(std::string nombre);
        
        inline std::string get_nombreUsuario() { return _nombreUsuario; }
        
        void preinscripcionActividad(int idActividad);
        void verActividadesPublicadas();
        void verEstadoActividades();

};

#endif
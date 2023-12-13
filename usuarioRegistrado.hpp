#ifndef USUARIOREGISTRADO_HPP
#define USUARIOREGISTRADO_HPP

#include <iostream>

class usuarioRegistrado {
    
    private:
        std::string _nombreUsuario;

    public:
        usuarioRegistrado(std::string nombre);
        void preinscripcionActividad();
        void verActividadesPublicadas();
        void verEstadoActividades();

};

#endif
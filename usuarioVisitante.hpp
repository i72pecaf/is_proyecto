#ifndef USUARIOVISITANTE_HPP
#define USUARIOVISITANTE_HPP

#include <iostream>

class usuarioVisitante {

    public:
        usuarioVisitante();  // Constructor
        void login(std::string &email, int &rol, bool &flagCorreo);   // Metodo para obtener la informacion del usuario y su rol
        void verActividadesPublicadas(); // Metodo para mostrar los anuncios publicados

};

#endif
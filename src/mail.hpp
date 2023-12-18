#ifndef MAIL_HPP
#define MAIL_HPP

#include <iostream>
#include <vector>   
#include "actividad.hpp"

class mail {
    
    private:
        std::string _cuerpo;
        std::vector<actividad> _listaActividades;
        std::vector<std::string> _destinatarios;
        

    public:

        mail();
        void verActividadesAsignadas();


};

#endif
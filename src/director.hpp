#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include <iostream>

class director {
    
    public:
        director();
        void verActividadesAsignadas();
        void completarActividad();
        void verActividadesPublicadas();
        void rollbackInscripcionAnuncio();
        void generarCertificados();
        void generarListaPreinscritos();
        void generarListaInscritos();

};

#endif
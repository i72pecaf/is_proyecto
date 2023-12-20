#include "usuarioRegistrado.hpp"
#include "panelActividades.hpp"
#include <iostream>

usuarioRegistrado::usuarioRegistrado(std::string nombre) {
    _nombreUsuario = nombre;
}

void usuarioRegistrado::preinscripcionActividad(int idActividad) {
    /* PARTE DE LA HISTORIA DE USUARIO OBLIGATORIA : PREEINSCRIPCION EN UN ANUNCIO*/
    panelActividades panel;
    // Se muestran solo los anuncios publicados
    panel.preinscribirUsuario(idActividad, this->get_nombreUsuario());


}

void usuarioRegistrado::verActividadesPublicadas() {
    /* PARTE DE LA HISTORIA DE USUARIO OBLIGATORIA : MOSTRAR ANUNCIOS PUBLICADOS Y SUS PREINSCRITOS*/
    panelActividades panel;
    // Se muestran solo los anuncios publicados
    panel.mostrarActividades(true);
}

void usuarioRegistrado::verEstadoActividades() {
    /* Método sin implementar. No obligatorio*/
}
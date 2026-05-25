#include "Pista.h"

Pista::Pista() : tipo(HUELLA), recogida(false) {}
Pista::Pista(TipoPista tipo) : tipo(tipo), recogida(false) {}

TipoPista Pista::getTipo()    const { return tipo; }
bool      Pista::isRecogida() const { return recogida; }

void Pista::recoger() { recogida = true; }

string Pista::getTipoString() const {
    switch (tipo) {
        case HUELLA:         return "Huella";
        case COARTADA:       return "Coartada";
        case TESTIMONIO:     return "Testimonio";
        case PRUEBA_FORENSE: return "Prueba Forense";
        default:             return "Desconocida";
    }
}

string Pista::getSimbolo() const {
    switch (tipo) {
        case HUELLA:         return "H";
        case COARTADA:       return "C";
        case TESTIMONIO:     return "T";
        case PRUEBA_FORENSE: return "P";
        default:             return "?";
    }
}

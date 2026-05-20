//
// Created by lupia on 19/05/2026.
//

#include "Ubicacion.h"
#include <iostream>
using namespace std;

Ubicacion::Ubicacion()
    : fila(0), columna(0), tipo(VACIO),
      visitada(false), visible(false), pista(nullptr),
      arriba(nullptr), abajo(nullptr),
      izquierda(nullptr), derecha(nullptr) {}

Ubicacion::Ubicacion(int fila, int columna, TipoUbicacion tipo)
    : fila(fila), columna(columna), tipo(tipo),
      visitada(false), visible(false), pista(nullptr),
      arriba(nullptr), abajo(nullptr),
      izquierda(nullptr), derecha(nullptr) {}

Ubicacion::~Ubicacion() {
    // La pista se elimina desde el Mapa, no aqui
}

// ── Getters ───────────────────────────────────────────────────────────────────
int           Ubicacion::getFila()    const { return fila; }
int           Ubicacion::getColumna() const { return columna; }
TipoUbicacion Ubicacion::getTipo()    const { return tipo; }
bool          Ubicacion::isVisitada() const { return visitada; }
bool          Ubicacion::isVisible()  const { return visible; }
Pista*        Ubicacion::getPista()   const { return pista; }

// ── Setters ───────────────────────────────────────────────────────────────────
void Ubicacion::setTipo(TipoUbicacion t) { tipo = t; }

void Ubicacion::visitar() {
    visitada = true;
    visible  = true;   // al visitarla automaticamente se hace visible
}

void Ubicacion::hacerVisible() {
    visible = true;    // para callejones: se ven pero no se pisan
}

void Ubicacion::setPista(Pista* p) {
    pista = p;
}

void Ubicacion::quitarPista() {
    pista = nullptr;
    tipo  = VACIO;     // la celda queda libre despues de recoger la pista
}

// ── Símbolo para imprimir en el tablero ───────────────────────────────────────
char Ubicacion::getSimbolo(int detectiveFila, int detectiveColumna) const {

    // Primero: si el detective está aqui, mostrar I
    if (fila == detectiveFila && columna == detectiveColumna)
        return 'I';

    // Segundo: segun el tipo de celda
    switch (tipo) {
        case PARED:    return '#';
        case CALLEJON:
            return visible ? '|' : 'o';  // solo se ve si ya fue descubierto
        case CON_TESTIGO:
            return visible ? 'W' : 'o';
        case CON_PISTA:
            // las pistas NUNCA se muestran, se ven como no visitadas
            return visitada ? ' ' : 'o';
        case VACIO:
            return visitada ? ' ' : 'o';
        default:
            return 'o';
    }
}
//
// Created by lupia on 19/05/2026.
//

#ifndef PROYECFINAL_UBICACION_H
#define PROYECFINAL_UBICACION_H

#include "Pista.h"
using namespace std;

// Todos los tipos posibles de contenido en una celda
enum TipoUbicacion {
    PARED,          // # borde del mapa
    VACIO,          // celda normal transitable
    CALLEJON,       // | no se puede pasar
    CON_PISTA,      // tiene una pista oculta
    CON_TESTIGO     // tiene un testigo
};


class Ubicacion {
private:
    int fila;
    int columna;
    TipoUbicacion tipo;
    bool visitada;
    bool visible;       // si el usuario ya puede verla en el tablero
    Pista* pista;       // solo si tipo == CON_PISTA, sino nullptr

public:
    // Punteros a las 4 vecinas (lista múltiplemente enlazada)
    Ubicacion* arriba;
    Ubicacion* abajo;
    Ubicacion* izquierda;
    Ubicacion* derecha;

    Ubicacion();
    Ubicacion(int fila, int columna, TipoUbicacion tipo);
    ~Ubicacion();

    int            getFila()     const;
    int            getColumna()  const;
    TipoUbicacion  getTipo()     const;
    bool           isVisitada()  const;
    bool           isVisible()   const;
    Pista*         getPista()    const;

    void setTipo(TipoUbicacion tipo);
    void visitar();
    void hacerVisible();
    void setPista(Pista* p);
    void quitarPista();

    char getSimbolo(int detectiveFila, int detectiveColumna) const;
};

#endif //PROYECFINAL_UBICACION_H

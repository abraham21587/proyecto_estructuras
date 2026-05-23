//
// Created by lupia on 19/05/2026.
//

#ifndef PROYECFINAL_UBICACION_H
#define PROYECFINAL_UBICACION_H

#include "Pista.h"
using namespace std;


enum TipoUbicacion {
    PARED,
    VACIO,
    CALLEJON,
    CON_PISTA,
    CON_TESTIGO
};


class Ubicacion {
private:
    int fila;
    int columna;
    TipoUbicacion tipo;
    bool visitada;
    bool visible;
    Pista* pista;

public:

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

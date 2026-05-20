//
// Created by lupia on 19/05/2026.
//

#ifndef PROYECFINAL_DETECTIVE_H
#define PROYECFINAL_DETECTIVE_H

#include <string>
using namespace std;

class Detective {
private:
    string nombre;
    int fila;
    int columna;
    int puntaje;
    int pistasRecogidas;

public:
    Detective();
    Detective(string nombre, int filaInicial, int columnaInicial);

    string getNombre()        const;
    int    getFila()          const;
    int    getColumna()       const;
    int    getPuntaje()       const;
    int    getPistasRecogidas() const;

    void setFila(int fila);
    void setColumna(int columna);
    void setPosicion(int fila, int columna);

    void sumarPunto();
    void reproducirPuntajeMitad();
    void duplicarPuntaje();
    void resetPuntaje();
    void teleportar(int nuevaFila, int nuevaColumna);

    void agregarPista();
    bool haGanado() const;
    void mostrarEstado()const;
};


#endif //PROYECFINAL_DETECTIVE_H
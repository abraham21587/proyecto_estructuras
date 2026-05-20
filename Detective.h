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


};


#endif //PROYECFINAL_DETECTIVE_H
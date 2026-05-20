//
// Created by lupia on 19/05/2026.
//

#include "Detective.h"
#include <iostream>
using namespace std;

Detective::Detective()
    : nombre(""), fila(0), columna(0),
      puntaje(0), pistasRecogidas(0) {}

Detective::Detective(string nombre, int filaInicial, int columnaInicial)
    : nombre(nombre), fila(filaInicial), columna(columnaInicial),
      puntaje(0), pistasRecogidas(0) {}
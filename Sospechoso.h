//
// Created by lupia on 19/05/2026.
//

#ifndef PROYECFINAL_SOSPECHOSO_H
#define PROYECFINAL_SOSPECHOSO_H

#include <string>
#include <vector>
using namespace std;

class Sospechoso {
private:
    string nombre;
    vector<string> atributos;
    vector<bool> atributosRevelados;
    bool esCulpable;


public:
    Sospechoso();
    Sospechoso(string nombre, vector<string> atributos);

    string getNombre() const;
    bool getEsCulpable() const;
    void marcarCulpable();

    void revelarSiguienteAtributo();
    void mostrar() const;
    void mostrarTodo() const;
};

#endif //PROYECFINAL_SOSPECHOSO_H
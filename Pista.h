#ifndef PISTA_H
#define PISTA_H

#include <string>
using namespace std;

enum TipoPista { HUELLA, COARTADA, TESTIMONIO, PRUEBA_FORENSE };

class Pista {
private:
    TipoPista tipo;
    bool recogida;

public:
    Pista();
    Pista(TipoPista tipo);

    TipoPista getTipo() const;
    bool isRecogida() const;
    void recoger();

    string getTipoString() const;
    string getSimbolo() const;
};

#endif

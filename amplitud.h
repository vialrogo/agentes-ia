#ifndef AMPLITUD_H
#define AMPLITUD_H

#include <QQueue>
#include "algoritmos.h"

class Amplitud : public Algoritmos
{
private:
    bool *direcciones;
public:
    Amplitud(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
};

#endif // AMPLITUD_H

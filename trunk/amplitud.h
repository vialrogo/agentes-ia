#ifndef AMPLITUD_H
#define AMPLITUD_H

#include <QQueue>
#include <QSet>
#include "algoritmos.h"

class Amplitud : public Algoritmos
{
private:
    bool *direcciones;
    QSet<QString> set;
public:
    Amplitud(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
};

#endif // AMPLITUD_H

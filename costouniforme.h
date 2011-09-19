#ifndef COSTOUNIFORME_H
#define COSTOUNIFORME_H

#include "algoritmos.h"

class CostoUniforme : public Algoritmos
{
public:
    CostoUniforme(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
};

#endif // COSTOUNIFORME_H

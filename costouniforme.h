#ifndef COSTOUNIFORME_H
#define COSTOUNIFORME_H

#include "algoritmos.h"
#include <queue>
#include <QSet>

class CostoUniforme : public Algoritmos
{
private:
    bool *direcciones;
    QSet<QString> set;
public:
    CostoUniforme(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
};

class mycomparison
{
private:
    bool reverse;

public:
    mycomparison(const bool& revparam=false)
    {
        reverse=revparam;
    }

    bool operator() (Nodo* lh, Nodo* rhs) const
    {
        if (reverse) return (lh->getCosto()>rhs->getCosto());
        else return (lh->getCosto()<rhs->getCosto());
    }
};


#endif // COSTOUNIFORME_H

#ifndef AVARA_H
#define AVARA_H

#include "algoritmos.h"
#include <queue>
#include <QSet>

class Avara : public Algoritmos
{
private:
    bool *direcciones;
    QSet<QString> set;
public:
    Avara(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
};

class comparaHeuristicas
{
private:
    bool reverse;

public:
    comparaHeuristicas(const bool& revparam=false)
    {
        reverse=revparam;
    }

    bool operator() (Nodo* lh, Nodo* rhs) const
    {
        if (reverse) return (lh->getHeuristica()>rhs->getHeuristica());
        else return (lh->getHeuristica()<rhs->getHeuristica());
    }
};

#endif // AVARA_H

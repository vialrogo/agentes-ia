#ifndef AESTRELLA_H
#define AESTRELLA_H

#include "algoritmos.h"
#include <queue>
#include <QSet>

class AEstrella : public Algoritmos
{
private:
    bool *direcciones;
    QSet<QString> set;
    int altura;
    int expandidos;
    double tiempoComputo;
public:
    AEstrella(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
    string sacarDatos();
};

class comparaHeuristicasCosto
{
private:
    bool reverse;

public:
    comparaHeuristicasCosto(const bool& revparam=false)
    {
        reverse=revparam;
    }

    bool operator() (Nodo* lh, Nodo* rhs) const
    {
        if (reverse) return ( (lh->getHeuristica()+lh->getCosto()) > (rhs->getHeuristica()+rhs->getCosto()) );
        else return ( (lh->getHeuristica()+lh->getCosto()) < (rhs->getHeuristica()+rhs->getCosto()) );
    }
};

#endif // AESTRELLA_H

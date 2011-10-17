#ifndef AVARA_H
#define AVARA_H

#include "algoritmos.h"
#include <queue>

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

class Avara : public Algoritmos
{
private:
    bool *direcciones;
    int altura;
    int expandidos;
    double tiempoComputo;
    priority_queue<Nodo*,vector<Nodo*>,comparaHeuristicas> *miCola;
    list<Nodo*> *listaTmp;
public:
    Avara(bool *dirIn);
    ~Avara();
    string buscarSolucion(Nodo* estadoInicial);
    string sacarDatos();
};

#endif // AVARA_H

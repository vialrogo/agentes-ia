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
    int altura;
    int expandidos;
    double tiempoComputo;

public:
    Amplitud(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
    string sacarDatos();
};

#endif // AMPLITUD_H

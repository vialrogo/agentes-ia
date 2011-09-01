#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <QPoint>

class Algoritmos
{
public:
    Algoritmos();
    QPoint* moverseCirculos(int** mapa, int wMapa, int hMapa, QPoint* posInicial, QPoint* posMeta);
};

#endif // ALGORITMOS_H

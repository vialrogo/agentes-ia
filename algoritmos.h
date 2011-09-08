#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <QPoint>
#include <QVector>

class Algoritmos
{
public:
    Algoritmos();

    QVector<QPoint*> moverseCirculos(int** mapa, int wMapa, int hMapa, QPoint* posInicial, QPoint* posMeta);
};
#endif // ALGORITMOS_H

#include "algoritmos.h"

Algoritmos::Algoritmos()
{
}

QPoint* Algoritmos::moverseCirculos(int **mapa, int wMapa, int hMapa, QPoint* posInicial, QPoint* posMeta)
{
    if ((posInicial->ry()+1)<wMapa)
        if(mapa[posInicial->rx()][posInicial->ry()+1]==0)
            return new QPoint(posInicial->rx(),posInicial->ry()+1);

    if ((posInicial->rx()+1)<hMapa)
        if(mapa[posInicial->rx()+1][posInicial->ry()]==0)
            return new QPoint(posInicial->rx()+1,posInicial->ry());

    if ((posInicial->ry()-1)>=0)
        if(mapa[posInicial->rx()][posInicial->ry()-1]==0)
            return new QPoint(posInicial->rx(),posInicial->ry()-1);

    if ((posInicial->rx()-1)>=0)
        if(mapa[posInicial->rx()-1][posInicial->ry()]==0)
            return new QPoint(posInicial->rx()-1,posInicial->ry());

    return new QPoint(posInicial->rx(),posInicial->ry());
}

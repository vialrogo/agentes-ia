#include "algoritmos.h"

Algoritmos::Algoritmos()
{

}

QVector<QPoint*> Algoritmos::moverseCirculos(int **mapa, int wMapa, int hMapa, QPoint* posInicial, QPoint* posMeta)
{
    QVector<QPoint*> vector(0);

    while (true) {

        if ((posInicial->ry()+1)<wMapa)
            if(mapa[posInicial->rx()][posInicial->ry()+1]==0)
            {
                if(vector.indexOf(new QPoint(posInicial->rx(),posInicial->ry()+1))==(-1))
                    vector.append(new QPoint(posInicial->rx(),posInicial->ry()+1));
                else
                    break;
            }

        if ((posInicial->rx()+1)<hMapa)
            if(mapa[posInicial->rx()+1][posInicial->ry()]==0)
            {
                if(vector.indexOf(new QPoint(posInicial->rx()+1,posInicial->ry()))==(-1))
                    vector.append(new QPoint(posInicial->rx()+1,posInicial->ry()));
                else
                    break;
            }

        if ((posInicial->ry()-1)>=0)
            if(mapa[posInicial->rx()][posInicial->ry()-1]==0)
            {
                if(vector.indexOf(new QPoint(posInicial->rx(),posInicial->ry()-1))==(-1))
                    vector.append(new QPoint(posInicial->rx(),posInicial->ry()-1));
                else
                    break;
            }

        if ((posInicial->rx()-1)>=0)
            if(mapa[posInicial->rx()-1][posInicial->ry()]==0)
            {
                if(vector.indexOf(new QPoint(posInicial->rx()-1,posInicial->ry()))==(-1))
                    vector.append(new QPoint(posInicial->rx()-1,posInicial->ry()));
                else
                    break;
            }
    }

    return vector;
}

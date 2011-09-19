#ifndef MAPA_H
#define MAPA_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <iostream>
#include <QDebug>

using namespace std;

class Mapa: public QGraphicsScene
{

public:
    Mapa(int ancho, int alto,int n,int m,int c);
    void crearCuadros(char** matriz, bool* direcciones);
    void moverCarro(char carro, int direccion, int casillas, bool* direcciones);

private:
    int W;
    int H;
    int N;
    int M;
    int CantidadCarros;
    QGraphicsPixmapItem** carros;
};
#endif // MAPA_H

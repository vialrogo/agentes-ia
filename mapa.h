#ifndef MAPA_H
#define MAPA_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <iostream>

using namespace std;

class Mapa: public QGraphicsScene
{

public:
    int** matriz;
    int n;
    int m;

    Mapa(int ancho, int alto);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void crearCuadros();

private:
    int W;
    int H;
    QGraphicsRectItem*** cuadros;
};
#endif // MAPA_H

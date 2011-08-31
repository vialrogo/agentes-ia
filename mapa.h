#ifndef MAPA_H
#define MAPA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

using namespace std;

class Mapa: public QGraphicsScene
{

public:
    Mapa();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MAPA_H

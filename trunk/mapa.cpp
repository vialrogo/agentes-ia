#include "mapa.h"

Mapa::Mapa()
{
}

void Mapa::mousePressEvent(QGraphicsSceneMouseEvent* mouseevent)
{
    QPointF posicion = mouseevent->scenePos();

    double xpos = posicion.rx();
    double ypos = posicion.ry();

    if(mouseevent->button()==Qt::RightButton)
        cout<<"Click Derecho";

    if(mouseevent->button()==Qt::LeftButton)
        cout<<"Click Izquierdo";

    cout<<" en la posición ["<< xpos << ","<< ypos <<"]"<<endl;

}

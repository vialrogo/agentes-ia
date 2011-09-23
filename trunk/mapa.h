#ifndef MAPA_H
#define MAPA_H

#include "imagencarro.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <iostream>
#include <QDebug>
#include <QTimer>
#include <QPropertyAnimation>

using namespace std;

class Mapa: public QGraphicsScene
{

    Q_OBJECT

public:
    Mapa(int ancho, int alto,int n,int m,int c);
    void crearCuadros(char** matriz, bool* direcciones);
    void moverCarro(char carro, int direccion, int casillas);
    void iniciarAnimacion(string solucion,bool *direcciones);

private:
    int W;
    int H;
    int N;
    int M;
    int tiempo;
    char carroActual;
    int dirreccionActual;
    int CantidadCarros;
    int movimientoActual;
    bool *direcciones;
    imagencarro** carros;
    QTimer *timer;
    QString solucion;
    QPoint posicionesCarro[7];

private slots:
    void animar();
};
#endif // MAPA_H

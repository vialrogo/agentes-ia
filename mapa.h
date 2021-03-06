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
    void moverCarro(char carro, int direccion);
    void iniciarAnimacion(string solucion,bool *direcciones);
    void pararAnimacion();

private:
    int W;
    int H;
    int N;
    int M;
    int tiempo;
    char carroActual;
    int dirreccionActual;
    int CantidadCarros;
    bool *direcciones;
    imagencarro** carros;
    QTimer *timer;
    QString solucion;
    QPoint posicionesCarro[7];

private slots:
    void animar();

signals:
    void terminoAnimacion();
};
#endif // MAPA_H

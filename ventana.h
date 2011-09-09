#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QGraphicsLineItem>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <mapa.h>

using namespace std;

namespace Ui {
    class Ventana;
}

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();
    Mapa* mapita;
    int W;
    int H;

private:
    Ui::Ventana *ui;
    void borrarMapa();
    void pintarCuadricula(int n, int m);
    void definirMapa(int n, int m);

public slots:
    void correr();
    void cargarArchivo();
};

#endif // VENTANA_H

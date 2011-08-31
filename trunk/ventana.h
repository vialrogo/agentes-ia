#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QGraphicsLineItem>
#include <mapa.h>

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

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H

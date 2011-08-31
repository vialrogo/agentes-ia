#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    mapita = new Mapa();

    mapita->setSceneRect(0,0,469,429);
    ui->graphicsView->setScene(mapita);

    //Ejemplo de agregar una linea!
    QGraphicsLineItem *line = new QGraphicsLineItem(10.0,10.0,50.0,150.0);
    line->setFlag( QGraphicsItem::ItemIsMovable );
    mapita->addItem(line);
}

Ventana::~Ventana()
{
    delete ui;
}

#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    mapita = new Mapa();

//    QGraphicsScene * scene = new QGraphicsScene();
//    ui->graphicsView->setScene(scene);

//    QGraphicsLineItem *line = new QGraphicsLineItem(10.0,10.0,50.0,50.0);
//    line->setFlag( QGraphicsItem::ItemIsMovable );
//    scene->addItem(line);

    ui->graphicsView->setScene(mapita);

    QGraphicsLineItem *line = new QGraphicsLineItem(10.0,10.0,50.0,150.0);
    line->setFlag( QGraphicsItem::ItemIsMovable );
    mapita->addItem(line);
}

Ventana::~Ventana()
{
    delete ui;
}

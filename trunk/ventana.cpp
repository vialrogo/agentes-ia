#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    W=471;
    H=429;
    mapita = new Mapa(W,H);
    mapita->setSceneRect(0,0,W,H);

    ui->graphicsView->setScene(mapita);

    connect(ui->actionQuit, SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->botonDefineMap, SIGNAL(clicked()),this,SLOT(definirMapa()));
    connect(ui->botonRun,SIGNAL(clicked()),this,SLOT(run()));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::borrarMapa()
{
    mapita->clear();
}

void Ventana::pintarCuadricula(int n, int m)
{
    borrarMapa();

    int ancho = W/m;
    int alto = H/n;

    for (int i = 0; i <=m; ++i)
    {
        QGraphicsLineItem *line = new QGraphicsLineItem(i*ancho,0,i*ancho,n*alto);
        line->setFlag( QGraphicsItem::ItemIsMovable );
        mapita->addItem(line);
    }

    for (int i = 0; i <= n; ++i)
    {
        QGraphicsLineItem *line = new QGraphicsLineItem(0,i*alto,m*ancho,i*alto);
        line->setFlag( QGraphicsItem::ItemIsMovable );
        mapita->addItem(line);
    }
}

void Ventana::definirMapa()
{
    int n = ui->spinBoxN->value(); //Numero de filas
    int m = ui->spinBoxM->value(); //Numero de columnas

    if(n!=0 && m!=0)
    {
        pintarCuadricula(n,m);

        mapita->matriz= new int*[n];
        for (int i = 0; i < n; ++i)
            mapita->matriz[i]=new int[m];

        mapita->m=m;
        mapita->n=n;

        mapita->crearCuadros();
    }
}

void Ventana::run()
{
    cout<<"run run"<<endl;
}

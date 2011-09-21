/*
  Victor Alberto Romero Gonzalez
  Erika Suárez Valencia
*/
#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    N = 7;
    M = 7;
    cantidadCarros = 7;
    W=455; //65
    H=455; //65
    mapita = new Mapa(W,H,N,M,cantidadCarros+1);
    mapita->setSceneRect(0,0,W,H);
    ui->graphicsView->setScene(mapita);

    IsMapaCargado=false;
    nombreProjecto="Project agentes-ia";
    miAgente=new Agente();

    this->setWindowTitle(nombreProjecto);

    ui->botonRun->setEnabled(false);
    ui->radioButtonInformed->setEnabled(false);
    ui->radioButtonUninformed->setEnabled(false);
    ui->comboBoxAlgoritmos->setEnabled(false);

    connect(ui->actionQuit, SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->botonRun,SIGNAL(clicked()),this,SLOT(correr()));
    connect(ui->actionLoad_map,SIGNAL(triggered()),this,SLOT(cargarArchivo()));
    connect(ui->radioButtonInformed, SIGNAL(clicked()),this,SLOT(cargarComboBoxInfor()));
    connect(ui->radioButtonUninformed, SIGNAL(clicked()),this,SLOT(cargarComboBoxUninfor()));
    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(acercaDe()));
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
        line->setPen(QColor(180,180,180,255));//Coloca el color de la cuadricula: R,G,B,alfa
        mapita->addItem(line);
    }

    for (int i = 0; i <= n; ++i)
    {
        QGraphicsLineItem *line = new QGraphicsLineItem(0,i*alto,m*ancho,i*alto);
        line->setPen(QColor(180,180,180,255));//Coloca el color de la cuadricula: R,G,B,alfa
        mapita->addItem(line);
    }
}

void Ventana::cargarArchivo()
{
    pintarCuadricula(N,M);
    QString rutaArchivo = QFileDialog::getOpenFileName();
    ifstream infile(qPrintable(rutaArchivo));

    matriz= new char*[N];
    for (int i = 0; i < N; ++i)
        matriz[i]=new char[M];

    direcciones= new bool[cantidadCarros];
    for (int i = 0; i < cantidadCarros; ++i)
        direcciones[i]=true;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
               infile >> matriz[i][j];
        }
    }
    char tmp=' ';
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(tmp == matriz[i][j] && tmp != '0' && tmp!='1'){
                direcciones[tmp-65]=false;
            }
            tmp = matriz[i][j];
        }
    }
    mapita->crearCuadros(matriz,direcciones);

    IsMapaCargado=true;
    ui->radioButtonInformed->setEnabled(true);
    ui->radioButtonUninformed->setEnabled(true);
    ui->botonRun->setEnabled(false);

    while(ui->comboBoxAlgoritmos->count()>0)
        ui->comboBoxAlgoritmos->removeItem(0);
    ui->comboBoxAlgoritmos->addItem("Select type of algorithm");
    ui->comboBoxAlgoritmos->setEnabled(false);

    ui->radioButtonInformed->setAutoExclusive(false);
    ui->radioButtonUninformed->setAutoExclusive(false);
    ui->radioButtonInformed->setChecked(false);
    ui->radioButtonUninformed->setChecked(false);
    ui->radioButtonInformed->setAutoExclusive(true);
    ui->radioButtonUninformed->setAutoExclusive(true);
    miAgente->setDireciones(direcciones);
}

void Ventana::cargarComboBoxInfor()
{
    if(IsMapaCargado){
        while(ui->comboBoxAlgoritmos->count()>0)
            ui->comboBoxAlgoritmos->removeItem(0);
        ui->comboBoxAlgoritmos->addItem("Greedy algorithm");
        ui->comboBoxAlgoritmos->addItem("A*");

        ui->comboBoxAlgoritmos->setEnabled(true);
        ui->botonRun->setEnabled(true);
    }
}

void Ventana::cargarComboBoxUninfor()
{
    if(IsMapaCargado){
        while(ui->comboBoxAlgoritmos->count()>0)
            ui->comboBoxAlgoritmos->removeItem(0);

        ui->comboBoxAlgoritmos->addItem("Breadth-first search");
        ui->comboBoxAlgoritmos->addItem("Uniform-cost search");
        ui->comboBoxAlgoritmos->addItem("Depth-first search (avoiding cycles)");

        ui->comboBoxAlgoritmos->setEnabled(true);
        ui->botonRun->setEnabled(true);
    }
}

void Ventana::acercaDe()
{
    QMessageBox msgBox;
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setWindowTitle("About");
    msgBox.setText("<h3>"+nombreProjecto+"</h3>");
    msgBox.setInformativeText("Create by: \n    Victor Alberto Romero\n    Erika Suarez Valencia");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
    return;
}

void Ventana::correr()
{
    QString Algoritmo = ui->comboBoxAlgoritmos->currentText();
    string paraMover="";

    if(Algoritmo=="Breadth-first search")
    {
        paraMover= miAgente->BuscarAmplitud(matriz);
        cout<< paraMover << endl; //Quitar cuadno se implemente el movimiento bonito
        return;
    }

    if(Algoritmo=="Uniform-cost search")
    {
        cout<<"Costo uniforme"<<endl;
        return;
    }

    if(Algoritmo=="Depth-first search (avoiding cycles)")
    {
        paraMover= miAgente->BuscarProfundidadEvitandoCiclos(matriz);
        cout<< paraMover << endl; //Quitar cuadno se implemente el movimiento bonito
        return;
    }

    if(Algoritmo=="Greedy algorithm")
    {
        cout<<"Avara"<<endl;
        return;
    }

    if(Algoritmo=="A*")
    {
        cout<<"A*"<<endl;
        return;
    }
}

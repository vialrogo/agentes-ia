#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    N = 7;
    M = 7;
    cantidadCarros = 6;
    W=455; //476 - 68
    H=455; //434 - 62
    mapita = new Mapa(W,H,N,M,cantidadCarros+1);
    mapita->setSceneRect(0,0,W,H);
    ui->graphicsView->setScene(mapita);

    IsMapaCargado=false;
    nombreProjecto="Project agentes-ia";

    this->setWindowTitle(nombreProjecto);

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
            if(tmp == matriz[i][j] && tmp != '0' && tmp!='1' && tmp!='A'){
                direcciones[tmp-66]=false;
            }
            tmp = matriz[i][j];
        }
    }
    mapita->crearCuadros(matriz,direcciones);
    IsMapaCargado=true;
}

void Ventana::cargarComboBoxInfor()
{
    while(ui->comboBoxAlgoritmos->count()>0)
        ui->comboBoxAlgoritmos->removeItem(0);

    ui->comboBoxAlgoritmos->addItem("Avara");
    ui->comboBoxAlgoritmos->addItem("A*");
}

void Ventana::cargarComboBoxUninfor()
{
    while(ui->comboBoxAlgoritmos->count()>0)
        ui->comboBoxAlgoritmos->removeItem(0);

    ui->comboBoxAlgoritmos->addItem("Preferente por amplitud");
    ui->comboBoxAlgoritmos->addItem("Costo uniforme");
    ui->comboBoxAlgoritmos->addItem("Preferente por profundidad evitando ciclos");
}

void Ventana::acercaDe()
{
    QMessageBox msgBox;
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setWindowTitle("About");
    msgBox.setText("<h3>"+nombreProjecto+"</h3>");
    msgBox.setInformativeText("Create by: \n    Erika Suarez Valencia\n    Victor Alberto Romero");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
    return;
}

void Ventana::correr()
{
    QString Algoritmo = ui->comboBoxAlgoritmos->currentText();

    if(!IsMapaCargado) //Traducir!!
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Seleccione una entrada");
        msgBox.setText("Debe primero selecionar un archivo de entrada.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }

    if(Algoritmo=="Select type of algorithm") //Traducir!!
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Seleccione un algoritmo");
        msgBox.setText("Por favor seleccione algún algoritmo de búsqueda.");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        return;
    }

    if(Algoritmo=="Preferente por amplitud")
    {
        cout<<"Preferente por amplitud"<<endl;
        return;
    }

    if(Algoritmo=="Costo uniforme")
    {
        cout<<"Costo uniforme"<<endl;
        return;
    }

    if(Algoritmo=="Preferente por profundidad evitando ciclos")
    {
        cout<<"Preferente por profundidad evitando ciclos"<<endl;
        return;
    }

    if(Algoritmo=="Avara")
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

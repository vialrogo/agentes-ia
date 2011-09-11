#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    W=455; //476 - 68
    H=455; //434 - 62
    mapita = new Mapa(W,H);
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
        mapita->addItem(line);
    }

    for (int i = 0; i <= n; ++i)
    {
        QGraphicsLineItem *line = new QGraphicsLineItem(0,i*alto,m*ancho,i*alto);
        mapita->addItem(line);
    }
}

void Ventana::cargarArchivo()
{
    borrarMapa();
    mapita->matriz= new int*[7];
    for (int i = 0; i < 7; ++i)
        mapita->matriz[i]=new int[7];
    mapita->m=7;
    mapita->n=7;

    QString rutaArchivo = QFileDialog::getOpenFileName();
    ifstream infile(qPrintable(rutaArchivo));

    char caracter;
    for(int j=0; j<7; j++)
    {
        for(int i=0; i<7; i++)
        {
            infile >> caracter;
            if(caracter=='A') mapita->matriz[j][i]=-1; //-1 vertical, -2 horizontal
            else if(caracter=='B') mapita->matriz[j][i]=-3; //-3 vertical, -4 horizontal
            else if(caracter=='C') mapita->matriz[j][i]=-5; //-5 vertical, -6 horizontal
            else if(caracter=='D') mapita->matriz[j][i]=-7; //-7 vertical, -8 horizontal
            else if(caracter=='E') mapita->matriz[j][i]=-9; //-9 vertical, -10 horizontal
            else if(caracter=='F') mapita->matriz[j][i]=-11; //-11 vertical, -12 horizontal
            else if(caracter=='G') mapita->matriz[j][i]=-13; //-13 vertical, -14 horizontal
            else if(caracter=='0') mapita->matriz[j][i]=0;
            else if(caracter=='1') mapita->matriz[j][i]=1;
        }
    }

    int tmp=2, x=0, y=0;
    for(int j=0; j<7; j++)
    {
        for(int i=0; i<7; i++)
        {
            if(mapita->matriz[j][i]==tmp && tmp!=0 && tmp!=1){
                tmp=mapita->matriz[j][i];
                mapita->matriz[j][i]--;
                if(mapita->matriz[x][y]%2!=0) mapita->matriz[x][y]--;
                x=j;
                y=i;
            }
            else{
                tmp=mapita->matriz[j][i];
                x=j;
                y=i;
            }
        }
    }

//    for(int j=0; j<7; j++)
//    {
//        for(int i=0; i<7; i++)
//            cout<<mapita->matriz[j][i]<<" ";
//        cout<<endl;
//    }

    mapita->crearCuadros();
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

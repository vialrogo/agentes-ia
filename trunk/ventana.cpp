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
    corriendo=false;
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
//    ui->textEdit->setEnabled(false);

    connect(ui->actionQuit, SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->botonRun,SIGNAL(clicked()),this,SLOT(correr()));
    connect(ui->actionLoad_map,SIGNAL(triggered()),this,SLOT(cargarArchivo()));
    connect(ui->radioButtonInformed, SIGNAL(clicked()),this,SLOT(cargarComboBoxInfor()));
    connect(ui->radioButtonUninformed, SIGNAL(clicked()),this,SLOT(cargarComboBoxUninfor()));
    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(acercaDe()));
    connect(mapita, SIGNAL(terminoAnimacion()),this,SLOT(terminarAnimacion()));
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
    terminarAnimacion();
    ui->textEdit->clear();
    QString rutaArchivo = QFileDialog::getOpenFileName();

    if(rutaArchivo!=NULL)
    {
        pintarCuadricula(N,M);
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
    }

    //Destruye el agente y lo vuelve a inicializar
//    miAgente=0;
    delete miAgente;

    miAgente=new Agente();
    connect(miAgente, SIGNAL(finished()),this, SLOT(terminoHilo()));

    miAgente->inicializarTodo(direcciones);
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
    if(corriendo)
    {
        terminarAnimacion();
    }
    else
    {
        QString Algoritmo = ui->comboBoxAlgoritmos->currentText();
        miAgente->setMatrizInicial(matriz);
        corriendo=true;

        ui->textEdit->clear();
        ui->botonRun->setText("Stop");
        ui->radioButtonInformed->setEnabled(false);
        ui->radioButtonUninformed->setEnabled(false);
        ui->comboBoxAlgoritmos->setEnabled(false);

        if(Algoritmo=="Breadth-first search")
            miAgente->setCual(0);

        if(Algoritmo=="Uniform-cost search")
            miAgente->setCual(1);

        if(Algoritmo=="Depth-first search (avoiding cycles)")
            miAgente->setCual(2);

        if(Algoritmo=="Greedy algorithm")
            miAgente->setCual(3);

        if(Algoritmo=="A*")
            miAgente->setCual(4);

        miAgente->start();
    }
}

void Ventana::mostrarDatos(QString aMostrar, int que)
{
    QString seccion;
    QString carro;
    QString linea;
    int largo=aMostrar.size();
    int i=0;
    if(que==0)
    {
        while(i<largo)
        {
            linea="";
            seccion=aMostrar.left(3);
            carro=seccion.left(1);
            linea.append(carro+" ");
            seccion=seccion.right(2);
            if(direcciones[(int)(carro.toLocal8Bit().data()[0])]) //M. Vertical
            {
                if((seccion.left(1)).toLocal8Bit().data()[0] == 1) //Arriba
                {
                   linea.append("↑ ");
                }
                else //Abajo
                {
                    linea.append("↓ ");
                }
            }
            else //M. Horizontal
            {
                if((seccion.left(1)).toLocal8Bit().data()[0] == 1) //Derecha
                {
                    linea.append("→ ");
                }
                else //Izquierda
                {
                   linea.append("← ");
                }
            }
            seccion=seccion.right(1);
            linea.append(seccion);
            ui->textEdit->append(linea);
            i+=3;
            aMostrar=aMostrar.right(aMostrar.size()-3);
        }
    }
    else
    {
        linea="Cantidad de nodos expandidos: ";
        largo=aMostrar.indexOf(" ");
        linea.append(aMostrar.left(largo));
        ui->textEdit->append(linea);
        aMostrar=aMostrar.right(aMostrar.size()-(largo+1));
        linea="Profundidad del árbol: ";
        largo=aMostrar.indexOf(" ");
        linea.append(aMostrar.left(largo));
        ui->textEdit->append(linea);
        aMostrar=aMostrar.right(aMostrar.size()-(largo+1));
        linea="Tiempo de Cómputo: ";
        linea.append(aMostrar);
        linea.append(" segundos");
        ui->textEdit->append(linea);
    }
}

void Ventana::terminarAnimacion()
{
    corriendo=false;
    ui->botonRun->setText("Run");
    miAgente->pararHilo();
    mapita->pararAnimacion();

    ui->radioButtonInformed->setEnabled(false);
    ui->radioButtonUninformed->setEnabled(false);
    ui->comboBoxAlgoritmos->setEnabled(false);
    ui->botonRun->setEnabled(false);
}

void Ventana::terminoHilo()
{
    cout<<"Termino la ejecucion del hilo!!!!!!!!"<<endl;

    string paraMover="";
    size_t pos=0;
    string datos="";

    paraMover= miAgente->getSolucion();

    if(paraMover!="")
    {
        pos=paraMover.find_first_of(".");
        datos=paraMover.substr(pos+1,(paraMover.size()-pos));
        paraMover=paraMover.substr(0,pos);

        cout<< "Para mover: "<< paraMover<<endl;
        cout << "Datos: " << datos<< endl;

        mostrarDatos(QString::fromStdString(paraMover), 0);
        mostrarDatos(QString::fromStdString(datos), 1);

        mapita->iniciarAnimacion(paraMover,direcciones);
    }
}

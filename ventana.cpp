#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    W=476; //471 - 68
    H=434; //429 - 62
    mapita = new Mapa(W,H);
    mapita->setSceneRect(0,0,W,H);

    ui->graphicsView->setScene(mapita);
//    definirMapa(7,7); -> no se debe llamar. La funci´on ya no debe existir.

    connect(ui->actionQuit, SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->botonRun,SIGNAL(clicked()),this,SLOT(correr()));
    connect(ui->actionLoad_map,SIGNAL(triggered()),this,SLOT(cargarArchivo()));
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

//Comentado por la razon dada en el llamado en el constructor.
//void Ventana::definirMapa(int n, int m)
//{
//    if(n!=0 && m!=0)
//    {
//        pintarCuadricula(n,m);

//        mapita->matriz= new int*[n];
//        for (int i = 0; i < n; ++i)
//            mapita->matriz[i]=new int[m];

//        mapita->m=m;
//        mapita->n=n;

//        mapita->crearCuadros();
//    }
//}

void Ventana::cargarArchivo()
{
    pintarCuadricula(7,7);
    mapita->matriz= new int*[7];
    for (int i = 0; i < 7; ++i)
        mapita->matriz[i]=new int[7];
    mapita->m=7;
    mapita->n=7;

    QString rutaArchivo = QFileDialog::getOpenFileName();
//    cout<<qPrintable(rutaArchivo)<<endl;
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
    for(int j=0; j<7; j++)
    {
        for(int i=0; i<7; i++)
            cout<<mapita->matriz[j][i]<<" ";
        cout<<endl;
    }
    mapita->crearCuadros();
}

void Ventana::correr()
{
    cout<<"run run"<<endl;
    mapita->ponerQuitarCuadro(2,0);
}

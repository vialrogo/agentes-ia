#include "mapa.h"

Mapa::Mapa(int ancho, int alto,int n,int m,int c)
{
    W=ancho;
    H=alto;
    N=n;
    M=m;
    CantidadCarros=c;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animar()));
}

void Mapa::crearCuadros(char** matriz, bool* direcciones)
{
    int anchoCelda = (W/M);
    int altoCelda = (H/N);

    carros = new QGraphicsPixmapItem*[CantidadCarros];
    bool* pintado = new bool[CantidadCarros];

    for (int i = 0; i < CantidadCarros; ++i)
    {
        carros[i] = new QGraphicsPixmapItem();
        pintado[i]=false;
    }

    int tmp=0;
    char letra=' ';
    char orientacion=' ';
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            letra = (matriz[i][j]);
            tmp =  letra - 65;

            if(letra != '0' && letra!='1' && !pintado[tmp])
            {
                pintado[tmp]=true;

                if(direcciones[tmp])
                    orientacion='2';
                else
                    orientacion='1';
                
                QString ruta = QString("Imagenes/%1%2.png").arg(letra).arg(orientacion);
                carros[tmp]= new QGraphicsPixmapItem(QPixmap (ruta));
                carros[tmp]->setOffset (j*anchoCelda,i*altoCelda);
                this->addItem(carros[tmp]);
            }

            if(letra == '1')
            {
                QGraphicsRectItem* qri =  new QGraphicsRectItem(j*anchoCelda,i*altoCelda,anchoCelda,altoCelda);                
                qri->setBrush(QPixmap ("Imagenes/muro.jpg"));
                qri->setPen(QColor(180,180,180,0));
                this->addItem(qri);
            }
        }
    }
}

void Mapa::iniciarAnimacion(string solucion,bool *direcciones){
    this->solucion = QString::fromStdString(solucion);
    this->direcciones = direcciones;
    timer->start(1000);
}

void Mapa::animar(){
    if(0 == solucion.size()){
        timer->stop();
    }
    else{
        QString l = solucion.left(3);
        QString tmp;
        solucion = solucion.right(solucion.size()-3);
        qDebug() << ">" << l;
        tmp = l.left(1);
        l = l.right(2);
        char a = tmp.toLocal8Bit().data()[0];
        tmp = l.left(1);
        l = l.right(1);
        int b = tmp.left(2).toInt();
        int c = l.left(3).toInt();
        moverCarro(a,b,c);
    }
}

void Mapa::moverCarro(char carro, int direccion, int casillas)
{
    int anchoCelda = (W/M);
    int altoCelda = (H/N);
    int NumeroCarro = (carro - 65);
    int posX = carros[NumeroCarro]->offset().rx();
    int posY = carros[NumeroCarro]->offset().ry();

    if(direcciones[NumeroCarro]) //Movimiento vertical
    {
        if(direccion==1) //Moverse hacia arriba
            carros[NumeroCarro]->setOffset(posX,(posY - casillas*altoCelda));
        else //Moverse hacia abajo
           carros[NumeroCarro]->setOffset(posX,(posY + casillas*altoCelda));
    }
    else //Movimiento horizontal
    {
        if(direccion==1) //Moverse hacia la derecha
            carros[NumeroCarro]->setOffset((posX + casillas*anchoCelda), posY);
        else //Moverse hacia la izquierda
            carros[NumeroCarro]->setOffset((posX - casillas*anchoCelda), posY);
    }
}

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
    tiempo = 0;
}

void Mapa::crearCuadros(char** matriz, bool* direcciones)
{
    int anchoCelda = (W/M);
    int altoCelda = (H/N);

    carros = new imagencarro*[CantidadCarros];
    bool* pintado = new bool[CantidadCarros];

    for (int i = 0; i < CantidadCarros; ++i)
    {
        //carros[i] = new imagencarro();
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
                carros[tmp]= new imagencarro(QSizeF(65*7,65*7),QPixmap (ruta),this);
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
    if(0 == solucion.size() && 0 == tiempo ){
        timer->stop();
    }
    else{
        if(0 == tiempo){
            QString l = solucion.left(3);
            QString tmp;
            solucion = solucion.right(solucion.size()-3);
            tmp = l.left(1);
            l = l.right(2);
            carroActual = tmp.toLocal8Bit().data()[0];
            tmp = l.left(1);
            l = l.right(1);
            movimientoActual = 1;
            dirreccionActual = tmp.left(2).toInt();
            tiempo = l.left(3).toInt()-1;
            moverCarro(carroActual,dirreccionActual,movimientoActual);
        }
        else
        {
            tiempo--;
            movimientoActual++;
            moverCarro(carroActual,dirreccionActual,movimientoActual);
        }
    }
}

void Mapa::moverCarro(char carro, int direccion, int casillas)
{
    int anchoCelda = (W/M);
    int altoCelda = (H/N);
    int NumeroCarro = (carro - 65);
    //int posX = carros[NumeroCarro]->offset().rx();
    //int posY = carros[NumeroCarro]->offset().ry();

    if(direcciones[NumeroCarro]) //Movimiento vertical
    {
        if(direccion==1) //Moverse hacia arriba
           carros[NumeroCarro]->animatePosition(QPointF(0,(-1*casillas)*altoCelda));
        else //Moverse hacia abajo
           carros[NumeroCarro]->animatePosition(QPointF(0,casillas*altoCelda));
    }
    else //Movimiento horizontal
    {
        if(direccion==1) //Moverse hacia la derecha
            carros[NumeroCarro]->animatePosition(QPointF(casillas*anchoCelda,0));
        else //Moverse hacia la izquierda
            carros[NumeroCarro]->animatePosition(QPointF((-1*casillas)*anchoCelda,0));
    }
}

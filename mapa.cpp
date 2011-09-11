#include "mapa.h"

Mapa::Mapa(int ancho, int alto,int n,int m,int c)
{
    W=ancho;
    H=alto;
    N=n;
    M=m;
    CantidadCarros=c;
}

void Mapa::crearCuadros(char** matriz, bool* direcciones)
{
    int anchoCelda = (W/M);
    int altoCelda = (H/N);

    cuadros = new QGraphicsPixmapItem*[CantidadCarros];
    for (int i = 0; i < CantidadCarros; ++i)
    {
        cuadros[i] = new QGraphicsPixmapItem[CantidadCarros];
    }

    bool* pintado = new bool[CantidadCarros];
    for (int i = 0; i < CantidadCarros; ++i)
        pintado[i]=false;

    int tmp=0;
    char letra=' ';
    int longitud=1;
    int alto=0;
    int ancho=0;
    char orientacion=' ';
    
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            letra = (matriz[i][j]);
            tmp =  letra - 65;
            if(letra != '0' && letra!='1' && !pintado[tmp]){                               
                pintado[tmp]=true;
                switch(tmp){
                    case 0:                        
                    case 1:
                    case 2:
                    case 3:
                        longitud = 2;
                        break;
                    case 4:
                    case 5:
                    case 6:
                        longitud=3;
                        break;
                }
                if(direcciones[tmp-1]){
                    alto=longitud*altoCelda;
                    ancho=anchoCelda;
                    orientacion='2';                    
                }
                else{
                    alto=altoCelda;
                    ancho=longitud*anchoCelda;
                    orientacion='1';
                }
                
                QString ruta = QString("Imagenes/%1%2.png").arg(letra).arg(orientacion);
                cuadros[tmp]= new QGraphicsPixmapItem(QPixmap (ruta));
                cuadros[tmp]->setOffset (j*anchoCelda,i*altoCelda);
                this->addItem(cuadros[tmp]);
            }
            if(letra == '1'){
                QGraphicsRectItem* qri =  new QGraphicsRectItem(j*anchoCelda,i*altoCelda,anchoCelda,altoCelda);                
                qri->setBrush(QPixmap ("Imagenes/muro.jpg"));
                qri->setPen(QColor(180,180,180,0));
                this->addItem(qri);
            }
        }
    }
}

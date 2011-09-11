#include "mapa.h"

Mapa::Mapa(int ancho, int alto)
{
    W=ancho;
    H=alto;
    n=1;
    m=1;

    matriz= new int*[n];

    for (int i = 0; i < n; ++i)
        matriz[i]=new int[m];
}

void Mapa::crearCuadros()
{
    int anchoCelda = (W/m);
    int altoCelda = (H/n);

    cuadros = new QGraphicsRectItem**[n];
    for (int i = 0; i < n; ++i)
    {
        cuadros[i] = new QGraphicsRectItem*[m];
    }

    int a=0,b=0,c=0,d=0,e=0,f=0,g=0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cuadros[i][j]= new QGraphicsRectItem(j*anchoCelda,i*altoCelda,anchoCelda,altoCelda,0,0);
            cuadros[i][j]->setPen(QColor(180,180,180,0));//Coloca el color de la cuadricula: R,G,B,alfa

//Aqui quedé, falta agregar banderas y terminar el switch para pintar el mapa.
            switch(matriz[i][j])
            {
                case 1:
                    cuadros[i][j]->setBrush(QPixmap ("Imagenes/muro_1.jpg"));
                    break;
                case -2:
                    if(a==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/A-1.png"));
                        a++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/A-2.png"));
                    break;
                case -3:
                    if(b==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/B-1-vl.png"));
                        b++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/B-2-vl.jpg"));
                    break;
                case -4:
                    if(b==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/B-1-hz.jpg"));
                        b++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/B-2-hz.jpg"));
                    break;
                case -5:
                    if(c==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/CD-1-vl.jpg"));
                        c++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/CD-2-vl.jpg"));
                    break;
                case -6:
                    if(c==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/CD-1-hz.jpg"));
                        c++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/CD-2-hz.jpg"));
                    break;
                case -7:
                    if(d==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/CD-1-vl.jpg"));
                        d++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/CD-2-vl.jpg"));
                    break;
                case -8:
                    if(d==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/CD-1-hz.jpg"));
                        d++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/CD-2-hz.jpg"));
                    break;
                case -9:
                    if(e==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-1-vl.jpg"));
                        e++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/E-2-vl.jpg"));
                    break;
                case -10:
                    if(e==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-1-hz.jpg"));
                        e++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-2-hz.jpg"));
                    break;
                case -11:
                    if(f==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-1-vl.jpg"));
                        f++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-2-vl.jpg"));
                    break;
                case -12:
                    if(f==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-1-hz.jpg"));
                        f++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-2-hz.jpg"));
                    break;
                case -13:
                    if(g==0) {
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-1-vl.jpg"));
                        g++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-2-vl.jpg"));
                    break;
                case -14:
                    if(g==0){
                        cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-1-hz.jpg"));
                        g++;
                    }
                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/EFG-2-hz.jpg"));
                    break;
                default:
                    cuadros[i][j]->setBrush(QPixmap ("Imagenes/A-2.jpg"));
                    break;
            }
            this->addItem(cuadros[i][j]);
        }
    }
}

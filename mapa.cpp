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

void Mapa::ponerQuitarCuadro(int xCelda, int yCelda)
{

    if(xCelda<n && yCelda<m)
    {
        if(this->items().contains(cuadros[xCelda][yCelda]))
        {
            matriz[xCelda][yCelda]=0;
            this->removeItem(cuadros[xCelda][yCelda]);
        }
        else
        {
            matriz[xCelda][yCelda]=1;
            this->addItem(cuadros[xCelda][yCelda]);
        }
    }
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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cuadros[i][j]= new QGraphicsRectItem(j*anchoCelda,i*altoCelda,anchoCelda,altoCelda,0,0);
//Aqui quedé, falta agregar banderas y terminar el switch para pintar el mapa.
//            switch(matriz[i][j])
//            {
//                case -2:
//                if(b==0){
//                    if(matriz[i+1][j]==-2) cuadros[i][j]->setBrush(QPixmap ("Imagenes/B-1-hz.jpg"));
//                    else cuadros[i][j]->setBrush(QPixmap ("Imagenes/B-1-vl.jpg"));
//                }
//                else{
//                    if(matriz[i][j-1]==-2)
//                }

//                        break;
//            }

            cuadros[i][j]->setBrush(QPixmap ("Imagenes/A-2.png"));  //Imagen de los cuadros de relleno
        }
    }
}

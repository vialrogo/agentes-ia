/*
  Victor Alberto Romero Gonzalez
  Erika Suárez Valencia
*/
#include "algoritmos.h"

Algoritmos::Algoritmos(bool *dirIn)
{
    direcciones= new int[6]; //true para vertical, false para horizontal
    for(int i=0; i<6; i++) direcciones[i]=dirIn[i];
}

//Verifica si un nodo es meta.
bool Algoritmos::esMeta(char** estado)
{
    if(estado[2][6]=='A') return true;
    else return false;
}

//Verifica si un carro se puede mover en la direccion indicada, las casillas indicadas, en la matriz indicada.
//Si se puede mover esas posiciones retorna la posicion mas arriba-izquerda del carro
//Si no, retorna (-1,-1)
QPoint* Algoritmos::sePuedeMover(char carro, int direccion, int casillas, char** matActual)
{
    //Encuentra la posicion mas a la izquierda-arriba del carro
    int x=0, y=0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if(matActual[i][j]==carro){
                x=i;
                y=j;
                i=6;
                j=6;
            }
        }
    }
    if(direcciones[carro-66]){//Movimiento vertical
        if(direccion==1){//Moverse hacia arriba
            if((x-casillas)>-1){
                for (int var = 1; var < casillas+1; var++) {
                    if(matActual[x-var][y]!='0') return new QPoint(-1,-1);
                }
                return new QPoint(x,y);
            }
            else return new QPoint(-1,-1);
        }
        else{//Moverse hacia abajo
            if((carro=='A' || carro=='B') || (carro=='C' || carro=='D')){//Carros de largo 2
                if((x+casillas+1)<7){
                    for (int var = 1; var < casillas+1; var++) {
                        if(matActual[x+var+1][y]!='0') return new QPoint(-1,-1);
                    }
                    return new QPoint(x,y);
                }
                else return new QPoint(-1,-1);
            }
            else{//Carros de largo 3
                if((x+casillas+2)<7){
                    for (int var = 1; var < casillas+1; var++) {
                        if(matActual[x+var+2][y]!='0') return new QPoint(-1,-1);
                    }
                    return new QPoint(x,y);
                }
                else return new QPoint(-1,-1);
            }
        }
    }
    else{//Movimiento horizontal
        if(direccion==1){//Moverse hacia la derecha
            if((carro=='A' || carro=='B') || (carro=='C' || carro=='D')){//Carros de largo 2
                if((y+casillas+1)<7){
                    for (int var = 1; var < casillas+1; var++) {
                        if(matActual[x][y+var+1]!='0') return new QPoint(-1,-1);
                    }
                    return new QPoint(x,y);
                }
                else return new QPoint(-1,-1);
            }
            else{//Carros de largo 3
                if((y+casillas+2)<7){
                    for (int var = 1; var < casillas+1; var++) {
                        if(matActual[x][y+var+2]!='0') return new QPoint(-1,-1);
                    }
                    return new QPoint(x,y);
                }
                else return new QPoint(-1,-1);
            }
        }
        else{//Moverse hacia la izquierda
            if((y-casillas)>-1){
                for (int var = 1; var < casillas+1; var++) {
                    if(matActual[x][y-var]!='0') return new QPoint(-1,-1);
                }
                return new QPoint(x,y);
            }
            else return new QPoint(-1,-1);
        }
    }
}

//Mueve el carro, cuya posición mas a la izquierda-arriba se indica y retorna la matriz con el carro movido
char** Algoritmos::mover(QPoint *posCarro, int direccion, int casillas, char** matActual)
{
    //La matriz que voy a retornar
    char** matFinal=new char*[7];
    for (int var = 0; var < 7; var++) {
        matFinal[var]=new char[7];
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            matFinal[i][j]=matActual[i][j];
        }
    }

    //Datos del carro
    int x=posCarro->x();
    int y=posCarro->y();
    char tmp=matActual[x][y];
    int tmpi=0;

    if(direcciones[tmp-66]){//Movimiento Vertical
        if(direccion==1){//Moverse hacia arriba
            if((tmp=='A' || tmp=='B') || (tmp=='C' || tmp=='D')){//Carros de largo 2
                for (int var = 0; var < 2; var++) {
                    tmpi=x-casillas+var;
                    matFinal[tmpi][y]=tmp;
                }
                tmpi+=1;
                for (int var = tmpi; var < x+2; var++) matFinal[var][y]='0';
            }
            else{//E, F, G, Carros de largo 3
                for (int var = 0; var < 3; var++) {
                    tmpi=x-casillas+var;
                    matFinal[tmpi][y]=tmp;
                }
                tmpi+=1;
                for (int var = tmpi; var < x+3; var++) matFinal[var][y]='0';
            }
        }
        else{//Moverse hacia abajo
            if((tmp=='A' || tmp=='B') || (tmp=='C' || tmp=='D')){//Carros de largo 2
                for (int var = 1; var > -1; var--) {
                    tmpi=x+casillas+var;
                    matFinal[tmpi][y]=tmp;
                }
                tmpi-=1;
                for (int var = tmpi; var > x-1; var--) matFinal[var][y]='0';
            }
            else{//E, F, G, Carros de largo 3
                for (int var = 2; var > -1; var--) {
                    tmpi=x+casillas+var;
                    matFinal[tmpi][y]=tmp;
                }
                tmpi-=1;
                for (int var = tmpi; var > x-1; var--) matFinal[var][y]='0';
            }
        }
    }
    else{//Movimiento Horizontal
        if(direccion==1){//Moverse hacia la derecha
            if((tmp=='A' || tmp=='B') || (tmp=='C' || tmp=='D')){//Carros de largo 2
                for (int var = 1; var > -1; var--) {
                    tmpi=y+casillas+var;
                    matFinal[x][tmpi]=tmp;
                }
                tmpi-=1;
                for (int var = tmpi; var > y-1; var--) matFinal[x][var]='0';
            }
            else{//E, F, G, Carros de largo 3
                for (int var = 2; var > -1; var--) {
                    tmpi=y+casillas+var;
                    matFinal[x][tmpi]=tmp;
                }
                tmpi-=1;
                for (int var = tmpi; var > y-1; var--) matFinal[x][var]='0';
            }
        }
        else{//Moverse hacia la izquierda
            if((tmp=='A' || tmp=='B') || (tmp=='C' || tmp=='D')){//Carros de largo 2
                for (int var = 0; var < 2; var++) {
                    tmpi=y-casillas+var;
                    matFinal[x][tmpi]=tmp;
                }
                tmpi+=1;
                for (int var = tmpi; var < y+2; var++) matFinal[x][var]='0';
            }
            else{//E, F, G, Carros de largo 3
                for (int var = 0; var < 3; var++) {
                    tmpi=y-casillas+var;
                    matFinal[x][tmpi]=tmp;
                }
                tmpi+=1;
                for (int var = tmpi; var < y+3; var++) matFinal[x][var]='0';
            }
        }
    }

    return matFinal;
}

void Algoritmos::imprimir(char** mat)
{
    for (int var = 0; var < 7; ++var) {
        for (int d = 0; d < 7; ++d) {
            cout<<mat[var][d]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Algoritmos *ensayo;

    char** prueba=new char*[7];
    char** resPrueba=new char*[7];
    for (int var = 0; var < 7; var++) {
        prueba[var]=new char[7];
        resPrueba[var]=new char[7];
    }
    prueba[0][0]='0';prueba[0][1]='E';prueba[0][2]='E';prueba[0][3]='E';prueba[0][4]='0';prueba[0][5]='0';prueba[0][6]='1';
    prueba[1][0]='0';prueba[1][1]='0';prueba[1][2]='0';prueba[1][3]='0';prueba[1][4]='0';prueba[1][5]='0';prueba[1][6]='0';
    prueba[2][0]='A';prueba[2][1]='A';prueba[2][2]='C';prueba[2][3]='0';prueba[2][4]='0';prueba[2][5]='0';prueba[2][6]='D';
    prueba[3][0]='0';prueba[3][1]='0';prueba[3][2]='C';prueba[3][3]='0';prueba[3][4]='0';prueba[3][5]='0';prueba[3][6]='D';
    prueba[4][0]='F';prueba[4][1]='0';prueba[4][2]='G';prueba[4][3]='G';prueba[4][4]='G';prueba[4][5]='B';prueba[4][6]='0';
    prueba[5][0]='F';prueba[5][1]='0';prueba[5][2]='0';prueba[5][3]='0';prueba[5][4]='0';prueba[5][5]='B';prueba[5][6]='0';
    prueba[6][0]='F';prueba[6][1]='0';prueba[6][2]='0';prueba[6][3]='1';prueba[6][4]='0';prueba[6][5]='0';prueba[6][6]='0';

    bool *pruebaDir=new bool[6];
    pruebaDir[0]=true;
    pruebaDir[1]=true;
    pruebaDir[2]=true;
    pruebaDir[3]=false;
    pruebaDir[4]=true;
    pruebaDir[5]=false;

    ensayo=new Algoritmos(pruebaDir);
    QPoint* punto;
//    punto=ensayo->sePuedeMover('A',1,1,prueba);
//    cout<<"A, derecha, 1: "<<punto->x()<<" "<<punto->y()<<endl;
//    punto=ensayo->sePuedeMover('A',0,1,prueba);
//    cout<<"A, izquierda 1: "<<punto->x()<<" "<<punto->y()<<endl;
    ensayo->imprimir(prueba);
    punto=ensayo->sePuedeMover('D',0,3,prueba);
    cout<<"D, abajo 3: "<<punto->x()<<" "<<punto->y()<<endl;
    resPrueba=ensayo->mover(punto,0,3,prueba);
    ensayo->imprimir(resPrueba);

    cout<<endl;

    ensayo->imprimir(prueba);
    punto=ensayo->sePuedeMover('D',1,1,prueba);
    cout<<"D, arriba 1: "<<punto->x()<<" "<<punto->y()<<endl;
    resPrueba=ensayo->mover(punto,1,1,prueba);
    ensayo->imprimir(resPrueba);

    cout<<endl;

    ensayo->imprimir(prueba);
    punto=ensayo->sePuedeMover('E',0,1,prueba);
    cout<<"E, izquierda 1: "<<punto->x()<<" "<<punto->y()<<endl;
    resPrueba=ensayo->mover(punto,0,1,prueba);
    ensayo->imprimir(resPrueba);

    cout<<endl;

    ensayo->imprimir(prueba);
    punto=ensayo->sePuedeMover('E',1,1,prueba);
    cout<<"E, derecha 1: "<<punto->x()<<" "<<punto->y()<<endl;
    resPrueba=ensayo->mover(punto,1,1,prueba);
    ensayo->imprimir(resPrueba);

//    punto=ensayo->sePuedeMover('C',0,1,prueba);
//    cout<<"C, abajo 1: "<<punto->x()<<" "<<punto->y()<<endl;
//    punto=ensayo->sePuedeMover('C',1,2,prueba);
//    cout<<"C, arriba 2: "<<punto->x()<<" "<<punto->y()<<endl;
}

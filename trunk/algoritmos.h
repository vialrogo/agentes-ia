/*
  Victor Alberto Romero Gonzalez
  Erika Suárez Valencia
*/
#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <QPoint>
#include <iostream>
using namespace std;

class Algoritmos
{
private:
    int *direcciones;
public:
    Algoritmos(bool *dirIn);
    bool esMeta(char** estado);
    QPoint* sePuedeMover(char carro, int direccion, int casillas, char** matActual);
    char** mover(QPoint *posCarro, int direccion, int casillas, char** matActual);
    void imprimir(char** mat);
};

#endif // ALGORITMOS_H

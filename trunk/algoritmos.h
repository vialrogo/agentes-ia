/*
  Victor Alberto Romero Gonzalez
  Erika Suárez Valencia
*/
#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <QPoint>
#include "nodo.h"
#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

class Algoritmos
{
private:
    bool *direcciones;
    bool esMeta(char** estado);
    QPoint* sePuedeMover(char carro, int direccion, int casillas, char** matActual);
    char** mover(QPoint *posCarro, int direccion, int casillas, char** matActual);
public:
    Algoritmos();
    Algoritmos(bool *dirIn);
    list<Nodo*>* expandir(Nodo *nodito);
//    void imprimir(char** mat);
};

#endif // ALGORITMOS_H

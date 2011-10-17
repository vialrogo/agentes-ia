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
#include <time.h>

using namespace std;

class Algoritmos
{
private:
    bool *direcciones;
    bool esMeta(char** estado);
    QPoint* sePuedeMover(char carro, int direccion, int casillas, char** matActual);
    char** mover(QPoint *posCarro, int direccion, int casillas, char** matActual);

protected:
    unsigned int MAXIMO_NODOS;
    bool pararHilo;

public:
    Algoritmos();
    Algoritmos(bool *dirIn);
    list<Nodo*>* expandir(Nodo *nodito);
    int calcularHeuristica(char** estadoActual);
//    void imprimir(char** mat);
    void setMaximoNodos(unsigned int MN_in);
    void setPararHilo(bool pararHilo_in);
};

#endif // ALGORITMOS_H

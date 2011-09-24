#include "costouniforme.h"

CostoUniforme::CostoUniforme(bool *dirIn)
{
    direcciones= new bool[7]; //true para vertical, false para horizontal
    for(int i=0; i<7; i++) direcciones[i]=dirIn[i];
}

string CostoUniforme::buscarSolucion(Nodo *estadoInicial)
{ // no funciona, creo que falta calcular el costo

    Nodo *actual=estadoInicial;
    PriorityQueue<Nodo*> *miCola= new PriorityQueue<Nodo*>();
    list<Nodo*> *listaTmp=new list<Nodo*>();

    listaTmp =expandir(actual);
    while(listaTmp!=0)
    {
        while(!listaTmp->empty())
        {
            listaTmp->front()->imprimir();
            if(!(listaTmp->front()== actual->getPadre()))
                miCola->enqueue(listaTmp->front()->getCosto(), listaTmp->front());
            listaTmp->pop_front();
        }
        actual=miCola->dequeue();
        listaTmp=0;
        listaTmp =expandir(actual);
    }

    return actual->getOperadorAplicado(); //Ventana se encarga de traducir ese string :P
}

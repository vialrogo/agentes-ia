#include "costouniforme.h"

CostoUniforme::CostoUniforme(bool *dirIn) : Algoritmos(dirIn)
{
    direcciones= new bool[7]; //true para vertical, false para horizontal
    for(int i=0; i<7; i++) direcciones[i]=dirIn[i];
}

string CostoUniforme::buscarSolucion(Nodo *estadoInicial)
{
    Nodo *actual=estadoInicial;

    //Cola de prioridad
    priority_queue<Nodo*,vector<Nodo*>,mycomparison> miCola(mycomparison(true));

    list<Nodo*> *listaTmp=new list<Nodo*>();

    listaTmp =expandir(actual);
    while(listaTmp!=0)
    {
        while(!listaTmp->empty())
        {
            if(!(listaTmp->front()->esIgualA(actual->getPadre())))
                miCola.push(listaTmp->front());
            listaTmp->pop_front();
        }
        actual=miCola.top();
        miCola.pop();
        listaTmp=0;
        listaTmp =expandir(actual);
    }

    return actual->getOperadorAplicado();
}

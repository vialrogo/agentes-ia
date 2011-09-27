#include "aestrella.h"

AEstrella::AEstrella(bool *dirIn) : Algoritmos(dirIn)
{
    direcciones= new bool[7]; //true para vertical, false para horizontal
    for(int i=0; i<7; i++) direcciones[i]=dirIn[i];
}

string AEstrella::buscarSolucion(Nodo *estadoInicial)
{
    Nodo *actual=estadoInicial;
    set.insert(QString::fromStdString(actual->getEstadoString()));
    priority_queue<Nodo*,vector<Nodo*>,comparaHeuristicasCosto> *miCola = new priority_queue<Nodo*,vector<Nodo*>,comparaHeuristicasCosto>(comparaHeuristicasCosto(true));
    list<Nodo*> *listaTmp=new list<Nodo*>();

    listaTmp =expandir(actual);
    while(listaTmp!=0)
    {
        while(!listaTmp->empty())
        {
            if(!set.contains(QString::fromStdString(listaTmp->front()->getEstadoString())))
            {
                miCola->push(listaTmp->front());
                set.insert(QString::fromStdString(listaTmp->front()->getEstadoString()));
            }
            listaTmp->pop_front();
        }
        actual=miCola->top();
        miCola->pop();
//        cout<<miCola->size()<<endl;
        listaTmp=0;
        listaTmp =expandir(actual);
    }

    return actual->getOperadorAplicado();
}

#include "avara.h"

Avara::Avara(bool *dirIn) : Algoritmos(dirIn)
{
    direcciones= new bool[7]; //true para vertical, false para horizontal
    for(int i=0; i<7; i++) direcciones[i]=dirIn[i];
    altura=0;
    expandidos=0;
    tiempoComputo=0;
}

string Avara::buscarSolucion(Nodo *estadoInicial)
{
    clock_t tIni=clock();
    Nodo *actual=estadoInicial;
//    set.insert(QString::fromStdString(actual->getEstadoString()));
    priority_queue<Nodo*,vector<Nodo*>,comparaHeuristicas> *miCola = new priority_queue<Nodo*,vector<Nodo*>,comparaHeuristicas>(comparaHeuristicas(true));
    list<Nodo*> *listaTmp=new list<Nodo*>();

    listaTmp =expandir(actual);
    expandidos=1;
    altura=actual->getProfundidad();
    while(listaTmp!=0)
    {
        while(!listaTmp->empty())
        {
            altura=(listaTmp->front()->getProfundidad() > altura)? listaTmp->front()->getProfundidad(): altura;
            miCola->push(listaTmp->front());
            listaTmp->pop_front();
        }
        actual=miCola->top();
        miCola->pop();
//        cout<<miCola->size()<<endl;
        listaTmp=0;
        listaTmp =expandir(actual);
        expandidos++;
    }

    clock_t tFin= clock();
    tiempoComputo=(double) (tFin - tIni)/CLOCKS_PER_SEC;

    return actual->getOperadorAplicado();
}

string Avara::sacarDatos()
{
    ostringstream tmp;
    tmp<<expandidos;
    tmp<<" ";
    tmp<<altura;
    tmp<<" ";
    tmp<<tiempoComputo;

    return tmp.str();
}

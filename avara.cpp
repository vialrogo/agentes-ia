#include "avara.h"

Avara::Avara(bool *dirIn) : Algoritmos(dirIn)
{
    direcciones= new bool[7]; //true para vertical, false para horizontal
    for(int i=0; i<7; i++) direcciones[i]=dirIn[i];
    altura=0;
    expandidos=0;
    tiempoComputo=0;
}

Avara::~Avara()
{
    direcciones=0;
    delete direcciones;

    while (miCola->size()!=0)
    {
        delete miCola->top();
        miCola->pop();
    }
    delete miCola;
    miCola=0;
    delete listaTmp;
    listaTmp=0;
}

string Avara::buscarSolucion(Nodo *estadoInicial)
{
    clock_t tIni=clock();
    Nodo *actual=estadoInicial;
//    set.insert(QString::fromStdString(actual->getEstadoString()));
    miCola = new priority_queue<Nodo*,vector<Nodo*>,comparaHeuristicas>(comparaHeuristicas(true));
    listaTmp=new list<Nodo*>();

    listaTmp =expandir(actual);
    expandidos=1;
    altura=actual->getProfundidad();
    while(listaTmp!=0 && miCola->size()<MAXIMO_NODOS && !pararHilo)
    {
        while(!listaTmp->empty())
        {
            altura=(listaTmp->front()->getProfundidad() > altura)? listaTmp->front()->getProfundidad(): altura;
            miCola->push(listaTmp->front());
            listaTmp->pop_front();
        }
        delete listaTmp;
        delete actual;

        actual=miCola->top();
        miCola->pop();
        listaTmp =expandir(actual);
        expandidos++;
    }
    clock_t tFin= clock();
    tiempoComputo=(double) (tFin - tIni)/CLOCKS_PER_SEC;

    string salida="";
    if(!pararHilo)
        salida=actual->getOperadorAplicado();

//    Destruyo todo lo que usé   <- No funciona!!!!!
    while (miCola->size()!=0)
    {
        delete miCola->top();
        miCola->pop();
    }
    delete miCola;
    miCola=0;
    delete listaTmp;
    listaTmp=0;

    return salida;
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

#include "profundidadevitandociclos.h"

ProfundidadEvitandoCiclos::ProfundidadEvitandoCiclos(bool *dirIn)
{
    direcciones= new bool[7]; //true para vertical, false para horizontal
    for(int i=0; i<7; i++) direcciones[i]=dirIn[i];
}

string ProfundidadEvitandoCiclos::buscarSolucion(Nodo* estadoInicial)
{
    Nodo *actual=estadoInicial;
    QStack <Nodo*> *miPila= new QStack<Nodo*>();
    list<Nodo*> *listaTmp=new list<Nodo*>();

    listaTmp=expandir(actual);
    while(listaTmp!=0)
    {
        while(!listaTmp->empty())
        {
            if(!generaCiclo(listaTmp->back()))
                miPila->push(listaTmp->back());
            listaTmp->pop_back();
        }
        actual=miPila->pop();
        listaTmp=0;
        listaTmp=expandir(actual);
    }
    return actual->getOperadorAplicado(); //Ventana se encarga de traducir ese string :P
}

bool ProfundidadEvitandoCiclos::generaCiclo(Nodo *nodito)
{
    bool cicloHallado=false;
    Nodo *tmp=nodito->getPadre();
    while(tmp!=0)
    {
        if(nodito==tmp) cicloHallado=true;
        tmp=tmp->getPadre();
    }
    return cicloHallado;
}

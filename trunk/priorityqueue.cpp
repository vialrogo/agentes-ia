#include "priorityqueue.h"

template<class T> PriorityQueue<T>::PriorityQueue()
{
}

template<class T> void PriorityQueue<T>::enqueue(int prioridad_in, T valor_in)
{
    Clausura<T> elemento(prioridad_in, valor_in);

    for(int i = 0 ; i < cola.count() ; i++)
    {
        const Clausura<T>& otroElemento = cola[i];
        if( prioridad_in < otroElemento.prioridad )
        {
            cola.insert(i,elemento);
            return;
        }
    }
    cola.append(elemento);
}

template<class T> T PriorityQueue<T>::dequeue()
{
    Clausura<T> elemento = cola.dequeue();
    return elemento.valor;
}

template<class T> int PriorityQueue<T>::count()
{
    return cola.count();
}


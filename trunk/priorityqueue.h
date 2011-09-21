#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <QQueue>

template<class T> class PriorityQueue
{
public:

    PriorityQueue();
    void enqueue(int prioridad_in, T valor_in);
    T dequeue();
    int count();

private:

template <class C> struct Clausura
{
    int prioridad;
    C valor;

    Clausura(int prioridad_in, C valor_in)
    {
        prioridad=prioridad_in;
        valor=valor_in;
    }
};

QQueue< Clausura<T> > cola;
};

#endif // PRIORITYQUEUE_H

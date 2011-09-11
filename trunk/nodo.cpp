#include "nodo.h"

Nodo::Nodo(char** estadoIn, Nodo *padreIn, string operadorAplicadoIn, int profundidadIn, int costoIn)
{
    estado=estadoIn;
    padre=padreIn;
    operadorAplicado=operadorAplicadoIn;
    profundidad=profundidadIn;
    costo=costoIn;
}

char** Nodo::getEstado()
{
    return estado;
}

Nodo* Nodo::getPadre()
{
    return padre;
}

string Nodo::getOperadorAplicado()
{
    return operadorAplicado;
}

int Nodo::getProfundidad()
{
    return profundidad;
}

int Nodo::getCosto()
{
    return costo;
}

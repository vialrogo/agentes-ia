#include "nodo.h"

Nodo::Nodo(char** estadoIn, Nodo *padreIn, string operadorAplicadoIn, int profundidadIn, int costoIn)
{
    estado=estadoIn;
    padre=padreIn;
    operadorAplicado=operadorAplicadoIn;
    profundidad=profundidadIn;
    costo=costoIn;
}

//Para evitar devolverme al estado inmediatamente anterior
bool Nodo::operator ==(Nodo* otroNodo)
{
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if(estado[i][j]!=otroNodo->getEstado()[i][j]) return false;
        }
    }
    return true;
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

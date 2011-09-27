#include "nodo.h"

Nodo::Nodo(char** estadoIn, Nodo *padreIn, string operadorAplicadoIn, int profundidadIn, int costoIn)
{
    estado=estadoIn;
    padre=padreIn;
    operadorAplicado=operadorAplicadoIn;
    profundidad=profundidadIn;
    costo=costoIn;
    heuristica=0;
}

bool Nodo::esIgualA(Nodo *otroNodo)
{
    if(otroNodo==0) return false;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if(estado[i][j]!= (otroNodo->getEstado())[i][j]) return false;
        }
    }
    return true;
}

char** Nodo::getEstado() const
{
    return estado;
}

string Nodo::getEstadoString()
{
    string resp="";
    for (int var = 0; var < 7; var++) {
        for (int var2 = 0; var2 < 7; var2++) {
            resp+=estado[var][var2];
        }
    }
    return resp;
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

void Nodo::setHeuristica(int heurIn)
{
    heuristica=heurIn;
}

int Nodo::getHeuristica()
{
    return heuristica;
}

void Nodo::imprimir()
{
    for (int var = 0; var < 7; var++) {
        for (int var2 = 0; var2 < 7; var2++) {
            cout << estado[var][var2];
        }
        cout << endl;
    }
    cout << endl;
}

#ifndef NODO_H
#define NODO_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Nodo
{
private:
    char** estado;
    Nodo *padre;
    string operadorAplicado;
    int profundidad;
    int costo;

public:
    Nodo(char** estadoIn, Nodo *padreIn, string operadorAplicadoIn, int profundidadIn, int costoIn);
    char** getEstado() const;
    Nodo* getPadre();
    string getOperadorAplicado();
    int getProfundidad();
    int getCosto();
    string getEstadoString();

    void imprimir();

    bool operator== (const Nodo& otroNodo) const;
};

#endif // NODO_H

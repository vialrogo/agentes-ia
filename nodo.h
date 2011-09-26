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
    int heuristica;//Cantidad de casillas entre A y la meta + la cantidad de casillas ocupadas entre A y la meta.

public:
    Nodo(char** estadoIn, Nodo *padreIn, string operadorAplicadoIn, int profundidadIn, int costoIn);
    char** getEstado() const;
    Nodo* getPadre();
    string getOperadorAplicado();
    int getProfundidad();
    int getCosto();
    string getEstadoString();
    void setHeuristica(int heurIn);
    int getHeuristica();

    void imprimir();

    bool esIgualA(Nodo* otroNodo);
};

#endif // NODO_H

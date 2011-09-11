#ifndef NODO_H
#define NODO_H

#include <string>
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
    char** getEstado();
    Nodo* getPadre();
    string getOperadorAplicado();
    int getProfundidad();
    int getCosto();
};

#endif // NODO_H

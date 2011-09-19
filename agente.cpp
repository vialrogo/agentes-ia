#include "agente.h"

Agente::Agente()
{
    direcciones=new bool[7];
    for (int var = 0; var < 7; var++) direcciones[var]=false;
}

Agente::~Agente()
{
    ptrAmplitud = 0;
    ptrCostoUniforme = 0;
    ptrProfundidadEvitandoCiclos = 0;
    ptrAvara = 0;
    ptrAEstrella = 0;
    delete ptrAmplitud;
    delete ptrCostoUniforme;
    delete ptrProfundidadEvitandoCiclos;
    delete ptrAvara;
    delete ptrAEstrella;
}

void Agente::setDireciones(bool *dirIn)
{
    for (int var = 0; var < 7; var++) direcciones[var]=dirIn[var];

    ptrAmplitud = new Amplitud(dirIn);
//    ptrCostoUniforme = new CostoUniforme(dirIn);
//    ptrProfundidadEvitandoCiclos = new ProfundidadEvitandoCiclos(dirIn);
//    ptrAvara = new Avara(dirIn);
//    ptrAEstrella = new AEstrella(dirIn);
}

string Agente::BuscarAmplitud(char **matInicial)
{
    Nodo* inicio=new Nodo(matInicial,0,"",0,0);
    string ruta= ptrAmplitud->buscarSolucion(inicio);
    return ruta;
}

string Agente::BuscarCostoUniforme(char **matInicial)
{
}

string Agente::BuscarProfundidadEvitandoCiclos(char **matInicial)
{
}

string Agente::BuscarAvara(char **matInicial)
{
}

string Agente::BuscarAEstrella(char **matInicial)
{
}

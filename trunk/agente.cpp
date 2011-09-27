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
    ptrCostoUniforme = new CostoUniforme(dirIn);
    ptrProfundidadEvitandoCiclos = new ProfundidadEvitandoCiclos(dirIn);
    ptrAvara = new Avara(dirIn);
    ptrAEstrella = new AEstrella(dirIn);
}

string Agente::BuscarAmplitud(char **matInicial)
{
    Nodo* inicio=new Nodo(matInicial,0,"",0,0);
    inicio->setHeuristica(ptrAmplitud->calcularHeuristica(matInicial));
    string ruta= ptrAmplitud->buscarSolucion(inicio);
    return ruta;
}

string Agente::BuscarCostoUniforme(char **matInicial)
{
    Nodo* inicio=new Nodo(matInicial,0,"",0,0);
    inicio->setHeuristica(ptrCostoUniforme->calcularHeuristica(matInicial));
    string ruta= ptrCostoUniforme->buscarSolucion(inicio);
    return ruta;
}

string Agente::BuscarProfundidadEvitandoCiclos(char **matInicial)
{
    Nodo* inicio=new Nodo(matInicial,0,"",0,0);
    inicio->setHeuristica(ptrProfundidadEvitandoCiclos->calcularHeuristica(matInicial));
    string ruta= ptrProfundidadEvitandoCiclos->buscarSolucion(inicio);
    return ruta;
}

string Agente::BuscarAvara(char **matInicial)
{
    Nodo* inicio=new Nodo(matInicial,0,"",0,0);
    inicio->setHeuristica(ptrAvara->calcularHeuristica(matInicial));
    string ruta= ptrAvara->buscarSolucion(inicio);
    return ruta;
}

string Agente::BuscarAEstrella(char **matInicial)
{
    Nodo* inicio=new Nodo(matInicial,0,"",0,0);
    inicio->setHeuristica(ptrAEstrella->calcularHeuristica(matInicial));
    string ruta= ptrAEstrella->buscarSolucion(inicio);
    return ruta;
}

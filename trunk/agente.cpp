#include "agente.h"

Agente::Agente() : QThread()
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

void Agente::run()
{
    Nodo* inicio=new Nodo(matrizInicial,0,"",0,0);
    string ruta="";

    switch(cual)
    {
    case 0:
        inicio->setHeuristica(ptrAmplitud->calcularHeuristica(matrizInicial));
        ruta= ptrAmplitud->buscarSolucion(inicio);
    //    ruta+=".";
    //    ruta+=ptrAmplitud->sacarDatos();
        break;
    case 1:
        inicio->setHeuristica(ptrCostoUniforme->calcularHeuristica(matrizInicial));
        ruta= ptrCostoUniforme->buscarSolucion(inicio);
    //    ruta+=".";
    //    ruta+=ptrAmplitud->sacarDatos();
        break;
    case 2:
        inicio->setHeuristica(ptrProfundidadEvitandoCiclos->calcularHeuristica(matrizInicial));
        ruta= ptrProfundidadEvitandoCiclos->buscarSolucion(inicio);
    //    ruta+=".";
    //    ruta+=ptrAmplitud->sacarDatos();
        break;
    case 3:
        inicio->setHeuristica(ptrAvara->calcularHeuristica(matrizInicial));
        ruta= ptrAvara->buscarSolucion(inicio);
    //    ruta+=".";
    //    ruta+=ptrAmplitud->sacarDatos();
        break;
    case 4:
        inicio->setHeuristica(ptrAEstrella->calcularHeuristica(matrizInicial));
        ruta= ptrAEstrella->buscarSolucion(inicio);
    //    ruta+=".";
    //    ruta+=ptrAmplitud->sacarDatos();
        break;
    default: break;
    }

    solucion=ruta;
}

void Agente::setCual(int cual_in)
{
    cual=cual_in;
}

void Agente::serMatrizInicial(char **matrizInicial_in)
{
    matrizInicial=matrizInicial_in;
}

string Agente::getSolucion()
{
    return solucion;
}

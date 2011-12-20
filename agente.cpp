#include "agente.h"

Agente::Agente() : QThread()
{
    direcciones=new bool[7];
    for (int var = 0; var < 7; var++) direcciones[var]=false;
}

Agente::~Agente()
{
    cout<<"Se destruye el agente!"<<endl;

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

void Agente::inicializar()
{
    switch(cual)
    {
        case 0:
            ptrAmplitud = new Amplitud(direcciones);
            break;
        case 1:
            ptrCostoUniforme = new CostoUniforme(direcciones);
            break;
        case 2:
            ptrProfundidadEvitandoCiclos = new ProfundidadEvitandoCiclos(direcciones);
            break;
        case 3:
            ptrAvara = new Avara(direcciones);
            break;
        case 4:
            ptrAEstrella = new AEstrella(direcciones);
            break;
    }

    setMaximoNodosTodosAlgoritmos(1000000); //Valor por defecto, toca ver si va a ser cambiable sin recompilar!
}

void Agente::setDireciones(bool *dirIn)
{
    for (int var = 0; var < 7; var++) direcciones[var]=dirIn[var];
}

void Agente::run()
{
    Nodo* inicio=new Nodo(matrizInicial,0,"",0,0);
    string ruta="";

    switch(cual)
    {
    case 0:
        ptrAmplitud->setPararHilo(false);
        inicio->setHeuristica(ptrAmplitud->calcularHeuristica(matrizInicial));
        ruta= ptrAmplitud->buscarSolucion(inicio);
        ruta+=".";
        ruta+=ptrAmplitud->sacarDatos();
        break;
    case 1:
        ptrCostoUniforme->setPararHilo(false);
        inicio->setHeuristica(ptrCostoUniforme->calcularHeuristica(matrizInicial));
        ruta= ptrCostoUniforme->buscarSolucion(inicio);
        ruta+=".";
        ruta+=ptrCostoUniforme->sacarDatos();
        break;
    case 2:
        ptrProfundidadEvitandoCiclos->setPararHilo(false);
        inicio->setHeuristica(ptrProfundidadEvitandoCiclos->calcularHeuristica(matrizInicial));
        ruta= ptrProfundidadEvitandoCiclos->buscarSolucion(inicio);
        ruta+=".";
        ruta+=ptrProfundidadEvitandoCiclos->sacarDatos();
        break;
    case 3:
        ptrAvara->setPararHilo(false);
        inicio->setHeuristica(ptrAvara->calcularHeuristica(matrizInicial));
        ruta= ptrAvara->buscarSolucion(inicio);
        ruta+=".";
        ruta+=ptrAvara->sacarDatos();
        break;
    case 4:
        ptrAEstrella->setPararHilo(false);
        inicio->setHeuristica(ptrAEstrella->calcularHeuristica(matrizInicial));
        ruta= ptrAEstrella->buscarSolucion(inicio);
        ruta+=".";
        ruta+=ptrAEstrella->sacarDatos();
        break;
    default: break;
    }

    solucion=ruta;
}

void Agente::setCual(int cual_in)
{
    cual=cual_in;
}

void Agente::setMatrizInicial(char **matrizInicial_in)
{
    matrizInicial=matrizInicial_in;
}

string Agente::getSolucion()
{
    return solucion;
}

void Agente::pararHilo()
{
    switch(cual)
    {
    case 0:
        ptrAmplitud->setPararHilo(true);
        break;
    case 1:
        ptrCostoUniforme->setPararHilo(true);
        break;
    case 2:
        ptrProfundidadEvitandoCiclos->setPararHilo(true);
        break;
    case 3:
        ptrAvara->setPararHilo(true);
        break;
    case 4:
        ptrAEstrella->setPararHilo(true);
        break;
    default: break;
    }
}

void Agente::setMaximoNodosTodosAlgoritmos(int MN_in)
{
    switch(cual)
    {
        case 0:
            ptrAmplitud->setMaximoNodos(MN_in);
            break;
        case 1:
            ptrCostoUniforme->setMaximoNodos(MN_in);
            break;
        case 2:
            ptrProfundidadEvitandoCiclos->setMaximoNodos(MN_in);
            break;
        case 3:
            ptrAvara->setMaximoNodos(MN_in);
            break;
        case 4:
            ptrAEstrella->setMaximoNodos(MN_in);
            break;
    }
}


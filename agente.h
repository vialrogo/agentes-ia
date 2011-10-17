#ifndef AGENTE_H
#define AGENTE_H

#include <QThread>
#include "amplitud.h"
#include "costouniforme.h"
#include "profundidadevitandociclos.h"
#include "avara.h"
#include "aestrella.h"

class Agente : public QThread
{
private:
    bool *direcciones;
    Amplitud *ptrAmplitud;
    CostoUniforme *ptrCostoUniforme;
    ProfundidadEvitandoCiclos *ptrProfundidadEvitandoCiclos;
    Avara *ptrAvara;
    AEstrella *ptrAEstrella;
    int cual; //0=> amplitud, 1=>costo, 2=>profundidad, 3=>Avara, 4=>A-estrella
    char** matrizInicial;
    string solucion;

public:
    Agente();
    ~Agente();
    void inicializarTodo(bool *dirIn);
    void setDireciones(bool *dirIn);
    void run();
    void setCual(int cual_in);
    void setMatrizInicial(char** matrizInicial_in);
    string getSolucion();
    void pararHilo();
    void setMaximoNodosTodosAlgoritmos(int MN_in);
};

#endif // AGENTE_H

#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "amplitud.h"
#include "costouniforme.h"
#include "profundidadevitandociclos.h"
#include "avara.h"
#include "aestrella.h"

class Algoritmos
{
private:
    Amplitud *ptrAmplitud;
    CostoUniforme *ptrCostoUniforme;
    ProfundidadEvitandoCiclos *ptrProfundidadEvitandoCiclos;
    Avara *ptrAvara;
    AEstrella *ptrAEstrella;
public:
    Algoritmos();
};

#endif // ALGORITMOS_H

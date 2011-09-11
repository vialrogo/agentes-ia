#ifndef AGENTE_H
#define AGENTE_H

#include "amplitud.h"
#include "costouniforme.h"
#include "profundidadevitandociclos.h"
#include "avara.h"
#include "aestrella.h"

class Agente
{
private:
    Amplitud *ptrAmplitud;
    CostoUniforme *ptrCostoUniforme;
    ProfundidadEvitandoCiclos *ptrProfundidadEvitandoCiclos;
    Avara *ptrAvara;
    AEstrella *ptrAEstrella;
public:
    Agente();
};

#endif // AGENTE_H

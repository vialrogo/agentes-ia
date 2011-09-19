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
    bool *direcciones;
    Amplitud *ptrAmplitud;
    CostoUniforme *ptrCostoUniforme;
    ProfundidadEvitandoCiclos *ptrProfundidadEvitandoCiclos;
    Avara *ptrAvara;
    AEstrella *ptrAEstrella;
public:
    Agente();
    ~Agente();
    void setDireciones(bool *dirIn);
    string BuscarAmplitud(char **matInicial);
    string BuscarCostoUniforme(char **matInicial);
    string BuscarProfundidadEvitandoCiclos(char **matInicial);
    string BuscarAvara(char **matInicial);
    string BuscarAEstrella(char **matInicial);
};

#endif // AGENTE_H

#ifndef PROFUNDIDADEVITANDOCICLOS_H
#define PROFUNDIDADEVITANDOCICLOS_H

#include <QStack>
#include <QSet>
#include <QString>
#include "algoritmos.h"

class ProfundidadEvitandoCiclos : public Algoritmos
{
private:
    bool *direcciones;
    QSet<QString> *set;
public:
    ProfundidadEvitandoCiclos(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
    bool generaCiclo(Nodo *nodito);
};

#endif // PROFUNDIDADEVITANDOCICLOS_H

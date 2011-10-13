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
    QSet<QString> set;
    int altura;
    int expandidos;
    double tiempoComputo;
public:
    ProfundidadEvitandoCiclos(bool *dirIn);
    string buscarSolucion(Nodo* estadoInicial);
    string sacarDatos();
};

#endif // PROFUNDIDADEVITANDOCICLOS_H

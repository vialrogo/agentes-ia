/*
  Victor Alberto Romero Gonzalez
  Erika Suárez Valencia
*/
#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QGraphicsLineItem>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <fstream>
#include "mapa.h"
#include "agente.h"

using namespace std;

namespace Ui {
    class Ventana;
}

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();
    Mapa* mapita;
    int W;
    int H;
    int N;
    int M;
    int cantidadCarros;
    bool IsMapaCargado; //Global para saber si ya se cargó un mapa
    QString nombreProjecto; //Es variable para que aparezca igual en about

private:
    Ui::Ventana *ui;
    void borrarMapa();
    void pintarCuadricula(int n, int m);
    char** matriz;
    bool* direcciones;
    Agente *miAgente;
public slots:
    void correr();
    void cargarArchivo();
    void cargarComboBoxInfor();
    void cargarComboBoxUninfor();
    void acercaDe();
};

#endif // VENTANA_H

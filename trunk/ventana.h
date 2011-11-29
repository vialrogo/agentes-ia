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

private:
    Mapa* mapita;
    int W;
    int H;
    int N;
    int M;
    int cantidadCarros;
    bool IsMapaCargado; //Global para saber si ya se cargó un mapa
    QString nombreProjecto; //Es variable para que aparezca igual en about
    bool corriendo;
    char** matriz;
    bool* direcciones;
    Agente *miAgente;
    int costoRuta;

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();
    Ui::Ventana *ui;
    void borrarMapa();
    void pintarCuadricula(int n, int m);
    void mostrarDatos(QString aMostrar, int que);//0 para los pasos, 1 para los datos

public slots:
    void correr();
    void cargarArchivo();
    void cargarComboBoxInfor();
    void cargarComboBoxUninfor();
    void acercaDe();
    void terminarAnimacion();
    void terminoHilo();
};

#endif // VENTANA_H

#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>

namespace Ui {
    class Ventana;
}

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H

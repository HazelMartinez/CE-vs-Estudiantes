#ifndef VENTANA_INICIO_H
#define VENTANA_INICIO_H

#include <QMainWindow>

namespace Ui {
class Ventana_Inicio;
}

class Ventana_Inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_Inicio(QWidget *parent = 0);
    ~Ventana_Inicio();

private slots:
    void on_pushButton_individual_win_clicked();

    void on_pushButton_clicked();

private:
    Ui::Ventana_Inicio *ui;
};

#endif // VENTANA_INICIO_H

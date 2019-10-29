#ifndef ESTADISTICASWINDOW_H
#define ESTADISTICASWINDOW_H

#include <QMainWindow>

namespace Ui {
class EstadisticasWindow;
}

class EstadisticasWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EstadisticasWindow(QWidget *parent = 0);
    ~EstadisticasWindow();
    void muestra_label_estadisticas();
    void muestra_label_reprobados();
    void muestra_label_fitness();
    void muestra_label_nivel();
    void muestra_label_proba_mutaciones();
    void muestra_label_muta_ocurridas();
    void muestra_label_inversiones();
    void muestra_label_inversiones_ocurridas();

private slots:
    void on_pushButton_close_clicked();


private:
    Ui::EstadisticasWindow *ui;

};

#endif // ESTADISTICASWINDOW_H

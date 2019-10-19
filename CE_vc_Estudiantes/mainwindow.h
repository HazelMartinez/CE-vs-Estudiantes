#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Listas/matriz.h"
#include "QGridLayout"
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene* scene;

private slots:
    void draw_matriz();
    void image_arquero();
    void image_artillero();
    void image_magos();
    void image_lanza_fuego();
    void settings_boton_estadisticas();


    void on_push_button_arquero_clicked();

    void on_push_button_mago_clicked();

    void on_push_button_artillero_clicked();

    void on_push_button_lanza_fuego_clicked();

    void on_push_button_estadisticas_clicked();

private:
    Ui::MainWindow *ui;
    Matriz <Personaje> *matriz=new Matriz<Personaje>();
};

#endif // MAINWINDOW_H

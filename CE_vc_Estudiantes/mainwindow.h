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

private:
    Ui::MainWindow *ui;
    Matriz <Personaje> *matriz=new Matriz<Personaje>();
};

#endif // MAINWINDOW_H

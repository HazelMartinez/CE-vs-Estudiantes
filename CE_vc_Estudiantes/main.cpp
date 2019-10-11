#include "mainwindow.h"
#include <QApplication>
#include "Juego.h"

Juego* juego;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    juego = new Juego();
    juego->show();
    juego->start();

    return a.exec();
 }




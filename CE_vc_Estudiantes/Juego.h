#ifndef CE_VS_ESTUDIANTES_JUEGO_H
#define CE_VS_ESTUDIANTES_JUEGO_H
#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "tablero.h"

class Juego: public QGraphicsView{
public:
    // constructors
    Juego(QWidget* parent=NULL);

    // public methods
    void start();

    // public attributes
    QGraphicsScene* scene;
    //Tablero *tablero;
    MainWindow *ventana;

    //QString whosTurn;
};


#endif //CE_VS_ESTUDIANTES_JUEGO_H


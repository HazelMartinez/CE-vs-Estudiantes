#ifndef CE_VS_ESTUDIANTES_JUEGO_H
#define CE_VS_ESTUDIANTES_JUEGO_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Tablero.h"

class Juego: public QGraphicsView {
public:
    // constructors
    Juego(QWidget* parent=NULL);

    // public methods
    void start();

    // public attributes
    QGraphicsScene* scene;
    Tablero* tablero;
    QString whosTurn;
};

#endif //CE_VS_ESTUDIANTES_JUEGO_H




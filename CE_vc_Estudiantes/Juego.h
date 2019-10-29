#ifndef CE_VS_ESTUDIANTES_JUEGO_H
#define CE_VS_ESTUDIANTES_JUEGO_H
#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "tablero.h"

/**
 * @brief
 *
 */
class Juego: public QGraphicsView{
public:
    // constructors
    /**
     * @brief
     *
     * @param parent
     */
    Juego(QWidget* parent=NULL);

    // public methods
    /**
     * @brief
     *
     */
    void start();

    // public attributes
    QGraphicsScene* scene; /**< TODO: describe */
    //Tablero *tablero;
    MainWindow *ventana; /**< TODO: describe */

    //QString whosTurn;
};


#endif //CE_VS_ESTUDIANTES_JUEGO_H


#include <QList>
#include "square.h"

#ifndef CE_VS_ESTUDIANTES_TABLERO_H
#define CE_VS_ESTUDIANTES_TABLERO_H


class Tablero {
public:
    // constructors
    Tablero();

    // getters/setters
    QList<Square*> getSquares();

    // public methods
    void placeSquares(int x, int y, int cols, int rows);

private:
    void createSquareColumn(int x, int y, int numOfRows);
    QList<Square*> squares;

};


#endif //CE_VS_ESTUDIANTES_TABLERO_H




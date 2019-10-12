#include "Tablero.h"
#include "Juego.h"

extern Juego* juego;

Tablero::Tablero(){

}

QList<Square*> Tablero::getSquares(){
    return squares;
}

void Tablero::placeSquares(int x, int y, int cols, int rows){
    int X_SHIFT = 82;
    int Y_SHIFT = 41;

    for (size_t i = 0, n = cols; i < n; i++){
        //Y_SHIFT = 0;

        if (i % 2 == 0){ // even column
            Y_SHIFT = 0;
        }
        else{ // odd column
            Y_SHIFT = 41;
        }
        createSquareColumn(x+X_SHIFT*i,y+Y_SHIFT,rows);

    }
}

void Tablero::createSquareColumn(int x, int y, int numOfRows){
    // creates a column of Hexes at the specified location with the specified
    // number of rows
    for (size_t i = 0, n = numOfRows; i < n; i++){
        Square* square = new Square();
        //Square* square;

        square->setPos(x,y+82*i);
        squares.append(square);
        juego->scene->addItem(square);
    }
}

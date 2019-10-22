#include "tablero.h"
#include "Listas/matriz.h"
#include "mainwindow.h"

extern Juego *juego;
Tablero::Tablero()
{

}

Matriz<Personaje>* Tablero::Create_matrix(){
    //QWidget* central_matriz = new QWidget(centralWidget);
    //QFrame* frame_matriz = new QFrame(central_matriz); ///&lt; frame donde se crearan los botones

    int x = 8; ///&lt;espaciado del boton en x
    int y = 10; ///&lt; espaciado del boton en y
    int square_width=115; ///&lt; ancho del boton
    int square_height=200; ///&lt;alto del boton
    int tamanio_matriz = this->matriz_juego->length; //se obtiene el tamanio de la lista

    for(int i = 0; i<tamanio_matriz; i++){ //para crear las filas de la matriz
        QRectF *square = new QRectF(10,10,square_width,square_height);
        //QRectF r2(QPointF(100.0, 200.1), QSizeF(11.2, 16.3));
        x = x + square_width + 5;
        //juego->scene->addItem(square);

    }

    //this->matriz.length;



}

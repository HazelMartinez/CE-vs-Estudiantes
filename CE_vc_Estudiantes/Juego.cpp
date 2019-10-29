#include "Juego.h"


Juego::Juego(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
}

void Juego::start(){

    // test code TODO remove
    //tablero = new Tablero();
    //hexBoard->placeHexes(100,100,3,3);

}


//
// Created by abigail on 8/10/19.
//

#include "Elfo.h"

Elfo::Elfo():Enemigo()
{
    ResistenciaArqueros = 3;
    ResistenciaArtilleros = 1;
    ResistenciaMago = 3;
    ResistenciaLanzaFuego = 1;
    Velocidad = 2;
    this->CalcularFitness();
    tipo = 2;
    QPixmap im(this->ruta+"tower_images/kareon0.png");
       imagen1 = im.scaled(150,150, Qt::IgnoreAspectRatio);
       QPixmap imag(this->ruta+"tower_images/kareon2.png");
      

}



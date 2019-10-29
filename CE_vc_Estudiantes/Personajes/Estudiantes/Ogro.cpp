//
// Created by abigail on 8/10/19.
//

#include "Ogro.h"
#include "Enemigo.h"

Ogro::Ogro():Enemigo()
{
    ResistenciaArqueros = 3;
    ResistenciaArtilleros = 1;
    ResistenciaMago = 1;
    ResistenciaLanzaFuego = 1;
    Velocidad = 1;
    this->CalcularFitness();
    tipo = 1;
    QPixmap im(this->ruta+"tower_images/kalimba0.png");
    imagen1 = im.scaled(150,150, Qt::IgnoreAspectRatio);
    QPixmap ima(this->ruta+"tower_images/kalimba4.png");

}



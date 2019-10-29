//
// Created by abigail on 8/10/19.
//

#include "Mercenario.h"

Mercenario::Mercenario():Enemigo()
{
    ResistenciaArqueros = 3;
    ResistenciaArtilleros = 3;
    ResistenciaMago = 3;
    ResistenciaLanzaFuego = 1;
    Velocidad = 5;
    this->CalcularFitness();
    tipo = 4;
    QPixmap im(this->ruta+"tower_images/honolulu2.png");
       imagen1 = im.scaled(150,150, Qt::IgnoreAspectRatio);
       QPixmap ima(this->ruta+"tower_images/honolulu5.png");
       
}


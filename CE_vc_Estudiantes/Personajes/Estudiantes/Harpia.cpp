//
// Created by abigail on 8/10/19.
//

#include "Harpia.h"

Harpia::Harpia():Enemigo()
{
    ResistenciaArqueros = 5;
    ResistenciaArtilleros = 1;
    ResistenciaMago = 5;
    ResistenciaLanzaFuego = 1;
    Velocidad = 2;
    this->CalcularFitness();
    tipo = 3;
}



//
// Created by abigail on 8/10/19.
//

#include "Enemigo.h"

Enemigo::Enemigo()
{

}

void Enemigo::CalcularFitness()
{
    fitness = (this->ResistenciaMago + this->ResistenciaArqueros
            + this->ResistenciaArtilleros + this->ResistenciaLanzaFuego
            + this->Velocidad);

}

Enemigo::~Enemigo()
{

}

inline bool operator < (Enemigo primero,  Enemigo segundo)
{
    return primero.fitness < segundo.fitness;
}

inline bool operator != (Enemigo primero,  Enemigo segundo)
{
    return primero.fitness != segundo.fitness;
}

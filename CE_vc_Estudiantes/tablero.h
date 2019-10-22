#ifndef TABLERO_H
#define TABLERO_H

#include "Listas/Lista.h"
#include "Listas/matriz.h"
#include "Juego.h"


class Tablero
{
public:
    Tablero();
private:
    Matriz<Personaje>* matriz_juego;
    Matriz<Personaje>* Create_matrix();
};

#endif // TABLERO_H



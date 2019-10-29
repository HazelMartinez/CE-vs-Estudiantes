#ifndef TABLERO_H
#define TABLERO_H

#include "Listas/Lista.h"
#include "Listas/matriz.h"
#include "Juego.h"


/**
 * @brief
 *
 */
class Tablero
{
public:
    /**
     * @brief
     *
     */
    Tablero();
private:
    Matriz<Personaje>* matriz_juego; /**< TODO: describe */
    /**
     * @brief
     *
     * @return Matriz<Personaje>
     */
    Matriz<Personaje>* Create_matrix();
};

#endif // TABLERO_H



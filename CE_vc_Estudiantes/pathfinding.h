#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "Listas/Lista.h"
#include "Personajes/Personaje.h"
#include "Listas/matriz.h"
/**
 * @brief Gestiona el pathfinding
 *
 */
class Pathfinding
{
public:
    /**
     * @brief Constructor por defecto
     *
     */
    Pathfinding();
    int meta = 0; /** Posicion en y de la meta*/
    /**
     * @brief Busca la ruta a seguir tomando el nodo de salida, le calcula el f a sus adyacentes,
     *luego elige el que tenga menor F de sus adyacentes y así sucesivamente hasta llegar a la meta
     * @param inicio Nodo de donde inicia el recorrido
     * @param matriz Tablero por donde se mueven los personajes
     * @return Ruta a seguir por el estudiante.
     */
    Lista<Personaje> Buscar_ruta(Node<Personaje> inicio, Matriz<Personaje> matriz);
    Lista<Personaje>* OpenList; /** Nodos que se evaluarán*/
    Lista<Personaje>* CloseList; /** Nodos evaluados*/
    /**
     * @brief Verifica cuál de los nodos del openList tiene menor F

     * @return Nodo con menor F
     */
    Node<Personaje> menorF();
    /**
     * @brief Verifica si el nodo esta en el open list
     * @return Bool que dice si esta o no en el open List
     */
    bool EstaEnOpenList(Node<Personaje> *adyacente);
    /**
     * @brief Verifica si el nodo esta en el close list
     * @return Bool que dice si esta o no en el close List
     */
    bool EstaEnCloseList(Node<Personaje> *adyacente);
    /**
     * @brief Calcula el G del nodo actual.
     */
    void CalcularG(Node<Personaje> adyacente);
};

#endif // PATHFINDING_H

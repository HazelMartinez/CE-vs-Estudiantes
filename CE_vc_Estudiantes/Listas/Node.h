#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "posicion.h"

using namespace std;

template <class T>

/**
 * @brief  Conforma la lista.
 *
 */
class Node
{
    public:
        /**
         * @brief Constructor por defecto
         *
         */
        Node();
        /**
         * @brief Constructor que recibe un valor para el nodo
         *
         * @param T
         */
        Node(T);
        /**
         * @brief Destructor por defecto
         *
         */
        ~Node();

        Node *next; /** Puntero al nodo siguiente. */
        T  Data; /** Valor a guardar en el nodo. */

          Node<T>* NodoPadre; /** Nodo padre para pathfinding */

               Posicion pos;/** Posicion en un array o matriz */

               float G = 0;/** Distancia a la meta */
               float H = 0; /** Distancia al inicio. */
               float F = 0; /** Suma de H y G */
               int obstaculo; /** Si es 1 hay un obstaculo si no esta libre */
               bool hayObstaculo(); /** Dice si hay o no un obstaculo*/
               bool esMeta(int final); /** Verifica si el nodo es la meta */
               double calcularH(int final); /**  Calcula el H del nodo*/


};
template <class T>
/**
 * @brief
 *
 * @param primero
 * @param segundo
 * @return bool operator
 */
inline bool operator < (Node<T> primero,  Node<T> segundo)
{
    return primero.F < segundo.F;
}

template <class T>
/**
 * @brief
 *
 * @param primero
 * @param segundo
 * @return bool operator
 */
bool operator == (Node<T> primero,  Node<T> segundo)
    {
        bool Flag = false;
        if(primero.pos.posX == segundo.pos.posX
                && primero.pos.posY == segundo.pos.posY){
            Flag = true;
        }

        return Flag;
    }

template<class T>
/**
 * @brief
 *
 * @return bool Node<T>
 */
bool Node<T>::hayObstaculo()
{
    bool flag = false;
    if(this->obstaculo != 0){
        flag = true;
    }

    return  flag;
}

template<class T>
/**
 * @brief
 *
 * @param final
 * @return bool Node<T>
 */
bool Node<T>::esMeta(int final) {
    bool flag = false;
    if(this->pos.posY == final){
        flag = true;
    }

    return  flag;

}

template<class T>
/**
 * @brief
 *
 * @param final
 * @return double Node<T>
 */
double Node<T>::calcularH(int final)
{
          double H = abs(this->pos.posY - final);
          return H;

}

template<class T>
/**
 * @brief
 *
 */
Node<T>::~Node()
{

}

template<typename T>
/**
 * @brief Constructor
 *
 * @param data
 */
Node<T>:: Node(T data){

    Data = data;
    next = nullptr;
}

#endif // NODE_H

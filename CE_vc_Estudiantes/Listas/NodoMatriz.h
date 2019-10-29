#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include "Lista.h"
template <class T>
/**
 * @brief Conforma una matriz
 *
 */
class NodoMatriz
{
public:
    Lista<T> * value; /** Lista a guardar en el nodo*/
    NodoMatriz * next; /** Puntero al nodo siguiente. */
    NodoMatriz * prev; /** Puntero al nodo anterior. */
    /**
     * @brief Constructor que recibe el valor a guardar
     *
     * @param T Valor a guardar en el nodo
     */
    NodoMatriz(T);
    /**
     * @brief Constructor por defecto
     *
     */
    NodoMatriz();
};
template<typename T>
/**
 * @brief
 *
 */
NodoMatriz<T>::NodoMatriz(){
    this->next=nullptr;
    this->prev=nullptr;
}
template<typename T>
/**
 * @brief
 *
 * @param T
 */
NodoMatriz<T>::NodoMatriz(T){
    this->next=nullptr;
    this->prev=nullptr;
}


#endif // NODOMATRIZ_H

#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include "Lista.h"
template <class T>
class NodoMatriz
{
public:
    Lista<T> * value;
    NodoMatriz * next;
    NodoMatriz * prev;
    NodoMatriz(T);
    NodoMatriz();
};
template<typename T>
NodoMatriz<T>::NodoMatriz(){
    this->next=nullptr;
    this->prev=nullptr;
}
template<typename T>
NodoMatriz<T>::NodoMatriz(T){
    this->next=nullptr;
    this->prev=nullptr;
}


#endif // NODOMATRIZ_H

#ifndef MATRIZ_H
#define MATRIZ_H
#include "NodoMatriz.h"
#include "Lista.h"

template <class T>
class Matriz
{

public:
    Matriz();
    Matriz(T);
    void Append(Lista<T> *value);
    void Display();
    int length;
    T ObtieneElemento(int x, int y);
    void EstablecerElemento(int x,int y, T personaje);
    NodoMatriz<T> *head, *tail;
};


template<typename T>
void Matriz<T>::EstablecerElemento(int x, int y, T personaje){
    NodoMatriz<T> *temp = this->head;

        for (int i = 0; i < x; i++) {
            temp = temp->next;
        }
        Lista<T> *fila=temp->value; // obtiene la fila busca
        fila->setValue(y,personaje);
}
template<typename T>
T Matriz<T>::ObtieneElemento(int x, int y){
    NodoMatriz<T> *temp = this->head;

        for (int i = 0; i < x; i++) {
            temp = temp->next;
        }
        Lista<T> *fila=temp->value; // obtiene la fila busca
        return  fila->get(y);
}

template<typename T>
Matriz<T>::Matriz(T){
    this->head=nullptr;
    this->tail=nullptr;
    this->length=0;
}

template<typename T>
Matriz<T>::Matriz(){
    this->head=nullptr;
    this->tail=nullptr;
    this->length=0;
}
template <typename T>
void Matriz<T>::Append(Lista<T> *value){
    NodoMatriz<T> *new_node = new NodoMatriz<T>();
    new_node->value = value;

    if(head==NULL) {
        // If head is null then list doesn't have any nodes, set head and tail to new node value.
        head=new_node;
        tail=new_node;
        new_node=NULL;
    } else {
        // else set current tail to be previous node on chain before new_node then set current tail next value to new_node
        // finally we set tail to be new node value and discard new_node by setting null.
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        new_node = NULL;
    }
    this->length++;
}
template <typename T>
void Matriz<T>::Display(){
    NodoMatriz<T> *display_node=new NodoMatriz<T>();
    display_node=head;

    while(display_node!=NULL) {
        Lista<T> *fila=display_node->value;
        fila->print();
        display_node=display_node->next;
    }
}



#endif // MATRIZ_H

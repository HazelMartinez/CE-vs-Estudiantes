#ifndef MATRIZ_H
#define MATRIZ_H
#include "NodoMatriz.h"
#include "Lista.h"

template <class T>
/**
 * @brief Matriz para guardar los personajes.
 *
 */
class Matriz
{

public:
    /**
     * @brief constructor por defecto
     *
     */
    Matriz();
    /**
     * @brief Constructor que recibe el valor
     *
     * @param T Valor para inicializar la matriz.
     */
    Matriz(T);
    /**
     * @brief Agrega una lista a la matriz.
     *
     * @param value lista a agregar.
     */
    void Append(Lista<T> *value);
    /**
     * @brief Muestra la matriz en consola.
     *
     */
    void Display();
    int length; /** Largo de la matriz */
    NodoMatriz<T> *head, *tail; /** Primer y ultimo nodo de la matriz*/
    T ObtieneElemento(int x, int y);
    void EstablecerElemento(int x,int y, T personaje);
    Lista<T> get(int index);


};
template<class T>
/**
 * @brief
 *
 * @param pos
 * @return Lista<T> Matriz<T>
 */
Lista<T> Matriz<T>::get(int pos)
{
    NodoMatriz<T> *temp = this->head;

        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return *temp->value;
}
template<typename T>
/**
 * @brief Asigna un valor a un nodo especifíco.
 *
 * @param x Valor en i del nodo
 * @param y Valor en j del nodo
 * @param personaje Valor a asignarle al nodo
 */
void Matriz<T>::EstablecerElemento(int x, int y, T personaje){
    NodoMatriz<T> *temp = this->head;

        for (int i = 0; i < x; i++) {
            temp = temp->next;
        }
        Lista<T> *fila=temp->value; // obtiene la fila busca
        fila->setValue(y,personaje);
}
template<typename T>
/**
 * @brief  Retorna el elemento de un nodo en específico
 *
 * @param x Valor en i del nodo
 * @param y Valor en j del nodo
 * @return T Matriz<T> Elemento que esta en el nodo
 */
T Matriz<T>::ObtieneElemento(int x, int y){
    NodoMatriz<T> *temp = this->head;

        for (int i = 0; i < x; i++) {
            temp = temp->next;
        }
        Lista<T> *fila=temp->value; // obtiene la fila busca
        return  fila->get(y);
}


template<typename T>
/**
 * @brief
 *
 * @param T
 */
Matriz<T>::Matriz(T){
    this->head=nullptr;
    this->tail=nullptr;
    this->length=0;
}

template<typename T>
/**
 * @brief
 *
 */
Matriz<T>::Matriz(){
    this->head=nullptr;
    this->tail=nullptr;
    this->length=0;
}
template <typename T>
/**
 * @brief
 *
 * @param value
 */
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
/**
 * @brief
 *
 */
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

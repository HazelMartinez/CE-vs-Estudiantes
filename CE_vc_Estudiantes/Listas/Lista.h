#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Node.h"
#include "Personajes/Personaje.h"
using namespace std;

template <class T>

/**
 * @brief Clase que gestiona Estructura de datos para guardar personajes
 *
 */

class Lista
{
    public:
        /**
         * @brief Constructor por defecto
         *
         */
        Lista();


        /**
         * @brief Agrega datos a la lista
         *
         * @param Data Datos a guardar en la lista
         */
        void add_end(T Data);
        /**
         * @brief  Borra todos los datos de la lista
         *
         */
        void del_all();
        /**
         * @brief Muestra la lista en consola
         *
         */
        void print();
        /**
         * @brief Busca un dato en la lista
         *
         * @param Data Dato a buscar
         */
        void search(T Data);
        /**
         * @brief Busca un dato por indice
         *
         * @param pos indice a buscar
         * @return T Dato buscado
         */
        T get(int pos);
        /**
         * @brief Elimina un nodo de la lista
         *
         * @param Dato dato que contiene el nodo a eliminar
         */
        void eliminar(Node<T> *Dato);
        bool verifica_full();
        Node<T> *head; /**Primer nodo de la lista*/
        int len; /**Largo de la lista*/
         void setValue(int pos,T Data);
         void add_first(Node<T> *data);
         void add_end(Node<T> *data);


    private:


};
template<typename T>
/**
 * @brief
 *
 * @param data
 */
void Lista<T>::add_end(Node<T> *data)
{

    Node<T> *temp = head;

    if (head == nullptr) {
        head = data;
    } else {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = data;
    }
    len++;

}

template<typename T>
/**
 * @brief  Le da un valor a un nodo en cierta posición
 *
 * @param pos posición a asignarle el valor
 * @param Data Valor a asignar
 */
void Lista<T>::setValue(int pos, T Data) {

       Node<T> *temp = this->head;

           for (int i = 0; i < pos; i++) {
               temp = temp->next;
           }
           temp->Data=Data;
   }

template<typename T>
/**
 * @brief Constructor por defecto
 *
 */
Lista<T>::Lista()
{
    len = 0;
    head = NULL;
}


// Insertar al final
template<typename T>
/**
 * @brief
 *
 * @param data
 */
void Lista<T>::add_end(T data)
{
    Node<T> *new_node = new Node<T> (data);
    Node<T> *temp = head;

    if (head == nullptr) {
        head = new_node;
    } else {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    len++;

}


// Eliminar todos los nodos
template<typename T>
/**
 * @brief
 *
 */
void Lista<T>::del_all()
{
    head->next = nullptr;
    head = 0;
}

// Buscar el dato de un nodo
template<typename T>
/**
 * @brief
 *
 * @param data_
 */
void Lista<T>::search(T data_)
{
    Node<T> *temp = head;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->data == data_) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->next;
        cont++;
    }

    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}
template<typename T>
/**
 * @brief
 *
 * @param data
 */
void Lista<T>::add_first(Node<T> *data)
{


    if (head == nullptr) {
        head = data;
    } else {
        data->next = this->head;
        this->head = data;

    }
    len++;

}

template<typename T>
/**
 * @brief
 *
 * @param pos
 * @return T Lista<T>
 */
T Lista<T>::get(int pos) {

       Node<T> *temp = this->head;

           for (int i = 0; i < pos; i++) {
               temp = temp->next;
           }
           return temp->Data;

   }
template<typename T>
/**
 * @brief
 *
 */
void Lista<T>::print() {
        Node<T> *temp = this->head;
        while (temp != NULL) {
            std::cout << ((Personaje)temp->Data ).id<< ",";
            temp = temp->next;
        }
        std::cout<< endl;
        std::cout<< " ---------------------------"<<endl;
    }
template<typename T>
bool Lista<T>::verifica_full(){
    int contador = 0;
    Node<T> *temp = this->head;
    while (temp != NULL){

        if((((Personaje)temp->Data).id) == -1){
            contador += 1;
        }
        temp = temp->next;


    }
    if(contador>=2){
        return true;
    }
    else{
        return false; //esta lleno
    }
}


template<typename T>
/**
 * @brief
 *
 * @param Dato
 */
void Lista<T>::eliminar(Node<T> *Dato) {
    if(this->head == nullptr){

    }else{
        Node<T>*temp = this->head;
        Node<T>*anterior = nullptr;
        while (temp != NULL && temp->Data != Dato->Data) {
            anterior = temp;
            temp = temp->next;

        }
        if(temp == NULL){
            std::cout << "El elemento no existe";
        }
        if(anterior == NULL){
            this->head = head->next;
            delete temp;
        }else{
            anterior->next = temp->next;
            delete temp;
        }

    }


    }






#endif // LIST_H

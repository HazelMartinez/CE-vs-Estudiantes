#include "mainwindow.h"
#include <QApplication>
#include "Listas/Lista.h"
#include "Personajes/Estudiantes/Enemigo.h"
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include "Personajes/Personaje.h"
#include "Evolucionador.h"
#include "Listas/matriz.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Personaje p;
    Lista<Enemigo> enemigos;
    int num;

    //prueba de la matriz
    Matriz <Personaje> *matriz=new Matriz<Personaje>();

    Personaje  *cualquierPernaje=new Personaje();
    Lista <Personaje> *lista=new Lista<Personaje>();
    // 10 elementos de una fila
    lista->add_end(*cualquierPernaje);
    lista->add_end(*cualquierPernaje);
    lista->add_end(*cualquierPernaje);
    lista->add_end(*cualquierPernaje);
    lista->add_end(*cualquierPernaje);
    lista->add_end(*cualquierPernaje);
    lista->add_end(*cualquierPernaje);
    lista->add_end(*cualquierPernaje);
    lista->add_end(*cualquierPernaje);
    lista->add_end(*cualquierPernaje);
    //10 filas y así se forma la matriz de 10xx10

    matriz->Append(lista);
    matriz->Append(lista);
    matriz->Append(lista);
    matriz->Append(lista);
    matriz->Append(lista);
    matriz->Append(lista);
    matriz->Append(lista);
    matriz->Append(lista);
    matriz->Append(lista);
    matriz->Append(lista);


    // finalización de la prueba de la matriz


    for(int i = 0; i<2; i++){
         num = 1 + rand() % (4);
         Enemigo*n = p.crearEnemigo(num);
         enemigos.add_end(*n);
         std::cout <<n->tipo<<": "<<n->fitness<< endl;

    }

    Evolucionador * uno = Evolucionador::getInstance();

    uno->Cruce(enemigos.get(0),enemigos.get(1));
    cout << uno->Cruce(enemigos.get(0),enemigos.get(1))->tipo;
    cout << uno->Cruce(enemigos.get(0),enemigos.get(1))->ResistenciaMago;



    return a.exec();
}

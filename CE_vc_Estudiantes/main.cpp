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
#include "Juego.h"
#include "ventana_inicio.h"

using namespace std;




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ventana_Inicio ventana_incio ;
    ventana_incio.show();

    //MainWindow w;
    //w.show();

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

    matriz->Display();
    // finalización de la prueba de la matriz


    for(int i = 0; i<1; i++){
         num = 1 + rand() % (4);
         Enemigo*n = p.crearEnemigo(num);
         enemigos.add_end(*n);
         std::cout <<n->tipo<<": "<<n->fitness<< endl;

    }

//    Evolucionador * uno = Evolucionador::getInstance();
//    cout<< uno->Mutacion(enemigos.get(0)).ResistenciaMago<<endl;
//    cout<< uno->Mutacion(enemigos.get(0)).ResistenciaArtilleros<<endl;
//    cout<< uno->Inversion(enemigos.get(0)).ResistenciaArtilleros<<endl;




    return a.exec();
}

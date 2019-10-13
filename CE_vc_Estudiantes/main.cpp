#include "mainwindow.h"
#include <QApplication>
#include "Listas/Lista.h"
#include "Personajes/Estudiantes/Enemigo.h"
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include "Personajes/Personaje.h"
#include "Evolucionador.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Personaje p;
    Lista<Enemigo> enemigos;
    int num;
    for(int i = 0; i<1; i++){
         num = 1 + rand() % (4);
         Enemigo*n = p.crearEnemigo(num);
         enemigos.add_end(*n);
         std::cout <<n->tipo<<": "<<n->fitness<< endl;

    }

    Evolucionador * uno = Evolucionador::getInstance();
    cout<< uno->Mutacion(enemigos.get(0)).ResistenciaMago<<endl;
    cout<< uno->Mutacion(enemigos.get(0)).ResistenciaArtilleros<<endl;
    cout<< uno->Inversion(enemigos.get(0)).ResistenciaArtilleros<<endl;




    return a.exec();
}

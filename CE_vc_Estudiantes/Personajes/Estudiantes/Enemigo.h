//
// Created by abigail on 8/10/19.
#include <iostream>
#include <string>
#include <QImage>
using namespace std;

#ifndef CE_VS_ESTUDIANTES_ENEMIGO_H
#define CE_VS_ESTUDIANTES_ENEMIGO_H


class Enemigo {
public:
        Enemigo();
       int fitness;
       int vida = 100;
       int ResistenciaArqueros;
       int ResistenciaArtilleros;
       int ResistenciaMago;
       int ResistenciaLanzaFuego;
       int PorcentajeAtaques;
       int Velocidad;
       int id;
       int tipo;
       QImage image;
       void mover(int x, int y);
       void reprobar();
       void validar();
       void CalcularFitness();

       ~Enemigo();

};


#endif //CE_VS_ESTUDIANTES_ENEMIGO_H

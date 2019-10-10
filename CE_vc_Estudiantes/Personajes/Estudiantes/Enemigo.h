//
// Created by abigail on 8/10/19.
//

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

       void mover(int x, int y);
       void reprobar();
       void validar();
       virtual ~Enemigo();

};


#endif //CE_VS_ESTUDIANTES_ENEMIGO_H

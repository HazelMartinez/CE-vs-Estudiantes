//
// Created by abigail on 8/10/19.
//

#include "Evolucionador.h"
#include "Personajes/Personaje.h"

Evolucionador::Evolucionador()
{

}

Enemigo* Evolucionador::Cruce(Enemigo madre, Enemigo padre)
{
    //Personaje p(0);
    Personaje p;
    Enemigo* hijo;
    if (madre.tipo > padre.tipo){
    hijo = p.crearEnemigo(madre.tipo);
    hijo->Velocidad = padre.Velocidad;
    hijo->ResistenciaMago = padre.ResistenciaMago;
    hijo->ResistenciaLanzaFuego = padre.ResistenciaLanzaFuego;
    }else{
        hijo = p.crearEnemigo(padre.tipo);
        hijo->Velocidad = madre.Velocidad;
        hijo->ResistenciaMago = madre.ResistenciaMago;
        hijo->ResistenciaLanzaFuego = madre.ResistenciaLanzaFuego;
    }
    hijo->CalcularFitness();
    return hijo;
}

Enemigo Evolucionador::Mutacion(Enemigo sujeto)
{
     int num;
     num = 1 + rand() % (2);
     if(num>2){
         sujeto.ResistenciaMago = sujeto.ResistenciaMago + 1 + rand() % (4);
         sujeto.ResistenciaArqueros = sujeto.ResistenciaArqueros+ 1 + rand() % (4);

     }else{
         sujeto.ResistenciaArtilleros = sujeto.ResistenciaArtilleros + 1 + rand() % (4);
         sujeto.ResistenciaLanzaFuego = sujeto.ResistenciaLanzaFuego+ 1 + rand() % (4);

     }
     return sujeto;

}

Enemigo Evolucionador::Inversion(Enemigo sujeto)
{
    if(sujeto.ResistenciaArtilleros == 3){
        sujeto.ResistenciaArtilleros =1;
    }else
    {
      sujeto.ResistenciaArtilleros =3;
    }
    return sujeto;
}

Evolucionador *Evolucionador::getInstance()
{
    static Evolucionador* instancia = new Evolucionador();
    return instancia;
}


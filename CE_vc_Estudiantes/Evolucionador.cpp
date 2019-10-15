//
// Created by abigail on 8/10/19.
//

#include "Evolucionador.h"
#include "Personajes/Personaje.h"
#include <bitset>
#include <iostream>
using namespace std;

Evolucionador::Evolucionador()
{

}

Enemigo* Evolucionador::Cruce(Enemigo madre, Enemigo padre)
{
    string ADNMadre = this->ObtenerADN(madre);
    string ADNPadre = this->ObtenerADN(padre);
    string ADNHijo;
    ADNHijo = ADNMadre.substr(0,ADNMadre.length()/2)+
            ADNPadre.substr(ADNPadre.length()/2,ADNPadre.length());

    Enemigo* hijo = this->Crearhijo(ADNHijo);




    return hijo;
}

Enemigo Evolucionador::Mutacion(Enemigo sujeto)
{
     return sujeto;

}

Enemigo Evolucionador::Inversion(Enemigo sujeto)
{
    return sujeto;

}

Evolucionador *Evolucionador::getInstance()
{
    static Evolucionador* instancia = new Evolucionador();
    return instancia;
}

string Evolucionador::ObtenerADN(Enemigo sujeto)
{
    bitset<4> Gen1(sujeto.ResistenciaMago);
    bitset<4> Gen2(sujeto.ResistenciaArqueros);
    bitset<4> Gen3(sujeto.ResistenciaArtilleros);
    bitset<4> Gen4(sujeto.ResistenciaLanzaFuego);
    bitset<4> Gen5(sujeto.Velocidad);
    bitset<4> Gen6(sujeto.tipo);
    string ADN = Gen1.to_string() + Gen2.to_string() +
            Gen3.to_string() + Gen4.to_string() +
            Gen5.to_string() + Gen6.to_string();

    return ADN;
}

Enemigo *Evolucionador::Crearhijo(string ADN)

{
    Personaje p;

     bitset<4> Gen1(ADN.substr(0,4));
     bitset<4> Gen2(ADN.substr(4,8));
     bitset<4> Gen3(ADN.substr(8,12));
     bitset<4> Gen4(ADN.substr(12,16));
     bitset<4> Gen5(ADN.substr(16,20));
     bitset<4> Gen6(ADN.substr(20,24));
     Enemigo *hijo = p.crearEnemigo(Gen6.to_ulong());
     hijo->ResistenciaMago = Gen1.to_ulong();
     hijo->ResistenciaArqueros = Gen2.to_ulong();
     hijo->ResistenciaArtilleros = Gen3.to_ulong();



    return hijo;

}




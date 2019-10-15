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

    Enemigo* hijo = this->CrearEnemigoADN(ADNHijo);




    return hijo;
}

Enemigo Evolucionador::Mutacion(Enemigo sujeto)
{
    string ADN = this->ObtenerADN(sujeto);
    int num = 1 + rand() % (12);
    ADN.replace(num,3,"111");
    sujeto = *this->CrearEnemigoADN(ADN);
     return sujeto;

}

Enemigo Evolucionador::Inversion(Enemigo sujeto)
{
    string ADN = this->ObtenerADN(sujeto);
    int num = 1 + rand() % (15);
    cout <<ADN<<endl;
    if(ADN[num] == 1){
        ADN.replace(num,1,"0");
    }else{
        ADN.replace(num,1,"1");
    }
    cout <<ADN;
    sujeto = *this->CrearEnemigoADN(ADN);
    return sujeto;

}

Evolucionador *Evolucionador::getInstance()
{
    static Evolucionador* instancia = new Evolucionador();
    return instancia;
}

string Evolucionador::ObtenerADN(Enemigo sujeto)
{
    bitset<3> Gen1(sujeto.ResistenciaMago);
    bitset<3> Gen2(sujeto.ResistenciaArqueros);
    bitset<3> Gen3(sujeto.ResistenciaArtilleros);
    bitset<3> Gen4(sujeto.ResistenciaLanzaFuego);
    bitset<3> Gen5(sujeto.Velocidad);
    bitset<3> Gen6(sujeto.tipo);
    string ADN = Gen1.to_string() + Gen2.to_string() +
            Gen3.to_string() + Gen4.to_string() +
            Gen5.to_string() + Gen6.to_string();

    return ADN;
}

Enemigo *Evolucionador::CrearEnemigoADN(string ADN)

{
    Personaje p;

     bitset<3> Gen1(ADN.substr(0,3));
     bitset<3> Gen2(ADN.substr(3,6));
     bitset<3> Gen3(ADN.substr(6,9));
     bitset<3> Gen4(ADN.substr(9,12));
     bitset<3> Gen5(ADN.substr(12,15));
     bitset<3> Gen6(ADN.substr(15,18));
     Enemigo *hijo = p.crearEnemigo(Gen6.to_ulong());
     hijo->ResistenciaMago = Gen1.to_ulong();
     hijo->ResistenciaArqueros = Gen2.to_ulong();
     hijo->ResistenciaArtilleros = Gen3.to_ulong();
     hijo->ResistenciaLanzaFuego = Gen4.to_ulong();
     hijo->Velocidad = Gen5.to_ulong();



    return hijo;

}




//
// Created by abigail on 8/10/19.
//

#include "Personaje.h"
#include "Estudiantes/Elfo.h"
#include "Estudiantes/Harpia.h"
#include "Estudiantes/Mercenario.h"
#include "Estudiantes/Ogro.h"

Enemigo *Personaje::crearEnemigo(int tipo)
{
        Enemigo *temp = new Enemigo();
        switch(tipo) {

        case 2:
        {
            Enemigo* elfo = new Elfo();
            temp = elfo;
            break;
        }
        case 3 :
        {
            Enemigo* harpia = new Harpia();
            temp = harpia;
            break;
        }
        case 4 :
        {
            Enemigo* mercenario = new Mercenario();
            temp = mercenario;
            break;
        }
        case 1 :
        {
            Enemigo* ogro = new Ogro();
           temp = ogro;
            break;
        }


        }
        return temp;
}

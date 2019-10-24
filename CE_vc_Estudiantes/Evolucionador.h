//
// Created by abigail on 8/10/19.
//

#ifndef CE_VS_ESTUDIANTES_EVOLUCIONADOR_H
#define CE_VS_ESTUDIANTES_EVOLUCIONADOR_H
#include "Listas/Lista.h"
#include "Personajes/Estudiantes/Enemigo.h"

class Evolucionador {
private:
    Evolucionador();

public:

    Lista<Enemigo> GenActual;
    int gen;
    Lista<Enemigo> CreaNuevaGeneracion(Lista<Enemigo>);
    Enemigo* Cruce(Enemigo madre, Enemigo padre);
    Enemigo Mutacion(Enemigo sujeto);
    Enemigo Inversion(Enemigo sujeto);
    static Evolucionador* getInstance();
    Evolucionador(const Evolucionador*) = delete;
    Evolucionador* operator = (const Evolucionador*) = delete;

    ~Evolucionador();


};


#endif //CE_VS_ESTUDIANTES_EVOLUCIONADOR_H

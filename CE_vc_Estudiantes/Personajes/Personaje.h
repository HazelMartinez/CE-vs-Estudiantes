//
// Created by abigail on 8/10/19.
//

#ifndef CE_VS_ESTUDIANTES_PERSONAJE_H
#define CE_VS_ESTUDIANTES_PERSONAJE_H
#include "Estudiantes/Enemigo.h"
#include "Cursos/Curso.h"


class Personaje {
public:
    int id=0;
     Enemigo* crearEnemigo(int tipo);
//     Curso* crearCurso(int tipo);

};

#endif //CE_VS_ESTUDIANTES_PERSONAJE_H

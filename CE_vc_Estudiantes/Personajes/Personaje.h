
#ifndef CE_VS_ESTUDIANTES_PERSONAJE_H
#define CE_VS_ESTUDIANTES_PERSONAJE_H
#include "Estudiantes/Enemigo.h"
#include "Cursos/Curso.h"


class Personaje {
private:
    int identificador;
public:
    //Personaje(int);
    void Mostrar_Personaje();
    int id=0;
    Enemigo* crearEnemigo(int tipo);
    int Get_Identificador();
//  Curso* crearCurso(int tipo);

};

#endif //CE_VS_ESTUDIANTES_PERSONAJE_H

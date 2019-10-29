
#ifndef CE_VS_ESTUDIANTES_PERSONAJE_H
#define CE_VS_ESTUDIANTES_PERSONAJE_H
#include "Estudiantes/Enemigo.h"



/**
 * @brief Clase encargada de gestionar los enemigos y los cursos.
 *
 */
class Personaje {
public:
     void Mostrar_Personaje();
     /**
      * @brief 
      *
      * @return int
      */
     int Get_Identificador();
    int id=0; /**Identificador del personaje. */
     /**
      * @brief Crea un enemigo de un tipo determinado.
      *
      * @param tipo tipo de enemigo a crear
      * @return Enemigo Instancia de la clase enemigo
      */
     Enemigo* crearEnemigo(int tipo);
//     Curso* crearCurso(int tipo);

};

#endif //CE_VS_ESTUDIANTES_PERSONAJE_H

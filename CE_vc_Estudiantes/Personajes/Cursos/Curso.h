#ifndef CURSO_H
#define CURSO_H

#include "Personajes/Personaje.h"
/**
 * @brief Gestiona los cursos
 *
 */
class Curso: public Personaje
{

private:
    int cantidadCreditos;  /** Analogo a los soles en Plants vs zombies */
    int horasReales; /** Caracteristica que define la dificultad de un curso*/
    int exigencia;   /** Cantidad de danio que hace un curso */
    int nivel; /** Nivel en el que se encuentra el curso */
    int costo; /** Cuantos creditos vale el curso para poder adquirirlo */
    int alcance;  /** A cuanta distancia puede atacar un curso */




public:
    //Curso(int cantidadCreditos, int horasReales, int exigencia, int nivel, int costo);
    /**
     * @brief  Constructor por defecto.
     *
     */
    Curso();
    /**
     * @brief Sube la dificultad del curso.
     *
     */
    void Upgrade();
    /**
     * @brief Las evaluaciones danian a los estudiantes.
     *
     */
    void Evaluar(); // evaluar y destruir o atacar es lo mismo
    /**
     * @brief Se adquiere un curso y se pone en la matriz.
     *
     */
    void Comprar(); // para hacer mejoras con los soles
    /**
     * @brief Se muestra el curso en la interfaz.
     *
     */
    void Mostar();

    /**
     * @brief 
     *
     * @param CantidadCreditos
     */
    void setCantidadCreditos(int CantidadCreditos);
    /**
     * @brief 
     *
     * @param HorasReales
     */
    void setHorasReales(int HorasReales);
    /**
     * @brief 
     *
     * @param SetExigencia
     */
    void setExigencia(int SetExigencia);
    /**
     * @brief 
     *
     * @param SetNivel
     */
    void setNivel(int SetNivel);
    /**
     * @brief 
     *
     * @param SetCosto
     */
    void setCosto(int SetCosto);
    /**
     * @brief 
     *
     * @param SetAlcance
     */
    void setAlcance(int SetAlcance);

    //void Curso(int tipo);
};

#endif // CURSO_H

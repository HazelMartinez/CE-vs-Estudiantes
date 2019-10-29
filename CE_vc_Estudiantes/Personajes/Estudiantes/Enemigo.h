//
// Created by abigail on 8/10/19.
#include <iostream>
#include <string>
#include <QPixmap>
#include <QLabel>
using namespace std;

#ifndef CE_VS_ESTUDIANTES_ENEMIGO_H
#define CE_VS_ESTUDIANTES_ENEMIGO_H


/**
 * @brief Clase encargada de darle las características necesarias a los estudiantes.
 *
 */
class Enemigo {
public:
        /**
         * @brief Constructor por defecto
         *
         */
        Enemigo();
       int fitness; /** Fitness del individuo*/
       int vida = 100; /** Vida inicial del estudiante.*/
       int ResistenciaArqueros; /** Resistencia que tiene el estudiante ante arqueros.*/
       int ResistenciaArtilleros; /** Resistencia que tiene el estudiante ante artilleros.*/
       int ResistenciaMago; /** Resistencia que tiene el estudiante ante magos. */
       int ResistenciaLanzaFuego; /** Resistencia que tiene el estudiante ante lanza fuegos. */
       int PorcentajeAtaques; /** Porcentaje de torres que han atacado al estudiante. */
       int Velocidad; /** Velocidad con la que se mueve el estudiante */
       int tipo; /** Tipo de enemigo */
       int posx = 180+(160*(rand() % (10))); /** Posición en el eje x del enemigo */
       int posy = 624; /** Posición en el eje y del enemigo */
       QPixmap imagen1; /** Imagen que representa al enemigo */
       QLabel *label; /** QLabel que contiene al enemigo.ç */

       /**
        * @brief Acción que saca al estudiante del juego.
        *
        */
       void reprobar();
       /**
        * @brief Valida que el estudiante haya recibido un porcentaje de ataques aceptable.
        *
        */
       void validar();
       /**
        * @brief  Calcula el fitness del estudiante
        *
        */
       void CalcularFitness();
       /**
        * @brief Destructor por defecto.
        *
        */
       ~Enemigo();
       QString ruta =
        "/home/hazel/Escritorio/Proyecto2_CEvsEstudiantes/CE-vs-Estudiantes/CE_vc_Estudiantes/"; /**Ruta donde estan guardadas las imagenes. */

};


#endif //CE_VS_ESTUDIANTES_ENEMIGO_H

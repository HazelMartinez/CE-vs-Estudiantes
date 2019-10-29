//
// Created by abigail on 8/10/19.
//

#ifndef CE_VS_ESTUDIANTES_EVOLUCIONADOR_H
#define CE_VS_ESTUDIANTES_EVOLUCIONADOR_H
#include "Listas/Lista.h"
#include "Personajes/Estudiantes/Enemigo.h"

/**
 * @brief Clase encargada de gestionar el algoritmo genetico.
 *
 */
class Evolucionador {
private:
    /**
     * @brief Constructor por defecto.
     *
     */
    Evolucionador();

public:

    Lista<Enemigo*> GenActual; /**Generación actual de enemigos */
    int gen; /**Número de generaciones transcurridas. */
    /**
     * @brief Crea una generación nueva a partir de la actual siguiendo un algoritmo genetico.
     *Toma los enemigos con fitness mayor y los agrega en una lista nueva.
     * Cruza los enemigos adyacentes.
     * Muta un 10% de la generación e invierte un 5%.
     * @param Generación actual.


     * @return Lista<Enemigo *> Nueva generación.
     */
    Lista<Enemigo*> CreaNuevaGeneracion(Lista<Enemigo*>);
    /**
     * @brief Cruza 2 enemigos para crear uno nuevo.
     * Toma la primera mitad del ADN de la madre y la segunda del padre
     * y las une para crear el ADN de un enemigo nuevo.
     *
     * @param madre Primera parte del ADN del individuo. 
     * @param padre Segunda parte del ADN del individuo. 
     * @return Enemigo Enemigo hijo
     */
    Enemigo* Cruce(Enemigo* madre, Enemigo* padre);
    /**
     * @brief Toma un bloque aleatorio de ADN y lo cambia por 111.
     *
     * @param sujeto Enemigo al que se le va a realizar la mutación.
     * @return Enemigo Enemigo mutado.
     */
    Enemigo *Mutacion(Enemigo* sujeto);
    /**
     * @brief Toma un bit aleatorio de ADN y lo cambia por 1 si es 0 y por 0 si es 1.
     *
     * @param sujeto Enemigo al que se le va a realizar la inversión.
     * @return Enemigo Enemigo invertido.
     */
    Enemigo* Inversion(Enemigo* sujeto);
    /**
     * @brief Singleton de la clase.
     *
     * @return Evolucionador Instancia de la clase evolucionador.
     */
    static Evolucionador* getInstance();
    /**
     * @brief
     *
     * @param
     */
    Evolucionador(const Evolucionador*) = delete;
    /**
     * @brief
     *
     * @param
     * @return Evolucionador *operator
     */
    Evolucionador* operator = (const Evolucionador*) = delete;
    /**
     * @brief Cambia los atributos del enemigo a una cadena binaria.
     *
     * @param sujeto Enemigo del que se quiere obtener el ADN.
     * @return string ADN del enemigo.
     */
    string ObtenerADN(Enemigo* sujeto);
    /**
     * @brief Crea un enemigo nuevo a partir de su ADN.
     *
     * @param ADN Cadena binaria con la información del enemigo a crear.
     * @return Enemigo Instancia de la clase enemigo.
     */
    Enemigo*CrearEnemigoADN(string ADN);

    /**
     * @brief Destructor por defecto
     *
     */
    ~Evolucionador();


};


#endif //CE_VS_ESTUDIANTES_EVOLUCIONADOR_H

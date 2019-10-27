#ifndef CURSO_H
#define CURSO_H
#include "Personajes/Cursos/evaluacion.h"
#include "Personaje.h"
class Curso:public Personaje {

private:
    int cantidadCreditos; // soles parecido a PvsZ
    int horasReales;
    int exigencia; // cantidad de danio
    int nivel;
    int costo;
    int alcance; //alcance de la bala hacia los enemigos
    Evaluacion evaluacion;//instancia



public:
    //Curso(int cantidadCreditos, int horasReales, int exigencia, int nivel, int costo);
    Curso();
    void Upgrade();
    void Evaluar(); // evaluar y destruir o atacar es lo mismo
    void Comprar(); // para hacer mejoras con los soles
    void Mostar();

    void setCantidadCreditos(int CantidadCreditos);
    void setHorasReales(int HorasReales);
    void setExigencia(int SetExigencia);
    void setNivel(int SetNivel);
    void setCosto(int SetCosto);
    void setAlcance(int SetAlcance);

    //void Curso(int tipo);
};

#endif // CURSO_H

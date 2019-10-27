#include "curso.h"
#include "Personaje.h"

//Curso::Curso(int cantidadCreditos, int horasReales, int exigencia, int nivel, int costo)
//{
//    this->cantidadCreditos = cantidadCreditos;
//    this->horasReales = horasReales;
//    this->exigencia = exigencia;
//    this->nivel = nivel;
//    this->costo = costo;
//}
Curso::Curso(){

}
void Curso::Mostar(){
    //Mostrar_Personaje();
    cout<<"Cantidad de creditos son: "<<cantidadCreditos<<endl;
    cout<<"Horas reales son: "<<horasReales<<endl;
    cout<<"Exigencia es : "<<exigencia<<endl;

}

void Curso::setCantidadCreditos(int CantidadCreditos){
    cantidadCreditos = CantidadCreditos;
}

void Curso::setHorasReales(int HorasReales){
    horasReales = HorasReales;
}

void Curso::setExigencia(int Exigencia){
    exigencia = Exigencia;
}

void Curso::setCosto(int Costo){
    costo = Costo;
}

void Curso::setNivel(int Nivel){
    nivel = Nivel;
}

void Curso::setAlcance(int SetAlcance){
    alcance = SetAlcance;
}

void Curso::Upgrade(){
    int cantidadCreditos_upgrade = cantidadCreditos + 2;
    setCantidadCreditos(cantidadCreditos_upgrade);

    int costo_upgrade = costo + 3;
    setCosto(costo_upgrade);

    int creditos_upgrade = cantidadCreditos + 4;
    setCantidadCreditos(creditos_upgrade);

    int alcance_upgrade = alcance + 1;
    setAlcance(alcance_upgrade);
}


void Curso::Evaluar(){ // ES atacar

}

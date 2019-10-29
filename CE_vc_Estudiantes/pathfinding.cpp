#include "pathfinding.h"
#include"Listas/matriz.h"
Pathfinding::Pathfinding()
{
    OpenList = new Lista<Personaje>;
    CloseList = new Lista<Personaje>;
}

Lista<Personaje> Pathfinding::Buscar_ruta(Node<Personaje> inicio, Matriz<Personaje> matriz)
{
    inicio.F = 0;
    OpenList->add_end(&inicio);
    Lista<Personaje> ruta;
//    while(OpenList->head != nullptr){
//        Node<Personaje> actual = this->menorF();
//        if(actual.esMeta(this->meta)){
//            Node<Personaje> temp = actual;
//            ruta.add_first(&actual);
//            while(temp.pos.posX != inicio.pos.posX
//                  && temp.pos.posY != inicio.pos.posY){
//                ruta.add_first(actual.NodoPadre);
//                actual = *actual.NodoPadre;
//            }
//            break;

//        }else{
//            for(int i = actual.pos.posX-1; i<actual.pos.posX+1; i++){
//                for(int j = actual.pos.posY-1; j<actual.pos.posY+1; j++){
//                    Node<Personaje> *temp = matriz.get(i).get(j);
//                    if(this->EstaEnOpenList(temp) or this->EstaEnCloseList(temp)
//                            or temp->hayObstaculo()){

//                    }else if(temp->esMeta(this->meta)){
//                        Node<Personaje> temp = actual;
//                        cout << actual.pos.posX<<" "<<actual.pos.posX;
//                        ruta.add_first(&actual);
//                        while(temp.pos.posX != inicio.pos.posX
//                              && temp.pos.posY != inicio.pos.posY){
//                            ruta.add_first(actual.NodoPadre);
//                            actual = *actual.NodoPadre;
//                            cout << actual.NodoPadre->pos.posX<<" "<<actual.NodoPadre->pos.posX;
//                        }
//                        break;
//                    }
//                    else
//                    {
//                        temp->calcularH(meta);
//                        temp->NodoPadre = &actual;
//                        this->CalcularG(*temp);
//                        temp->F = temp->G + temp->H;
//                        OpenList->eliminar(temp);
//                        CloseList->add_end(temp);


//                    }



//            }
//        }


//    }
//    }


    return ruta;
}

Node<Personaje> Pathfinding::menorF()
{
    Node<Personaje> *temp = OpenList->head;
    Node<Personaje> *menor = nullptr;
    while(temp->next != nullptr){
        if(temp->F<temp->next->F){
            menor = temp;
        }else{
            menor = temp->next;
        }
        temp = temp->next;
    }
    return *menor;
}

bool Pathfinding::EstaEnCloseList(Node<Personaje>* adyacente)
{
    bool flag = false;
    Node<Personaje>* temp = CloseList->head;
    while (temp != nullptr) {
        if(adyacente == temp){
            flag = true;
        }
        temp = temp->next;

    }
    return flag;

}

void Pathfinding::CalcularG(Node<Personaje> adyacente)
{
    int x = adyacente.pos.posX;
    int y = adyacente.pos.posY;
    Node<Personaje> padre = *adyacente.NodoPadre;
    if(x == padre.pos.posX or y == padre.pos.posY){
        adyacente.G = padre.G + 10;
    }else{
        adyacente.G = padre.G + 14;

    }


}

bool Pathfinding::EstaEnOpenList(Node<Personaje>* adyacente)
{
    bool flag = false;
    Node<Personaje>* temp = OpenList->head;
    while (temp != nullptr) {
        if(adyacente == temp){
            flag = true;
        }
        temp = temp->next;

    }
    return flag;
}


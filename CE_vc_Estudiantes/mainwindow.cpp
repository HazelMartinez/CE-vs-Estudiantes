#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Listas/matriz.h"
#include "QFrame"
#include "QWidget"
#include "QRectF"
#include "QPushButton"
#include "QLabel"
#include "QHBoxLayout"
#include "QGraphicsScene"
#include "QPixmap"
#include "QIcon"
#include "estadisticaswindow.h"
#include <unistd.h>
#include <pthread.h>
#include <Listas/matriz.h>
#include "Personajes/Cursos/arquero.h"
#include "Personajes/Cursos/artillero.h"
#include "Personajes/Cursos/mago.h"
#include "Personajes/Cursos/lanza_fuego.h"

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int shiftx=62,shifty=29;
    int x=MapeadorX(cursor->pos().x()),y= MapeadorY(cursor->pos().y());
    int mapa_x = Definicion_MapaX(cursor->pos().x()), mapa_y= Definicion_MapaY(cursor->pos().y());
    //cout<<"Posición X:"<<cursor->pos().x() <<" Posición Y:"<<cursor->pos().y()<<endl;
    //cout<<"LA POSICION PRESIONADA ES: ("<<mapa_x<<" , "<<mapa_y<< " )"<<endl;
    ColocarImagen(x,y);


    //ColocarImagen(QCursor::pos().x(),QCursor::pos().y());
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    scene = new QGraphicsScene();
//    scene->setSceneRect(0,0,1024,768);
//    setScene(scene);
    //this->centralWidget()->setStyleSheet();
    //this->centralWidget()->setStyleSheet("background-image:url(\"fondo_total_f.png\"); background-position: center;" );
    draw_matriz();
    image_arquero();
    image_artillero();
    image_magos();
    image_lanza_fuego();
    image_coin();

    settings_boton_estadisticas();

    QPixmap bkgnd(this->ruta+"tower_images/image_grid.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //this->mapFromGlobal(QCursor::pos());

    QLabel *imagen=new QLabel(this);//=new QLabel();
    QPixmap pixmap(this->ruta+"tower_images/kareon2.png");
    imagen->setPixmap(pixmap);
    imagen->setFixedSize(135, 70);
    imagen->move(243,973); //ensure that this coordinates are in you widget
    imagen->show();
    InicializarMatriz();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InicializarMatriz()
{
    for(int i = 0; i < 10; i++){ //despues del primer for crea la lista
        Lista <Personaje> *lista=new Lista<Personaje>();

        for(int j = 0; j < 10; j++){
            Personaje  *cualquierPernaje=new Personaje;
            cualquierPernaje->id=-1; //para indicar que esta vacio
            lista->add_end(*cualquierPernaje);
        }
        this->matriz->Append(lista); // despues de 10 elementos en una lista se mete en la matriz
    }
//    Personaje  *cualquierPernaje=new Personaje;
//    cualquierPernaje->id=-1;
//        Lista <Personaje> *lista=new Lista<Personaje>();
//        // 10 elementos de una fila
//        lista->add_end(*cualquierPernaje);
//        lista->add_end(*cualquierPernaje);
//        lista->add_end(*cualquierPernaje);
//        lista->add_end(*cualquierPernaje);
//        lista->add_end(*cualquierPernaje);
//        lista->add_end(*cualquierPernaje);
//        lista->add_end(*cualquierPernaje);
//        lista->add_end(*cualquierPernaje);
//        lista->add_end(*cualquierPernaje);
//        lista->add_end(*cualquierPernaje);
//        //10 filas y así se forma la matriz de 10xx10

//        this->matriz->Append(lista);
//         this->matriz->Append(lista);
//         this->matriz->Append(lista);
//         this->matriz->Append(lista);
//         this->matriz->Append(lista);
//         this->matriz->Append(lista);
//         this->matriz->Append(lista);
//         this->matriz->Append(lista);
//         this->matriz->Append(lista);
//         this->matriz->Append(lista);
}

void MainWindow::ColocarImagen(int x, int y)
{
    Personaje* personaje;
    int posX_torre = Definicion_MapaY(y);
    int posY_torre = Definicion_MapaX(x);
//    int posX_torre = Definicion_MapaX(cursor->pos().x());
//    int posY_torre= Definicion_MapaY(cursor->pos().y());

    if (this->clickedPersonaje=="arquero11.png"){
        Arquero *arquero=new Arquero();
        personaje=arquero;


        cout<<"objeto posicionado en: "<<posX_torre<<" , "<< posY_torre<<endl;
        //this->matriz->EstablecerElemento(posX_torre, posY_torre, personaje);
    }
    else if(this->clickedPersonaje=="mago11.png"){
        // crear un objeto de mago
        Mago* mago = new Mago();
        personaje = mago;
    }
    else if(this->clickedPersonaje=="artillero11.png"){
        // crear un objeto de artillero
        Artillero* artillero = new Artillero();
        personaje = artillero;
    }
    else if(this->clickedPersonaje=="lanza_fuego1.png"){
        // crear un objeto de lanza fuego
        Lanza_Fuego* lanza_fuego = new Lanza_Fuego;
        personaje = lanza_fuego;
    }
    QLabel *imagen=new QLabel(this);//=new QLabel();
    if (this->clickedPersonaje!="" && x>150 && y>60 && x<1670 &&y<970)
    {
    QPixmap pixmap(this->ruta+"tower_images/"+this->clickedPersonaje);
    imagen->setPixmap(pixmap);
    imagen->setFixedSize(135, 70);
    imagen->move(x,y); //ensure that this coordinates are in you widget
    imagen->show();
    this->clickedPersonaje="";
    }
    this->matriz->EstablecerElemento(posX_torre, posY_torre, *personaje);
    this->matriz->Display();

    cout<<"poniendo imagen";

}

  void* MainWindow::AnimacionHaciaAbajo(void * argumentos)//(int x,int y, int velocidad)
{
    struct thread_data *a;
    a=(struct thread_data*)argumentos;

    int x=a->x,y=a->y;
    QLabel *imagen=new QLabel(this);//=new QLabel();
    QPixmap pixmap(this->ruta+"tower_images/image_grid.png");
    imagen->setPixmap(pixmap);
    imagen->setFixedSize(30, 30);
    int movimiento=5;
    while (y<400) { // aquí hay que agregar que en la posición no esté un curso
        y=y+movimiento;
        imagen->move(x, y); //ensure that this coordinates are in you widget
        imagen->show();
        usleep(a->velocidad);
    }




    cout<<"poniendo imagen";
  }

  void *MainWindow::prueba()
  {

  }

  int MainWindow::MapeadorX(int x)
  {
      int valorFinalx=0, shift=243-195;
      if (x>=243 && x<=388){
          valorFinalx=243;
      }
      else if (x<=563 && x>=388){
          valorFinalx=388;
      }
      else if (x<=722 && x>=563){
          valorFinalx=563;
      }
      else if (x<=878 && x>=722){
          valorFinalx=722;
      }
      else if (x<=1036 && x>=878){
          valorFinalx=878;
      }
      else if (x<=1198 && x>=1036){
          valorFinalx=1036;
      }
      else if (x<=1358 && x>=1198){
          valorFinalx=1198;
      }
      else if (x<=1509 && x>=1358){
          valorFinalx=1358;
      }
      else if (x<=1679 && x>=1509){
          valorFinalx=1509;
      }
      else if (x<=1800 && x>=1679){
          valorFinalx=1679;
      }
      return valorFinalx-shift;
  }

  int MainWindow::MapeadorY(int y)
  {
      int valorFinaly=0,shift=45;
      if (y>=120 && y<=207){
          valorFinaly=120;
      }
      else if (y<=281 && y>=207){
          valorFinaly=207;
      }
      else if (y<=368 && y>=281){
          valorFinaly=281;
      }
      else if (y<=453 && y>=368){
          valorFinaly=368;
      }
      else if (y<=534 && y>=453){
          valorFinaly=453;
      }
      else if (y<=619 && y>=534){
          valorFinaly=534;
      }
      else if (y<=713 && y>=619){
          valorFinaly=619;
      }
      else if (y<=803 && y>=713){
          valorFinaly=713;
      }
      else if (y<=893 && y>=803){
          valorFinaly=803;
      }
      else if (y<=973 && y>=893){
          valorFinaly=893;
      }
      return valorFinaly-shift;
  }

int MainWindow::Definicion_MapaX(int mapa_x){
    int posX=0;
    mapa_x = mapa_x + 48;
    if(mapa_x ==243){
        posX = 0;
    }
    else if(mapa_x == 388){
        posX = 1;
    }
    else if(mapa_x == 563){
        posX = 2;
    }
    else if(mapa_x == 722){
        posX = 3;
    }
    else if(mapa_x == 878){
        posX = 4;
    }
    else if(mapa_x == 1036){
        posX = 5;
    }
    else if(mapa_x == 1198){
        posX = 6;
    }
    else if(mapa_x == 1358){
        posX = 7;
    }
    else if(mapa_x == 1509){
        posX = 8;
    }
    else if(mapa_x == 1679){
        posX = 9;
    }
    return posX;
}

int MainWindow::Definicion_MapaY(int mapa_y){
    int posY=0;
    mapa_y = mapa_y + 45;
    if (mapa_y==120 ){
        posY=0;
    }
    else if (mapa_y == 207){
        posY=1;
    }
    else if (mapa_y == 281){
        posY=2;
    }
    else if (mapa_y == 368){
        posY=3;
    }
    else if (mapa_y == 453){
        posY=4;
    }
    else if (mapa_y == 534){
        posY=5;
    }
    else if (mapa_y == 619){
        posY=6;
    }
    else if (mapa_y == 713){
        posY=7;
    }
    else if (mapa_y == 803){
        posY=8;
    }
    else if (mapa_y == 893){
        posY=9;
    }
    return posY;
}

void MainWindow::ColocarPersonajeMatriz(int x, int y, Personaje personaje)
{

}


void MainWindow::draw_matriz(){
//    Personaje p;
//    Lista<Enemigo> enemigos;
//    int num;

//    //prueba de la matriz
//    Matriz <Personaje> *matriz=new Matriz<Personaje>();

//    Personaje  *cualquierPernaje=new Personaje();
//    Lista <Personaje> *lista=new Lista<Personaje>();
//    // 10 elementos de una fila
//    lista->add_end(*cualquierPernaje);
//    lista->add_end(*cualquierPernaje);
//    lista->add_end(*cualquierPernaje);
//    lista->add_end(*cualquierPernaje);
//    lista->add_end(*cualquierPernaje);
//    lista->add_end(*cualquierPernaje);
//    lista->add_end(*cualquierPernaje);
//    lista->add_end(*cualquierPernaje);
//    lista->add_end(*cualquierPernaje);
//    lista->add_end(*cualquierPernaje);
//    //10 filas y así se forma la matriz de 10xx10

//    matriz->Append(lista);
//    matriz->Append(lista);
//    matriz->Append(lista);
//    matriz->Append(lista);
//    matriz->Append(lista);
//    matriz->Append(lista);
//    matriz->Append(lista);
//    matriz->Append(lista);
//    matriz->Append(lista);
//    matriz->Append(lista);

//    matriz->Display();
//    // finalización de la prueba de la matriz

}

void MainWindow::image_arquero(){

//    QPixmap pixmap("/home/hazel/Escritorio/CE_proyecto3_datos/CE-vs-Estudiantes/Imagenes/elfo2.png");
//    QIcon ButtonIcon(pixmap);
//    ui->push_button_arquero->setIcon(ButtonIcon);
//    ui->push_button_arquero->setIconSize(pixmap.rect().size());

//    QPalette pal = ui->push_button_arquero->palette();
//    pal.setColor(QPalette::Button, QColor(1,32,15));  //"50,116,109"
//    ui->push_button_arquero->setAutoFillBackground(true);
//    ui->push_button_arquero->setPalette(pal);
//    ui->push_button_arquero->update();

    ui->push_button_arquero->setStyleSheet("QPushButton {background-color:#01200F; color: white;}");
    ui->push_button_arquero->setIcon(QIcon(this->ruta+"tower_images/arquero1.png"));
    ui->push_button_arquero->setIconSize(QSize(150, 150));


}

void MainWindow::image_artillero(){

//    QPalette pal = ui->push_button_artillero->palette();
//    pal.setColor(QPalette::Button, QColor(1,32,15));  //"50,116,109"
//    ui->push_button_artillero->setAutoFillBackground(true);
//    ui->push_button_artillero->setPalette(pal);
//    ui->push_button_artillero->update();

    ui->push_button_artillero->setStyleSheet("QPushButton {background-color:#01200F; color: white;}");
    ui->push_button_artillero->setIcon(QIcon(this->ruta+"tower_images/artillero1_1.png"));
    ui->push_button_artillero->setIconSize(QSize(150, 150));

}

void MainWindow::image_magos(){

//    QPalette pal = ui->push_button_mago->palette();
//    pal.setColor(QPalette::Button, QColor(1,32,15));  //"50,116,109"
//    ui->push_button_mago->setAutoFillBackground(true);
//    ui->push_button_mago->setPalette(pal);
//    ui->push_button_mago->update();

    ui->push_button_mago->setStyleSheet("QPushButton {background-color:#01200F; color: white;}");
    ui->push_button_mago->setIcon(QIcon(this->ruta+"tower_images/mago1_1.png"));
    ui->push_button_mago->setIconSize(QSize(150, 150));
}

void MainWindow::image_lanza_fuego(){

//    QPalette pal = ui->push_button_lanza_fuego->palette();
//    pal.setColor(QPalette::Button, QColor(1,32,15));  //"50,116,109"
//    ui->push_button_lanza_fuego->setAutoFillBackground(true);
//    ui->push_button_lanza_fuego->setPalette(pal);
//    ui->push_button_lanza_fuego->update();

    ui->push_button_lanza_fuego->setStyleSheet("QPushButton {background-color:#01200F; color: white;}");
    ui->push_button_lanza_fuego->setIcon(QIcon(this->ruta+"tower_images/lanza_fuego.png"));
    ui->push_button_lanza_fuego->setIconSize(QSize(150, 150));

}

void MainWindow::image_coin(){
    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    Pal.setColor(QPalette::Background, Qt::transparent);
    ui->pushButton_coin->setAutoFillBackground(true);
    ui->pushButton_coin->setPalette(Pal);
    //ui->pushButton_coin->setStyleSheet("QPushButton{background: transparent;}");
    ui->pushButton_coin->setIcon(QIcon(this->ruta+"tower_images/skull_coin.png"));
    ui->pushButton_coin->setIconSize(QSize(150, 150));

}

void MainWindow::settings_boton_estadisticas(){
    ui->push_button_estadisticas->setStyleSheet("QPushButton {background-color:#01200F; color: white;}");

}

void MainWindow::on_push_button_arquero_clicked()
{
    this->clickedPersonaje="arquero11.png";
    cout<<"You have push Arquero"<<endl;
}

void MainWindow::on_push_button_mago_clicked()
{
    this->clickedPersonaje="mago11.png";
    cout<<"You have push Mago "<<endl;
}

void MainWindow::on_push_button_artillero_clicked()
{
    this->clickedPersonaje="artillero11.png";
    cout<<"You have push Artillero"<<endl;
}

void MainWindow::on_push_button_lanza_fuego_clicked()
{
    this->clickedPersonaje="lanza_fuego1.png";
    cout<<"You have push Lanza Fuego"<<endl;
}

void MainWindow::on_push_button_estadisticas_clicked()
{
    EstadisticasWindow *ventana_estadisticas = new EstadisticasWindow;
    ventana_estadisticas->show();

}

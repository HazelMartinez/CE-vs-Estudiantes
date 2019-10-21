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
#include "QPalette"

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int shiftx=62,shifty=29;
    int x=cursor->pos().x()-933-shiftx,y=cursor->pos().y()-46-shifty;
    cout<<"Posición X:"<<cursor->pos().x() <<" Posición Y:"<<cursor->pos().y()<<endl;
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
    this->mapFromGlobal(QCursor::pos());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ColocarImagen(int x, int y)
{
    QLabel *imagen=new QLabel(this);//=new QLabel();
    QPixmap pixmap(this->ruta+"tower_images/image_grid.png");
    imagen->setPixmap(pixmap);
    imagen->setFixedSize(135, 70);
    imagen->move(x, y); //ensure that this coordinates are in you widget
    imagen->show();

    // cuando se coloca una una torre esta debe de enviar cada cierto tiempo una bala
    struct thread_data *argumentos;
    argumentos->x=x;
    argumentos->y=y;
    argumentos->velocidad=50000;
    pthread_t thread1;
    pthread_create(&thread1,nullptr,AnimacionHaciaAbajo,nullptr);

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


void MainWindow::draw_matriz(){
    //QGridLayout *matriz_lay = QGridLayout(ui->centralWidget);
    //matriz_lay->SetMinimumSize();

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

    cout<<"You have push Arquero"<<endl;
}

void MainWindow::on_push_button_mago_clicked()
{
    cout<<"You have push Mago "<<endl;
}

void MainWindow::on_push_button_artillero_clicked()
{
    cout<<"You have push Artillero"<<endl;
}

void MainWindow::on_push_button_lanza_fuego_clicked()
{
    cout<<"You have push Lanza Fuego"<<endl;
}

void MainWindow::on_push_button_estadisticas_clicked()
{
    EstadisticasWindow *ventana_estadisticas = new EstadisticasWindow;
    ventana_estadisticas->show();

}

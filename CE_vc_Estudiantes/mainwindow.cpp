#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Listas/matriz.h"
#include "QFrame"
#include "QWidget"
#include "QRectF"
#include "QPushButton"
#include "QHBoxLayout"
#include "QGraphicsScene"
#include "QPixmap"
#include "QIcon"
#include "estadisticaswindow.h"


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

    QPixmap bkgnd("/home/hazel/Escritorio/CE_proyecto3_datos/CE-vs-Estudiantes/Imagenes/fondo_total_f.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    ui->push_button_arquero->setIcon(QIcon("/home/hazel/Escritorio/CE_proyecto3_datos/CE-vs-Estudiantes/images_towers/arquero1.png"));
    ui->push_button_arquero->setIconSize(QSize(150, 150));


}

void MainWindow::image_artillero(){

//    QPalette pal = ui->push_button_artillero->palette();
//    pal.setColor(QPalette::Button, QColor(1,32,15));  //"50,116,109"
//    ui->push_button_artillero->setAutoFillBackground(true);
//    ui->push_button_artillero->setPalette(pal);
//    ui->push_button_artillero->update();

    ui->push_button_artillero->setStyleSheet("QPushButton {background-color:#01200F; color: white;}");
    ui->push_button_artillero->setIcon(QIcon("/home/hazel/Escritorio/CE_proyecto3_datos/CE-vs-Estudiantes/images_towers/artillero1_1.png"));
    ui->push_button_artillero->setIconSize(QSize(150, 150));

}

void MainWindow::image_magos(){

//    QPalette pal = ui->push_button_mago->palette();
//    pal.setColor(QPalette::Button, QColor(1,32,15));  //"50,116,109"
//    ui->push_button_mago->setAutoFillBackground(true);
//    ui->push_button_mago->setPalette(pal);
//    ui->push_button_mago->update();

    ui->push_button_mago->setStyleSheet("QPushButton {background-color:#01200F; color: white;}");
    ui->push_button_mago->setIcon(QIcon("/home/hazel/Escritorio/CE_proyecto3_datos/CE-vs-Estudiantes/images_towers/mago1_1.png"));
    ui->push_button_mago->setIconSize(QSize(150, 150));
}

void MainWindow::image_lanza_fuego(){

//    QPalette pal = ui->push_button_lanza_fuego->palette();
//    pal.setColor(QPalette::Button, QColor(1,32,15));  //"50,116,109"
//    ui->push_button_lanza_fuego->setAutoFillBackground(true);
//    ui->push_button_lanza_fuego->setPalette(pal);
//    ui->push_button_lanza_fuego->update();

    ui->push_button_lanza_fuego->setStyleSheet("QPushButton {background-color:#01200F; color: white;}");
    ui->push_button_lanza_fuego->setIcon(QIcon("/home/hazel/Escritorio/CE_proyecto3_datos/CE-vs-Estudiantes/images_towers/lanza_fuego.png"));
    ui->push_button_lanza_fuego->setIconSize(QSize(150, 150));

}

void MainWindow::image_coin(){
    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    Pal.setColor(QPalette::Background, Qt::transparent);
    ui->pushButton_coin->setAutoFillBackground(true);
    ui->pushButton_coin->setPalette(Pal);
    //ui->pushButton_coin->setStyleSheet("QPushButton{background: transparent;}");
    ui->pushButton_coin->setIcon(QIcon("/home/hazel/Escritorio/CE_proyecto3_datos/CE-vs-Estudiantes/images_towers/skull_coin.png"));
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

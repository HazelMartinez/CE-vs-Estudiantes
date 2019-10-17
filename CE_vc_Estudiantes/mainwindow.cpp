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
    /*
    QPixmap pixmap("/home/hazel/Escritorio/CE_proyecto3_datos/CE-vs-Estudiantes/Imagenes/elfo2.png");
    QIcon ButtonIcon(pixmap);
    ui->push_button_arquero->setIcon(ButtonIcon);
    ui->push_button_arquero->setIconSize(pixmap.rect().size());
    */
    ui->push_button_arquero->setIcon(QIcon("/home/hazel/Escritorio/CE_proyecto3_datos/CE-vs-Estudiantes/Imagenes/elfo2.png"));
    ui->push_button_arquero->setIconSize(QSize(65, 65));


}

void MainWindow::image_artillero(){

}

void MainWindow::image_magos(){

}

void MainWindow::image_lanza_fuego(){

}

void MainWindow::on_push_button_arquero_clicked()
{
    cout<<"You have push Arquero"<<endl;
}

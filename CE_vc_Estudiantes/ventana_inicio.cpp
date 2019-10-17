#include "ventana_inicio.h"
#include "ui_ventana_inicio.h"
#include "mainwindow.h"

Ventana_Inicio::Ventana_Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Inicio)
{
    ui->setupUi(this);

}

Ventana_Inicio::~Ventana_Inicio()
{
    delete ui;
}

void Ventana_Inicio::on_pushButton_individual_win_clicked()
{
    MainWindow *ventana_juego = new MainWindow;
    hide();
    ventana_juego->show();
}

void Ventana_Inicio::on_pushButton_clicked()   //aca se debe validar que se entre en el modo aprobacion individual
{
    MainWindow *ventana_juego = new MainWindow;
    hide();
    ventana_juego->show();

}

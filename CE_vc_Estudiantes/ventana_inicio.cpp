#include "ventana_inicio.h"
#include "ui_ventana_inicio.h"

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

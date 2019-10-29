#include "estadisticaswindow.h"
#include "ui_estadisticaswindow.h"

EstadisticasWindow::EstadisticasWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EstadisticasWindow)
{
    ui->setupUi(this);
    muestra_label_estadisticas();
    muestra_label_reprobados();
    muestra_label_fitness();
    muestra_label_inversiones();
    muestra_label_inversiones_ocurridas();
    muestra_label_muta_ocurridas();
    muestra_label_nivel();
    muestra_label_proba_mutaciones();
}

EstadisticasWindow::~EstadisticasWindow()
{
    delete ui;
}

void EstadisticasWindow::muestra_label_estadisticas()
{

    //ui->label_generaciones->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    ui->label_1->setText("1");
    ui->label_1->show();
}

void EstadisticasWindow::muestra_label_reprobados()
{
    ui->label_2->setText("1000000");
    ui->label_2->show();
}

void EstadisticasWindow::muestra_label_fitness()
{
    ui->label_3->setText("8");
    ui->label_3->show();
}

void EstadisticasWindow::muestra_label_nivel()
{
    ui->label_4->setText("5");
    ui->label_4->show();

}

void EstadisticasWindow::muestra_label_proba_mutaciones()
{
    ui->label_5->setText("50%");
    ui->label_5->show();
}

void EstadisticasWindow::muestra_label_muta_ocurridas()
{
    ui->label_6->setText("4 mutaciones ocurridas");
    ui->label_6->show();
}

void EstadisticasWindow::muestra_label_inversiones()
{
    ui->label_7->setText("2");
    ui->label_7->show();
}

void EstadisticasWindow::muestra_label_inversiones_ocurridas()
{
    ui->label_8->setText("4");
    ui->label_8->show();
}

void EstadisticasWindow::on_pushButton_close_clicked()
{
    destroy();
}

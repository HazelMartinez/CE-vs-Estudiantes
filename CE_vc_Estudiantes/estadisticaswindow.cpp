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
    ui->label_generaciones->setText("1");
    ui->label_generaciones->show();
}

void EstadisticasWindow::muestra_label_reprobados()
{
    ui->label_reprobados_2->setText("1000000");
    ui->label_reprobados_2->show();
}

void EstadisticasWindow::muestra_label_fitness()
{
    ui->label_fitness_2->setText("8");
    ui->label_fitness_2->show();
}

void EstadisticasWindow::muestra_label_nivel()
{
    ui->label_nivel_2->setText("5");
    ui->label_nivel_2->show();

}

void EstadisticasWindow::muestra_label_proba_mutaciones()
{
    ui->label_probabilidades->setText("50%");
    ui->label_probabilidades->show();
}

void EstadisticasWindow::muestra_label_muta_ocurridas()
{
    ui->label_mutaciones_ocurridas->setText("4 mutaciones ocurridas");
    ui->label_mutaciones_ocurridas->show();
}

void EstadisticasWindow::muestra_label_inversiones()
{
    ui->label_proba_inveriones->setText("2");
    ui->label_proba_inveriones->show();
}

void EstadisticasWindow::muestra_label_inversiones_ocurridas()
{
    ui->label_inversiones_ocurridas->setText("4");
    ui->label_inversiones_ocurridas->show();
}

void EstadisticasWindow::on_pushButton_close_clicked()
{
    destroy();
}

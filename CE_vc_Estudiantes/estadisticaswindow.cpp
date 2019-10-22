#include "estadisticaswindow.h"
#include "ui_estadisticaswindow.h"

EstadisticasWindow::EstadisticasWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EstadisticasWindow)
{
    ui->setupUi(this);
}

EstadisticasWindow::~EstadisticasWindow()
{
    delete ui;
}

void EstadisticasWindow::on_pushButton_close_clicked()
{
    destroy();
}

#ifndef ESTADISTICASWINDOW_H
#define ESTADISTICASWINDOW_H

#include <QMainWindow>

namespace Ui {
class EstadisticasWindow;
}

class EstadisticasWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EstadisticasWindow(QWidget *parent = 0);
    ~EstadisticasWindow();

private slots:
    void on_pushButton_close_clicked();

private:
    Ui::EstadisticasWindow *ui;
};

#endif // ESTADISTICASWINDOW_H

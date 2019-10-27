#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Listas/matriz.h"
#include "QGridLayout"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>


namespace Ui {
class MainWindow;
class Widget;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event) override;

public:
    struct thread_data {
       int  x,y,velocidad;

    };
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene* scene;
    void InicializarMatriz();
    void ColocarImagen(int x,int y);
    void* AnimacionHaciaAbajo(void*  argumentos);
    void *prueba();
    int MapeadorX(int x);
    int MapeadorY(int y);
    int Definicion_MapaX(int mapa_x);
    int Definicion_MapaY(int mapa_y);
    void ColocarPersonajeMatriz(int x, int y, Personaje personaje);

private slots:
    void draw_matriz();
    void image_arquero();
    void image_artillero();
    void image_magos();
    void image_lanza_fuego();
    void image_coin();



    void settings_boton_estadisticas();



    void on_push_button_arquero_clicked();

    void on_push_button_mago_clicked();

    void on_push_button_artillero_clicked();

    void on_push_button_lanza_fuego_clicked();

    void on_push_button_estadisticas_clicked();

private:
    Ui::MainWindow *ui;
    QCursor *cursor;
    QString clickedPersonaje="";
    QString ruta="/home/hazel/Vídeos/CE-vs-Estudiantes/CE_vc_Estudiantes/";

    Matriz <Personaje> *matriz=new Matriz<Personaje>();
};

#endif // MAINWINDOW_H

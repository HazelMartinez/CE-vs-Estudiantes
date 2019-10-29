#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Listas/matriz.h"
#include "QGridLayout"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "Evolucionador.h"


namespace Ui {
class MainWindow;
class Widget;
}

/**
 * @brief Clase que gestiona la ventana principal y el juego.
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    /**
     * @brief Sobreescritura de la acción al presionar el mouse.
     *
     * @param event
     */
    void mousePressEvent(QMouseEvent *event) override;

public:
    /**
     * @brief
     *
     */
    struct thread_data {
       int  x,y,velocidad; /**< TODO: describe */

    };
    Node<Enemigo*> *tempAparecer; /**Enemigo que se esta moviendo */
       int movimientoActual = 1; /**Movimiento del enemigo */
       int pixmap = 1; /**Imagen actual*/
    /**
     * @brief Constructor
     *
     * @param parent padre de la ventana.
     */
    explicit MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Destructor por defecto.
     *
     */
    ~MainWindow();
    QGraphicsScene* scene; /**< TODO: describe */
    /**
     * @brief Coloca la imagen de los cursos en el tablero
     *
     * @param x Posición en el eje x a colocar el curso.
     * @param y Posición en el eje y a colocar el curso.
     */
    void ColocarImagen(int x,int y);
    /**
     * @brief
     *
     * @param argumentos
     */
    void* AnimacionHaciaAbajo(void*  argumentos);
    /**
     * @brief
     *
     */
    void *prueba();
    /**
     * @brief Le asigna un rango de pixeles a una posición i de la matriz.
     *
     * @param x posición en x a asignarle al i.
     * @return int i correspondiente al x.
     */
    int MapeadorX(int x);
    /**
     * @brief Le asigna un rango de pixeles a una posición j de la matriz.
     *
     * @param y posición en y a asignarle al j.
     * @return int j correspondiente al y.
     */
    int MapeadorY(int y);
    /**
     * @brief
     *
     * @param mapa_x
     * @return int
     */
    int Definicion_MapaX(int mapa_x);
    /**
     * @brief
     *
     * @param mapa_y
     * @return int
     */
    int Definicion_MapaY(int mapa_y);
    void InicializarMatriz();
    void ColocarPersonajeMatriz(int x, int y, Personaje personaje);

private slots:
    /**
     * @brief Muestra enemigos nuevos.
     *
     */
    void aparecenEnemigos();
    /**
     * @brief Mueve a los enemigos.
     *
     */
    void moverEnemigos();
    /**
     * @brief Dibuja el tablero.
     *
     */
    void draw_matriz();
    /**
     * @brief Muestra imagen de arqueros
     *
     */
    void image_arquero();
    /**
     * @brief Muestra imagen de artilleros
     *
     */
    void image_artillero();
    /**
     * @brief Muestra imagen de magos
     *
     */
    void image_magos();
    /**
     * @brief Muestra imagen de lanza fuegos.
     *
     */
    void image_lanza_fuego();
    /**
     * @brief Muestra imagen de los creditos.
     *
     */
    void image_coin();



    /**
     * @brief Muestra el boton de estadisticas.
     *
     */
    void settings_boton_estadisticas();



    /**
     * @brief Guarda un arquero para colocarlo en el tablero.
     *
     */
    void on_push_button_arquero_clicked();

    /**
     * @brief Guarda un mago para colocarlo en el tablero.
     *
     */
    void on_push_button_mago_clicked();

    /**
     * @brief Guarda un artillero para colocarlo en el tablero.
     *
     */
    void on_push_button_artillero_clicked();

    /**
     * @brief Guarda un lanza fuego para colocarlo en el tablero.
     *
     */
    void on_push_button_lanza_fuego_clicked();

    /**
     * @brief Muestra la ventana de estadisticas.
     *
     */
    void on_push_button_estadisticas_clicked();

private:
    Ui::MainWindow *ui; /**Interfaz de la ventana. */
    QCursor *cursor; /**De aquí se obtiene la posición del mouse */
    QString clickedPersonaje=""; /**Se guarda el curso a colocar en el tablero */
    QString ruta=
    "/home/hazel/Escritorio/Proyecto2_CEvsEstudiantes/CE-vs-Estudiantes/CE_vc_Estudiantes/";
    /**Ruta donde se guardan las imagenes*/
    Matriz <Personaje> *matriz=new Matriz<Personaje>(); /**Matriz que guarda los personajes colocados en el tablero. */
    Lista<Enemigo*> enemigos; /**Oleada actual de enemigos*/
    Evolucionador *e; /** Instancia de la clase evolucionador para crear nuevas oleadas */
};

#endif // MAINWINDOW_H

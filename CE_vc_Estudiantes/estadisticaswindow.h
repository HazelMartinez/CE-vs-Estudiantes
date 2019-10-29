#ifndef ESTADISTICASWINDOW_H
#define ESTADISTICASWINDOW_H

#include <QMainWindow>

namespace Ui {
class EstadisticasWindow;
}

/**
 * @brief Ventana para mostrar las estadisticas del juego.
 *
 */
class EstadisticasWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor por defecto,
     *
     * @param parent padre de la clase a crear.
     */
    explicit EstadisticasWindow(QWidget *parent = nullptr);
    /**
     * @brief Destructor por defecto.
     *
     */
    ~EstadisticasWindow();
    void muestra_label_estadisticas();
    void muestra_label_reprobados();
    void muestra_label_fitness();
    void muestra_label_nivel();
    void muestra_label_proba_mutaciones();
    void muestra_label_muta_ocurridas();
    void muestra_label_inversiones();
    void muestra_label_inversiones_ocurridas();

private slots:
    /**
     * @brief Slot para cerrar la ventana.
     *
     */
    void on_pushButton_close_clicked();

private:
    Ui::EstadisticasWindow *ui; /**Interfaz de usuario de la ventana. */
};

#endif // ESTADISTICASWINDOW_H

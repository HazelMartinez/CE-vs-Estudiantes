#ifndef VENTANA_INICIO_H
#define VENTANA_INICIO_H

#include <QMainWindow>

namespace Ui {
class Ventana_Inicio;
}

/**
 * @brief Ventana de inicio
 *
 */
class Ventana_Inicio : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor por defecto.
     *
     * @param parent padre de la ventana
     */
    explicit Ventana_Inicio(QWidget *parent = nullptr);
    /**
     * @brief Destructor por defecto.
     *
     */
    ~Ventana_Inicio();

private slots:
    /**
     * @brief Selecciona el modo de juego individual
     *
     */
    void on_pushButton_individual_win_clicked();

    /**
     * @brief Selecciona el modo de juego colectivo
     *
     */
    void on_pushButton_clicked();

private:
    Ui::Ventana_Inicio *ui; /**Interfaz grafica de la ventana*/
};

#endif // VENTANA_INICIO_H

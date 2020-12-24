#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define FORMULA(var) (4*var*(1-var))

#include <QMainWindow>
#include "evolutionprocess.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_Quitter_clicked();
    void on_pb_Lancer_clicked();
    void on_pb_Precedent_clicked();
    void on_pb_Suivant_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double> qv_x, qv_y;

    EvolutionProcess *m_process;
    bool m_lancer_pushed = false;
    int m_generations_index = 0;
};
#endif // MAINWINDOW_H

#ifndef MONCANVAS_H
#define MONCANVAS_H

#include <QWidget>
#include <QtGui>
#include "generation.h"

class MonCanvas : public QWidget
{
    Q_OBJECT
private:
    int nb_cubes_x = 10, nb_cubes_y = 5;
    int ech_x, ech_y;
    Generation *m_generation;

    void changeEchelle();
    QPointF changeCoo(QPointF p);
    QPointF changeCoo_figure(QPointF p);
public:
    explicit MonCanvas(QWidget *parent = nullptr);
    Generation *getGeneration() const;
    void setGeneration(Generation *generation);

protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // MONCANVAS_H

#include "moncanvas.h"
#include <QDebug>
#include <QPainter>

MonCanvas::MonCanvas(QWidget *parent) : QWidget(parent)
{}

Generation *MonCanvas::getGeneration() const
{
    return m_generation;
}

void MonCanvas::setGeneration(Generation *generation)
{
    m_generation = generation;
}

void MonCanvas::changeEchelle()
{
    // récupère la taille du canvas
    int largCan=size().width();
    int hautCan=size().height();
    // recalcule ech_x et ech_y
    ech_x = largCan / nb_cubes_x;
    ech_y = hautCan / nb_cubes_y;
    qDebug() << ech_x <<", "<< ech_y;
}

QPointF MonCanvas::changeCoo(QPointF p)
{
    return QPointF(p.rx()*ech_x, p.ry()*ech_y);
}

QPointF MonCanvas::changeCoo_figure(QPointF p)
{
    return QPointF(
        p.rx() /*/ (m_generation->getX_max() - m_generation->getX_min())*/ * ech_x / 100,
        p.ry() /*/ (m_process->getY_max() - m_process->getY_min())*/ * ech_y / 100
    );
}

void MonCanvas::paintEvent(QPaintEvent *)
{
    changeEchelle();
    QPainter painter(this);

    QPen black_slim(Qt::black,1);
    QPen black_bold(Qt::black,3);
    QPen black_dash(Qt::black,1);
    black_dash.setStyle(Qt::DashLine);

    painter.setPen(black_dash);

    //display frame

    for(int l=0; l<=nb_cubes_y; l++)
        painter.drawLine(changeCoo(QPointF(0,l)), changeCoo(QPointF(nb_cubes_x,l)));
    for(int c=0; c<=nb_cubes_x; c++)
        painter.drawLine(changeCoo(QPointF(c,0)), changeCoo(QPointF(c, nb_cubes_y)));

    //display figure
    /*
    for(int i = int(m_process->getX_min()) * 100; i < int(m_process->getX_max()) * 100; i++) {

    }*/

    //display points
/*
    painter.setPen(black_bold);
    int temp = m_generation->length();
    for(int i = 0; i < temp; i++) {
        painter.drawPoint(changeCoo(QPointF(m_generation->at(i)->getX(), m_generation->at(i)->getY())));
    }*/
}

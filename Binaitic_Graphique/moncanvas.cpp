#include "moncanvas.h"
#include <QDebug>
#include <QPainter>
#include <QTextStream>
#include <QList>
#include <stdio.h>

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
    qDebug() << "repaint scale :" << ech_x <<", "<< ech_y;
}

QPointF MonCanvas::changeCoo(QPointF p)
{
    return QPointF(p.rx()*ech_x, p.ry()*ech_y);
}

QPointF MonCanvas::changeCoo_figure(QPointF p)
{
    return QPointF(p.rx()*ech_x * nb_cubes_x, (m_generation->at(m_generation->length()-1)->getY() - p.ry())*ech_y * nb_cubes_y);
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

    painter.setPen(black_bold);
    int temp = m_generation->length();
    char digit_text[10];
    for(int i = 0; i < temp; i++) {
        //qDebug()<<m_generation->at(i)->getX();
        sprintf(digit_text,"%d",m_generation->at(i)->getGene_num());
        QString text(digit_text);
        painter.drawPoint(changeCoo_figure(QPointF(m_generation->at(i)->getX(), m_generation->at(i)->getY())));
        painter.drawText(changeCoo_figure(QPointF(m_generation->at(i)->getX(), m_generation->at(i)->getY())), text);
    }
}

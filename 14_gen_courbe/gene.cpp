#include "gene.h"
#include <QTextStream>


double Gene::getX() const
{
    return m_x;
}

double Gene::getY() const
{
    return m_y;
}

QString Gene::toString()
{
    QString res;
    QTextStream buf(&res);

    buf<<"x = "<<m_x<<", y = "<<m_y;

    return res;
}

bool Gene::lessXThan(Gene *g1, Gene *g2)
{
    return g1->getX() < g2->getX();
}

bool Gene::lessYThan(Gene *g1, Gene *g2)
{
    return g1->getY() < g2->getY();
}

Gene::Gene(double x, double y): m_x(x), m_y(y)
{

}


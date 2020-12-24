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

    buf<<"gene num "<<m_gene_num<<" : x = "<<m_x<<", y = "<<m_y;

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

void Gene::setX(double x)
{
    m_x = x;
}

void Gene::setY(double y)
{
    m_y = y;
}

int Gene::getGene_num() const
{
    return m_gene_num;
}

void Gene::setGene_num(int gene_num)
{
    m_gene_num = gene_num;
}

Gene::Gene(double x, double y): m_x(x), m_y(y)
{

}


#include "generation.h"
#include <QTextStream>

Generation::Generation(double x_min, double x_max): m_x_max(x_max), m_x_min(x_min)
{

}

double Generation::getX_min() const
{
    return m_x_min;
}

double Generation::getX_max() const
{
    return m_x_max;
}

void Generation::GeneAppend(Gene *a_gene)
{
    append(a_gene);
    m_ind++;
}

void Generation::GeneAppend(double x, double y)
{
    Gene *a_gene = new Gene(x, y);
    append(a_gene);
    m_ind++;
}

QString Generation::toString()
{
    QString res;
    QTextStream buf(&res);

    for(int i = 0; i < m_ind; i++)
        buf<<"Point num "<<i<<" : "<<at(i)->toString()<<endl;

    return res;
}

double Generation::getFitness() const
{
    return m_fitness;
}

void Generation::setFitness(double fitness)
{
    m_fitness = fitness;
}

bool Generation::lessFitnessThan(Generation *g1, Generation *g2)
{
    return g1->getFitness() < g2->getFitness();
}

int Generation::getGeneration_number() const
{
    return m_generation_number;
}

void Generation::setGeneration_number(int generation_number)
{
    m_generation_number = generation_number;
}

#include "generation.h"
#include <QTextStream>

int Generation::getGene_ind() const
{
    return m_gene_ind;
}

void Generation::setGene_ind(int gene_ind)
{
    m_gene_ind = gene_ind;
}

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
    a_gene->setGene_num(m_gene_ind);
    m_gene_ind++;
}

void Generation::GeneAppend(double x, double y)
{
    Gene *a_gene = new Gene(x, y);
    a_gene->setGene_num(m_gene_ind);
    append(a_gene);
    m_gene_ind++;
}

QString Generation::toString()
{
    QString res;
    QTextStream buf(&res);

    buf<<"generation num "<<m_generation_number<<" :"<<endl;

    for(int i = 0; i < m_gene_ind; i++)
        buf<<at(i)->toString()<<endl;

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

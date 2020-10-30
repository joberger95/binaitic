#include "evolutionprocess.h"
#include <QTextStream>
#include <QDebug>

EvolutionProcess::EvolutionProcess(double x_min, double x_max): m_x_min(x_min), m_x_max(x_max)
{

}

void EvolutionProcess::GenerationAppend(void)
{
    double x;
    double y;
    Gene *a_gene;

    Generation *a_generation = new Generation(m_x_min, m_x_max);
    a_generation->setGeneration_number(m_generation_ind);
    append(a_generation);
    m_generation_ind++;

    for(int i = 0; i < Parameters::initialGenesNb; i++) {
        x = Parameters::randomGenerator->getFloat();
        if(x < m_x_min || x > m_x_max) {
            i--;
            continue;
        }
        y = FORMULA(x);
        a_gene = new Gene(x, y);
        a_generation->GeneAppend(a_gene);
    }

    //qDebug() <<a_generation->toString();
    std::sort(a_generation->begin(), a_generation->end(), Gene::lessYThan);
    a_generation->setFitness(a_generation->at(0)->getY());
}

void EvolutionProcess::init()
{
    for(int i = 0; i < Parameters::generationsMaxNb; i++) {
        //qDebug() <<"Géneration "<<i;
        EvolutionProcess::GenerationAppend();
    }
    std::sort(begin(), end(), Generation::lessFitnessThan);
}

QString EvolutionProcess::toString()
{
    QString res;
    QTextStream buf(&res);
    for(int i = 0; i < m_generation_ind; i++)
        buf<<"Generation num "<<at(i)->getGeneration_number()<<" : "<<at(i)->getFitness()<<endl;

    return res;
}

int EvolutionProcess::getGeneration_ind() const
{
    return m_generation_ind;
}

void EvolutionProcess::setGeneration_ind(int generation_ind)
{
    m_generation_ind = generation_ind;
}

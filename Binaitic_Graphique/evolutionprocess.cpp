#include "evolutionprocess.h"
#include <QTextStream>
#include <QDebug>
#include "misc.h"
#include <math.h>

double EvolutionProcess::getX_min() const
{
    return m_x_min;
}

double EvolutionProcess::getX_max() const
{
    return m_x_max;
}

double EvolutionProcess::getY_min() const
{
    return m_y_min;
}

double EvolutionProcess::getY_max() const
{
    return m_y_max;
}

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

        if(y < m_y_min)
            m_y_min = y;
        else if(y > m_y_max)
            m_y_max = y;

        a_gene = new Gene(x, y);
        a_generation->GeneAppend(a_gene);
    }
    std::sort(a_generation->begin(), a_generation->end(), Gene::lessYThan);
    a_generation->setFitness(a_generation->at(0)->getY());
}

void EvolutionProcess::run()
{
    EvolutionProcess::GenerationAppend();
    for(int i = 0; i < Parameters::generationsMaxNb - 1; i++) {
        crossover(0);
        mutate(0);
    }
    std::sort(begin(), end(), Generation::lessFitnessThan);
}

QString EvolutionProcess::toString()
{
    QString res;
    QTextStream buf(&res);
    for(int i = 0; i < m_generation_ind; i++) {
        buf<<"Fitness "<<at(i)->getGeneration_number()<<" : "<<at(i)->getFitness()<<endl<<at(i)->toString()<<endl;
    }
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

void EvolutionProcess::mutate(int ind)
{

    do_ch_t temp;
    int rand_offset;

    for (int i = 0; i < Parameters::initialGenesNb; i++) {
        if(Parameters::randomGenerator->getFloat() < Parameters::mutationRate) {

            rand_offset = Parameters::randomGenerator->get(DOUBLE_EXP_OFFSET - 1); // from 0 to 51 (mantiss lenght)

            temp._double = at(ind)->at(i)->getX();
            temp._long_long ^= (1<<rand_offset);

            if (temp._double < 0)
                temp._long_long &= ~DOUBLE_SIGN_MASK;

            if(temp._double > 1)
                temp._long_long %= 2;

            at(ind)->at(i)->setX(temp._double);

            at(ind)->at(i)->setY(FORMULA(temp._double));
        }
    }
}

void EvolutionProcess::crossover(int ind)
{

    do_ch_t temp;
    do_ch_t temp_2;

    Gene *a_gene;

    Generation *a_generation = new Generation(m_x_min, m_x_max);
    a_generation->setGeneration_number(m_generation_ind);
    append(a_generation);
    m_generation_ind++;

    a_gene = new Gene(at(0)->at(0)->getX(), at(0)->at(0)->getY()); //insert first gene
    a_gene->setGene_num(at(0)->at(0)->getGene_num());
    a_generation->GeneAppend(a_gene);

    for (int i = 1; i < Parameters::initialGenesNb; i++) {

        temp._double = at(0)->at(i)->getX(); //X alfa
        temp_2._double = at(ind)->at(i)->getX(); //selected X

        if(Parameters::randomGenerator->getFloat() < Parameters::crossoverRate) {
            temp_2._long_long &= ~(uint64_t(pow(2, DOUBLE_EXP_OFFSET/1.2) - 1));
            temp_2._long_long |= temp._long_long & (uint64_t(pow(2, DOUBLE_EXP_OFFSET/1.2) - 1)); // modified selected X

            if (temp_2._double < 0)
                temp_2._long_long &= ~DOUBLE_SIGN_MASK;

            if(temp_2._double > 1)
                temp_2._long_long %= 2;
        }

        a_gene = new Gene(temp_2._double, FORMULA(temp_2._double));
        a_gene->setGene_num(at(ind)->at(i)->getGene_num());

        a_generation->append(a_gene);
        a_generation->setGene_ind(a_generation->getGene_ind() + 1);
    }

    std::sort(a_generation->begin(), a_generation->end(), Gene::lessYThan);
    a_generation->setFitness(a_generation->at(0)->getY());
}


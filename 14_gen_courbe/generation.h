#ifndef GENERATION_H
#define GENERATION_H

#include "gene.h"
#include <QList>
#include <QString>

class Generation : public QList<Gene *>
{
private:
    double m_x_max;
    double m_x_min;
    int m_ind;
    double m_fitness;
    int m_generation_number;
public:
    Generation(double x_min, double x_max);
    double getX_max() const;
    double getX_min() const;
    void GeneAppend(Gene *a_gene);
    void GeneAppend(double x, double y);
    QString toString();
    double getFitness() const;
    void setFitness(double fitness);
    static bool lessFitnessThan(Generation *g1, Generation *g2);
    int getGeneration_number() const;
    void setGeneration_number(int generation_number);
};

#endif // GENERATION_H

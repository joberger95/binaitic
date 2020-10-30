#ifndef EVOLUTIONPROCESS_H
#define EVOLUTIONPROCESS_H

#include "generation.h"
#include "myrandom.h"
#include "parameters.h"
#include <QList>
#include <QString>

#define FORMULA(var) (4*var*(1-var))

class EvolutionProcess : public QList<Generation *>
{
private:
    double m_x_min;
    double m_x_max;
    int m_generation_ind = 0;
public:
    EvolutionProcess(double x_min, double x_max);
    void GenerationAppend(void);
    void init(void);
    QString toString(void);
    int getGeneration_ind() const;
    void setGeneration_ind(int generation_ind);
};

#endif // EVOLUTIONPROCESS_H

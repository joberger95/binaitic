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
    double m_x_min = 0;
    double m_x_max = 0;
    double m_y_min = 0;
    double m_y_max = 0;
    int m_generation_ind = 0;
public:
    EvolutionProcess(double x_min, double x_max);
    void GenerationAppend(void);
    void run(void);
    QString toString(void);
    int getGeneration_ind() const;
    void setGeneration_ind(int generation_ind);
    void mutate(int ind);
    void crossover(int ind);
    double getX_min() const;
    double getX_max() const;
    double getY_min() const;
    double getY_max() const;
};

#endif // EVOLUTIONPROCESS_H

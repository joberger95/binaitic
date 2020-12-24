#include "historique.h"
#include <QTextStream>

int Historique::getIdGeneration() const
{
    return m_idGeneration;
}

Individual Historique::getIndividu() const
{
    return m_individu;
}

Historique::Historique(int id, Individual *ind):m_idGeneration(id)
{
    // recopie brute de ind dans m_individu
    m_individu.setFitness(ind->getFitness());
    foreach (Gene *g, ind->m_genome) {
        m_individu.m_genome.append(g);
    }
}

QString Historique::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"Generation "<<m_idGeneration<<" : {"<<m_individu.toString()<<"}";
    return res;
}
